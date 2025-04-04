#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <TP0_Bis.h>


double sumar(double x, double y)
{
    return x + y;
}

double restar(double x, double y)
{
    double resultado = x - y;
    return resultado;
}

double dividir(double x, double y)
{
    return (x / y);
}

double potencia(double x, double y)
{
    x = (double) x;
    y = (double) y;
    return pow(x,y);
}

enum Comparacion Comparar(struct NumeroRacional racional)
{
    if (racional.x > racional.y)
    {
        return MAYOR;
    }
    else if (racional.x < racional.y)
    {
        return MENOR;
    }
    else
    {
        return IGUAL;
    }
    
}



int main()
{

    struct NumeroRacional racionales = {2,3};
    enum Comparacion ResultadoComparacion;

    double x = 2;
    double y = 3;

    double resultado;

    resultado = sumar(x,y);
    printf("Suma %f + %f = %f\n", x,y,resultado);
    
    resultado = restar(x,y);
    printf("Resta %f - %f = %f\n", x,y,resultado);

    resultado = dividir(x,y);
    printf("Division %f / %f = %f\n", x,y,resultado);

    resultado = potencia(x,y);
    printf("Potenciacion %f - %f = %f\n", x,y,resultado);

    ResultadoComparacion = Comparar(racionales);

    if (ResultadoComparacion == MAYOR)     printf("Comparacion %f con %f = MAYOR\n", racionales.x,racionales.y, ResultadoComparacion);
    if (ResultadoComparacion == MENOR)     printf("Comparacion %f con %f = MENOR\n", racionales.x,racionales.y, ResultadoComparacion);
    if (ResultadoComparacion == IGUAL)     printf("Comparacion %f con %f = IGUAL\n", racionales.x,racionales.y, ResultadoComparacion);


    system("pause");
    return 0;

}