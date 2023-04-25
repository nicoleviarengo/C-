/* generar N pares ponerlos en una matriz cuadrada */
/*Matriz cuadrada -> con pow() */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int matriz[10][10];
int numeros[100];
void pasarymostrar(int v, int x);
int main()
{
	srand(time(NULL));
	int num, v=-1, n, x=0, pot;

	printf("Ingrese la cantidad de N numeros de la matriz: "); 
	scanf("%d", &n);

	for(int i=0; i<n; i++)
	{
		num=1+rand()%(100+1-1); //numeros entre el 1000 y el 1
		if(num%2==0) //comprobamos que sean pares
		{
			v++;
			numeros[v]=num; //pasamos los numeros generados a un vector
		}
	}
	//encontrar la dimension de la matriz con la potencia
	do{
		x++; //va incrementando porque va probando
		pot=pow(x, 2);
	}while(pot<=v); //tiene que ser de la dimension v

	pasarymostrar(v, x);
}

void pasarymostrar(int v, int x)
{
	//pasamos del vector a la matriz
	v=-1;
	for(int f=0; f<x; f++)
	{
		for(int c=0; c<x; c++)
		{
			v++;
			matriz[f][c]=numeros[v];
		}
	}

	//la mostramos
	printf("MATRIZ CUADRADA PARES: ");
	for(int f=0; f<x; f++)
	{
		for(int c=0; c<x; c++)
		{
			printf(" %d ", matriz[f][c]);
		}
		printf("\n");
	}
}