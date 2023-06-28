/*1.- Los organizadores del Congreso Nacional de Educacion Tecnologica que se realizaron en
junio, cuentan con la siguiente informacion de los inscriptos al congreso: 
Nombre, Edad, Categoria, numero de entrada. Donde: Categoria= 01: Profesional, 02: Estudiante, 03: Docente.

Los organizadores desean obtener la siguiente informacion:
* Lista ordenada de numeros de entrada de estudiantes mayores a 22 años. (1)
* Grafico de * que muestre la cantidad de entradas cargadas de las categorias de las entradas.
* Si la inscripcion de los Profesionales cuesta $2500, Docentes $ 1500 y los estudiantes $800,
calcular lo recaudado hasta el momento.

No se sabe cuantos inscriptos se deberan cargar, preguntar al usuario cuando es el fin de la carga. 
Usar modularidad.
Desarrolle en lenguaje C. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Estructura informacion del congreso
struct CNET{
	char nombre[20];
	int edad;
	int categoria;
	int numEntrada;
}congreso[100];

//Declaracion lista (1)
struct lista {
	int numMayores;
	struct lista *sig;
}*L, *p;

void carga();
int vectorOrden[500];
void ordenar();
void grafico();

int main()
{
	printf("Bienvenido/a al Congreso Nacional de Educacion Tecnologica\n");
	carga();
	ordenar();
	grafico();
}

void carga() //Ingreso de la informacion
{
	int res, i;
	
	do{ 
		i++; //se empieza a incrementar cada vez que se ingresa un participante
		fflush(stdin);
		printf("NOMBRE: \n");
		gets(congreso[i].nombre);
		fflush(stdin);
			
		printf("EDAD: \n");
		scanf("%d", &congreso[i].edad);
			
		do{
			printf("CATEGORIA 01: Profesional, 02: Estudiante, 03: Docente: \n");
			scanf("%d", &congreso[i].categoria);
		}while(congreso[i].categoria!=01 && congreso[i].categoria!=02 && congreso[i].categoria!=03);
			
		printf("NRO DE ENTRADA: \n");
		scanf("%d", &congreso[i].numEntrada);
			
		printf("Desea seguir cargando? Si(1)/No(0): \n"); //se pregunta al usuario cuando es el final de la carga
		scanf("%d", &res);
			
	}while(res!=0); //se cargan participantes mientras no se ingrese el 0 
	
}

//Lista ordenada de numeros de entrada de estudiantes mayores a 22 años
void ordenar()
{
	//buscamos los numeros de entrada en base a la condicion
	int f=-1, aux, cont1=0;
	for(int i=0; i<500; i++) //bien recorrido?
	{
		if(congreso[i].edad>22 && congreso[i].categoria==02)
		{
			f++;
			vectorOrden[f]=congreso[i].numEntrada; //los pasamos al vector
			cont1++; //vamos contando
		}
	}
	
	//Ordenamos el vector
	for(int j=0; j<cont1-1; j++)
	{
		for(int k=j+1; k<cont1; k++)
		{
			if(vectorOrden[j]<vectorOrden[k])
			{
				aux=vectorOrden[j];
				vectorOrden[j]=vectorOrden[k];
				vectorOrden[k]=aux;
			}
		}
	}
	
	//Pasamos a la lista
	L=NULL;
	for(int c=0; c<cont1; c++)
	{
		p=(struct lista *)malloc(sizeof(struct lista));
		p->numMayores=vectorOrden[c];
		p->sig=L;
		L=p;
	}
	
	printf("Lista ordenada: \n");
	p=L; 
	while(p!=NULL)
	{
		printf(" %d \n", p->numMayores); //error, muestra solo el primer numero
		p=p->sig;
	}
	
}

//Grafico de * que muestre la cantidad de entradas cargadas de las categorias de las entradas.
//Categoria= 01: Profesional, 02: Estudiante, 03: Docente
void grafico()
{
	int cont01=0, cont02=0, cont03=0, total;
	
	printf("Entradas (*) segun categoria\n");
	
	printf("PROFESIONALES: ");
	for(int i=0; i<500; i++)
	{
		if(congreso[i].categoria==01)
		{
			cont01++;
			printf("*");
			printf("\n");
		}
	}
	
	printf("ESTUDIANTES: ");
	for(int i=0; i<500; i++)
	{
		if(congreso[i].categoria==02)
		{
			cont02++;
			printf("*");
			printf("\n");
		}
	}
	
	printf("DOCENTES: ");
	for(int i=0; i<500; i++)
	{
		if(congreso[i].categoria==03)
		{
			cont03++;
			printf("*");
			printf("\n");
		}
	}
	
	/*Si la inscripcion de los Profesionales cuesta $2500, Docentes $ 1500 y los estudiantes $800,
	calcular lo recaudado hasta el momento.*/
	
	total=(cont01*2500)+(cont02*1500)+(cont03*800);
	printf("\nTotal recaudado: %d", total);
}






