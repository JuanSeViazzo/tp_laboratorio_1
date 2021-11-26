#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "inputsGets.h"
#define LEN_NOMBRE 256

int menu()
{

  int opcion = 0;
  printf("..............................................\n"
		  "                 ABM EMPLEADOS               \n"
		  ".............................................\n\n"
		  "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
		  "2. Cargar los datos de los empleados desde el archivo data.csv (modo pFileario).\n"
		  "3. Alta de empleado\n"
		  "4. Modificar datos de empleado\n"
		  "5. Baja de empleado\n"
		  "6. Listar empleados\n"
		  "7. Ordenar empleados\n"
		  "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
		  "9. Guardar los datos de los empleados en el archivo data.bin (modo pFileario).\n"
		  "10. Salir\n\n");
  utn_obtenerEnteroConReintentosMinMax(&opcion,"\nIngrese la opcion deseada: ","La opcion elegida es invalida",0,11,3);
  return opcion;
}






/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	int estado=-1;

		FILE* pFileEmployee; // para leer los empleados

		if(path!=NULL)
		{
			pFileEmployee = fopen(path, "r");


				if(pFileEmployee!=NULL)
				{

					if(parser_EmployeeFromText(pFileEmployee,pArrayListEmployee)==0)
					{
						estado=0;
						puts("La carga se realizo correctamente");
					}
				}else
				{
					printf("El archivo no existe");
				}

				fclose(pFileEmployee);

		}else
		{
			printf("El archivo no existe");
		}

    return estado;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo pFileario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	int estado=-1;

		FILE* pFileEmployee; // para leer los empleados


		pFileEmployee = fopen(path, "rb");


		if(pFileEmployee!=NULL)
		{
			parser_EmployeeFromBinary(pFileEmployee,pArrayListEmployee);
			estado=0;
		}else
		{
			printf("El archivo no existe");
		}

		fclose(pFileEmployee);

	return estado;

}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

static int createId(void)
{
    static int createId = 1000;

    createId++;

    return createId;

}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int estado = -1;
	int id;
	int sueldo;
	int horasTrabajadas;
	char nombre[256];
	Employee* auxEmployee;

	auxEmployee=employee_new();

	if (pArrayListEmployee!=NULL)
	{
		utn_getDescripcion(nombre,LEN_NOMBRE, "ingrese el nombre: ","Dato Invalido\n",3);
		utn_obtenerNumeroEntero(&sueldo, "Ingrese el sueldo: ", "Dato invalido\n");
		utn_obtenerNumeroEntero(&horasTrabajadas, "Ingrese las horas trabajadas: ", "Dato invalido\n");

		id=createId();
		employee_setNombre(auxEmployee,nombre);
		employee_setHorasTrabajadas(auxEmployee,horasTrabajadas);
		employee_setSueldo(auxEmployee, sueldo);
		employee_setIdInt(auxEmployee,id);
		estado = 0;

		ll_add(pArrayListEmployee,auxEmployee);


	}
	return estado;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

	int estado = -1;
	int bufferIndex;
	int bufferId;
	int option;
	char auxNombre[256];
	int auxSueldo;
	int auxHorasTrabajadas;
	Employee* auxEmployee;
	int lenLista;

	lenLista=ll_len(pArrayListEmployee);


	if(lenLista>0)
	{
		if(pArrayListEmployee!=NULL)
		{
			if(utn_obtenerEnteroConReintentos(&bufferId, "Por favor ingrese el ID: ","Dato invalido",3)==0)
			{
				printf("ID cargado %d \n",bufferId);
			}else
			{
				printf("ID no encontrado, reintentos maximos");
			}
		}
		if(bufferId>=0)
		{
			bufferIndex=employee_findById(pArrayListEmployee,(bufferId));

			auxEmployee = ll_get(pArrayListEmployee, bufferIndex);

			if(auxEmployee!=NULL)
			{

				puts("Por favor ingrese la opcion que desea modificar: 1: Nombre, 2: Horas Trabajadas, 3: Sueldo");

				if(utn_obtenerEnteroConReintentos(&option, "Por favor ingrese la opcion: ","Dato invalido",3)==0)
				{

					printf("opcion elegida: %d \n",option);
				}else
				{
					printf("opcion no valida, reintentos maximos");
				}

				switch (option)

				{
					case 1:

						if(utn_getDescripcion(auxNombre,256, "ingrese el nombre: ","Dato Invalido",3)==0)
						{

							employee_setNombre(auxEmployee,auxNombre);
						}else
						{
							puts("No se pudo cambiar el nombre");
						}

						break;
					case 2:
							if(utn_obtenerEnteroConReintentos(&auxHorasTrabajadas, "\nIngrese las horas trabajadas: ", "Dato invalido",3)==0)
							{

								employee_setHorasTrabajadas(auxEmployee,auxHorasTrabajadas);


							}else
							{
								puts("No se pudieron cambiar las horas trabajads");
							}
						break;
					case 3:
						if(utn_obtenerEnteroConReintentos(&auxSueldo, "\nIngrese el sueldo: ", "Dato invalido",3)==0)
							{

								employee_setSueldo(auxEmployee,auxSueldo);


							}else
							{
								puts("No se pudo cambiar el sueldo");
							}

					break;

						estado=0;
				}
			}
		}
	}
