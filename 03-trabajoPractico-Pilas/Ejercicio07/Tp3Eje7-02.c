#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"
#include "libs/pilas/headers/main_tp3.h"

/*
7. Dada dos pilas realizar una función que permita determinar los elementos que tienen
en común. Debe retornar una nueva pila con esos elementos (que están en ambas
pilas) sin perder las pilas originales. Determinar la complejidad algorítmica de la
solución.
Ejemplo: si “P1” contiene (1, 4, 7, 9, 8) y “P2” contiene (4,1,6,9,3) el resultado será la
pila “PR” = (1,4,9).
*/

// retornar la nueva pila con las claves en comun de ambas Pilas recibidas por parametro. Si no hay claves en comun retornar una pila vacia.

void ejecutar_TP3_EJ07(){
    int opcion = 0;
    Pila P1 = p_crear();
    Pila P2 = p_crear();
    bool x = false;
    Pila Presultado;

    clearScreen();
    printf("Ejercicio 7: \n");
    printf("Ingresa 1 si desea realizar la carga manual de las pilas\n");
    printf("Ingresa 2 si desea realizar la carga automatica de las pilas\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        cargarPilaManual(P1);
        cargarPilaManual(P2);
        break;
    case 2:
        srand(time(NULL));    //para evitar tener la misma secuencia de numeros
        cargarPilaAutomatica(P1);
        cargarPilaAutomatica(P2);
        break;
    default:
        break;
    }

    clearScreen();
    printf("Pila 1\n");
    p_mostrar(P1);
    printf("Pila 2\n");
    p_mostrar(P2);
    
    Presultado = p_ej7_elementoscomunes(P1, P2);
    printf("\n");
    printf("Contenido de las pilas despues del procesamiento\n");
    printf("Pila 1\n");
    p_mostrar(P1);
    printf("Pila 2\n");
    p_mostrar(P2);
    printf("Pila resultado\n");
    p_mostrar(Presultado);
    printf("\n");
    printf("La complejidad del algoritmica de esta implementacion es de O(n^2) donde n es la cantidad de elementos de las pilas, se recorre la pila 1 y por cada elemento se recorre la pila 2\n");
    system("pause");
}