/*
	FINAL DE ALGORITMO - ESTRUCTURAS

	FECHA:14/09

	Una farmacia vende sus productos de manera virtual.

	Realiza la entrega de cada venta una vez a la semana por medio de un distribuidor de productos.
	
	La ultima venta tiene valor 0 en todos sus datos.

	Por cada venta se registra el numero de cliente, el numero de obra social (1: OSDE, 2: DATUSEN, 3:OITA)
	y el importe de la venta. 

	El empresario necesita saber:

	1) El promedio de ventas de afiliados OSDE

	2) Armar una lista ordenada de mayor a menor con el número de clientes que sea un número primo

	3) 	Otorgar un número aleatorio (distinto no repetido), mayor que el número de cliente
		a cada venta (este numero se usa como codigo de seguridad que acompaña a la mercaderia. 
*/

/*#################LIBRERIAS#################*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

struct farmacia{
	int num_cli;
	int obra_social;
	float importe;
	int num;
}venta[50];

struct lista{
	int primo;
	struct lista *sig;
}*L, *p;

void carga(int n);
void promedio(int n);
int primo(int n);
int vectorp[50];
int ordenar(int cont);
void mostrar_lista(int cont);
void aleatorio(int n);

int main()
{
	int n, primos, orden;
	printf("Ingrese la cantidad de ventas: \n");
	scanf("%d", &n);
	carga(n);
	promedio(n);
	primos=primo(n);
	orden=ordenar(primos);
	mostrar_lista(primos);
	aleatorio(n);
}

void carga(int n) //se cargan los datos en la estructura 
{
	printf("\n-Datos de las ventas: ");
	for(int i=0; i<n; i++)
	{
		do{
			printf("Ingrese el numero de cliente: ");
			scanf("%d", &venta[i].num_cli);
		} while(venta[i].num_cli!=0);
		do{
			printf("Ingrese la obra social (1: OSDE, 2: DATUSEN, 3:OITA): ");
			scanf("%d", &venta[i].obra_social);
		} while(venta[i].obra_social!=0);
		do{
			printf("Ingrese el numero de cliente: ");
			scanf("%f", &venta[i].importe);
		} while(venta[i].importe!=0);
	}
}

//1) Promedio de ventas de afiliados OSDE
void promedio(int n)
{
	float suma, prom, cont=0;
	for(int i=0; i<n; i++)
	{
		cont++;
		suma=0;
		prom=0;
		if(venta[i].obra_social==1) //el 1 es OSDE
		{
			suma=suma+venta[i].obra_social;
		}
		prom=suma/cont;
	}
	printf("\nPromedio afiliados con OSDE: %f", prom);
}

//2) Armar una lista ordenada de mayor a menor con el nmero de clientes que sea un número primo
int primo(int n) 
{
	int Bandera=0, contadorDePrimos=2;
	
	if(n=1){vectorp[0] = venta[0].num_cli;}
	else if(n=2){vectorp[1] = venta[1].num_cli;}
	else if(n=3){vectorp[2] = venta[3].num_cli;}

	else if(n>3){
		for(int i=2; i<n; i++)
		{
			if(venta[i].num_cli % n==0)
			{
				Bandera=1;
			}
			if(Bandera==0)
			{
				contadorDePrimos++;

				vectorp[contadorDePrimos] = venta[i].num_cli; //pasamos los primos a un vector 
			}
		}
	}
	else{
		printf("Verificar número de clientes ingresado");
	}

	return contadorDePrimos;
}

int ordenar(int cont)
{
	int aux;
	for(int i=0; i<cont-1; i++)
	{
		for(int k=i+1; k<cont; k++)
		{
			if(vectorp[i]>vectorp[k])
			{
				aux=vectorp[i];
				vectorp[i]=vectorp[k];
				vectorp[k]=aux;
			}
		}
	}
	
	L=NULL;
	for(int l=0; l<cont; l++)
	{
		p=(struct lista *)malloc(sizeof(struct lista));
		p->primo=vectorp[l];
		p->sig=L;
		L=p;
	}
	
	return 0;
}

void mostrar_lista()
{
	int c=0;
	p=L;
	printf("\nNumeros de clientes primos: ");
	while(p!=NULL)
	{
		printf(" %d ", c, p->primo);
		c++;
		p=p->sig;
	}
}

/*Otorgar un numero aleatorio (distinto no repetido), mayor que el numero de cliente
a cada venta (este numero se usa como codigo de seguridad que acompa�a a la mercaderia. */

void aleatorio(int n)
{
	int num, ban=0;
	srand(time(NULL));
	for(int i=0; i<n; i++)
	{
		num=1+rand()%(venta[i].num_cli+1-1);
		if(num=venta[i].num_cli)
		{
			ban=1;
		}
		if(ban==0)
		{
			num=venta[i].num;
		}
	}
	for(int k=0; k<n; k++)
	{
		printf(" %d ", venta[k].num);
	}
}
