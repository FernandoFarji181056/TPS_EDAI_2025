#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tp_1_recursividad.h" 
#include "tp_1_prueba.h" 


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
    char frase9[1000];

    do {
        //system("clear");

        // Ejecuta el ejercicio correspondiente
        switch (opcion) {
            case 1:

             printf("Ingrese una frase para ver si es palindromo (X para salir): \n");
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

             case 2:
             printf("Elegiste la opcion 2\n");
             recibirLlamado();
             system("pause");
             break;
             
             case 3:
             printf("Elegiste la opcion 3\n");
             system("pause");
             break;

             case 4:
             printf("Elegiste la opcion 4\n");
             system("pause");
             break;

             case 5:
             printf("Elegiste la opcion 5\n");
             system("pause");
             break;

             case 6:
             printf("Elegiste la opcion 6\n");
             system("pause");
             break;
             
             case 7:
             printf("Elegiste la opcion 7\n");
             system("pause");
             break;

             case 8:
             printf("Elegiste la opcion 8\n");
             system("pause");
             break;
             
             case 9:
                         // Declaramos variables específicas para este case
            int numero;
            bool entradaValida = false;
            
            // Ciclo de validación
            while(!entradaValida) {
                printf("Por favor ingrese un numero entero: ");
                
                // Verificamos si scanf leyó correctamente un entero
                if(scanf("%d", &numero) == 1) {
                    entradaValida = true;
                    
                    // Aquí puedes agregar más validaciones si necesitas
                    // Por ejemplo, verificar rango:
                    // if(numero >= 0 && numero <= 100) {
                    //     entradaValida = true;
                    // } else {
                    //     printf("El número debe estar entre 0 y 100\n");
                    // }
                } else {
                    printf("Error: Debe ingresar un número entero válido.\n");
                    
                    // Limpiamos el buffer de entrada para evitar bucles infinitos
                    while(getchar() != '\n');
                }
            }
            
            // Aquí ya tenemos un número válido
            printf("Numero ingresado correctamente: %d\n", numero);
            if(divisiblePor7(numero)) {
                printf("El numero %d es divisible por 7\n", numero);
            } else {
                printf("El numero %d NO es divisible por 7\n", numero);
            }
            
            // Más código específico para el case 2...
            break;

/*

             printf("Ingrese un entero para ver si es divisible por 7: \n");
             while (getchar() != '\n'); 

             fgets(frase9, 1000, stdin);            	
             int longitud9 = strlen(frase9);             
             frase9[longitud9-1]='\0'; //quita el espacio que pone fgets al final del string
             longitud9=strlen(frase9);


             if (divisiblePor7(frase9)) {
                 printf("ES divisible x 7\n");
                 system("pause");
             } else {
                 printf("NO divisible x 7\n");
                 system("pause");
             }
             break;
             system("pause");
             break;
*/


             printf("Elegiste la opcion 9\n");
             system("pause");
             break;



            default:
                printf("Opcion no validaa.\n");
                system("pause");
                break;
               
        }
        while (getchar() != '\n'); 
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
    } while (subopcion == 0); // mientras quiera seguir ejecutando el ejercicio
  
}



int main(){
    int opcion;
    char c;

     do {
        menu();
        printf("Seleccione un ejercicio: ");  
        scanf(" %d", &opcion);

        if (opcion >= 1 && opcion <= 9){
            submenu(opcion);
        } else if (opcion != 0){
            printf("Opcion invalida, vuelva a intentarlo\n");
            while((c = getchar()) != '\n' && c != EOF);
            system("pause");

        }
    } while (opcion != 0);
	
    return 0;
}
