#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputsGets.h"
#include <ctype.h>
#include "Employee.h"



Employee* employee_new(void)
{
	Employee* pEmployee = (Employee*) malloc(sizeof(Employee));

	return pEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{

       Employee* pEmployee = employee_new();


       if(pEmployee!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL)
       {


    	   if(employee_setHorasTrabajadasTxt(pEmployee,horasTrabajadasStr)==0 &&
    	   employee_setIdTxt(pEmployee,idStr)==0 &&
    	   employee_setSueldoTxt(pEmployee,sueldo)==0 &&
    	   employee_setNombre(pEmployee, nombreStr)==0)
		   {
    		   printf("Empleado ID: %s - Nombre: %s - Horas trabajadas: %s - Sueldo: %s \n",idStr,nombreStr,horasTrabajadasStr,sueldo);

		   }
       }

return pEmployee;


}


void employee_delete(Employee* this)
{

	if(this!=NULL)
	{
		free(this);
	}

}

int employee_setIdInt(Employee* this,int id)
{

	int retorno = -1 ;

	if(this!= NULL && id>=0)
	{

		this->id=id;
		retorno=0;
	}

return retorno;
}



int employee_printEmployee(Employee* this)
{
	int estado = -1;
    int horasTrabajadas;
    int sueldo;
    int id;
    char nombre [256];



    if(this!=NULL)
    {
      if(employee_getHorasTrabajadas(this, &horasTrabajadas)==0 &&
		employee_getSueldo(this, &sueldo)==0 &&
		employee_getIdInt(this, &id)==0 &&
		employee_getNombre(this, nombre)==0)
        {
    		printf("Empleado ID: %d - Nombre: %s - Horas trabajadas: %d - Sueldo: %d\n",id,nombre,horasTrabajadas,sueldo);

    	    estado = 0;
        }


    }

    return estado;
}


int employee_setIdTxt(Employee* this, char* id)
{

	int retorno = -1;
	//int IdTrabj;

	if(this!= NULL && id!=NULL && (esNumerica(id)==0))
	{

		this->id=atoi(id);
		retorno=0;
	}

	return retorno;
}


int employee_getIdInt(Employee* this,int* id)
{

	int retorno = -1 ;

	if(this!= NULL && id!=NULL)
	{

		*id=this->id;
		retorno=0;
	}

	return retorno;

}


int employee_getIdTxt(Employee* this, char* id)
{

	int retorno = -1 ;

	if(this!= NULL && (esNumerica(id)==0))
	{

		sprintf(id,"%d",this->id);
		retorno=0;
	}

	return retorno;
}

int employee_setNombre(Employee* this,char* nombre) //set para escribir en la posicion
{

	int retorno = -1;


	if(this!=NULL && nombre!=NULL && (esNombre(nombre,LEN_NOMBRE)==0))
	{
			strncpy(this->nombre,nombre,LEN_NOMBRE);
			retorno = 0;
	}

return retorno;
}




int employee_getNombre(Employee* this,char* nombre) //get para leer de la posicion.
{
	int retorno = -1;

		if(this!=NULL && nombre!=NULL)
		{
			retorno = 0;
			strncpy(nombre,this->nombre,LEN_NOMBRE);

		}

	return retorno;
}


int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{

	int retorno = -1;
	int horas;



	if(this!= NULL && horasTrabajadas!=NULL && horasTrabajadas>=0 && (esNumerica(horasTrabajadas)==0))
	{

		horas=atoi(horasTrabajadas);
		this->horasTrabajadas=horas;
		retorno=0;
	}

	return retorno;
}




int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{


	int retorno = -1 ;

	if(this!= NULL && horasTrabajadas>=0)
	{

		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}

return retorno;


}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

	int retorno = -1 ;

	if(this!= NULL && horasTrabajadas!=NULL)
	{

		*horasTrabajadas=this->horasTrabajadas;
		retorno=0;
	}

	return retorno;




}

