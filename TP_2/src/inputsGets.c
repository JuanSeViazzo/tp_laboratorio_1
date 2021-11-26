/*
 * inputsGets.c
 *
 *  Created on: 28 sep. 2021
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrays.h"
#include "inputsGets.h"
#include <ctype.h>
static int myGets(char* string, int len);
static int utn_SologetFloat(float* pResultado);
static int esNumerica(char str[]);
static int getNumeroEnteroValidacion(int* pResultado);
static int esTexto(char str[], int longitud);
static int getTexto(char* pResultado, int len);
static int esEmail(char str[]);
static int esTelefono(char str[]);
static int esSoloLetras(char str[]);
static int esAlfaNumerico(char str[]);
static int getNombre(char* pResultado, int longitud);
// FUNCIONES GENERALES

static int myGets(char* string, int len)
{
	int retorno=-1;
	char bufferString[4096];
	if(string != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(string,bufferString,len);
				retorno=0;
			}
		}
	}
	return retorno;
}


//------------------------------------------------------------------------------------------


//FUNCIONES DE FLOTANTES

int utn_obtenerFlotanteWhile(float* pResultado,char mensaje[], char mensajeError[])
 {
	int retorno=-1;
	char bufferStr[50];
	if(pResultado !=NULL && mensaje!=NULL)
	{

	printf(mensaje);
	myGets(bufferStr,sizeof(bufferStr));
	while (!esFlotante(bufferStr))
	{

        printf("%s", mensajeError);
		myGets(bufferStr,sizeof(bufferStr));
	}
	}
	retorno=1;
	*pResultado= atof(bufferStr);

	return retorno;
}

int utn_obtenerFloatIfError(float *pResultado, char mensaje[], char mensajeError[])

{
    int retorno = -1;
    char bufferCadenaAux[16];
    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL)
    {
            printf("%s", mensaje);
            fflush(stdin);
            if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
            {

                if(esFlotante(bufferCadenaAux)==0)
                {
                	*pResultado = atof(bufferCadenaAux);

                }
                else {
                    printf("%s", mensajeError);
                }
            }
            else {
                printf("%s", mensajeError);

        }
    }
    return retorno;
}

int esFlotante(char *string) {
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if (string != NULL && strlen(string) > 0) {
		for (i = 0; string[i] != '\0'; i++) {
			if (i == 0 && (string[i] == '-' || string[i] == '+')) {
				continue;
			}
			if (string[i] < '0' || string[i] > '9') {
				if (string[i] == '.' && contadorPuntos == 0) {
					contadorPuntos++;
				}
				else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

static int utn_SologetFloat(float* pResultado)
{
	int retorno=-1;
	char buffer[64];

	if(pResultado != NULL){
		if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer)){
			*pResultado = atof(buffer);
			retorno = 0;
		}
	}
	return retorno;
}

int utn_getNumeroFlotanteMinyMaxReintentos(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)

{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0){
		reintentos--;
		printf("%s",mensaje);
		if(utn_SologetFloat(&bufferFloat) == 0){
			if(bufferFloat >= minimo && bufferFloat <= maximo){
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


int utn_getNumeroFlotanteConReintentos(float* pResultado, char mensaje[], char mensajeError[], int reintentos)
{
	float bufferFloat;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL  && reintentos >= 0)
	{
		while(reintentos>=0)

		{
				reintentos--;
				printf("%s",mensaje);
				if(utn_SologetFloat(&bufferFloat) == 0)
				{
						*pResultado = bufferFloat;
						retorno = 0;
						break;
				}else
				{
					printf("%s",mensajeError);
				}
		}
	}




	return retorno;
}





//------------------------------------------------------------------------------------------


// FUNCIONES DE ENTEROS

//es numerica con + y -
static int esNumerica(char str[])
{
   int i=0;
   int retorno = -1;
   if (str[i] == '-')
   {
   	 		i = 1;
   	}
   while(str[i] != '\0')
   {
       if(str[i] > '0' || str[i] < '9')
       {
    	   retorno=0;
           break;
       }
       i++;
   }
   return retorno;
}

//tiene myGets y esNumerica
int utn_obtenerNumeroEntero(int* pResultado, char* mensaje, char* mensajeError)
{
	int retorno = -1;
	char bufferCadenaAux[16];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{

			printf("%s", mensaje);
			fflush(stdin);

			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				if(esNumerica(bufferCadenaAux)==0)
				{
					*pResultado = atoi(bufferCadenaAux);
				}
				else
				{
					printf("%s", mensajeError);
				}
			}
			else
			{
				printf("%s", mensajeError);
			}
	}
	return retorno;
}

int utn_obtenerEnteroConReintentosMinMaxa(float* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)

{
	int retorno = -1;
	float bufferInt;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);
			fflush(stdin);

			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				// el usuario ingreso algo
				// lo valido, para ver si los simbolos ingresados son numericos
				if(esFlotante(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					bufferInt = atof(bufferCadenaAux);

					if(bufferInt >= minimo && bufferInt <= maximo){
						*pResultado = bufferInt;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
					}
				}
				else {
					printf("%s", mensajeError);
				}
			}
			else {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}



int utn_obtenerEnteroConReintentosMinMax(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)

{
	int retorno = -1;
	int bufferInt;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{

		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);
			fflush(stdin);

			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{
				// el usuario ingreso algo
				// lo valido, para ver si los simbolos ingresados son numericos
				if(esNumerica(bufferCadenaAux)==0)
				{
					// si son numericos, convierto la cadena a INT
					bufferInt = atoi(bufferCadenaAux);

					if(bufferInt >= minimo && bufferInt <= maximo){
						*pResultado = bufferInt;
						retorno = 0;
						break;
					}else{
						printf("%s", mensajeError);
					}
				}
				else {
					printf("%s", mensajeError);
				}
			}
			else {
				printf("%s", mensajeError);
			}
		}
	}
	return retorno;
}

int utn_obtenerEnteroConReintentos(int* pResultado, char* mensaje, char* mensajeError, int reintentos)

{
	int retorno = -1;
	int i;
	char bufferCadenaAux[16];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL  && reintentos >= 0)
	{

		for(i=0; i<=reintentos; i++)
		{
			printf("%s", mensaje);

			if(myGets(bufferCadenaAux,sizeof(bufferCadenaAux))==0)
			{

				if(esNumerica(bufferCadenaAux)==0)
				{
					*pResultado = atoi(bufferCadenaAux);

						retorno = 0;
						break;
				}else
				{
						printf("%s", mensajeError);
				}
			}else
			{
					printf("%s", mensajeError);
			}
		}
	}else
	{
		printf("%s", mensajeError);
	}

	return retorno;
}

//VA DENTRO DE GETNUMERO Y TIENE myGets y EsNumerica.
static int getNumeroEnteroValidacion(int* pResultado)
{
    int retorno=-1;
    char bufferString[50];
    if(	pResultado != NULL && myGets(bufferString,sizeof(bufferString)) == 0 && esNumerica(bufferString))

    {
		retorno=0;
		*pResultado = atoi(bufferString);

	}
    return retorno;
}

// tiene dentro getNumeroEnteroValidacion
int utn_getNumeroMinMaxReint(int* pResultado, char mensaje[], char mensajeError[],int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do{
		printf("%s",mensaje);
		if(	getNumeroEnteroValidacion(&bufferInt) == 0 &&
			bufferInt >= minimo &&
			bufferInt <= maximo){
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

int utn_getNumeroReintentos(int* pResultado, char mensaje[], char mensajeError[], int reintentos)
{
	int retorno = -1;
	int bufferInt;
	do{
		printf("%s",mensaje);
		if(	getNumeroEnteroValidacion(&bufferInt) == 0)
		{
			retorno = 0;
			*pResultado = bufferInt;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos>=0);

	return retorno;
}

//------------------------------------------------------------------------------------------

// FUNCIONES DE LETRAS
static int esTexto(char str[], int longitud)
{
	int i=0;
	int retorno = 1;

	if (str != NULL && longitud > 0) {
		for (i = 0; str[i] != '\0' && i < longitud; i++)
		{
			if ((str[i] < 'A' || str[i] > 'Z')
					&& (str[i] < 'a' || str[i] > 'z'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
// TIENE myGets y esTexto
static int getTexto(char* pResultado, int len)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL){
    	if(	myGets(buffer,sizeof(buffer))==0 &&
    		esTexto(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer))<len){
    		strncpy(pResultado,buffer,len);
			retorno = 0;
		}
    }
    return retorno;
}

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el array y -1 si no
 */
