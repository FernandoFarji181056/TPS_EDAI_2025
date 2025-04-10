#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/validaciones/headers/tp01_EJ_04.h"

// ----- FUNCIONES DE VALIDACION ----- //







float division(int m, int n)
{
    static int contador = 0;

    //Caso base cuando m < n
    if (m < n)
    {
        //La division es exacta no hay decimales
        if (m == 0) return 0;
        //else printf("RESTO= %d\n", m); return 0;
        
        if (m < n)
        {
            //Contador hace de flag para saber cuando parar la recursion
            contador++;

            //Multiplico m * 10 porque para calcular los decimales hay que agregar un 0 adelante del resto
            m = m*10;
            //Cuando m-n llego a un resultado que es menor a n, se divide por 10
            return  division(m,n) / 10;
        }
   
    }
    else
    {
        //El 1 va sumando la cantida de veces que se llama la funcion
        //por lo que cuando retorna retorna el total de llamadas
        if (contador == 0) return (1 + division(m-n,n)); 

        
        if (contador > 0)
        {
            if (contador > 4) return 0;
            return  1 + division(m-n,n); //Sumo la cantidad de veces que se resto m-n
        }
        
    }
}



//float division(int m, int n){
//int main()
//{
    //int m =2;
    //int n = -3;
    void ejecutarDivision(void) {

    int longitud,m,n;
    float resultado;
    bool negativo = false;

    //---------- INGRESO Y VALIDACION DE DATOS ----------//

    char* dividendo = (char*) malloc(50 * sizeof(char));
    char* divisor = (char*) malloc(50 * sizeof(char));
    char* numero_validado = (char*) malloc(11 * sizeof(char));
    bool esValido1 = false;
    bool esValido2 = false;

    printf("---------- Multiplicacion recursiva ----------\n\n");
    
    
    while (!esValido1 || !esValido2) //Mientras esValido sea falso entra al while
    {
        //Ingreso primer numero (multiplicando)
        if (esValido1 == false)
        {
            printf("Ingrese el dividendo (X para salir): ");
            gets(dividendo);
            //Condicion de salida
            if ((dividendo[0] == 88  || dividendo[0] == 120) && strlen(dividendo) == 1){ system("pause"); return;}
        }

        if (validarEntero(dividendo) || esValido1)
        {
            esValido1 = true;
            //Pido numero 2
            printf("Ingrese el divisor (X para salir): ");
            gets(divisor);

            //Condicion de salida
            if ((divisor[0] == 88  || divisor[0] == 120) && strlen(divisor) == 1) break;

            if (validarEntero(divisor))
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
            m = strtol(dividendo,NULL,10);
            n = strtol(divisor,NULL,10);

            if (m == __LONG_MAX__ || n == __LONG_MAX__)
            {
                esValido1 = false;
                esValido2 = false;
                printf("Los numeros ingresados fueron demasiado altos\n");
            }
        }
     

    }

    // ----- CONTROL DE NUMEROS NEGATIVOS ----- //
    
    if (m < 0 && n >= 0) //Si M es negativo se pasa a positivo
    {
        m = m*-1;
        resultado = division(m,n);
        negativo = true;
    }
    else if (n < 0 && m >= 0)//Si N es negativo se pasa a positivo
    {
        n = n*-1;
        resultado = division(m,n);
        negativo = true;
    }
    else if (n < 0 && m < 0) //Si AMBOS son negativos se pasan a positivo
    {
        m = m*-1;
        n = n*-1;
        resultado = division(m,n);
        
    }
    else //Si no cumple ninguna condicion por descarte son positivos
    {
        resultado = division(m,n);
    }
    // ----- CONTROL DE NUMEROS NEGATIVOS ----- //  


    if (negativo)
    {
        //Con %.4f limito los decimales a 4
        printf("El resultado de dividir %d/%d = -%.4f\n", m,n,resultado);
    }
    else
    {
        //Con %.4f limito los decimales a 4
        printf("El resultado de dividir %d/%d = %.4f\n", m,n,resultado);
    }


    system("pause");
    return;
}