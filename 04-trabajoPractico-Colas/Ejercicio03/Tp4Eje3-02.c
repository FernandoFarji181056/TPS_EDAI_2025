#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "../tp_colas.h"
#include "../main_tp4.h"


void ejecutar_TP4_EJ03(){
    
    int opcion = 0;
    bool x = false;
    Cola C1 = c_crear();
    Cola C2 = c_crear();

    clearScreen();
    printf("Ejercicio 3: \n");
    printf("Ingresa 1 si desea realizar la carga manual de las colas\n");
    printf("Ingresa 2 si desea realizar la carga automatica de las colas\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        cargarColaManual(C1);
        cargarColaManual(C2);
        break;
    case 2:
        srand(time(NULL));    //para evitar tener la misma secuencia de numeros
        cargarColaAutomatica(C1);
        cargarColaAutomatica(C2);
        break;
    default:
        break;
    }

    clearScreen();
    printf("Cola 1\n");
    c_mostrar(C1);
    printf("Cola 2\n");
    c_mostrar(C2);
    
    if(c_ej3_iguales(C1, C2)){
        printf("Las colas son iguales\n");
    } else{
        printf("Las colas son distintas\n");
    }

    printf("\n");
    printf("Contenido de las colas despues del procesamiento\n");
    printf("Cola 1\n");
    c_mostrar(C1);
    printf("Cola 2\n");
    c_mostrar(C2);
    printf("\n");
    printf("La complejidad del algoritmica de esta implementacion es de O(n) donde n es la cantidad de elementos de las colas\n");
    system("pause");

}