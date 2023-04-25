/*Cargar en un arreglo:
Numero de provincia, numero de campo, numero de cereal, toneladas de cereal. Cosecados en N establecimients agropecuarios
que una epresa administra sus cosechas.
El numero de provincia puede ser 1- cordoba, 2-santa fe 3-bs as (validar).
Numero de cereal puede ser 1-soja, 2-trigo, 3-girasol (validar)
Mostrar:
1)La cantidad de establecimientos en la pcia de cordoba
2)Promedio de toneladas de cada cereal 
3)Armar y mostrar una lista ordenada de mayor a menor con los totales (tonelas) por provincia
4)Armar y mostrar un vector con las cosechas en toneladas de la pcia de santa fe (cuyo valor en toneladas sea un numero primo).*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int cosecha[50][4];
void carga(int n);
void cordoba(int n);
void promedio(int n);
int vector[3];
void totales_pcia(int n);
void mostrar_lista();
int vector_sf[50];
void santafe(int n);

struct lista{
	int totales;
	struct lista *sig;
}*L, *p;

int main()
{
	int n;
	printf("\nIngrese la cantidad de estabecimientos: ");
	scanf("%d", &n);
	carga(n);
	cordoba(n);
	promedio(n);
	totales_pcia(n);
	mostrar_lista();
	santafe(n);
}

void carga(int n)
{
	int num_pcia, num_campo, num_cereal;
	int toneladas;
	for(int f=0; f<n; f++)
	{
		do{
			printf("\nIngrese el numero de provincia (1-Cordoba, 2-Santa Fe 3-Buenos Aires): ");
			scanf("%d", &num_pcia);
			cosecha[f][0]=num_pcia;
		} while(num_pcia!=1 and num_pcia!=2 and num_pcia!=3);
		
		printf("Ingrese el numero de campo: ");
		scanf("%d", &num_campo);
		cosecha[f][1]=num_campo;
		
		do{
			printf("\nIngrese el numero de cereal (1-Soja, 2-Trigo 3-Girasol): ");
			scanf("%d", &num_cereal);
			cosecha[f][2]=num_cereal;
		} while(num_cereal!=1 and num_cereal!=2 and num_cereal!=3);
		
		printf("Ingrese el numero de toneladas: ");
		scanf("%d", &toneladas);
		cosecha[f][3]=toneladas;
	}
}

void cordoba(int n) // 1)Cantidad de establecimientos en la pcia de Cordoba
{
	int cont=0;
	for(int f=0; f<n; f++)
	{
		if(cosecha[f][0]==1)
		{
			cont++;
		}
	}
	printf("\nCantidad de establecimientos en la provincia de Cordoba: %d", cont);
}

void promedio(int n) // 2)Promedio de toneladas de cada cereal 
{
	int suma1=0, cont1=0, suma2=0, cont2=0, suma3=0, cont3=0;
	float prom1, prom2, prom3;
	for(int f=0; f<n; f++)
	{
		for(int c=0; c<4; c++)
		{
			if(cosecha[f][2]==1)
			{
				cont1++;
				suma1=suma1+cosecha[f][3];
			}
			if(cosecha[f][2]==2)
			{
				cont2++;
				suma2=suma2+cosecha[f][3];
			}
			if(cosecha[f][2]==3)
			{
				cont3++;
				suma3=suma3+cosecha[f][3];
			}
		}
	}
	//Validar que no se divida por 0
	prom1=suma1/cont1;
	prom2=suma2/cont2;
	prom3=suma3/cont3;;
	printf("\nPromedio de toneladas de Soja: %f", prom1);
	printf("\nPromedio de toneladas de Trigo: %f", prom2);
	printf("\nPromedio de toneladas de Girasol: %f", prom3);
}

void totales_pcia(int n) // 3)Armar y mostrar una lista ordenada de mayor a menor con los totales por provincia
{
	int i, aux, suma1=0, suma2=0, suma3=0, min=1000;
	for(int f=0; f<n; f++)
	{
		for(int c=0; c<4; c++)
		{
			if(cosecha[f][0]==1)
			{
				suma1=suma1+cosecha[f][3];
				vector[i]=suma1;
			}
			if(cosecha[f][0]==2)
			{
				suma2=suma2+cosecha[f][3];
				vector[i]=suma2;
			}
			if(cosecha[f][0]==3)
			{
				suma3=suma3+cosecha[f][3];
				vector[i]=suma3;
			}
		}
	}
	
	for(int i=0; i<3-1; i++)
	{
		for(int k=i+1; k<3; k++)
		{
			if(vector[i]>min)
			{
				aux=vector[i];
				vector[i]=vector[k]; //COMPARA CON UNA VARIABLE AUXILIAR !!!! K
				vector[k]=aux;
			}
		}
	}
	
	for(int c=0; c<3; c++) 
	{
		p=(struct lista *)malloc(sizeof(struct lista));
		p->totales=vector[c];
		p=p->sig;
	}
}

void mostrar_lista()
{
	printf("\nTotales (toneladas) por provincia: ");
	while(p!=NULL)
	{
		printf(" %d ", p->totales);
		p=p->sig;
		L=p;
	}
}

void santafe(int n) //4)Armar y mostrar un vector con las cosechas en toneladas de la pcia de santa fe (cuyo valor en toneladas sea un numero primo)
{
	int senial=0, cont=0, j=0;
	for(int f=0; f<n; f++) //recorremos la matriz
	{
		for(int c=0; c<4; c++)
		{
			if(cosecha[f][0]==2 and cosecha[f][3]%2==0) //2-Santa Fe 3=toneladas
			{
				senial=1;
				if(senial==0)
				{
					cont++;
					vector_sf[j]=cosecha[f][3]; //pasamos al vector
					j++;
				}
			} else {
				printf("\nNo hay toneladas cuyo valor es primo");
			}
		}
	}
	
	printf("\nCosechas en toneladas de Santa Fe cuyo valor es primo: ");
	for(int l=0; l<cont; l++)
	{
		printf(" %d ", vector_sf[l]);
	}
}




