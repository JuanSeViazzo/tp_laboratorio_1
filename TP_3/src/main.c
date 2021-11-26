#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
	int flagCarga=0;

    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
    	option = menu();
    	switch(option)
    	        {
    	            case 1:
    	            	if(flagCarga==0)
    	            	{
        	                if(controller_loadFromText("data.csv",listaEmpleados)==0)
        	            	{
        	            		puts("----LA CARGA SE REALIZO CORRECTAMENTE----");
        	            		flagCarga=1;
        	            	}
    	            	}else
    	            		puts("Ya se ha cargado el archivo");
    	                break;
    	            case 2:
    	            	if(flagCarga==0)
    	            	{	if(controller_loadFromBinary("data.bin",listaEmpleados)==0)
							{
								puts("----LA CARGA SE REALIZO CORRECTAMENTE----");
        	            		flagCarga=1;
							}
            			}else
            				puts("Ya se ha cargado el archivo");
    	            	break;
    	            case 3:
    	            	controller_addEmployee(listaEmpleados);
    	            	break;
    	            case 4:
    	            	puts("------LISTA DE TRABAJADORES-----");
    	            	controller_ListEmployee(listaEmpleados);
    	            	controller_editEmployee(listaEmpleados);
    	            	break;
    	            case 5:
    	            	puts("------LISTA DE TRABAJADORES-----");
    	            	controller_ListEmployee(listaEmpleados);
    	            	controller_removeEmployee(listaEmpleados);
    	            	break;
    	            case 6:
    	            	controller_ListEmployee(listaEmpleados);
    	            	break;
    	            case 7:
    	            	controller_sortEmployee(listaEmpleados);
    	            	break;
    	            case 8:
    	            	if(flagCarga==0)
    	            	{
    	            		puts("Primero debera realizar la carga para guardar el archivo");
    	            	}else
    	            	controller_saveAsText("data.csv",listaEmpleados);
    	            	break;
    	            case 9:
    	            	if(flagCarga==0)
    	            	{
    	            		puts("Primero debera realizar la carga para guardar el archivo");
    	            	}else
    	            	controller_saveAsBinary("data.bin",listaEmpleados);
    	            break;
    	        }

    }while(option != 10);
    return 0;
}

