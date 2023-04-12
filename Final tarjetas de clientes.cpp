/*
Se necesita generar una tarjeta de coordenadas de 32 números aleatorios para cada uno de los N clientes de un banco
 
la tarjeta es usada por los clientes para realizar transacciones desde homebancking.

Cada tarjeta debe tener 32 numeros aleatorios (de dos y tres digitos).

Dispuestos en filas y columnas:
	-mostrar cada tarjeta
	-armar y mostrar una lista ordenada de mayor a menor con los numeros generados en la fila F, columna C. 
	(F y C se leen como datos al comienzo del proceso)
	-mostar la cantidad de numeros repetidos por columnas
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define FILAS 4
#define COLUMNAS 8

int TarjetasDeCredito[100][FILAS][COLUMNAS];
int vector[32]; //como sabemos la cantidad de elementos del vector??
void carga(int numeroDeClientes);
void mostrar(int numeroDeClientes);
void Ordenar(int numeroDeClientes);
void mostrarlista();
void repetidos(int numeroDeClientes);
int vectrep[32];

struct lista{
	int num;
	struct lista *sig;
}*L, *p;

int main()
{
	int numeroDeClientes;
	printf(	"Buenos Dias! Bienvenidos a Viarengobank.SA!!! \n"
			"Nuestros clientes son exclusivos y es por ello que nuestro cupo\n"
			"a registrar clientes por hoy es de 100 personas maximo. \n"
			"\n Por favor, Ingrese la cantidad de clientes a registrar:");
	scanf("%d", &numeroDeClientes);

	carga(numeroDeClientes);

	while(1){
		int Opcion=0;

		printf(	"1_ Mostrar Clientes \n"
				"2_ Ordenar Clientes segun X Fila y X Columna\n"
				"3_ Mostrar lista. \n"
				"4_ Mostrar Numeros repetidos por columna \n");
		scanf("%d", &Opcion);

		switch(Opcion){
		case 1:
			mostrar(numeroDeClientes);
			break;
		case 2:
			Ordenar(numeroDeClientes);
			break;
		case 3:
			mostrarlista();
			break;
		case 4:
			repetidos(numeroDeClientes);
			break;
		}
	}
}

void carga(int numeroDeClientes)
{
	int num;
	// Semilla de la función rand() basada en el reloj del sistema
	srand(time(NULL));

	for(int i=0; i<numeroDeClientes; i++) //cada cliente es una fila nueva
	{
		for(int f=0; f<FILAS; f++)
		{
            for(int c=0; c<COLUMNAS; c++)
            {
                //genero un numero aleatorio del 0 al 990 y le sumo 10
			    num = 10 + rand() % 989;
			    //printf("%d, ", num); //debug para ver generacion de numeros aleatorios
			   TarjetasDeCredito[i][f][c] = num;
            }
		}
        //printf("\n"); //debug para ver generacion de numeros aleatorios
	}
}

void mostrar(int numeroDeClientes)
{
	printf("Tarjetas: ");
	for(int i=0; i<numeroDeClientes; i++)
	{
        printf("\n \n Cliente: %d \n", i);
		for(int f=0; f<4; f++)
		{
				printf(" %d, %d, %d, %d, %d, %d, %d, %d"	, TarjetasDeCredito[i][f][0]
															, TarjetasDeCredito[i][f][1]
															, TarjetasDeCredito[i][f][2]
															, TarjetasDeCredito[i][f][3]
															, TarjetasDeCredito[i][f][4]
															, TarjetasDeCredito[i][f][5]
															, TarjetasDeCredito[i][f][6]
															, TarjetasDeCredito[i][f][7]);
		}
	}
}

/*	Armar y mostrar una lista ordenada de mayor a menor con los números generados en la fila F, 
	columna C. (F y C se leen como datos al comienzo del proceso)*/
void Ordenar(int numeroDeClientes) 
{
	int fi, co, pos=0;

	//ingreso Fila y Columna a ordenar
	printf("\n Ingrese F: ");
	scanf("%d", &fi);
	printf("\n Ingrese C: ");
	scanf("%d", &co);

	//Guardo los valores en un vector
	for(int i=0; i<numeroDeClientes; i++)
	{
		vector[pos]=TarjetasDeCredito[i][fi][co];
		pos++;
	}

	//Ordeno los valores del vector de mayor a menor
	int aux;

	for(int l=0; l<numeroDeClientes-1; l++)//uso l porque pinto //because painted
	{
		for(int m=l+1; m<numeroDeClientes; m++)
		{
			if(vector[l]>vector[m])
			{
				aux=vector[l];
				vector[l]=vector[m];
				vector[m]=aux;
			}
		}
	}
	
	for(int n=0; n<numeroDeClientes; n++)
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

//Mostar la cantidad de numeros repetidos por columnas
void repetidos(int numeroDeClientes) 
{
	for(int i=0; i<numeroDeClientes; i++)
	{
		int cont=0; //iniciamos el contador
		for(int Col=0; Col<COLUMNAS; Col++) //recorremos por columnas
		{
			//printf("Columnas: %d \n", c+1); //las mostramos
			for(int FilaAux1=0; FilaAux1<FILAS; FilaAux1++)
			{
				for(int FilaAux2=0; FilaAux2<FILAS; FilaAux2++)
				{
					if(FilaAux1!=FilaAux2){
						
						if(TarjetasDeCredito[i][FilaAux1][Col]==TarjetasDeCredito[i][FilaAux2][Col]) //comparamos
						{
							cont++; //contamos
						}
					}
					
				}
			}
			printf(	"\n 	Cantidad de numeros repetidos"
					"\n 	Cliente Num %d:" 
					"\n		Col num: %d"
					"\n		Num repetidos: %d", i, Col, cont);
		}
		printf("\n");
	}
}


