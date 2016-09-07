#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float resultado, numero1=0, numero2=0;

    while(seguir=='s')
    {
        system("cls");
        printf("1- Ingresar 1er operando (A = %.2f)\n", numero1);
        printf("2- Ingresar 2do operando (B = %.2f)\n", numero2);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                numero1 = numeroIngresado();
                break;
            case 2:
                numero2 = numeroIngresado();
                break;
            case 3:
                resultado = sumar(numero1, numero2);
                mostrar(resultado, "suma");
                break;
            case 4:
                resultado = restar(numero1, numero2);
                mostrar(resultado, "resta");
                break;
            case 5:
                resultado = dividir(numero1, numero2);
                mostrar(resultado, "divicion");
                break;
            case 6:
                resultado = multiplicar(numero1, numero2);
                mostrar(resultado, "multiplicacion");
                break;
            case 7:
                resultado = factoriar((int)numero1);
                mostrar(resultado, "factorizacion");
                break;
            case 8:
                todasLasOperaciones(numero1, numero2);
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }
    return 0;
}