// Posee getTexto
int utn_obtenerTextoconReintentos(char* pResultado, int len,char mensaje[], char mensajeError[], int reintentos)
{
	char bufferString[4096];
	int retorno = 0;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getTexto(bufferString,sizeof(bufferString)) == 0 &&
				strnlen(bufferString,sizeof(bufferString)) < len )
		{
			strncpy(pResultado,bufferString,len);
			retorno = 1;
			break;
		}
		printf("%s",mensajeError);
	}
	return retorno;
}


//------------------------------------------------------------------------------------------


// FUNCION PARA EMAIL
static int esEmail(char str[])
{
   int i=0;
   int contadorDeArroba=0;
   int contadorDePuntos=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] == '.') && (str[i] < '0' || str[i] > '9')&&(str[i]=='@'))
           return 0;
       if(str[i] == '.')
    	   contadorDePuntos++;
       if(str[i] == '@')
            contadorDeArroba++;
       i++;

   }
   if(contadorDePuntos==1&&contadorDeArroba==1) // debe tener un punto y arroba
        return 1;

    return 0;
}

char getEmail(char *retorno,char str[])
{


	char bufferChar[500];
	printf(str);
	if(myGets(bufferChar, sizeof(bufferChar))==0)
	{
		while(!esEmail(bufferChar))
		{
			printf("error ingrese un mail valido");
			myGets(bufferChar, sizeof(bufferChar));
		}
	}
	strcpy(retorno,bufferChar);

	return *retorno;

}

