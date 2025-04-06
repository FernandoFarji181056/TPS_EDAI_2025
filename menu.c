#include <stdio.h>
#include <stdlib.h>
//#include "tp1-1.h"


void menu(){
	
	int i;
	system("clear");
	printf("--------TP Recursividad--------\n");
	for (i = 1; i <=9; i++){
		printf("%d. Ejercicio %d \n", i , i);	
	}
	printf("0. Salir \n");
	
}

void submenu(int opcion){
    int subopcion;

    do {
        system("clear");

        // Ejecuta el ejercicio correspondiente
        switch (opcion) {
            case 1:
                //ejecutar_tp1();
                break;
            default:
                printf("Ejercicio no implementado aún.\n");
                break;
        }

        // Bucle interno para validar ingreso
        do {
            printf("\n1. ¿Desea volver a ingresar un nuevo dato?\n");
            printf("2. Volver al menú principal\n");
            printf("Ingrese una opción: ");
            scanf("%d", &subopcion);
            getchar(); // limpia el buffer del ENTER

            if (subopcion != 1 && subopcion != 2) {
                printf("Opción inválida. Intente nuevamente.\n\n");
            }
        } while (subopcion != 1 && subopcion != 2);

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
            printf("Opción inválida\n");
        }
    } while (opcion != 0);
	
    return 0;
}
