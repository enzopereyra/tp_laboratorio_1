#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "libreria.h"

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param cantidad largo del array.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[], int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].estado == -1)
            return i;
    }
    return -1;
}

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @param cantidad largo del array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], int dni, int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].dni == dni)
            return i;
    }
    return -1;
}

/** \brief carga el array con un dato determinado.
 *
 * \param lista[] el array se pasa como parametro.
 * \param dato es el cual se carga en el array.
 * \param cantidad largo del array.
 * \return void no tiene retorno
 */
void cargarArray(EPersona lista[], int dato, int cantidad)
{
    int i;

    for(i=0; i<cantidad; i++)
    {
        lista[i].estado = dato;
    }
}

/** \brief da de alta una persona
 * \param lista[] el array se pasa como parametro.
 * \param cantidad largo del array.
 * \return void no tiene retorno
 *
 */
void alta(EPersona lista[], int cantidad)
{
    int indice;
    char auxiliarNumerico[30];

    printf("*****Agregar persona*****\n\n");
    indice = obtenerEspacioLibre(lista, cantidad);
    if(indice == -1)
    {
        printf("No hay espacio disponible");
        return;
    }
    if(!getStringLetras("Ingrese nombre: ", lista[indice].nombre))
    {
        printf("Nombre incorrecto\n");
        system("pause");
        return;
    }
    if(!getStringNumeros("\nIngrese edad: ", auxiliarNumerico))
    {
        printf("Edad incorrecta\n");
        system("pause");
        return;
    }
    lista[indice].edad = atoi(auxiliarNumerico);
    if(!getStringNumeros("\nIngrese DNI: ", auxiliarNumerico))
    {
        printf("DNI incorrecto\n");
        system("pause");
        return;
    }
    lista[indice].dni = atoi(auxiliarNumerico);
    lista[indice].estado = 1;
    system("pause");
}

/** \brief da de baja logica una persona
 * \param lista[] el array se pasa como parametro.
 * \param cantidad largo del array.
 * \return void no tiene retorno
 *
 */
void baja(EPersona lista[], int cantidad)
{
    int indice, auxiliarDni;
    char auxiliarNumerico[30];

    printf("*****Borrar persona*****\n\n");
    if(!getStringNumeros("\nIngrese DNI: ", auxiliarNumerico))
    {
        printf("DNI incorrecto\n");
        system("pause");
        return;
    }
    auxiliarDni = atoi(auxiliarNumerico);
    indice = buscarPorDni(lista, auxiliarDni, cantidad);
    if(indice == -1)
    {
        printf("No existe\n");
        system("pause");
        return;
    }
    lista[indice].estado = -1;
    system("pause");
}

/** \brief ordena y muestra por pantalla una lista de personas
 * \param lista[] el array se pasa como parametro.
 * \param cantidad largo del array.
 * \return void no tiene retorno
 *
 */
void ordenar(EPersona lista[], int cantidad)
{
    int i, j;
    EPersona auxPersona;
    for(i=0; i<cantidad-1; i++)
    {
        if(lista[i].estado == 1)
        {
            for(j=i+1; j<cantidad; j++)
            {
                if(lista[j].estado == 1)
                {
                    if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
                    {
                        auxPersona = lista[i];
                        lista[i] = lista[j];
                        lista[j] = auxPersona;
                    }
                }
            }
        }
    }
    printf("NOMBRE\tEDAD\tDNI\n");
    for(i=0; i<cantidad; i++)
    {
        if(lista[i].estado == 1)
        {
            printf("%s\t", lista[i].nombre);
            printf("%d\t", lista[i].edad);
            printf("%d\n", lista[i].dni);
        }
    }
    system("pause");
}

/** \brief grafica con * y muestra por patalla
 * \param lista[] el array se pasa como parametro.
 * \param cantidad largo del array.
 * \return void no tiene retorno
 *
 */
void graficarEdades(EPersona lista[], int cantidad)
{
    int i, contador_18=0, contador_19_35=0, contador_35=0, mayor=0;
    int flag = 0;

    for(i=0; i<cantidad; i++)
    {
        if(lista[i].estado == 1)
        {
            if(lista[i].edad <= 18)
                contador_18++;
            else if((lista[i].edad > 18) && (lista[i].edad < 35))
                contador_19_35++;
                else
                    contador_35++;
        }
    }
    if(contador_18 >= contador_19_35 && contador_18 >= contador_35){
        mayor = contador_18;
    }else{
        if(contador_19_35 >= contador_18 && contador_19_35 >= contador_35)
        {
            mayor = contador_19_35;
        }
        else{
        mayor = contador_35;
        }
    }

    for(i=mayor; i>0; i--){
        if(i<= contador_18){
            printf("*");
        }
        if(i<= contador_19_35){
            flag=1;
            printf("\t*");
        }
        if(i<= contador_35){
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");
        }
        //Bajo una linea luego de cada iteracion
        printf("\n");
    }
    printf("\n<18   19-35   >35\n");
    system("pause");
}
