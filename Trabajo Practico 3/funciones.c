#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "miLibreria.h"

#define ARCH "bin.dat"

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna -1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
 int agregarPelicula(EMovie* movie)
{
    FILE* fBin= NULL;
    char aux[20];

    if((fBin = fopen(ARCH, "r+b"))== NULL)
    {
        if((fBin = fopen(ARCH, "w+b"))== NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit(1);
        }
    }

    getString("\nIngrese titulo: ", movie->titulo);

    if(!getStringLetras("\nIngrese genero: ", movie->genero))
    {
        printf("\nNo se pudo agregar el genero");
        return -1;
    }

    if(!getStringNumeros("\nIngrese duracion: ", aux))
    {
        printf("\nNo se pudo agregar la duracion");
        return -1;
    }
    movie->duracion = atoi(aux);

    getString("\nIngrese una breve descripcion: ", movie->descripcion);

    if(!getStringNumeros("\nIngrese puntuacion: ", aux))
    {
        printf("\nNo se pudo agregar la duracion");
        return -1;
    }
    movie->puntaje = atoi(aux);

    getString("\nIngrese el link de la imagen: ", movie->linkImagen);

    movie->estado = 1;

    fseek(fBin, 0L, SEEK_END);

    fflush(stdin);
    fwrite(&movie, sizeof(EMovie), 1, fBin);

    fclose(fBin);

    return 0;
}

/**
 *  Borra una pelicula del archivo binario
 *  @param lista array de peliculas.
 *  @param nombre de pelicula a eliminar.
 *  @param index cantidad de elementos de la estructura.
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(char* nombre, EMovie** lista, int index)
{
    int i;

    for(i=0; i<index; i++)
    {
        if(!strcmp(lista[i]->titulo, nombre))
        {
            lista[i]->estado = 0;
            printf("\nborrado\n");
            return 0;
        }
    }
    return -1;
}

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista array de peliculas.
 *  @param nombre el nombre para el archivo.
 *  @param index cantidad de elementos de la estructura.
 */
void generarPagina(EMovie** lista, char* nombre, int index)
{
    FILE* fHtml = NULL;
    int i;

    if((fHtml = fopen(nombre, "r+"))== NULL)
    {
        if((fHtml = fopen(nombre, "w+"))== NULL)
        {
            printf("\nEl archivo no puede ser abierto");
            exit(1);
        }
    }

    fprintf(fHtml, "<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'><!-- Repetir esto para cada pelicula -->");
    for(i=0; i<index; i++)
    {
        if(lista[i]->estado ==1)
        {
            fprintf(fHtml,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s", lista[i]->linkImagen, lista[i]->titulo);
            fprintf(fHtml,"</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duración:%d", lista[i]->genero, lista[i]->puntaje, lista[i]->duracion);
            fprintf(fHtml,"</li></ul><p>%s</p></article>", lista[i]->descripcion);
        }
    }
    fprintf(fHtml, "</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");

	fclose(fHtml);

}
