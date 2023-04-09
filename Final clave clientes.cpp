/*Se necesita mostrar para cada uno de los N clientes 5 claves para cada uno.
Por cada cliente se ingresa el numero. La primer clave es un numero primo
generado mayor que el numero del cliente. La segunda clave es el primer par
mayor al numero del cliente. La tercer clave es el promedio de la primera 
y de la segunda. La cuarta clave es la suma de los cuadrados de las 2
anteriores claves. La quinta clave es la suma de todas las anteriores.
Mostrar cada clave y la primera de cada cliente cargarla en una lista
ordenada de mayor a menor.*/

#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

int clave[100][5];
int vector[100];
void primera_clave(int i, int num_cliente);
void segunda_clave(int i, int num_cliente);
void tercera_clave(int i);
void cuarta_clave(int i);
void quinta_clave(int i);
void carga(int N);
void ordenar(int N);
void recorrer(int N);


struct lista {
	int nro;
	struct lista *sig;
}*p, *L;

int main()
{
	int N, num_cliente;
    printf("Ingrese la cantidad de clientes: ");
	scanf("%d", &N);
	for(int i=0; i<N; i++)
	{
		printf("\nIngrese el numero de cliente: ");
		scanf("%d", &num_cliente);
		primera_clave(i, num_cliente);
		segunda_clave(i, num_cliente);
		tercera_clave(i);
		cuarta_clave(i);
		quinta_clave(i);
	}
	carga(N);
	ordenar(N);
	recorrer(N);
}

void primera_clave(int i, int num_cliente)
{
	int div, senial=1, num;
	float resto=0;
	
	srand(time(NULL));
	
	while (senial==1)
	{
		senial=0;
		num=num_cliente+rand()%(100-num_cliente+1);
		
		for(div=1; div<num-1; div++)
		{
			resto=num/div;
			if(resto==0)
			{
				senial=1;
			}
		}
	}
	
	clave[i][1]=num;
	printf("\nLa primera clave es: %d\n", clave[i][1]);
}

void segunda_clave(int i, int num_cliente)
{
	num_cliente++;
	while((num_cliente%2)!=0)
	{
		num_cliente++;
	}
	clave[i][2]=num_cliente;
	printf("La segunda clave es: %d\n", clave[i][2]);
}

void tercera_clave(int i)
{
	int suma, promedio;
	
	suma=clave[i][1]+clave[i][2];
	promedio=suma/2;
	clave[i][3]=promedio;
	printf("La tercera clave es: %d\n", clave[i][3]);
}

void cuarta_clave(int i)
{
	clave[i][4]=(pow(clave[i][2], 2))+(pow(clave[i][3], 2));
	printf("La cuarta clave es: %d\n", clave[i][4]);
}

void quinta_clave(int i)
{
	clave[i][5]=clave[i][1]+clave[i][2]+clave[1][3]+clave[i][4];
	printf("La quinta clave es: %d\n", clave[i][5]);
}

void ordenar(int N)
{
	int aux=0;
	for(int i=0; i<N; i++)
	{
		vector[i]=clave[i][1];
		i++;
	}
	for(int c=0; c<N-1; c++)
	{
		for(int x=c+1; x<N; x++)
		{
			if(vector[c]<vector[x])
			{
				aux=vector[c];
				vector[c]=vector[x];
				vector[x]=aux;
				aux++;
			}
		}
	}
}

void carga(int N)
{
	L=NULL;
	for(int i=0; i<N; i++)
	{
		p=(struct lista *)malloc(sizeof(struct lista));
		p->nro=vector[i];
		p->sig=L;
		L=p;
	}
}

void recorrer(int N)
{
	p=L;
	printf("La lista ordenada de menor a mayor es: \n");
	while (p!=NULL)
	{
		printf("%d ", p->nro);
		p=p->sig;
	}
}
	
	
    

	
