#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"

/*
Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la
clave), sin destruirlas. Utilizar para la resolución del problema una única pila auxiliar.
Determinar la complejidad algorítmica de la solución.
*/

void ejecutar_TP3_EJ03(){
    int opcion = 0;
    Pila P1 = p_crear();
    Pila P2 = p_crear();
    bool x = false;

    clearScreen();
    printf("Ejercicio 3: \n");
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
    if (p_ej3_iguales(P1, P2)){
        printf("Las pilas son iguales\n");
    } else printf("Las pilas son distintas\n");
    printf("La complejidad del algoritmica de esta implementacion es de O(n) donde n es la cantidad de elementos de las pilas\n");
    printf("\n");
    printf("Contenido de las pilas despues del procesamiento\n");
    printf("Pila 1\n");
    p_mostrar(P1);
    printf("Pila 2\n");
    p_mostrar(P2);
    system("pause");
}