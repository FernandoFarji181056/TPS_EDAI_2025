#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "tp_1_recursividad.h" 
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/validaciones/headers/tp01_EJ_04.h"
#include "libs/validaciones/headers/tp1_ejercicio7.h"
#include "libs/validaciones/headers/tp01-ej-08.h"

void ejecutarProducto();

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void menu(){
	
	int i;
	system("cls");

	printf("--------TP Recursividad--------\n");
    printf("\n");
    printf("Ejercicio 1: Palindromo\n");
    printf("Ejercicio 2: Multiplicacion\n");
    printf("Ejercicio 3: Fibonacci \n");
    printf("Ejercicio 4: Division\n");
    printf("Ejercicio 5: Colocar Puntos\n");
    printf("Ejercicio 6: Ondas H L\n");
    printf("Ejercicio 7: Mafia\n");
    printf("Ejercicio 8: Subconjuntos\n");
    printf("Ejercicio 9: Divisible x 7 \n");
    printf("O Ingrese cero para salir\n");
    printf("\n");

	
}

void submenu(int opcion){
    int subopcion;
    char frase[1000];
    char frase9[1000];


        // Ejecuta el ejercicio correspondiente
        switch (opcion) {
            case 1:
            

             printf("Ingrese una frase para ver si es palindromo (X para salir): \n");
    
             fgets(frase, 1000, stdin);            	
             int longitud2 = strlen(frase);             
             frase[longitud2-1]='\0'; //quita el espacio que pone fgets al final del string
             longitud2=strlen(frase);


             if (palindromo(frase)) {
                 printf("La frase ES un palindromo\n");
                 system("pause");
             } else {
                 printf("La frase NO es un palindromo\n");
                 system("pause");
             }
             break;

             case 2:
             printf("Elegiste la opcion 2\n");   
             ejecutarProducto();
             return ;       
             system("pause");
             break;
             
             case 3:
             printf("Elegiste la opcion 3\n");
             terminoSeridFibonacci(3); //mando un numero cualquiera porque el ingreso lo pide en el .c del ejercicio
             system("pause");
             break;

             case 4:
             printf("Elegiste la opcion 4\n");
             ejecutarDivision(); //mando un numeros cualquiera porque el ingreso lo pide en el .c del ejercicio
             system("pause");
             break;

             case 5:
             printf("Elegiste la opcion 5\n");
             char numero[] = "nomandonadapideentradaenelejercicio"; 
             agregarSeparadorMiles(numero);
             system("pause");
             break;

             case 6:
             printf("Elegiste la opcion 6\n");
             char entrada[] = "nomandonadapideentradaenelejercicio"; 
             ondaDigital(entrada);
             system("pause");
             break;
             
             case 7:
             printf("Elegiste la opcion 7\n");
             ejercicio7();
             system("pause");
             break;

             case 8:
             printf("Elegiste la opcion 8\n");
             ejecutarSubconjuntos();
             system("pause");
             break;
             
             case 9:

             
                      char buffer[100];
                      int numero02;
                       bool entradaValida = false;

                     while (!entradaValida) {
                           printf("Ingrese un numero entero entre -100000 y 100000 para ver si es divisible por 7: ");

                            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                                // Elimina el salto de línea
                                buffer[strcspn(buffer, "\n")] = '\0';

                                // Puntero para saber si hay caracteres no válidos
                                char *endptr;
                                long valor = strtol(buffer, &endptr, 10);  // base 10

                                // Validamos que toda la entrada sea un número válido
                             if (*endptr == '\0') {
                                    // Validamos rango
                                 if (valor >= -100000 && valor <= 100000) {
                                     numero02 = (int)valor;
                                       entradaValida = true;
                                  } else {
                                       printf("El numero debe estar entre -100000 y 100000.\n");
                                   }
                                } else {
                                    printf("Error: debe ingresar un numero entero válido sin letras ni símbolos.\n");
                             }
                         } else {
                             printf("Error al leer la entrada.\n");
                         }
                     }

                          // Ya tenemos el número válido
                      printf("Numero ingresado correctamente: %d\n", numero02);
                      if (divisiblePor7(numero02)) {
                          printf("El numero %d es divisible por 7\n", numero02);
                      } else {
                          printf("El numero %d NO es divisible por 7\n", numero02);
                      }

                      system("pause");
                       break;
                  

            default:
                printf("Opcion no validaa.\n");
                system("pause");
                break;
               
        }
        while (getchar() != '\n');   
}



int main(){

    char buffer[100];
int opcion = 0;

     do {
        menu();
        printf("Seleccione un ejercicio: ");  

       if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        opcion = atoi(buffer);  // convierte string a int
    } else {
        opcion = -1;  // valor inválido para forzar mensaje de error
    }



        if (opcion >= 1 && opcion <= 9){
            submenu(opcion);
        } else if (opcion != 0){
            printf("Opcion invalida, vuelva a intentarlo\n");

            system("pause");

        }
    } while (opcion != 0);
	
    return 0;
}
