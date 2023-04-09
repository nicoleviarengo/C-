/*En una f�brica de yerba mate se quiere llevar el control de la producci�n de cada
uno de los lotes de producci�n. Cada lote tiene 50 paquetes.
Se debe cargar en una estructura los siguientes datos de lotes:
- N� de lote,
- fecha de envazado.
- tipo (1: con palo, 2: sin palo, 3: compuesta, 4:saborizada)
- Origen (c: corrientes, m: misiones)
- Codigo de verificaci�n ( 4 digitos) 
Validar el ingreso de tipo, origen y c�digo, de acuerdo a la entrada.
El �ltimo lote tiene 0 (cero) en N� de lote.
Determinar:
- Generar y mostrar un vector ordenado con los n�meros de c�digos de
verificaci�n que sean menores a 5400, de menor a mayor.
- Mostrar la cantidad de lotes correntinos con n� de lotes mayores o iguales a
4200.
- El lote con el mayor n�mero en su c�digo de verificaci�n.*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct yerbamate{
	int num;
	int fecha;
	int tipo;
	char origen;
	int codigo;
}lote[50];

int vector[50];
void pasar();
void ordenar();
void mayores();
void mayornum();
int main()
{
	for(int i=0; i<50; i++)
	{
		do{
			printf("Ingrese el numero de lote: ");
			scanf("%d", &lote[i].num);
		} while(lote[i].num!=0);
		printf("Ingrese la fecha del lote: ");
		scanf("%d", &lote[i].fecha);
		do{
			printf("Ingrese el tipo de lote: ");
			scanf("%d", &lote[i].tipo);
		} while(lote[i].tipo!=1 and lote[i].tipo!=2 and lote[i].tipo!=3 and lote[i].tipo!=4);
		do{
			printf("Ingrese el origen del lote: ");
			scanf("%c", &lote[i].origen);
		} while(lote[i].origen!='c' and lote[i].origen!='m');
		do{
			printf("Ingrese el codigo del lote: ");
			scanf("%d", &lote[i].codigo);
		} while(lote[i].codigo<999 and lote[i].codigo>9999);
	}
	pasar();
	ordenar();
	mayores();
	mayornum();
}

void pasar() 
{
	int i=0;
	for(int k=0; k<50; k++)
	{
		if(lote[k].codigo<5400)
		{
			lote[k].codigo=vector[i];
			i++;
		}
	}
}

void ordenar() 
{
	int aux=0;
	for(int j=0; j<50-1; j++) //50-1 porq esta en una pos anterior a l
	{ 
		for(int l=j+1; l<50; l++) //j+1 porq los compara 
		{
			if(vector[j]<vector[l])
			{
				aux=vector[j];
				vector[j]=vector[l];
				vector[l]=aux;
			}
		}
	}
	
	printf("\nVector ordenado: ");
	for(int m=0; m<0; m++)
	{
		printf(" %d ", vector[m]);
	}
}

void mayores() 
{
	int cont=0;
	for(int i=0; i<50; i++)
	{
		if(lote[i].origen == 'c' and lote[i].num>=4200)
		{
			cont++;
		}
	}
	printf("\nCantidad de lotes correntinos con n� de lotes mayores o iguales a 4200: %d", cont);
}

void mayornum() //El lote con el mayor n�mero en su c�digo de verificaci�n
{
	int loteMayor, mayor=-1;
	for(int i=0; i<50; i++)
	{
		if(lote[i].codigo > mayor)
		{
			mayor=lote[i].codigo;
			loteMayor=lote[i].num;
		}
	}
	printf("\nEl lote con el mayor n�mero en su c�digo de verificaci�n es: %d", loteMayor);
}
