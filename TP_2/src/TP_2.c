/*
 ============================================================================
 Name        : TP_2.c
 Author      : JuanSebastian Viazzo Perrone
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include "ArrayEmployees.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"
#include "inputsGets.h"
#include <ctype.h>

int main(void)
{


	setbuf(stdout, NULL);
	Employee listEmployee[TAM];
	initEmployees(listEmployee,TAM);
	int option;
	int freeId;
	float promedio;
	int contador=0;
	float acumulador=0;
	int order;
	int idEmployee=0;








	do
	{

		menu(&option);

		switch (option)

		{
			case 1:

				if(loademployee(listEmployee)==0)
				{
					printf("carga correcta\n");
				}else
				{
					puts("Error, carga incorrecta, maximo de reintentos");
				}

				break;

			case 2:
				utn_obtenerEnteroConReintentos(&freeId,"Por favor ingrese el numero de ID: ","Error cantidad de reintentos superada",3);
					if(modifyemployee(listEmployee,TAM,freeId)==0)
					{
						puts("Modificacion Correcta");
					}
					else
					{
						if(modifyemployee(listEmployee,TAM,freeId)==1)
						{
							puts("ID No encontrado");
						}else
						{
							puts("Error, modificacion incorrecta, maximo de reintentos");
						}
					}

				break;

			case 3:
				utn_obtenerEnteroConReintentos(&freeId,"Por favor ingrese el numero de ID: ","Error cantidad de reintentos superada",3);
				if(removeEmployee(listEmployee,TAM,freeId)==0)
				{
					puts("Baja Correcta");
				}
				else
				{
					if(removeEmployee(listEmployee,TAM,freeId)==1)
					{
						puts("ID No encontrado");
					}else
					{
						puts("Error, baja incorrecta, maximo de reintentos");
					}
				}
				break;



			case 4:

				utn_obtenerEnteroConReintentos(&order,"Por favor Ingrese '1' para ordenar de 'A' a 'Z' o '2' para 'Z' a 'A': ","Error ingrese valor correcto",3);
				printf("\n----------------------------------------------------------------------------------------------\n");
				sortEmployees(listEmployee,TAM,order);
				printEmployees(listEmployee,TAM);
				averageSalaryEmployee (listEmployee,TAM,&promedio,&contador,&acumulador);
				printf("\n-----------------------------------------\n");
				printf("El total de los sueldos es: %.2f \n-----------------------------------------\n",acumulador);
				printf("El promedio de sueldos es: %.2f \n-----------------------------------------\n",promedio);
				printf("La cantidad de trabajadores que superan el promedio es: %d \n-----------------------------------------\n",contador);



				break;
		}



	} while (option!=5);














return 0;

}
