/*Cargar numeros en un vector
Armar otro vector con los numeros primos
Buscar el mayor de los numeros primos
Mostrar */

#include <stdio.h>
#include <conio.h>

int vector[50];
int primos[50];
void buscarprimos(int n);
int main()
{
	int n;
	printf("Ingrese la cantidad de numeros: ");
	scanf("%d", &n);

	buscarprimos(n);
	
}
void buscarprimos(int n)
{
	int s=0, k=0, c=-1,cont;
	
	for(int k=0; k<n; k++)
	{
		printf("Ingrese los numeros del vector: ");
		scanf("%d", &vector[k]);
	}
	
	for(int i=2; i<vector[k]-1; i++)
	{
		if(vector[k]%2==0)
		{
			s=1;
		}
	}
	cont=0;
	if(s==0)
	{
		c++;
		primos[c]=vector[k];
		cont++;
	}
	
	printf("\nCantidad de primos: %d", cont);
	printf("\nPrimos: ");
	for(int j=0; j<cont; j++)
	{
		printf(" %d ", primos[j]);
	}
}
	
