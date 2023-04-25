/*Escribir un programa que lea del teclado un vector de 10 números
enteros, lo invierta y finalmente lo muestre de nuevo.*/

#include <stdio.h>
# include <conio.h>
#define N 10
int vector [N];
void invertir();

int main()
{
	int i;
	
	printf( "\nIntroduzca 10 numeros enteros:\n\t" );
	for(i=0;i<10;i++)
	{
		scanf( "%d%*c", &vector[i] );
		printf( "\t" );
	}
	printf( "\nEl vector original es:\n\t" );
	for(i=0;i<10;i++)
		printf( "v[%d]=%d\n\t", i, vector[i] );
	
	invertir();
	
	printf( "\nEl vector invertido es:\n\t" );
	for(i=0;i<10;i++)
		printf( "v[%d]=%d\n\t", i, vector[i] );
}

void invertir ()
{
	int i,tmp;
	for(i=0;i<N/2;i++)
	{
		tmp=vector[i];
		vector[i]=vector[9-i];
		vector[9-i]=tmp;
	}
	
}
