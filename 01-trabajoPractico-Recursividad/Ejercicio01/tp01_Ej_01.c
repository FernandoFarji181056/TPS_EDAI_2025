#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libs/validaciones/headers/Validacion_datos.h"



//Funcion prototipo
bool palindromo02(char* palabra, int longitud, int comienzo);

//Desarrollo la funcion
bool palindromo02(char* palabra, int longitud, int comienzo)
{

    //Caso base cuando longitud llega a 0
    if (longitud == 0)
    {
        return true; //la palabra es palindromo
    }
    else
    {
        if (palabra[comienzo] == palabra[longitud-1])
        {
            palindromo02(palabra,longitud-1,comienzo+1);// FUNCION RECURSIVA
        }
        else{
            return false; //La palabra NO es palindromo
        }
    }
}


/*

*/
bool palindromo(char *cadena) {
    int longitud;
    char* palabra = (char*) malloc(50 * sizeof(char));
    char* palabra_procesada = (char*) malloc(50 * sizeof(char));
    bool esValido = false;
    bool esPalindromo = false;
    strcpy(palabra, cadena);

    while (esValido == false){
        longitud = strlen(palabra);

        //Si el texto ingresado es mas largo que lo que admite el array lo informa
        //y vuelve a pedir un texto
        if (longitud > 49)   { 
            printf("Excedio el limite de caracteres, vuelva a intentarlo cuando quiera, gracias.\n");
            system("pause");
            break;
           }

        //Si el texto ingresado es una "x" o "X" y solamente se ingreso una letra
        //Sale del programa
        if ((palabra[0] == 88  || palabra[0] == 120) && longitud == 1){ 
            printf("Gracias, vuelva cuando quiera.\n");
            system("pause");           
            break;}

//   Uso la funcion "validarLetras" para ver que solo se hayan ingresados
         //   caracteres alfabeticos. Caracteres numericos y especiales (como tildes, comas, guines)
         //   se devuelve como erroneo. 
         //   Si el input empieza con un 'espacio' tambien devuelve error
        



         if (validarLetras(palabra) && longitud > 1 && longitud < 49 && palabra[0] != 32)
         {
             
                 //Paso toda la oracion a mayusculas para que los caracteres a comparar
              //   sean iguales
             
             palabra_procesada = pasarAMayuscula(palabra);
        
             
              //   Calculo la longitud del array ya procesado sin espacios
               //  y compruebo que sea palindromo
             
 
             longitud = strlen(palabra_procesada);
             esPalindromo = palindromo02(palabra_procesada,longitud,0);
 
             if (esPalindromo){ 
               // printf("Es palindromo-que pasa\n");
                return true;
            }
             else {
                //printf("No es palindromo-que pasa\n");
                return false;
            }
 
         }
         else
         {
             printf("Entrada incorrecta, no puede ingresar numeros, espacios ni caracteres especiales. Vuelva a intentarlo\n");
             system("pause");
             break;
         }

    }


    }//cierro while
