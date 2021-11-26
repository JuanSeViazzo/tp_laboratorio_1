/*
 * inputsGets.h
 *
 *  Created on: 28 sep. 2021
 *      Author: User
 */

#ifndef INPUTSGETS_H_
#define INPUTSGETS_H_
/**
 * @brief trae un caracter
 * @param string
 * @param len
 * @return 0 si esta ok -1 si esta mal
 */
int myGetsUno(char string, int len);


/**
 * @brief obtiene numero flotante usando metodo con while
 * @param pResultado es el puntero hacia la dir de memoria del resultado
 * @param mensaje invita el ingreso del numero
 * @param mensajeError alerta el error
 * @return 0 si esta ok -1 si hay error
 */
int utn_obtenerFlotanteWhile(float* pResultado,char mensaje[], char mensajeError[]);
/**
 * @brief obtiene numero flotante usando metodo con while
 * @param pResultado es el puntero hacia la dir de memoria del resultado
 * @param mensaje invita el ingreso del numero
 * @param mensajeError alerta el error
 * @return 0 si esta ok -1 si hay error
 */
int utn_obtenerFloatIfError(float* pResultado, char mensaje[], char mensajeError[]);
/**
 * @brief obtiene numero flotante con reintentos y rango
 * @param pResultado es el puntero hacia la dir de memoria del resultado
 * @param mensaje invita el ingreso del numero
 * @param mensajeError alerta el error
 * @param minimo da el numero de rango minimo a la funcion
 * @param maximo da el numero de rango maximo a la funcion
 * @param reintentos la cantidad de reintentos para error del usuario
 * @return 0 si esta ok -1 si hay error
 */
int utn_getNumeroFlotanteConReintentosMinMax(float *pResultado, char mensaje[], char mensajeError[], float minimo, float maximo, int reintentos);
/**
 * @brief obtiene numero entero
 * @param pResultado es el puntero hacia la dir de memoria del resultado
 * @param mensaje invita el ingreso del numero
 * @param mensajeError alerta el error
 * @return 0 si esta ok -1 si hay error
 */
int utn_obtenerNumeroEntero(int* pResultado, char* mensaje, char* mensajeError);
/**
 * @brief obtiene numero entero con reintentos y rango
 * @param pResultado es el puntero hacia la dir de memoria del resultado
 * @param mensaje invita el ingreso del numero
 * @param mensajeError alerta el error
 * @param minimo da el numero de rango minimo a la funcion
 * @param maximo da el numero de rango maximo a la funcion
 * @param reintentos la cantidad de reintentos para error del usuario
 * @return 0 si esta ok -1 si hay error
 */
int utn_obtenerEnteroConReintentosMinMax(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/**
 * @brief obtiene numero flotante
 * @param pResultado es el puntero hacia la dir de memoria del resultado
 * @param mensaje invita el ingreso del numero
 * @param mensajeError alerta el error
 * @return 0 si esta ok -1 si hay error
 */
int utn_getNumeroFlotanteConReintentos(float* pResultado, char mensaje[], char mensajeError[], int reintentos);
/**
 * @brief obtiene numero flotante con reintentos sin rango
 * @param pResultado es el puntero hacia la dir de memoria del resultado
 * @param mensaje invita el ingreso del numero
 * @param mensajeError alerta el error
 * @param reintentos da oportunidad de tres reintentos al usuario
 * @return 0 si esta ok -1 si hay error
 */
int utn_obtenerEnteroConReintentos(int* pResultado, char* mensaje, char* mensajeError, int reintentos);

//VA DENTRO DE GETNUMERO Y TIENE myGets y EsNumerica.

int utn_getNumero(int* pResultado, char mensaje[], char mensajeError[],int minimo, int maximo, int reintentos);


// TIENE myGets y esTexto

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud Es la longitud del array resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje de Error a ser mostrado
 * \param reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el array y -1 si no
 */

int utn_obtenerTextoconReintentos(char* pResultado, int len,char mensaje[], char mensajeError[], int reintentos);

//-------------------------


char getEmail(char *retorno,char str[]);


char getTelefono(char *retorno,char str[]);


char unt_getSoloLetras(char cadena[],char *retorno);



char unt_getAlfaNumerico(char cadena[],char *retorno);

int esFlotante(char* str);

int utn_getNumeroFlotanteMinyMaxReintentos(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


int esNombre(char* cadena,int longitud);

int utn_getNombreIntentos(char pResultado[], int longitud,char mensaje[], char mensajeError[], int reintentos);

int utn_getNombre(char pResultado[], int longitud,char mensaje[], char mensajeError[]);

int esDescripcion(char cadena[],int longitud);


int utn_getDescripcion(char pResultado[], int longitud,char mensaje[], char mensajeError[], int reintentos);

void strMayuscula(char str[]);

void strMinuscula(char str[]);

void uppercaselInitial(char string[]);

void cleanStdin(void);

int menu(int *numero);
//


#endif /* INPUTSGETS_H_ */
