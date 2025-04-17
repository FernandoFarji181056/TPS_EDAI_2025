#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "libs/validaciones/headers/Validacion_datos.h"

/*
#include "tp_1_recursividad.h" 
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/validaciones/headers/tp01_EJ_04.h"
#include "libs/validaciones/headers/tp1_ejercicio7.h"
#include "libs/validaciones/headers/tp01-ej-08.h"
*/


void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


void menu(){
	
	int i;
	//system("cls");

	printf("--------TP02 Listas--------\n");
    printf("\n");
    printf("Ejercicio 2: \n");
    printf("Ejercicio 3: Multiplo\n");
    printf("Ejercicio 4: Comparacion\n");
    printf("Ejercicio 5: Polinomio\n");
    printf("Ejercicio 6: Sublista\n");
    printf("O Ingrese cero para salir\n");
    printf("\n");

	
}

void submenu(int opcion){
    //int subopcion;
    //char frase[1000];
    //char frase9[1000];


        // Ejecuta el ejercicio correspondiente
        switch (opcion) {
            case 1:

            printf("Elegiste la opcion 1\n");   
                 system("pause");
             
             break;

             case 2:
             printf("Elegiste la opcion 2\n");   
            // ejecutarProducto();
             return ;       
             system("pause");
             break;
             
             case 3:
             printf("Elegiste la opcion 3\n");
            // terminoSeridFibonacci(3); //mando un numero cualquiera porque el ingreso lo pide en el .c del ejercicio
            // system("pause");
             break;

             case 4:
             printf("Elegiste la opcion 4\n");
           //  ejecutarDivision(); //mando un numeros cualquiera porque el ingreso lo pide en el .c del ejercicio
             system("pause");
             exit(0);
             break;

             case 5:
             printf("Elegiste la opcion 5\n");
             char numero[] = "nomandonadapideentradaenelejercicio"; 
          //   agregarSeparadorMiles(numero);
             system("pause");
             break;

             case 6:
             printf("Elegiste la opcion 6\n");
             char entrada[] = "nomandonadapideentradaenelejercicio"; 
           //  ondaDigital(entrada);
             system("pause");
             break;
             
             case 7:
             printf("Elegiste la opcion 7\n");
         //    ejercicio7();
             system("pause");
             break;

             case 8:
             printf("Elegiste la opcion 8\n");
           //  ejecutarSubconjuntos();
             system("pause");
             break;
             
             case 9:             
             printf("Elegiste la opcion 9\n");

                      system("pause");
                       break;
                  

            default:
                printf("Opcion no validaa.\n");
                system("pause");
                break;
               
        }
       // while (getchar() != '\n');   
}



int main(){
   
    char ingreso[1000];

    menu();

    fgets(ingreso, 1000, stdin);            	
    int longitud = strlen(ingreso);             
    ingreso[longitud-1]='\0'; //quita el espacio que pone fgets al final del string
    longitud=strlen(ingreso);

    if (validarEntero(ingreso))
    {
        printf("Ingreso valido\n");
        int opcion = atoi(ingreso);
        submenu(opcion);
        

    }
    else {
        printf("Ingreso NO valido\n");

    }
    system("pause");

	
    return 0;
}
