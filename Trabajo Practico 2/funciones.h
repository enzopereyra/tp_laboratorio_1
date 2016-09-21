#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;


int obtenerEspacioLibre(EPersona lista[], int cantidad);
int buscarPorDni(EPersona lista[], int dni, int cantidad);
void cargarArray(EPersona lista[], int dato, int cantidad);

void alta(EPersona lista[], int cantidad);
void baja(EPersona lista[], int cantidad);
void ordenar(EPersona lista[], int cantidad);
void graficarEdades(EPersona lista[], int cantidad);

#endif // FUNCIONES_H_INCLUDED
