/* Ingresar N numeros. Los pares ponerlos en una matriz cuadrada */ 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

int numeros[100];
int matriz[10][10];

int main(){
	
	int n, num, v=-1, x=0, pot;
	
	printf("\nIngrese la canidad N de numeros: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		
		printf("\nIngrese el numero: ");
		scanf("%d", &num);
		
		if(num%2==0){
			
			v++;
			numeros[v]=num;
			
		}
	}
	
	// encuentro dimension de matriz
	
	do{
		x=x+1;
		pot=pow(x,2);
	} while(pot<v);
	
	
	// paso los numeros guardados en el vector a la matriz
	
	v=-1;
	for(int f=0; f<x; f++){
		for(int c=0; c<x; c++){
			
			v++;
			matriz[f][c]=numeros[v];
			
		}
	}
	
	// muestro la matriz
	
	for(int f=0; f<x; f++){
		for(int c=0; c<x; c++){
			
			printf(" %d ", matriz[f][c]);
			
		}
		
		printf(" \n");
	}
	
}
