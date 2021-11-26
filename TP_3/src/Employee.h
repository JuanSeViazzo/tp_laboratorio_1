#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define LEN_NOMBRE 256
#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[LEN_NOMBRE];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo);
void employee_delete();

int employee_setIdInt(Employee* this,int id);
int employee_setIdTxt(Employee* this, char* id);
int employee_getIdInt(Employee* this,int* id);
int employee_getIdTxt(Employee* this, char* id);


int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);


int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);


int employee_setSueldoTxt(Employee* this, char* sueldo);
int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_findById(LinkedList* pListEmployee,int id);

int employee_printEmployee(Employee* this);

void showEmployee(Employee* pArrayList);

int employee_sortId(void* parametroUno,void* parametroDos);
int employee_sortHoras(void* parametroUno,void* parametroDos);
int employee_sortSueldo(void* parametroUno,void* parametroDos);
int employee_sortNombre(void* parametroUno,void* parametroDos);
#endif // employee_H_INCLUDED
