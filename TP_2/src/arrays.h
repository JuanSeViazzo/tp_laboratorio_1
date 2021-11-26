/*
 * arrays.h
 *
 *  Created on: 25 sep. 2021
 *      Author: User
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_


void iniciarArray(int vector[], int tam);

void getInt(char mensaje[], int vector[], int tam);

int sumarArray (int vector[], int tam);

int imprimirArrayEnteros (int arrayAImprimir[],int tam);

void mostrarArrayCreciente(int vector[], int tam);

void mostrarArrayDecreciente (int vector[], int tam);

int calcularMaximoArray (int vector[], int tam);

int calcularMinimoArray(int vector[], int tam);

int calcularArrayPar(int vector [], int tam);

int calcularArrayImpar(int vector [], int tam);

float calcularPromedioArrays(int vector[], int tam);

void cargarTextoArray (char mensaje[], char texto[], int tam);

int ordenarArray (int arrayAOrdenar[], int tam, int mayorOMenor);

int PedirEnteroExcluyente(char mensaje[],char mensajeError[], int numeroExcluyente);

int CargarArrayEnterosExcluyente(int lista[], int tam, char mensaje[],char mensajeError[], int numeroExcluyente);

int MostrarArrayEnteros(int lista[], int tam);

int clasificarNumero(int numeroAClasficiar);

int ordenarArrayEnterosExcluyentes(int lista[], int tam);

int mostrarPrimos(int lista[], int tam);

int clasificarPrimos(int numero);

void mostrarEntero(int entero);

#endif /* ARRAYS_H_ */
