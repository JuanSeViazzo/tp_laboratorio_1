/*
 * ArrayEmployees.h
 *
 *  Created on: 2 oct. 2021
 *      Author: User
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define TAM 51
#include "inputsGets.h"

typedef struct
{
	int id;
	char name[TAM];
	char lastName[TAM];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/**
 * @brief inicia array employee
 * @param listEmployee array de empleados
 * @param len tamaño del array
 * @return 0 si esta bien -1 si esta mal
 */
int initEmployees(Employee listEmployee[], int len);
/**
 * @brief recibe el array de empleados y dentro pide todos las variables de los campos de la struct
 * @param listEmployee array de empleados
 * @return 0 si esta bien -1 si esta mal
 */
int loademployee(Employee listEmployee[]);

/**
 * @brief recibe todos los datos pedidos en loademployee y los carga en el index del array
 * @param listEmployee array de empleados
 * @param len tamaño del array
 * @param id id creado por create ID inicia en 0
 * @param name nombre del trabajador
 * @param lastName apellido del trabajador
 * @param salary sueldo del trabajador
 * @param sector sector del trabajador
 * @return 0 si esta bien, -1 si esta mal
 */
int addEmployee(Employee listEmployee[], int len, int id, char name[],char lastName[],float salary,int sector);

/**
 * @brief busca empleado libre por IsEmpty
 * @param listEmployee array de empleados
 * @param len tamaño del array
 * @return 0 si esta bien -1 si esta mal
 */
int employeeSearchFree(Employee listEmployee[], int len);

/**
 * @brief crea el ID, tiene variable static local, para guardar el dato cada vez que se llama
 * @return 0 si esta ok -1 si esta mal
 */
int createId(void);

/**
 * @brief busca empleado por ID
 * @param list array empleados
 * @param len tampaño del array
 * @param id del trabajador
 * @return 0 si esta ok -1 si da error
 */
int findEmployeeById(Employee list[], int len,int id);
/**
 * @brief borra empleado por id
 * @param list array empleados
 * @param len tampaño del array
 * @param id del trabajador
 * @return 0 si esta ok -1 si da error
 */
int removeEmployee(Employee* list, int len, int id);
/**
 * @brief ordena empleados
 * @param list array empleados
 * @param len tampaño del array
 * @param order criterio de mayor a menor o menor a mayor
 * @return
 */
int sortEmployees(Employee* list, int len, int order);

/**
 * @brief imprimi los trabajadores
 * @param list array empleados
 * @param length tampaño del array
 */
void printEmployees(Employee* list, int length);

/**
 * @brief carga los empleados para mostrar
 * @param list array empleados
 */
void showEmployee(Employee list);

/**
 * @brief modifica cualquier campo de cada empleado segun ID
 * @param list array empleados
 * @param len tampaño del array
 * @param id del trabajador
 * @return 0 si esta ok -1 si da error
 */
int modifyemployee (Employee* list, int len, int id);

/**
 * @brief realiza suma de sueldos para el promedio y cuenta la cantidad que estan por encima del promedio
 * @param list array empleados
 * @param len tampaño del array
 * @param promedio de los sueldos de los trabajadores activos
 * @param contador cuenta la cantidad de trabajadores que superan el promedio
 * @param acumulador acumula los sueldos
 * @return -1 si tiene error, 0 si esta correcto.
 */
int averageSalaryEmployee (Employee *list,int len,float *promedio,int *contador,float *acumulador);


int addForced(Employee listEmployee[], int len,int index, int *id, char name[],char lastName[],float salary,int sector);


#endif /* ARRAYEMPLOYEES_H_ */
