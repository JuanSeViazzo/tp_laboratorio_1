/*
 * arrays.c
 *
 *  Created on: 25 sep. 2021
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"


void iniciarArray(int vector[], int tam)
{
       int i;

    for(i=0; i<tam; i++) {
        vector[i] = 0;
        printf("%d\n", vector[i]);
    }
}

int sumarArray (int vector[], int tam)
{
    int suma=0;
    int i;

    for(i=0; i<tam; i++) {

        suma+=vector[i];
    }

    return suma;
}

int imprimirArrayEnteros (int arrayAImprimir[],int tam)
{
	int retorno = -1;
	if (arrayAImprimir != NULL && tam >=0)
	{

		for (int i = 0; i < tam; i++)
		{
			printf(" EL ELEMENTO %d, TIENE SU POSICION %d\n",arrayAImprimir[i],i);
		}

		retorno = 0;


	}
	return retorno;
}

void mostrarArrayCreciente(int vector[], int tam)
{
    int i;

    for(i=0; i<tam; i++) {

        printf("%d\n", vector[i]);
    }
}

void mostrarArrayDecreciente (int vector[], int tam)
{
    int i;

    for(i=tam-1; i>-1; i--) {

        printf("%d\n", vector[i]);
    }

}

int calcularMaximoArray (int vector[], int tam)
{
    int i;
    int maximo;

    for(i=0; i<tam; i++) {

        if(i==0 || maximo<vector[i]) {
            maximo=vector[i];
        }
    }

    return maximo;
}

int calcularMinimoArray(int vector[], int tam)
{
    int i;
    int minimo;

    for(i=0; i<tam; i++) {

        if(i==0 || minimo>vector[i]) {
            minimo = vector[i];
        }
    }
    return minimo;
}

int calcularArrayPar(int vector [], int tam)
{
    int i;
    int pares=0;

    for(i=0; i<tam; i++) {
        int resultado;
        resultado=vector[i]%2;

        if(resultado==0){
            pares++;
        }
    }

    return pares;
}

int calcularArrayImpar(int vector [], int tam)
{
    int i;
    int impares=0;

    for(i=0; i<tam; i++) {
        int resultado;
        resultado=vector[i]%2;

        if(resultado!=0){
            impares++;
        }
    }

    return impares;
}

float calcularPromedioArrays(int vector[], int tam)
{
    float promedio;
    int acumulador;

    acumulador = sumarArray(vector, tam);

    promedio = (float) acumulador / tam;

    return promedio;
}

void cargarTextoArray (char mensaje[], char texto[], int tam)
{
    printf("%s", mensaje);
    fflush(stdin);
    fgets(texto, tam, stdin);
    texto[strlen(texto)-1]='\0';
}

int ordenarArray (int arrayAOrdenar[], int len, int mayorOMenor)
{
	int retorno =-1;
	int flagSwap;
	int aux;
	int contadorDeVueltas=0;
	int limite = len;

	if(arrayAOrdenar!=NULL && len>=0)
	{

		do
		{
			flagSwap=0; //esto es pensar que esta ordenado
			limite=limite-1;

		if(mayorOMenor==1) // mayores a menor
		{
		for(int i = 0; i < limite; i++)
		 {

			if(arrayAOrdenar[i]<arrayAOrdenar[i+1])
			{
				flagSwap=1;//CONSIDERAMOS QUE EL ARRAY ESTA DESORDENADO
				//ESTO ES EL SWAP
				aux = arrayAOrdenar[i];
				arrayAOrdenar[i]=arrayAOrdenar[i+1];
				arrayAOrdenar[i+1]=aux;
			}
		 }
		}else
		{
			for(int i = 0; i < limite; i++)//menor a mayor.
			 {
				if(arrayAOrdenar[i]>arrayAOrdenar[i+1])
				{
					flagSwap=1;//CONSIDERAMOS QUE EL ARRAY ESTA DESORDENADO
					//ESTO ES EL SWAP
					aux = arrayAOrdenar[i];
					arrayAOrdenar[i]=arrayAOrdenar[i+1];
					arrayAOrdenar[i+1]=aux;
				}
			 }
		}
		contadorDeVueltas++;
		}while(flagSwap==1);

		retorno = contadorDeVueltas;
	}


	return retorno;

}

int PedirEnteroExcluyente(char mensaje[],char mensajeError[], int numeroExcluyente)
{
    int numeroIngresado;

    printf("%s\n",mensaje);
    scanf("%d",&numeroIngresado);

    while(numeroIngresado ==numeroExcluyente)
    {
        printf("%s\n",mensajeError);
        scanf("%d",&numeroIngresado);
    }
    return numeroIngresado;
}

int CargarArrayEnterosExcluyente(int lista[], int tam, char mensaje[],char mensajeError[], int numeroExcluyente)
{
    int i;
    int banderaTodoBien;

    banderaTodoBien = 0;

    if(lista != NULL && tam>0)
    {
        banderaTodoBien = 1;
        for (i=0; i<tam ;i++)
        {
            lista[i] = PedirEnteroExcluyente(mensaje, mensajeError, numeroExcluyente);
        }
    }
    return banderaTodoBien;

}

int MostrarArrayEnteros(int lista[], int tam)
{

    int banderaTodoBien;

    banderaTodoBien = 0;

    if(lista != NULL && tam>0) {
        banderaTodoBien = 1;

        for (int i = 0; i < tam; i++) {
            printf("Posición [%d]: %d\n", i, lista[i]);
        }
    }

    return banderaTodoBien;
}

int clasificarNumero(int numeroAClasficiar)
{

    int retorno= 0;

    if (numeroAClasficiar>0)
    {
        retorno = 1;
    }else
    {
        if(numeroAClasficiar<0)
        {
            retorno = -1;
        }
    }

    return retorno;

}

int ordenarArrayEnterosExcluyentes(int lista[], int tam)
{
    int i;
    int j;
    int buffer;//int auxiliar;
    int banderaTodoBien;

    banderaTodoBien = 0;



    if(lista != NULL && tam>0)
    {
        for(i=0;i<tam-1;i++)  // toma el elemento y compara con el if el resto de los elementos
        {
            for(j=i+1;j<tam;j++) // el resto de los elementos
            {
                if(lista[i]>lista[j]) // > de menor a mayor
                {
                    buffer=lista[i];
                    lista[i]=lista[j];
                    lista[j]=buffer;
                }// else if(lista[i]<lista[j] && criterio==0){ //< de mayor a menor 2 4 3 -1




            }
        }
        banderaTodoBien = 1;
    }

    return banderaTodoBien;

}

int mostrarPrimos(int lista[], int tam)
{
    int banderaTodoBien = 0;

    if(lista != NULL && tam>0) {
        banderaTodoBien = 1;
        printf("Lista de numeros Primos \n");
        for (int i = 0; i < tam; i++) {

            if(clasificarNumero(lista[i])==1){

                if(clasificarPrimos(lista[i])!=0){
                    mostrarEntero(lista[i]);
                }
            }
        }
    }

    return banderaTodoBien;
}

int clasificarPrimos(int numero)
{
    int noPrimo=1;
    int contadordiv=0;

    for (int i = numero; i>0 ; i--) {

        if(numero%i==0){
            contadordiv++;
        }
        if(contadordiv>2){
            noPrimo=0;
            break;
        }
    }

    return noPrimo;

}

void mostrarEntero(int entero)
{
    printf("%d \n", entero);

}
