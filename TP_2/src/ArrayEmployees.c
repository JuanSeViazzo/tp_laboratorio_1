/*
 * ArrayEmployees.c
 *
 *  Created on: 2 oct. 2021
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"
#include "inputsGets.h"
#include <ctype.h>
#include "ArrayEmployees.h"
#define TAM 51








/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee listEmployee[], int len)
{
	int index;
	int status = -1;
	if (listEmployee != NULL && len > 0)
	{
		status = 0;
		for (index = 0; index < len; index++)
		{
			listEmployee[index].isEmpty = 1;
		}
	}
	return status;
}




int loademployee(Employee listEmployee[])
{

int status = -1;
	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;

	if (listEmployee != NULL)
	{
		if(utn_getNombreIntentos(auxName,TAM,"Por favor ingrese el nombre del empleado: ","Dato invalido.\n",3) == 0 &&
			utn_getNombreIntentos(auxLastName,TAM,"Por favor ingrese el apellido del empleado: ","Dato invalido.\n",3) == 0 &&
			utn_obtenerEnteroConReintentosMinMax(&auxSector,"Por favor ingrese el sector: ","Dato invalido.\n",1,10,3) == 0 &&
			utn_getNumeroFlotanteMinyMaxReintentos(&auxSalary,"Por favor ingrese el sueldo del empleado: ","Dato invalido.\n",0001,10000000,3)==0)
			{
						auxId=createId();
						status= 0;
						addEmployee(listEmployee,TAM,auxId,auxName,auxLastName,auxSalary,auxSector);
			}
	}

	return status;
}

/**
 * @brief
 * @param listEmployee
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/


int addEmployee(Employee listEmployee[], int len, int id, char name[],char lastName[],float salary,int sector)
{

	int bufferIndex;

	if((bufferIndex=employeeSearchFree(listEmployee,len))>=0)
	{
		listEmployee[bufferIndex].id=id;
		strncpy(listEmployee[bufferIndex].name,name,sizeof(listEmployee->name));
		strncpy(listEmployee[bufferIndex].lastName,lastName,sizeof(listEmployee->lastName));
		listEmployee[bufferIndex].salary=salary;
		listEmployee[bufferIndex].sector=sector;
		listEmployee[bufferIndex].isEmpty=0;
		return 0;

	}

 return -1;
}


int employeeSearchFree(Employee listEmployee[], int len)
{
	int i=0;
	int indexisEmpty=-1;

	if(listEmployee!=NULL && len>0)
	{
		indexisEmpty=-2;

		for (i=0;i<len;i++)
		{

			if(listEmployee[i].isEmpty==1)
			{
				indexisEmpty=i;
				break;
			}

		}

	}

	return indexisEmpty;

}


int createId(void)
{
    static int createId = 0;

    createId++;

    return createId;

}



/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id)
{

		int index;
		int status = -1;
		if (list != NULL && len > 0)
		{
			for (index = 0; index < len; index++)
			{
				if (list[index].isEmpty != 1)
				{
					if (list[index].id == id)
					{
						status = index;
						break;
					}
				}//else
				//{
					//puts("Slot vacio");
			//	}
			}
		}
 return status;

}


/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee* list, int len, int id)
{

	int retorno=-1;
	int bufferIndex;
	int option;
	bufferIndex=findEmployeeById(list,len,id);

		if(bufferIndex>=0 && list[bufferIndex].isEmpty==0)
		{
			puts("ID encontrado, por favor Ingrese 1 para borrar, 2 para cancelar");
			utn_obtenerEnteroConReintentos(&option,"Ingrese su opcion: ","Error, cantidad de reintentos superada",3);
			switch (option)
			{
				case 1:
					list[bufferIndex].isEmpty=1;
					retorno = 0;
					break;
				case 2:
					puts("Se ha cancelado la opcion de elimiar usuario");
					break;
			}

		}else
		{
			retorno=1;
		}



 return retorno;
}


/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	Employee bufferList;
	int i;
	int j;

	if (list != NULL && len >= 0)
	{
		switch (order)
		{
		case 1:
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (strcmp(list[i].lastName, list[j].lastName) > 0) {
						bufferList = list[i];
						list[i] = list[j];
						list[j] = bufferList;
						retorno = 0;
					} else {
						if (strcmp(list[i].lastName, list[j].lastName) == 0
								&& list[i].sector > list[j].sector) // > de menor a mayor
										{
							bufferList = list[i];
							list[i] = list[j];
							list[j] = bufferList;
						}
					}
				}
			}
			break;
		case 2:
			for (i = 0; i < len; i++) {
				for (j = i + 1; j < len; j++) {
					if (strcmp(list[i].lastName, list[j].lastName) < 0) {
						bufferList = list[i];
						list[i] = list[j];
						list[j] = bufferList;
						retorno = 0;
					} else {
						if (strcmp(list[i].lastName, list[j].lastName) == 0
								&& list[i].sector < list[j].sector) // > de menor a mayor
										{
							bufferList = list[i];
							list[i] = list[j];
							list[j] = bufferList;
						}
					}
				}
			}
			break;
		}
	}
	return retorno;
}



/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void printEmployees(Employee* list, int length)
{


puts(" ID Apellido             Nombre                  Sueldo                Sector\n----------------------------------------------------------------------------------------------\n");


	{
		for (int i = 0; i < length; i++)
		{
			if(list[i].isEmpty==0)
			{
				showEmployee(list[i]);
			}
		}
	}
}

void showEmployee(Employee list)
{
	printf("\n----------------------------------------------------------------------------------------------\n");
	printf("%3d %-20s %-20s %12.2f  %12d\n", list.id, list.lastName, list.name, list.salary, list.sector);



}




int modifyemployee(Employee* list, int len, int id)
{

		int retorno = -1;
		int bufferIndex;
		int option;
		char auxName[51];
		char auxLastName[51];
		float auxSalary;
		int auxSector;

		bufferIndex = findEmployeeById(list, len, id);

			if (bufferIndex >= 0 && list[bufferIndex].isEmpty == 0)
			{
				puts("ID encontrado, por favor ingrese");
				puts("1 para modificar nombre");
				puts("2 para modificar apellido");
				puts("3 para modificar Salario");
				puts("4 para modificar sector");
				puts("5 para cancelar la modificacion");
				if (utn_obtenerEnteroConReintentos(&option,
						"Ingrese su opcion: ",
						"Error, cantidad de reintentos superada", 3) == 0)
				{

					switch (option)
					{
					case 1:
						if (utn_getNombreIntentos(auxName, TAM,
								"Por favor ingrese el nombre del empleado: ",
								"Error No puede realizar mas intentos.", 3)
								== 0)
						{
							strncpy(list[bufferIndex].name, auxName,
									sizeof(list->name));
						}
						retorno = 0;
						break;
					case 2:
						if (utn_getNombreIntentos(auxLastName, TAM,
								"Por favor ingrese el apellido del empleado: ",
								"Error No puede realizar mas intentos.", 3)
								== 0)
						{
							strncpy(list[bufferIndex].lastName, auxLastName,
									sizeof(list->lastName));
						}
						retorno = 0;
						break;
					case 3:
						if (utn_getNumeroFlotanteConReintentos(&auxSalary,
								"Por favor ingrese el sueldo del empleado: ",
								"Error No puede realizar mas intentos.", 3)
								== 0)
						{
							list[bufferIndex].salary = auxSalary;
						}
						retorno = 0;
						break;
					case 4:
						if (utn_obtenerEnteroConReintentos(&auxSector,
								"Por favor ingrese el sector: ",
								"Error no puede realizar mas reintentos", 3)
								== 0)
						{
							list[bufferIndex].sector = auxSector;
						}
						retorno = 0;
						break;
					case 5:
						puts("Se ha cancelado la modificacion");
						retorno = 0;
						break;
					}
				}

			}else
			{
				retorno=1;
			}



return retorno;
}

//2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.


int averageSalaryEmployee (Employee *list,int len,float *promedio,int *contador,float *acumulador)
{

	int i;
	int retorno=-1;
	float bufferAcumulador=0;
	int bufferContador=0;
	int bufferContadorMayor=0;
	float bufferPromedio;
	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0)
			{
				bufferAcumulador = bufferAcumulador + list[i].salary;
				bufferContador++;
				retorno=0;
			}
		}
	}

	*acumulador=bufferAcumulador;
	bufferPromedio=bufferAcumulador/bufferContador;
	*promedio=bufferPromedio;

	for (i = 0; i < len; i++)
			{
				if (list[i].isEmpty == 0 && list[i].salary>bufferPromedio)
				{

					bufferContadorMayor++;

				}

			*contador=bufferContadorMayor;

			}
return retorno;


}





/**
 * @brief
 * @param listEmployee
 * @param len
 * @param id
 * @param name
 * @param lastName
 * @param salary
 * @param sector
 * @return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok*/


int addForced(Employee listEmployee[], int len,int index, int *id, char name[],char lastName[],float salary,int sector)
{

	Employee bufferEmployee;
	int status = -1;

	if(listEmployee != NULL && len>0 && index < len && index >= 0)
	{
		strncpy(bufferEmployee.name,name,TAM);
		strncpy(bufferEmployee.lastName,lastName,TAM);
		bufferEmployee.salary=salary;
		bufferEmployee.sector=sector;
		bufferEmployee.id=*id;
		bufferEmployee.isEmpty=0;
		status = 0;
		listEmployee[index]=bufferEmployee;
		(*id)++;



	}

 return status;
}
