#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "../tp_colas.h"
#include "../main_tp4.h"


void ejecutar_TP4_EJ04(){
    
    int opcion = 0;
    bool x = false;
    Cola C1 = c_crear();
    Cola Caux;

    clearScreen();
    printf("Ejercicio 4: \n");
    printf("Ingresa 1 si desea realizar la carga manual de la cola\n");
    printf("Ingresa 2 si desea realizar la carga automatica de la cola\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        cargarColaManual(C1);
        break;
    case 2:
        srand(time(NULL));    //para evitar tener la misma secuencia de numeros
        cargarColaAutomatica(C1);
        break;
    default:
        break;
    }

    clearScreen();
    printf("Cola 1\n");
    c_mostrar(C1);
    
    Caux = c_ej4_colanorepetidos(C1);
    printf("Cola con las claves que no tienen repeticiones\n");
    c_mostrar(Caux);
    printf("\n");
    printf("Contenido de la cola original despues del procesamiento\n");
    c_mostrar(C1);
    printf("\n");
    printf("La complejidad del algoritmica de esta implementacion es de O(n^2) donde n es la cantidad de elementos de las colas, esto porque por cada elemento se recorre toda la cola nuevamente\n");
    system("pause");

}