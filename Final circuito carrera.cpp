/*Se realiza una carrera en un circuito de carrera de 6,150 km. a reccorer. Existen 3 pruebas de velocidad que deberan realizar cada uno de los 
competidores.
Se necesita ingresar:
-Numero del competidor
-Nombre del competidor
-Tiempo del competidor en cada prueba.
Con estos datos determinar y mostrar:
-Competidor y prueba que realizo el menor tiempo
-Promedio de tiempo de cada competidor
-Porcentaje de competidores que hicieron un tiempo menor a 5 min. en cualquiera de las pruebas
-Para determinar la posicion de largada de cada competidor se desea cargar en forma ordenada, de menor a mayor, los promedios de tiempo de cada 
conductor en una lista. Mostrar la lista ordenada con la ubicacion que corresponderia en la linea de largada.*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct carrera{
	int numero;
	char nombre[50];
	float t1, t2, t3;
}km[50];

struct lista{
	float competidor;
	struct lista *sig;
}*L, *p;

int vec[100];

void carga (int n);
void menor_tiempo(int n);
void promedio_tiempo(int n);
void porcentaje_competidor(int n);
void proceso_lista(int n);
void mostrar_lista(int n);

int main()
{
	int N;
	
	printf("-Ingrese la cantidad de competidores: ");
	scanf("%d", &N);	
	
	carga(N);
	menor_tiempo(N);
	promedio_tiempo(N);
	porcentaje_competidor(N);
	proceso_lista(N);
	mostrar_lista(N);
}
void carga(int n)
{
	printf("\n-Ingrese los datos de los competidores: ");
	for (int i=0;i<n;i++){
		printf("\n");
		printf("Numero del competidor: ");
		scanf("%d", &km[i].numero); 
		fflush(stdin);
		printf("Nombre: ");
		gets(km[i].nombre); 
		fflush(stdin);
		printf("Tiempo del competidor en la primero prueba: ");
		scanf("%f", &km[i].t1);
		printf("Tiempo del competidor en la segunda prueba: ");
		scanf("%f", &km[i].t2);
		printf("Tiempo del competidor en la tercer prueba: ");
		scanf("%f", &km[i].t3);
	}
}

/*Competidor y prueba que realizo el menor tiempo*/

void menor_tiempo(int n)
{
	float min=100.0;
	int p, idmin;
	
	for (int i=0;i<n;i++){
		if (km[i].t1<min){ 
			min=km[i].t1;
			idmin=km[i].numero;
			p=1;
		}
		if (km[i].t2<min){
			min=km[i].t2;
			idmin=km[i].numero;
			p=2;
		}
		if (km[i].t3<min){
			min=km[i].t3;
			idmin=km[i].numero;
			p=3;
		}
	}
	printf("\nEl competidor %d fue quien realizo en la prueba %d el menor tiempo. ", idmin, p);
}

/*Promedio de tiempo de cada competidor*/

void promedio_tiempo(int n)
{
	float suma, prom;
	int k=0; 
	
	for (int i=0;i<n;i++){
		suma=0;
		prom=0;
		
		suma=(km[i].t1+km[i].t2+km[i].t3);
		prom=suma/3;
		vec[k]=prom;
		k++;
		printf("\nPromedios de tiempos de los competidores: %.2f", prom);
	}
}

/*Porcentaje de competidores que hicieron un tiempo menor a 5 min. en cualquiera de las pruebas*/

void porcentaje_competidor(int n)
{
	float contador=0, porcentaje;
	
	for (int i=0;i<n;i++){
		if (km[i].t1<5 || km[i].t2<5 || km[i].t3<5){
			contador++;
		}
	}
	if (contador!=0){
		porcentaje=contador*100/n; 
		printf("\nEl porcentaje de competidores  que hicieron un tiempo menor a 5 min. es: %.2f", porcentaje);
	}
	else{
		printf("\nNingun competidor hizo un tiempo menor a 5 min. ");
	}
}

/*Para determinar la posicion de largada de cada competidor se desea cargar en forma ordenada, de menor a mayor, los promedios de tiempo de cada 
conductor en una lista. Mostrar la lista ordenada con la ubicacion que corresponderia en la linea de largada.*/

void proceso_lista(int n)
{
	float aux; 
	
	for (int k=0;k<(n-1);k++){
		for (int v=k+1;v<n;v++){
			if (vec[k]<vec[v]){
				aux=vec[k];
				vec[k]=vec[v];
				vec[v]=aux;
			}
		}
	}
	
	L=NULL;
	for (int v=0;v<n;v++){
		p=(struct lista *)malloc(sizeof(struct lista));
		p->competidor=vec[v];
		p->sig=L;
		L=p;
	}
}
void mostrar_lista(int n)
{
	int c=0;
	p=L;
	printf("\nPosicion de largada de los competidores: ");
	while(p!=NULL){
		printf("%f\t", c, p->competidor);
		c++;
		p=p->sig;
	}
}


