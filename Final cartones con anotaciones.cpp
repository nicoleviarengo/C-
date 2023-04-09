/*generar N cartones de un bingo. Cada carton consta de una grilla de 4 filas
por 5 columnas con nros al azar en el rango de 1 a 99 inclusive (cada carton no 
tiene que tener nros repetidos). A cada carton se le otorga un nro para el sorteo
que sera la suma de los nros del carton de bingo. Mostrar el nro de carton y cada 
carton. 
Cada uno de los nros para el sorteo (nro del carton) se debera cargar en una lista 
en forma ordenada de mayor a menor. Mostrar lista.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int carton[4][5];
int vector[100];
void generar(int n);
void ordenarvect(int n);
void mostrarlist();

struct lista{
	int orden;
	struct lista *sig;
}*L, *p;

int main()
{
	int n;
	printf("Ingrese la cantidad de cartines a generar: \n");
	scanf("%d", &n);
	generar(n);
	ordenarvect(n);
}

void generar(int n)
{
	int num, ban=0, suma, k=0;
	srand(time(NULL));
	for(int i=0; i<n; i++)
	{
		suma=0;     // 1)INICIALIZAR LA SUMA EN 0
		
		for(int f=0; f<4; f++) 
		{                        // 2)RECORRER LA MATRIZ POR SUS FILAS Y COLUMNAS (INDICA LA CANTIDAD DE NUMS A GENERAR)
			for(int c=0; c<5; c++)
			{
				num=1+rand()%(99+1-1);  // 3)GENERAR NUMEROS ENTRE EL 1 Y EL 99
				
				if(num==carton[f][c])  // 4)COMPROBAR QUE NO ESTEN REPETIDOS
				{
					ban=1; // bandera
				}
				if(ban==0)
				{
					carton[f][c]=num; // Numero de cada carton
				}
				suma=suma+carton[f][c];   // 5) SUMA DE LOS ELEMENTOS DEL CARTON PARA EL NUM DE SORTEO
			}
		}
		printf("El numero de carton es: %d \n", suma);
		for(int f=0; f<4; f++)    // 6)MOSTRAMOS LA MATRIZ
		{
			for(int c=0; c<5; c++)
			{
				printf(" %d ", carton[f][c]);
			}
			printf("\n");
		}
		vector[k]=suma;  // 7)ARMAMOS EL VECTOR
		k++;
		printf("\n");
	}
}

void ordenarvect(int n)
{
	int aux;
	for(int k=0; k<n-1; k++)
	{
		for(int j=k+1; j<n; j++)
		{
			if(vector[k]<vector[j])
			{
				aux=vector[k];
				vector[k]=vector[j];
				vector[j]=aux;
			}
		}
	}
	// PASAMOS EL VECTOR A UNA LISTA
	
	for(int i=0; i<n; i++)
	{
		p=(struct lista *)malloc(sizeof(struct lista));
		p->orden=vector[i]; 
		p->sig=L;
		L=p;
	}
}

void mostrarlist()
{
	p=L;
	while(p!=NULL)
	{
		printf("-%d-", p->orden);
		p=p->sig;
	}
}
