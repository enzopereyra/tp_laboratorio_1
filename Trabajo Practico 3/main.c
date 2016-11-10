#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "miLibreria.h"


int main()
{

    EMovie* pelicula;
    EMovie** lista;
    char seguir='s', auxTitulo[30];
    int opcion=0, index=0, size=5, i;

    lista = (EMovie**)malloc(sizeof(EMovie*)*size);

    while(seguir=='s')
    {
        system("cls");
        printf("\n1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("---------------PELICULA NUEVA-----------------");
                pelicula = (EMovie*) malloc(sizeof(EMovie));
                if(agregarPelicula(pelicula))
                {
                    printf("\nNo se pudo agregar pelicula\n");
                    break;
                }

                lista[index] = pelicula;
                index++;

                if(index>=size)
                {
                    size+=5;
                    lista = realloc(lista,sizeof(EMovie*)*size);
                }

                printf("Pelicula agregada\n");
                break;

            case 2:
                system("cls");
                printf("---------------BORRANDO PELICULA-----------------");
                printf("\nIngrese titulo de pelicula a borrar: ");
                fflush(stdin);
                gets(auxTitulo);
                if(borrarPelicula(auxTitulo,lista, index))
                {
                    printf("\nNo se encontro la pelicula\n");
                    system("pause");
                    break;
                }

                system("pause");

                break;
            case 3:
                system("cls");
                printf("---------------GENERANDO ARCHIVO HTML----------------\n");
                generarPagina(lista, "index.html", index);
                system("pause");

               break;
            case 4:
                seguir = 'n';
                break;
        }
    }
    for(i=0; i<index; i++)
    {
        free(lista[i]);
    }
    free(lista);
    return 0;
}
