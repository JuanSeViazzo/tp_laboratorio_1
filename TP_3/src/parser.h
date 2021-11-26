/*
 * parser.h
 *
 *  Created on: 12 nov 2021
 *      Author: Juan Sebastian
 */

#ifndef PARSER_H_
#define PARSER_H_


int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);


#endif /* PARSER_H_ */
