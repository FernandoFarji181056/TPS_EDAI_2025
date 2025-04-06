#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tp_1_recursividad.h" 


void menu(){
	
	int i;
	system("cls");
	printf("--------TP Recursividad--------\n");
	for (i = 1; i <=9; i++){
		printf("%d. Ejercicio %d \n", i , i);	
	}
	printf("0. Salir \n");
	
}

void submenu(int opcion){
    int subopcion;
    //int opcion;
    char frase[1000];

    do {
        //system("clear");

        // Ejecuta el ejercicio correspondiente
        switch (opcion) {
            case 1:

             printf("(main) Ingrese una frase: \n");
             while (getchar() != '\n'); 

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



            default:
                printf("Ejercicio no implementado aún.\n");
                break;
        }
/*
        // Bucle interno para validar ingreso
        do {
            printf("\n1. Desea volver a ingresar un nuevo dato?\n");
            printf("2. Volver al menu principal\n");
            printf("Ingrese una opcion: ");
            scanf("%d", &subopcion);
            getchar(); // limpia el buffer del ENTER

            if (subopcion != 1 && subopcion != 2) {
                printf("Opcion invalida. Intente nuevamente.\n\n");
            }
        } while (subopcion != 1 && subopcion != 2);
  */
    } while (subopcion == 1); // mientras quiera seguir ejecutando el ejercicio
  
}



int main(){
    int opcion;
    do {
        menu();
        printf("Seleccione un ejercicio: ");
        scanf("%d", &opcion);
		
        if (opcion >= 1 && opcion <= 9){
            submenu(opcion);
        } else if (opcion != 0){
            printf("Opcion invalida\n");
        }
    } while (opcion != 0);
	
    return 0;
}
