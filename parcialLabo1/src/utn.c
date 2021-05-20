#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include "utn.h"

/** \brief
 *
 * \param CHAR MENSAJE PARA PEDIR EL NUMERO
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param INT MIN NUMERO MINIMO DENTRO DEL RANGO
 * \param INT MAX NUMERO MAXIMO DENTRO DEL RANGO
 * \return -1 SI FALLO 0 SI EL ENTERO ESTA EN EL RANGO
 *
 */

int GetInt(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
    int retorno = -1;
    int bufferInt;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){
        do{
            printf("%s",mensaje);
            scanf("%d",&bufferInt);
            if(bufferInt >= minimo && bufferInt <= maximo){
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            else{
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/** \brief RECIBE UN FLOAT Y CONTROLA QUE ESTE DENTRO DE UN RANGO
 *
 * \param CHAR MENSAJE PARA PEDIR EL NUMERO
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param FLOAT MIN NUMERO MINIMO DENTRO DEL RANGO
 * \param FLOAT MAX NUMERO MAXIMO DENTRO DEL RANGO
 * \return FLOAT NUMERO DENTRO DEL RANGO
 *
 */


int GetFloat(int* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
    int retorno = -1;
    float bufferFloat;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){
        do{
            printf("%s",mensaje);
            scanf("%f",&bufferFloat);
            if(bufferFloat >= minimo && bufferFloat <= maximo){
                *pResultado = bufferFloat;
                retorno = 0;
                break;
            }
            else{
                printf("%s",mensajeError);
                reintentos--;
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/** \brief LA FUNCION DETERMINA SI EL NUMERO ES PAR O IMPAR
 *
 * \param MENSAJE PARA PEDIR EL DATO
 * \param MENSAJEERROR MENSAJE DE ERROR
 * \return DEVUELVE 0 SI ES IMPAR
 *         DEVUELVE 1 SI ES PAR
 */
int EsPar(char mensaje[],char mensajeError[])
{
    int resultado = 0;
    int numero;
    printf("%s",mensaje);
    scanf("%d",&numero);
    if(numero%2 == 0)
    {
        resultado = 1;
    }
    return resultado;
}
/** \brief Factorial de un numero
 *
 * \param CHAR MENSAJE DE ERROR
 * \param INT NUMPARAFACTOREAR NUMERO PARA FACTOREAR
 * \return DEVUELVE EL NUMERO FACTORIADO O -1 SI EL NUMERO NO SE PUEDE FACTOREAR
 *
 */

int GetFactorial(char mensaje[],char mensajeError[],int numParaFactorear){
    long resultado = 1;
    int i;
    if(numParaFactorear < 0)
    {
        printf("%s",mensajeError);
        resultado = -1;
    }
    else if (numParaFactorear == 0){
        resultado = 1;
    }else{
        for(i = 1; i <= numParaFactorear; i++)
        {
            resultado *= i;
        }
    }
    return resultado;
}
/** \brief
 * \param CHAR LABEL MENSAJE PARA PEDIR EL CHAR
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param CHAR MINIMO DEL RANGO PARA UNA RESPUESTA VALIDA
 * \param CHAR MAXIMO DEL RAGNO PARA UNA RESPUESTA VALIDA
 * \return -1 SI FALLO 0 SI EL CARACTER ESTA EN EL RANGO
 *
 */
int GetChar(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos)
{
    int retorno = -1;
    char bufferChar;
    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0){
        do{
            printf("%s",mensaje);
            fflush(stdin);
            scanf("%c",&bufferChar);
            bufferChar = tolower(bufferChar);
            if(bufferChar >= minimo && bufferChar <= maximo){
                *pResultado = bufferChar;
                retorno = 0;
                break;
            }
            printf("%s",mensajeError);
            reintentos--;
        }while(reintentos>=0);
    }
    return retorno;
}
/** \brief
 * \param CHAR LABEL MENSAJE PARA PEDIR EL CHAR
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param INT LARGO MAXIMO DE LA CADENA
 * \param INT CANTIDAD DE REINTENTOS POSIBLES
 * \return -1 SI FALLO 0 SI LA CADENA ES CORRECTA
 *
 */

int GetString(char resultado[],char* mensaje,char* mensajeError,int lenCadena,int reintentos)
{
    int retorno = -1;
    char bufferCadena[100];
    if(mensaje != NULL && mensajeError != NULL && reintentos >=0){
        do{
        	printf("%s",mensaje);
        	fflush(stdin);
			scanf("%[^\n]",bufferCadena);
			if (strlen(bufferCadena)<=lenCadena){
				strcpy(resultado,bufferCadena);
                retorno = 0;
                break;
            }
            printf("%s",mensajeError);
            reintentos--;
        }while(reintentos>=0);
    }
    return retorno;
}

/** \brief RECIBE UN CHAR Y CONTROLA QUE SEA UNA U OTRA RESPUESTA
 *
 * \param CHAR LABEL MENSAJE PARA PEDIR EL CHAR
 * \param CHAR MENSAJEERROR MENSAJE DE ERROR
 * \param CHAR RESPUESTA1 UNA RESPUESTA ACEPTADA
 * \param CHAR RESPUESTA2 OTRA RESPUESTA ACEPTADA
 * \return CHAR CARACTER LETRA QUE RESPONDIO
 */

char GetSoN(char label[],char mensajeError[],char respuesta1,char respuesta2)
{
    char caracter;

    printf ("%s",label);
    fflush(stdin);
    scanf("%c",&caracter);
    caracter = tolower(caracter);
    while(caracter!= respuesta1 && caracter != respuesta2)
    {
        printf ("%s",mensajeError);
        fflush(stdin);
        scanf("%c",&caracter);
    }
    return caracter;
}