//------------------------------------------------------------------------------------------


// FUNCION PARA TELEFONO
static int esTelefono(char str[])
{
   int i=0;
   int contadorDeGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
    	   contadorDeGuiones++;
       i++;
   }
   if(contadorDeGuiones==1) // debe tener un guion
        return 1;

    return 0;
}

char getTelefono(char *retorno,char str[])
{


	char bufferChar[500];
	printf(str);
	if(myGets(bufferChar, sizeof(bufferChar))==0)
	{
		while(!esTelefono(bufferChar))
		{
			printf("error ingrese un mail valido");
			myGets(bufferChar, sizeof(bufferChar));
		}
	}
	strcpy(retorno,bufferChar);

	return *retorno;
}


//------------------------------------------------------------------------------------------

// FUNCION PARA SOLO LETRAS, O ALFANUMERICO
static int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
    	   return 0;
    	   i++;
       }

   }
   return 1;
}

char unt_getSoloLetras(char cadena[],char *retorno)
{

	char auxiliarChar[500];
	printf(cadena);
	if (myGets(auxiliarChar, sizeof(auxiliarChar)) == 0)
	{
		while (!esSoloLetras(auxiliarChar))
		{
			printf("error ingrese solo alfaNumerico ");
			myGets(auxiliarChar, sizeof(auxiliarChar));
		}
	}
	strcpy(retorno, auxiliarChar);

	return *retorno;

}

static int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

char unt_getAlfaNumerico(char cadena[],char *retorno)
{

	char auxiliarChar[500];
	printf(cadena);
	if (myGets(auxiliarChar, sizeof(auxiliarChar)) == 0)
	{
		while (!esAlfaNumerico(auxiliarChar))
		{
			printf("error ingrese solo alfaNumerico ");
			myGets(auxiliarChar, sizeof(auxiliarChar));
		}
	}
	strcpy(retorno, auxiliarChar);

	return *retorno;

}



// FUNCION PARA NOMBRES, DESCRIPCION MAYUSCULA O MINUSCULA.


int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena!=NULL)
	{
		retorno=0;
		while(cadena[i]!='\0')
		{
			if((cadena[i]>='A'&&cadena[i]<='z')||cadena[i]=='-'||cadena[i]==32)
			{
				if(cadena[i]>'Z'&&cadena[i]<'a')
				{
					retorno=-1;
					break;
				}
				i++;

			} else
			{
				retorno=-1;
				break;
			}
		}
	}
	return retorno;


}

static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[51];

    if(pResultado != NULL){
    	if(	myGets(buffer,sizeof(buffer))==0 && esNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_getNombreIntentos(char pResultado[], int longitud,char mensaje[], char mensajeError[], int reintentos)
{
	char bufferString[51];
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;
			break;
		}else
		{
			printf("%s",mensajeError);
		}
	}
	return retorno;

}

int utn_getNombre(char pResultado[], int longitud,char mensaje[], char mensajeError[])
{
	char bufferString[4096];
	int retorno = -1;

		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud )
		{
			strncpy(pResultado,bufferString,longitud);
			retorno = 0;

		}else
		{
			printf("%s",mensajeError);

		}
	return retorno;
}


int menu(int *numero)
{

	int retorno=-1;
	int buffer;

	puts("Por favor ingrese un numero para las siguientes opciones: ");
	printf("\n-----------------------------------------\n");
	puts("1: ALTAS.");
	puts("2: MODIFICAR.");
	puts("3: BAJAS.");
	puts("4: INFORMAR");
	puts("5. SALIR.");

	utn_obtenerEnteroConReintentos(&buffer,"OPCION?: ","Reintentos maximos",3);

	*numero=buffer;


	return retorno;

}




//

