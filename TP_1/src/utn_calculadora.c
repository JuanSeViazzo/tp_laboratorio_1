/*
 * utn_calculadora.c
 *
 *  Created on: 21 sep. 2021
 *      Author: User
 */

#include "utn_calculadora.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief menu, donde el usuario elije de las opciones 1 a 5.
 * @param numeroUno primer operando ingresado
 * @param numeroDos segundo operando ingresado
 * @return opcion del menu
 */

int menu(float numeroUno, float numeroDos)
{

	int numeroMenu;
	int salidaScanf;



	printf("\nPor favor ingrese un numero para las siguientes opciones: \n");
	printf("1. Ingresar 1er operando (A=%.2f)",numeroUno);
	printf("\n2. Ingresar 2do operando (B=%.2f). \n",numeroDos);
	printf("3. Calcular todas las operaciones.\n");
	printf("4. Informar resultados.\n");
	printf("5. Salir.\n");

	printf("Opcion?: ");
	fflush(stdin);
	salidaScanf=scanf("%d", &numeroMenu);

	while (salidaScanf==0 || numeroMenu<1 || numeroMenu>5)
	{
		printf("Por favor ingrese una opcion entre 1 y 5: ");
		fflush(stdin);
		salidaScanf=scanf("%d", &numeroMenu);

	}


	return numeroMenu;

}

/**
 * @brief obtenerFloatDelUsuario le pide al usuario un numero entero o decimal y positivo o negativo pero no del tipo char.
 * @param mensaje le indica al usuario que ingrese un numero;
 * @return buffer el numero ingresado por el usuario restringido para que no sea tipo char
 */


float obtenerFloatDelUsuario(char mensaje[], char mensajeError[])

{
   float buffer;
   int salidaScanf;

   printf("%s",mensaje);
   fflush(stdin);
   salidaScanf=scanf("%f", &buffer);

   	while (salidaScanf==0)
   	{
   		printf("Por favor ingrese un numero valido: ");
   		fflush(stdin);
   		salidaScanf=scanf("%f", &buffer);

   	}

   return buffer;

}

/**
 * @brief sumar ejecuta la suma del operando A y operando B.
 * @param numUno operando A
 * @param numDos operando B
 * @return suma el resultado de la suma
 */

float sumar(float numUno, float numDos)
{

	float suma;

	suma = numUno + numDos;

	return suma;

}

/**
 *@brief restar ejecuta la resta del operando A menos operando B
 * @param numUno numUno, es el ingreso de A (primer operando)
 * @param numDos
 * @return resta, el resultado de la operacion
 */

float restar(float numUno, float numDos)

{

	float resta;

	resta = numUno - numDos;

	return resta;

}

/**
 * @brief multiplicar, realizo operando A x por operando B
 * @param numUno, es el ingreso de A (primer operando)
 * @param numDos es el ingreso de B (segundo operando)
 * @return multiplicacion el resultado de la operacion
 */

float multiplicar(float numUno, float numDos)

{

	float multiplicacion;

	multiplicacion = numUno*numDos;

	return multiplicacion;
}


/**
 * @brief realiza la division del primer numero (numerador) dividido por el 2do numero (divisor).
 * @param numUno, es el ingreso de A (primer operando)
 * @param numDos es el ingreso de B (segundo operando),
 * @param resultado el resultado vuelve por puntero
 * @return retorno 0 si todo esta bien, y -1 si no es posible realizar la division, divisor==0.
 */


float dividir(float numUno, float numDos, float* pResultado)
{ // pasaje por referencia "*"


	int retorno = 0; //salio todo bien

	if(pResultado!= NULL && numDos!=0)//esto causa el error
	{
	*pResultado = numUno/numDos;//el asterisco sirve para trabajar con el valor de resultado es punteo, pasaje por referencia y no por valor
	}else
	{
		retorno =1;//salio todo mal
	}

	return retorno;

}
/**
 * @brief calcula el factorial de numero, y devuelve el resultado
 * @param numero es el numero recibido A o B y por puntero el resultado
 * @return acumuladorMultiplicador 0 si es null o decimal, -1 negativo 1 positivo entero.
 */


int factorial(float numero, int* pResultado)
{
	int i;
	int estado=1;
	int buffer;
	int pBuffer;

	buffer=(int)numero;

	if(numero-buffer==0 && pResultado!=NULL)
	{

	if (numero>0) //7
	{
	// i = 7   			i<=7 (SI)  i=i-1
	for (i=1;i<=numero;i++)
		pBuffer=pBuffer*i;
	}else
	{
		if(numero==0)
		{
			pBuffer=1;
		}else
		{
			estado=-1;
		}
	}
	}else
	{
		estado=-1;
	}

	*pResultado=pBuffer;

return estado;

}
