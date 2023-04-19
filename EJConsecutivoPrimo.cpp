/* Ingresar N numeros, para cada uno mostrar su consecutivo y su primer consecutivo primo*/ 

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void consecutivo(int num);
void consecutivo_primo(int num);

int main()
{
	
	int num, n;
	printf("\n\nIngrese la cantidad N de numeros: ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("\n\tIngrese el numero: ");
		scanf("%d", &num);
		
		consecutivo(num);
		consecutivo_primo(num);
	}
	
}
	
void consecutivo(int num)
{
	int c;
	c=num+1;
	printf("\n\nEl consecutivo del numero ingresado es: %d", c);
	
}
	
void consecutivo_primo(int num)
{
	int pp, ban=0, s=0;
	pp=num+1; //numero consecutivo 
	// hay que verificar que ese consecutivo sea primo
	do{
		ban=0;
		if(pp==1 or pp==2 or pp==3)
		{
			ban=1;
		}else{
			//algoritmo numeros primos
			s=0; 
			for(int i=2; i<pp-1; i++)
			{
				if(pp%i==0)
				{
					s=1;
				}
			}
			if(s==0)
			{
				ban=1;
			}else{
				pp=pp+1; //es primo, sacamos el consecutivo del num primo
			}
		}
	} while(ban==0); //??

	printf("\n\nEl primer consecutivo primo es: %d", pp);
}

