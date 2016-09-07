#include<stdio.h>

/** \brief Solita un numero al usuario y lo devuelve
 *
 * \param No recibe ningun parametro
 * \return El numero ingresao por el resultado
 *
 */
float numeroIngresado(void)
{
    float numero;

    printf("Ingresar un numero: ");
    scanf("%f", &numero);

    return numero;
}
/** \brief Muestra un mensaje por pantalla
 *
 * \param resultado Recibe el mensaje a ser mostrado
 * \return No retorna resultado
 *
 */
void mostrar(float resultado, char operacion[])
{
    printf("El resultado de la %s es: %.3f\n", operacion, resultado);
    system("pause");
    return;
}
/** \brief Solicita dos numeros los suma y los devuelve
 *
 * \param numero1 Es uno de los parametros a sumar
 * \param numero2 Es uno de los parametros a sumar
 * \return La suma de dichos numeros
 *
 */
float sumar(float numero1, float numero2)
{
    return (numero1 + numero2);
}

/** \brief Solicita dos numeros los resta y los devuelve
 *
 * \param numero1 Es uno de los parametros a restar
 * \param numero2 Es uno de los parametros a restar
 * \return La resta de dichos numeros
 *
 */
float restar(float numero1, float numero2)
{
    return (numero1 - numero2);
}

/** \brief Solicita dos numeros los divides y los devuelve
 *
 * \param numero1 Es uno de los parametros a dividir
 * \param numero2 Es uno de los parametros a dividir
 * \return La division de dichos numeros
 *
 */
float dividir(float numero1, float numero2)
{
    while(numero2 == 0)
    {
        printf("No se puede dividir por cero, Reingrese\n");
        numero2 = numeroIngresado();
    }

    return (numero1 / numero2);
}

/** \brief Solicita dos numeros los multiplica y los devuelve
 *
 * \param numero1 Es uno de los parametros a multiplicar
 * \param numero2 Es uno de los parametros a multiplicar
 * \return La multiplicacion de dichos numeros
 *
 */
float multiplicar(float numero1, float numero2)
{
    return (numero1 * numero2);
}

/** \brief Solicita un numero y devuelve el factorial
 *
 * \param numero Es el parametro a factoriar
 * \return El resultado de factoriar
 *
 */
int factoriar(int numero)
{
    int resultado = 1, i;

    for (i=numero; i>0; i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}

/** \brief Solicita dos numeros y realiza todas las operaciones anteriores
 *
 * \param numero1 Es uno de los parametros
 * \param numero2 Es uno de los parametros
 * \return No retorna resultado
 *
 */
void todasLasOperaciones(float numero1, float numero2)
{
    mostrar(sumar(numero1, numero2), "suma");
    mostrar(restar(numero1, numero2), "resta");
    mostrar(dividir(numero1, numero2), "divicion");
    mostrar(multiplicar(numero1, numero2), "multiplicacion");
    mostrar(factoriar(numero1), "factorizacion");
}
