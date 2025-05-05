#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/listas/headers/main_tp3.h"
#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/Tp_2_listas.h"
#include "libs/tipoElemento/headers/tipo_elemento.h"



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

        // Ejecuta el ejercicio correspondiente
        switch (opcion) {
            case 0:

            printf("Elegiste la opcion 0\n");   
                 system("pause");
                 exit(0);
             
             break;
               
             case 2:
             printf("Elegiste la opcion 2\n");
             printf("Presiona ENTER para ir al ejercicio elegido\n");
             system("pause");
             ejecutar_TP2_EJ02();

             return ;       
             system("pause");
             break;
             
             case 3:             
             printf("Elegiste la opcion 3\n");
             printf("Presiona ENTER para ir al ejercicio elegido\n");
             system("pause");
             ejecutar_TP2_EJ03();
             break;

             case 4:
             printf("Elegiste la opcion 4\n");
             printf("Presiona ENTER para ir al ejercicio elegido\n");
             system("pause");
             ejecutar_TP2_EJ04();       
             break;

             case 5:
             printf("Elegiste la opcion 5\n");
             printf("Presiona ENTER para ir al ejercicio elegido\n");
             system("pause");
             ejecutar_TP2_EJ05();             
             system("pause");
             break;

             case 6:
             printf("Elegiste la opcion 6\n");
             printf("Presiona ENTER para ir al ejercicio elegido\n");
             system("pause");
             ejecutar_TP2_EJ06();
             //system("pause");   
             break;
                  

            default:
                printf("Opcion no valida.\n\n");
                system("pause");
                break;
               
        }
       // while (getchar() != '\n');   
}



int main(){
   
    char ingreso[1000];

    menu();
    printf("Ingrese un numero del 2 al 6\n");
    fgets(ingreso, 1000, stdin);            	
    int longitud = strlen(ingreso);             
    ingreso[longitud-1]='\0'; //quita el espacio que pone fgets al final del string
    longitud=strlen(ingreso);

    if (validarEntero(ingreso))
    {
       // printf("Ingreso de numero de ejercicio CORRECTO\n\n");
        
        int opcion = atoi(ingreso);
        submenu(opcion);
        

    }
    else {
        printf("Ingreso NO valido\n");

    }
    system("pause");

	
    return 0;
}