int employee_setSueldoTxt(Employee* this, char* sueldo)
{

	int retorno = -1 ;
	int sueldoTrabj;


	if(this!= NULL && sueldo!=NULL && sueldo>=0 &&(esNumerica(sueldo)==0))
	{
		sueldoTrabj=atoi(sueldo);
		this->sueldo=sueldoTrabj;
		retorno=0;
	}

	return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{


	int retorno = -1 ;

	if(this!= NULL && sueldo>=0)
	{

		this->sueldo=sueldo;
		retorno=0;
	}

return retorno;




}
int employee_getSueldo(Employee* this,int* sueldo)
{

	int retorno = -1 ;

	if(this!= NULL && sueldo!=NULL)
	{

		*sueldo=this->sueldo;
		retorno=0;
	}

	return retorno;
}

int employee_findById(LinkedList* pListEmployee,int id)
{
	int retorno = -1;
	int lenEmployee;
	int i;
	Employee* auxEmployee;
	int idLeido;

	if(pListEmployee!=NULL && id>=0)
	{
		lenEmployee=ll_len(pListEmployee);

		for(i=0;i<lenEmployee;i++)
		{
			auxEmployee=ll_get(pListEmployee,i);
			if(employee_getIdInt(auxEmployee,&idLeido)==0)
			{
				if(idLeido==id)
				{
					retorno = i;
					break;
				}
			}
		}
	}
return retorno;
}

void showEmployee(Employee* pArrayList)
{
  if(pArrayList!=NULL)
    {
      printf("\n%5d %10s %10d %15d",pArrayList->id,pArrayList->nombre,pArrayList->horasTrabajadas,pArrayList->sueldo);
    }
  else
    {
      printf("\nNo se encontraron empleados para mostrar.");
    }
}






int employee_sortId(void* parametroUno,void* parametroDos)
{
    int retorno;
    int idAuxUno;
    int idAuxDos;

    if(parametroUno!=NULL&&parametroDos!=NULL)
	{
		employee_getIdInt((Employee*)parametroUno,&idAuxUno);
		employee_getIdInt((Employee*)parametroDos,&idAuxDos);
		if (idAuxUno<idAuxDos)
		{
			retorno=1;
		}
		else
		{
			if (idAuxUno>idAuxDos)
			{
				retorno=-1;
			} else
			{
				retorno=0;
			}
		}
	}

    return retorno;
}

int employee_sortHoras(void* parametroUno,void* parametroDos)
{
    int retorno;
    int horasAuxUno;
    int horasAuxDos;

    if(parametroUno!=NULL&&parametroDos!=NULL)
	{
		employee_getHorasTrabajadas((Employee*)parametroUno,&horasAuxUno);
		employee_getHorasTrabajadas((Employee*)parametroDos,&horasAuxDos);

		if (horasAuxUno<horasAuxDos)
		{
			retorno=1;
		}
		else
		{
			if (horasAuxUno>horasAuxDos)
			{
				retorno=-1;
			} else
			{
				retorno=0;
			}
		}
	}

    return retorno;
}

int employee_sortSueldo(void* parametroUno,void* parametroDos)
{
    int retorno;
    int sueldoAuxUno;
    int sueldoAuxDos;

    if(parametroUno!=NULL&&parametroDos!=NULL)
	{
		employee_getSueldo((Employee*)parametroUno,&sueldoAuxUno);
		employee_getSueldo((Employee*)parametroDos,&sueldoAuxDos);

		if (sueldoAuxUno<sueldoAuxDos)
		{
			retorno=1;
		}
		else
		{
			if (sueldoAuxUno>sueldoAuxDos)
			{
				retorno=-1;
			} else
			{
				retorno=0;
			}
		}
	}

    return retorno;
}


int employee_sortNombre(void* parametroUno,void* parametroDos)
{
    int retorno;
    char auxPriNombre[LEN_NOMBRE];
    char auxSegNombre[LEN_NOMBRE];

    if(parametroUno!=NULL&&parametroDos!=NULL)
	{
		employee_getNombre((Employee*)parametroUno,auxPriNombre);
		employee_getNombre((Employee*)parametroDos,auxSegNombre);

		if (strcmp(auxPriNombre,auxSegNombre)<0)
		{
			retorno=1;
		}
		else
		{
			if (strcmp(auxPriNombre,auxSegNombre)>0)
			{
				retorno=-1;
			} else
			{
				retorno=0;
			}
		}
	}

    return retorno;
}



