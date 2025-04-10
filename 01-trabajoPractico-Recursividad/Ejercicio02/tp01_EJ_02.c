/*
    Dados dos números enteros m y n, construir una función recursiva que devuelva el 
    producto de ambos, calculando el mismo como sumas sucesivas. Esto es: 
    m*n=m+m+...+m, n veces. 
    Ejemplos: 
    producto(5, 3) => 15 
    producto (10, 4) => 40 
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h> 
#include "libs/validaciones/headers/Validacion_datos.h"




//Prototipo de la funcion
int producto(int m, int n);


int producto(int m, int n)
{
    //Casos bases:
    //1) cuando N es igual a 0 quiere decir que ya se hicieron todas las sumas
    if (n == 0)
    {    
        return 0;
    }
    else
    {
        return (m + producto(m,n-1));
    }

}


//int main()
void ejecutarProducto()
{

    int x,y;
    int resultado;
    char* numero1 = (char*) malloc(50 * sizeof(char));
    char* numero2 = (char*) malloc(50 * sizeof(char));
    char* numero_validado = (char*) malloc(11 * sizeof(char));
    bool esValido1 = false;
    bool esValido2 = false;
    bool esNegativo = false;

    printf("---------- Multiplicacion recursiva ----------\n\n");
    
    
    while (!esValido1 || !esValido2) //Mientras esValido sea falso entra al while
    {
        //Ingreso primer numero (multiplicando)
        if (esValido1 == false)
        {
            printf("Ingrese el multiplicando (X para salir): ");
            gets(numero1);
            //Condicion de salida
            if ((numero1[0] == 88  || numero1[0] == 120) && strlen(numero1) == 1){ system("pause"); return ;}
        }

        if (validarEntero(numero1) || esValido1)
        {
            esValido1 = true;
            //Pido numero 2
            printf("Ingrese el multiplicador (X para salir): ");
            gets(numero2);

            //Condicion de salida
            if ((numero2[0] == 88  || numero2[0] == 120) && strlen(numero2) == 1) break;

            if (validarEntero(numero2))
            {
                esValido2 = true;
            }
            else
            {
                printf("Error en el dato ingresado. Vuelva a ingresar los datos\n");
            }        
        }
        else
        {
            printf("Error en el dato ingresado. Vuelva a ingresar los datos\n");
        } 


        if (esValido1 && esValido2)
        {
            x = strtol(numero1,NULL,10);
            y = strtol(numero2,NULL,10);

            if (x == __LONG_MAX__ || y == __LONG_MAX__)
            {
                esValido1 = false;
                esValido2 = false;
                printf("Los numeros ingresados fueron demasiado altos\n");
            }
        }
     

    }


    // ----- CONTROL DE NUMEROS NEGATIVOS ----- //

    if (x < 0 && y >= 0)
    {
        x = x*-1;
        resultado = producto(x,y);
        if (resultado != 0) esNegativo = true;
    }
    else if(y < 0 && x >= 0)
    {
        y = y*-1;
        resultado = producto(x,y);
        if (resultado != 0) esNegativo = true;
    }
    else if (x < 0 && y < 0)
    {
        x = x*-1;
        y = y*-1;
        resultado = producto(x,y);

    }
    else
    {
        resultado = producto(x,y);
    }

    
    if (esNegativo)
    {
        printf("Resultado: -%d\n",resultado);
    }
    else
    {
        printf("Resultado: %d\n",resultado);
    }
    
    

    system("pause");
    return ;
}
