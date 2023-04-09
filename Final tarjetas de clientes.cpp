/*Se necesita generar una tarjeta de coordenadas de 32 n�meros aleatorios para cada uno de los N clientes de un banco, 
la tarjeta es usada por los clientes para realizar transacciones desde homebancking.
Cada tarjeta tiene que tener 32 n�meros aleatorios (de dos y tres d�gitos) dispuestos en filas y columnas.
- mostrar cada tarjeta
-armar y mostrar una lista ordenada de mayor a menor con los n�meros generados en la fila F, columna C. 
(F y C se leen como datos al comienzo del proceso)
-mostar la cantidad de n�meros repetidos por columnas*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int matrix[4][8];
int vector[32]; //como sabemos la cantidad de elementos del vector??
void carga(int n);
void mostrar(int n);
void proceso(int n);
void ordenar();
void mostrarlista();
void repetidos(int n);
int vectrep[32];

struct lista{
	int num;
	struct lista *sig;
}*L, *p;

int main()
{
	int n;
	printf("Ingrese la cantidad de clientes: \n");
	scanf("%d", &n);
	carga(n);
	mostrar(n);
	proceso(n);
	ordenar();
	mostrarlista();
	repetidos(n);
}

void carga(int n)
{
	int num;
	srand(time(NULL));
	for(int i=0; i<n; i++)
	{
		for(int f=0; f<4; f++)
		{
			for(int c=0; c<8; c++)
			{
				num=10+rand()%(999+10-10);
				num=matrix[f][c];
			}
		}
	}
}

void mostrar(int n)
{
	printf("Tarjetas: ");
	for(int i=0; i<n; i++)
	{
		for(int f=0; f<4; f++)
		{
			for(int c=0; c<8; c++)
			{
				printf("%d", matrix[f][c]);
			}
		}
	}
}

void proceso(int n) //-armar y mostrar una lista ordenada de mayor a menor con los n�meros generados en la fila F, columna C. 
	//(F y C se leen como datos al comienzo del proceso)
{
	int fi, co, pos=0, l;
	printf("Ingrese F: ");
	scanf("%d", &fi);
	printf("Ingrese C: ");
	scanf("%d", &co);
	for(int i=0; i<n; i++)
	{
		for(int f=0; f<4; f++)
		{
			for(int c=0; c<8; c++)
			{
				pos++;
				if(pos==fi and pos==co) //??
				{
					vector[l]=matrix[fi][co]; //esta bien???
					l++;
				}
			}
		}
	}
}

void ordenar()
{
	int aux;
	for(int l=0; l<32-1; l++)
	{
		for(int m=l+1; m<32; m++)
		{
			if(vector[l]<vector[m])
			{
				aux=vector[l];
				vector[l]=vector[m];
				vector[m]=aux;
			}
		}
	}
	
	for(int n=0; n<32; n++)
	{
		p=(struct lista *)malloc(sizeof(struct lista));
		p->num=vector[n];
		p->sig=L;
		L=p;
	}
}

void mostrarlista()
{
	printf("LISTA: ");
	p=L;
	while(p!=NULL)
	{
		printf(" %d ", p->num);
		p=p->sig;
	}
}

void repetidos(int n) //Mostar la cantidad de n�meros repetidos por columnas
{
	int cont=0;
	for(int j=0; j<n; j++)
	{
		for(int c=0; c<8; c++) //recorremos por columnas
		{
			printf("Columnas: %d \n", c+1); //las mostramos
			for(int i=0; i<n; i++)
			{
				cont=0; //iniciamos el contador
				for(int k=0; k<n; k++)
				{
					if(matrix[i][c]==matrix[j][c]) //comparamos
					{
						cont++; //contamos
					}
				}
			}
		}
	}
	printf("Cantidad de numeros repetidos: %d", cont);
}
