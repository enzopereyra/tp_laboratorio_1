#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[20];
    char genero[20];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[400];
    int estado;
}EMovie;


int agregarPelicula(EMovie* movie);
int borrarPelicula(char* nombre, EMovie** lista, int index);
void generarPagina(EMovie** lista, char* nombre, int index);


#endif // FUNCIONES_H_INCLUDED
