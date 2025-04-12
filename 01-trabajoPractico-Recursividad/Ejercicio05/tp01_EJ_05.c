#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "libs/validaciones/headers/Validacion_datos.h"



char* quitarCerosIzquierda(char* numero)
{
    char* numero_Sin_cero = (char*) malloc(50 * sizeof(char));

    //Lo convierto a entero
    int x = strtol(numero,NULL,10);
    //Lo vuelvo a convertir a char array
    sprintf(numero_Sin_cero,"%d", x);
    int longitud = strlen(numero_Sin_cero);
    numero_Sin_cero[longitud] = 0;

    return numero_Sin_cero;
}


void SeparardorMiles(char* , int ,char*, int );


void SeparadorMiles(char* numero, int longitud, char* resultado, int n)
{
    //El flag lo que va a hacer es darse cuenta cuando poner la coma.
    //Cada vez que llegue a 3 pone una coma
    static int flag = 1;
    //Caso base
    if (longitud == 0){
        resultado[n] = 0; //Pongo ultimo caracter de fin de linea
        return;
    }
    else
    {
        if (flag > 3) //Cada 3 numeros pone una coma
        { 
            //Si se contaron 3 numeros agrego la coma
            resultado[n] = '.';
            flag = 1;
            return SeparadorMiles(numero, longitud,resultado,n+1);

        }
        else
        {
            //Arranco de atras para delante
            resultado[n] = numero[longitud-1];
            flag++;
            return SeparadorMiles(numero,longitud-1,resultado,n+1);

        }

        

    }


}

char * agregarSeparadorMiles(char numero[])
//int main()
{




    int i,longitud;
    char* numero3 = (char*) malloc(50 * sizeof(char));
    char* numero2 = (char*) malloc(100 * sizeof(char));
    bool esValido = false;
    printf("----- Colocar separador -----\n");


    while (!esValido) //Mientras esValido sea false
    {

        printf("Ingrese un Numero (X para salir): ");
        gets(numero3);
        longitud = strlen(numero3);

        //Condicion de salida
        if ((numero3[0] == 88  || numero3[0] == 120) && longitud == 1) break;

        //Validaciones
        if (validarEntero(numero3) && longitud < 10 && numero3[0] != 32)
        {
            //Elimino los 0 de adelante
            numero3 = quitarCerosIzquierda(numero3);
            longitud = strlen(numero3);
            esValido = true;
        }
        else
        {
            printf("Error en el ingreso de datos. No ingrese numeros de mas de 10 caracteres.\nTampoco pueden contener espacios, puntos o comas.\n");
        }


    }

    SeparadorMiles(numero3,longitud,numero2,0);
    longitud = strlen(numero2);
    //Imprimo el numero invertido
    for (i = longitud; i >= 0; i--)
    {
        printf("%c", numero2[i]);
    }

    printf("\nFin de programa.\n");
    system("pause");
    return 0;
}