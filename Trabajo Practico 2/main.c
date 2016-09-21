#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "libreria.h"

#define CANTIDAD_PERSONA 20


int main()
{
    EPersona persona[CANTIDAD_PERSONA];
    char seguir='s';
    int opcion=0;

    cargarArray(persona, -1, CANTIDAD_PERSONA);

    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                alta(persona, CANTIDAD_PERSONA);
                break;
            case 2:
                system("cls");
                baja(persona, CANTIDAD_PERSONA);
                break;
            case 3:
                system("cls");
                ordenar(persona, CANTIDAD_PERSONA);
                break;
            case 4:
                system("cls");
                graficarEdades(persona, CANTIDAD_PERSONA);
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
