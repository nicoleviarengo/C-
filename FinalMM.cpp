/* Se necesita realizar un proceso para emitir numero favorecidos para un sorteo de entradas para ver la pelicula MIONS.

Para ello se debe cargar en una matriz cuadrada de N elementos numeros primos no repetidos de una y dos cifras.
Validar que N no supere 25.

Armar una lista ordenada de menor a mayor con los numeros comprendidos entre p y q (dos numeros), 
valores que se lee al comienzo del proceso.

Mostrar la matriz generada y la lista ordenada; */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//declaracion de la lista
struct lista{
    int numbers;
    struct lista *sig;
}*L, *puntero;

int matriz[5][5];
int vector[25];
int vectorValoresEntrePyQ[25];
int carga(int n);
void mostrarmatriz(int x);
void proceso(int x);
void mostrarlista(int x);
int main()
{
    int n, c;
    printf("Ingrese la cantidad de numeros N de la matriz: ");
    scanf("%d", &n);
    if(n>25)
    {
        printf("Tiene que se menor o igual a 25, vuelva a ingresar \n");
        printf("\nNumero: ");
        scanf("%d", &n);
    }else{
        c=carga(n);
        proceso(c);
        mostrarmatriz(c);
        mostrarlista(c);
    }
}

int carga(int n)
{
    int num, ban=0, x, pot, v=-1;
    while(v<n)
    {
        printf("Ingrese un numero: \n");
        scanf("%d", &num);

        if(num>1 && num<=99){
        
            ban=0; //proceso primo
            for(int i=0; i<num-1; i++)
            {
                if(num%2==0 && num==vector[v]) //comprobamos queno este repetido tmb ?
                {
                    ban=1;
                }
            }
            if(ban==0)
            {
                v++;
                printf("%d", v);
                vector[v]=num; //armamos el vector con los numeros primos
            }
        }
        else
        {
            printf("Debe ser un numero de 1 o 2 digitos\n");
        }
        

    } //la cantidad tiene que ser <= a n (proceso carga)

//proceso matriz cuadrada
    do{
        x++;
        pot=pow(x, 2);
    }while(pot<=v);

//pasamos el vector a la matriz
    v=-1;
    for(int f=0; f<x; f++)
    {
        for(int c=0; c<x; c++)
        {
            v++;
            matriz[f][c]=vector[v];
        }
    }
    return x;
}

void mostrarmatriz(int x)
{
    printf("MATRIZ: \n");
    for(int f=0; f<x; f++)
    {
		for(int c=0; c<x; c++)
        {
			printf(" %d ", matriz[f][c]);
		}
		printf(" \n");
	}
 
}

/*Armar una lista ordenada de menor a mayor con los numeros comprendidos entre p y q (dos numeros), 
valores que se lee al comienzo del proceso.*/
void proceso(int v)
{
    int p, q, aux=0, aux2;
    printf("INGRESO 2 NUMEROS \n");
    printf("Ingrese p: \n");
    scanf("%d", &p);
    printf("Ingrese q: \n");
    scanf("%d", &q);


    for(int i=0; i<v; i++)
    {
		if (vector[i]>=p && vector[i]<=q)
        {
            vectorValoresEntrePyQ[aux]=vector[i]; //pasamos los valores
            aux++;
        }
	}
    
    //ordenamos de menor a mayor
    for(int c=0; c<v-1; c++)
    {
        for(int h=c+1; h<v; h++)
        {
            if(vectorValoresEntrePyQ[c]<vectorValoresEntrePyQ[h])
            {
                aux2=vectorValoresEntrePyQ[c];
                vectorValoresEntrePyQ[c]=vectorValoresEntrePyQ[h];
                vectorValoresEntrePyQ[h]=aux2;
            }
        }
    }

    //pasamos a la lista
    L=NULL;
    for(int j=0; j<v; j++)
    {
        puntero=(struct lista *)malloc(sizeof(struct lista));
        puntero->numbers=vectorValoresEntrePyQ[j];
        puntero=puntero->sig;
        L=puntero;
    }
}

//mostramos la lista
void mostrarlista(int x)
{
    puntero=L;
    printf("LISTA ORDENADA: \n");
    while(puntero!=NULL)
    {
        printf(" %d ", puntero->numbers);
        puntero=puntero->sig;
    }
}