return estado;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

	int bufferIndex;
	Employee* auxEmployee;
	int estado=-1;
	int bufferId;

	if(pArrayListEmployee!=NULL)
	{
		if(utn_obtenerEnteroConReintentos(&bufferId, "Por favor ingrese el ID: ","Dato invalido",3)==0)
		{
			printf("ID cargado: %d\n",bufferId);
		}else
		{

			printf("ID no encontrado, reintentos maximos");
		}
	}
	if(bufferId>0)

	{

		bufferIndex=employee_findById(pArrayListEmployee,bufferId);
		printf("%d\n",bufferIndex);

		//bufferIndex=bufferIndex-1;
		auxEmployee = ll_get(pArrayListEmployee, (bufferIndex));


		if(auxEmployee!=NULL)
		{

			ll_remove(pArrayListEmployee,bufferIndex);

			free(auxEmployee);


			estado=0;
		}

	}

    return estado;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int estado=-1;
    int index;
    Employee* auxEmployee;
    int lenLista;


    if(pArrayListEmployee!=NULL)
    {

    	lenLista=ll_len(pArrayListEmployee);


    	if(lenLista>0)
    	{

			for(index=0;index<lenLista;index++)
			  {
				auxEmployee=ll_get(pArrayListEmployee,index);

				if(auxEmployee!=NULL)
				{

					employee_printEmployee(auxEmployee);
				}

				estado=0;
			  }
		 }else
			 puts("No hay trabajadores cargados");
    }

		return estado;
}







/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
	int option;
	int lenght;
	int optionSeg;

	lenght=ll_len(pArrayListEmployee);


	if(lenght>0)
	{
		printf("Elija la opcion para el criterio de orden?\n"
				" 1)ID\n"
				" 2)Nombre\n"
				" 3)Horas trabajadas\n"
				" 4)Sueldo\n"
				" 5)Volver al menu principal\n");

		if(utn_obtenerEnteroConReintentosMinMax(&option,"Ingrese la opcion elegida: ","Error",0,6,3)==0)
		{
			printf("Elija la opcion 0 de menor a mayor, y la opcion 1 de mayor a menor\n");
			utn_obtenerEnteroConReintentosMinMax(&optionSeg,"Ingrese la opcion elegida: ","Error",0,1,3);

		    if (pArrayListEmployee!=NULL)
		    {

		    	switch (option)
		    	{
		    	case 1:
		    		printf("\n ordenando...\n");
		    		printf("\n ordenando...\n");
		    		ll_sort(pArrayListEmployee,employee_sortId,optionSeg); // 0 menor a mayor, 1 mayor a menor.
		    		printf("\nLista ordenada por ID\n");
		    		retorno=0;
		    		break;
		    	case 2:
		    		printf("\n ordenando...\n");
		    		printf("\n ordenando...\n");
		    		ll_sort(pArrayListEmployee,employee_sortNombre,optionSeg);
		    		printf("\nLista ordenada por Nombre\n");
		    		retorno=0;
		    		break;
		    	case 3:
		    		printf("\n ordenando...\n");
		    		printf("\n ordenando...\n");
		    		ll_sort(pArrayListEmployee,employee_sortHoras,optionSeg);
		    		printf("\nLista ordenada por Horas Trabajadas\n");
		    		retorno=0;
		    		break;
		    	case 4:
		    		printf("\n ordenando...\n");
		    		printf("\n ordenando...\n");
		    		ll_sort(pArrayListEmployee,employee_sortSueldo,optionSeg);
		    		printf("\nLista ordenada por Sueldo\n");
		    		retorno=0;
		    		break;
		    	case 5:
		    		printf("\n regreso al menu principal");
		    		retorno=0;
		    		break;
		    	}
		    }
		}
	}else
	{
		printf("\nNo hay empleados cargados para ordenar\n");
	}

    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
  int estado=-1;
  FILE* pFile;
  Employee* bufferEmployee;
  int id;
  int sueldo;
  int horasTrabajadas;
  int index;
  char nombre[LEN_NOMBRE];
  int ll_tam;


	  if(path!=NULL && pArrayListEmployee!=NULL)
	  {

		  ll_tam=ll_len(pArrayListEmployee);

		if(ll_tam>0)
		{
			 pFile = fopen(path,"w");
			 if(pFile!=NULL)
			 {
				 fprintf(pFile,"id,nombre,horastrabajadas,sueldo\n");
				 for(index=0;index<ll_tam;index++)
				 {
					 bufferEmployee=(Employee*) ll_get(pArrayListEmployee,index);
					 if(bufferEmployee!=NULL)
					 {
						  employee_getHorasTrabajadas(bufferEmployee,&horasTrabajadas);
						  employee_getIdInt(bufferEmployee,&id);
						  employee_getNombre(bufferEmployee,nombre);
						  employee_getSueldo(bufferEmployee,&sueldo);
						  fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
						  estado =0;
					 }

				  }
			  fclose(pFile);

			}
		}
	  }

		  if(estado==0)
		  puts("datos guardados");
		  else
		  puts("No se pudo guardar");



return estado;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo pFileario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int estado = -1;
	FILE* pFile;
	Employee* bufferEmployee;
	int ll_tam=-1;
	int index;

	if(path!=NULL && pArrayListEmployee!=NULL)
	 {

		ll_tam=ll_len(pArrayListEmployee);
		if(ll_tam>=0)
		{

			if((pFile = fopen(path,"w+b"))!=NULL)
			{

				for(index=0;index<ll_tam;index++)
				{

					bufferEmployee=ll_get(pArrayListEmployee,index);
					if(bufferEmployee!=NULL)
					{

						fwrite(bufferEmployee,sizeof(Employee),1,pFile);
						estado=0;

					}
				}
			fclose(pFile);
			}
		 }
	 }
	if(estado==0)
		puts("Datos guardados");
	else
		puts("No se pudo guardar");





    return estado;
}

