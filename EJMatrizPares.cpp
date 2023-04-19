/* generar 100 pares ponerlos en una matriz */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int matriz[5][5];
void mostrar_matriz();
int main(){
	
	srand(time(NULL));
	int num, cont=0, f=0, c=-1;
	do{
		num=1+rand()%(100+1-1); //numeros entre el 100 y el 1
		if(num%2==0)
		{
			c++; //se incrementan las columnas
			matriz[f][c]=num;
			cont++;
		}	
	} while(cont<25); //que sean solo 25 numeros

	mostrar_matriz();
}
	
void mostrar_matriz()
{
	for(int f=0; f<5; f++)
	{
		for(int c=0; c<5; c++)
		{
			printf(" %d ", matriz[f][c]);
		}
		printf("\n");
	}
}
