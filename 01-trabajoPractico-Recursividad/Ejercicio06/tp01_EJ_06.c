#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "libs/validaciones/headers/Validacion_datos.h"




//void ondaDigital(char*, int,int);
void graficarOndaDigital(char*, int, int); 

void graficarOndaDigital(char* senial, int longitud, int n)
{
    //Tengo un array char ['L','H','L']
    //Leo el array

    //Caso base cuando longitud llega a 1

    if (longitud == -1)
    {
        printf("\n");
        return;
    }
    else
    {
        if (senial[n] == 'L'){
            printf("_");
        }

        if (senial[n] == 'H'){
            //printf("%c", 196); //codigo ascii —
            printf("-");
            
        }

        if (longitud > 1 && senial[n+1] != senial[n] && (senial[n] == 'L' || senial[n] == 'H'))
        {
            printf("%c", 173); //codigo ascii de |
        }


        return graficarOndaDigital(senial, longitud -1, n + 1);
    }

}



//int main()
char *ondaDigital(char seniales[])
{

    int i;
    char* senial = (char*) malloc(50 * sizeof(char));
    char* senial_procesada;
    int longitud;
    bool esValido = false;
    bool esValido2 = true;


    //INPUT DE DATOS
    while (esValido == false)
    {
        esValido2 = true;
        printf("Ingrese L (low) o H (High) para graficar una onda digital (X para salir): ");
        gets(senial);
        longitud = strlen(senial);

        //Si el texto ingresado es mas largo que lo que admite el array lo informa
        //y vuelve a pedir un texto
        if (longitud > 49){ printf("Excedio el limite de caracteres\n"); esValido2 = false;}

        //Si el texto ingresado es una "x" o "X" y solamente se ingreso una letra
        //Sale del programa
        if ((senial[0] == 88  || senial[0] == 120) && longitud == 1) break;
        
        senial = pasarAMayuscula(senial);
        senial = sacarEspacios(senial);
        longitud = strlen(senial);
        //Hago un FOR
        for (i = 0; i < longitud; i++)
        {
            if (senial[i] != 'L' && senial[i] != 'H')
            {
                esValido2 = false;
            }

        }

        if (validarLetras(senial) && longitud >= 1 && longitud < 49 && esValido2 == true)
        {

            longitud = strlen(senial);
            graficarOndaDigital(senial,longitud,0);

        }
        else
        {
            printf("ERROR solo puede ingresar L y H. El limite de caracteres es de 50, tampoco ingrese numeros ni caracteres especiales.\n");
        }



    }

    system("pause");
    return NULL;
}