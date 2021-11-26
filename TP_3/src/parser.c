#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int estado =-1;
	Employee* auxEmployee;
	char auxId[256];
	char auxNombre[256];
	char auxHsTrabajadas[256];
	char auxSueldo[256];
	int contador=0;

		if(pFile!=NULL && pArrayListEmployee!=NULL)
		{
			//fgets() otra opcion para leer la 1er linea desde el archivo.

			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHsTrabajadas,auxSueldo); // salteo la 1era

			do
			{
				if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHsTrabajadas,auxSueldo)==4)
				{

						auxEmployee =employee_newParametros(auxId,auxNombre,auxHsTrabajadas,auxSueldo);

						if (auxEmployee!=NULL)
						{
							ll_add(pArrayListEmployee,auxEmployee);
							estado = 0;
							contador++;
						}
						else
						{

							printf("Error en el Archivo id: %s\n", auxId); //solo muestro los Id de los Empleados con errores ( MOSTRE SOLO NOMBRE NO TOMO NOMBRES CON ESPACIO)
							employee_delete(auxEmployee);
							break;
						}

				}else
				{
					puts("Error en el archivo");
					continue;

				}
			}while(feof(pFile)==0);
			printf("La cantidad de trabajadores cargados es: %d\n",contador);
		}
	return estado;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int estado =-1;
	Employee* auxEmployee;
	int elPrimeroEsError=0;

		if(pFile!=NULL && pArrayListEmployee!=NULL)
		{
			//fgets() otra opcion para leer la 1er linea desde el archivo.

			do
			{
				auxEmployee=employee_new();
				if(auxEmployee!=NULL)
				{
					if(fread(auxEmployee,sizeof(Employee),1,pFile)==1)
					{
						ll_add(pArrayListEmployee,auxEmployee);
						estado = 0;
					}else
					{
					    employee_delete(auxEmployee);
						break;
						elPrimeroEsError++;
					}
				}
			}while(feof(pFile)==0);
			fclose(pFile);

		}

		if(elPrimeroEsError>1)
		{
			puts("Hubo un error en la carga");
		}

	return estado;
}
