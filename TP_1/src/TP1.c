/*
 ============================================================================
 Name        : TP1.c
 Author      : Juan Sebastian Viazzo Perrone
 Version     :Division H
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 . Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las func1iones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones*/

#include <stdio.h>
#include <stdlib.h>
#include "utn_calculadora.h"



int main(void)
{

	setbuf(stdout,NULL);

	int numeroMenu;
	float numeroUno=0;
	float numeroDos=0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoMultiplicacion;
	int estadoDivision;
	float resultadoDivision;
	int resultadoFactorialPrimero;
	int resultadoFactorialSegundo;
	int estadoFactorialPrimer;
	int estadoFactorialSegundo;
	char deseaContinuar = 's';
	int flagNumeroUno = 0;
	int flagNumeroDos = 0;
	int flagoperaciones = 0;


	do
	{

	numeroMenu=menu(numeroUno,numeroDos);

	switch(numeroMenu)
	{
	case 1:
		numeroUno=obtenerFloatDelUsuario("Por favor ingrese el 1er numero: ","Error ingrese un numero: ");
		flagNumeroUno = 1;
		break;
	case 2:
		numeroDos=obtenerFloatDelUsuario("Por favor ingrese el 2do numero: ","Error ingrese un numero: ");
		flagNumeroDos = 1;
		break;
	case 3:
		if (flagNumeroUno==1 && flagNumeroDos==1)
		{
		resultadoSuma=sumar(numeroUno,numeroDos);
		resultadoResta=restar(numeroUno,numeroDos);
		resultadoMultiplicacion=multiplicar(numeroUno,numeroDos);
		estadoDivision=dividir(numeroUno,numeroDos,&resultadoDivision);
		estadoFactorialPrimer=factorial(numeroUno,&resultadoFactorialPrimero);
		estadoFactorialSegundo=factorial(numeroDos,&resultadoFactorialSegundo);
		flagoperaciones=1;

		}else
		{
			if (flagNumeroUno==0 && flagNumeroDos==1)
			{
				printf("\nPor favor, primero realice la carga del 1er operando.\n");
			}else
			{
				if (flagNumeroUno==1 && flagNumeroDos==0)
				{
					printf("\nPor favor, primero realice la carga del 2do operando.\n");
				}else
				{
					printf("\nPor favor, cargue ambos numeros. \n");

				}
			}
		}

		break;
	case 4:
		if (flagoperaciones==1)
		{

			printf("\n\nEl resultado de (%.2f)+(%.2f) es: %.2f \n------------\n",numeroUno,numeroDos,resultadoSuma);
			printf("El resultado de  (%.2f)-(%.2f) es: %.2f  \n------------\n",numeroUno,numeroDos,resultadoResta);

		if (estadoDivision==0)
			{
				printf("El resultado de  (%.2f)/(%.2f) es: %.2f  \n------------\n",numeroUno,numeroDos,resultadoDivision);

			}else
			{
				printf("No se pudo realizar la division \n------------\n");

			}

		printf("El resultado de (%.2f)*(%.2f) es: %.2f  \n------------\n",numeroUno,numeroDos,resultadoMultiplicacion);



		if(estadoFactorialPrimer>0 && estadoFactorialSegundo>0)
		{
			printf("El factorial de (%.2f) es: %d. El factorial de (%.2f) es: %d  \n------------\n",numeroUno,resultadoFactorialPrimero,numeroDos,resultadoFactorialSegundo);
		}else
		{
			if(estadoFactorialPrimer<0 && estadoFactorialSegundo>0)
			{
				printf("No hay resultado del 1er Nº ya que no se puede realizar factorizacion de decimales, o negativos, y El factorial de (%.2f) es: %d  \n------------\n",numeroDos,resultadoFactorialSegundo);
			}else
			{
				if(estadoFactorialPrimer>0 && estadoFactorialSegundo<0)
				{
						printf("El factorial de (%.2f) es: %d y No hay resultado del 2do Nº ya que no se puede realizar factorizacion de decimales, o negativos.  \n------------\n",numeroUno,resultadoFactorialPrimero);

				}else
				{
						printf("No se pueden realizar ambas factorizaciones, ya que no se realizan de numeros negativos o decimales \n------------\n");
				}
			}
		}

		}else
		{
			if (flagoperaciones==0)
			{
				printf("\nPor favor, primero realice el paso Nº 3.\n");
			}
		}

		flagoperaciones=0;
		break;

	case 5:
		deseaContinuar='a';
		break;
	}

	}while(deseaContinuar!='a');

	return 0;
}


