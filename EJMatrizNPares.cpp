/* generar N pares ponerlos en una matriz cuadrada */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int matriz[100][100];

int main()
{
	srand(time(NULL));
	int num, cont=0, f=0, c=-1, n, t;
	printf("Ingrese el tamaño N de la matriz: ");
	scanf("%d", &n);
	t=n/2; //operacion dividir
	do{
		num=1+rand()%(1000+1-1); //numeros entre el 1000 y el 1
		if(num%2==0) //comprobamos que sean pares
		{
			c++;
			matriz[f][c]=num;
			cont++;
		}
	} while(cont<n); //tienen que ser n numeros (tamaño de la matriz)
	
	printf("MATRIZ CUADRADA PARES: ");
	//dividimos la mitad para las filas, mitad para las columnas (operacion t)
	for(int f=0; f<t; f++)
	{
		for(int c=0; c<t; c++)
		{
			printf(" %d ", matriz[f][c]);
		}
		printf("\n");
	}
}
	
