#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int getInt(char mensaje[])
{
    char auxiliar[50];
    int control, resultado;

    printf("%s", mensaje);
    fflush(stdin);
    gets(auxiliar);
    control = esNumerico(auxiliar);
    if(control)
    {
        resultado = atoi(auxiliar);
        return resultado;
    }

    return 0;
}

float getFloat(char mensaje[])
{
    float auxiliar;

    printf("%s", mensaje);
    scanf("%f", &auxiliar);

    return auxiliar;
}

char getChar (char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);

    return auxiliar;
}


int esNumerico(char cadena[])
{
    int i=0;

    while(cadena[i] != '\0')
    {
        if(cadena[i]<'0' || cadena[i]>'9')
        {
                return 0;
        }
        i++;
    }

    return 1;
}


int esSoloLetra(char cadena[])
{
    int i=0;

    while(cadena[i] != '\0')
    {
        if((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z') && (cadena[i] != ' '))
        {
            return 0;
        }
        i++;
    }
    return 1;
}
int esAlfaNumerico(char cadena[])
{
    int i=0;

    while(cadena[i] != '\0')
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void getString(char mensaje[], char input[])
{
    printf("%s", mensaje);
    fflush(stdin);
    gets(input);
}

int getStringLetras(char mensaje[],char input[])
{
    char auxiliar[256];

    getString(mensaje, auxiliar);
    if(esSoloLetra(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }
    return 0;
}
int getStringNumeros(char mensaje[],char input[])
{
    char auxiliar[256];

    getString(mensaje, auxiliar);
    if(esNumerico(auxiliar))
    {
        strcpy(input, auxiliar);
        return 1;
    }
    return 0;
}
