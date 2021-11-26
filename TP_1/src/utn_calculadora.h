/*
 * utn_calculadora.h
 *
 *  Created on: 21 sep. 2021
 *      Author: User
 */

#ifndef UTN_CALCULADORA_H_
#define UTN_CALCULADORA_H_



int menu(float numeroUno, float numeroDos);

float obtenerFloatDelUsuario(char mensaje[], char mensajeError[]);

float sumar(float numUno, float numDos);

float restar(float numUno, float numDos);

float multiplicar(float numUno, float numDos);

float dividir(float numUno, float numDos, float* pResultado);

int factorial(float numero, int* pResultado);





#endif /* UTN_CALCULADORA_H_ */
