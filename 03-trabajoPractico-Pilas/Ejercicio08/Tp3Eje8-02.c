#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"
#include "libs/pilas/headers/main_tp3.h"

/**
8.	Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los valores (sin repetición) y la cantidad de veces que aparecen.
	No debe perderse la pila original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves unicas (no deben existir repetidas) y por cada una la cantidad de veces que aparecia en la Pila recibida por parametro
// Si la pila estavacia retorna pila vacia.

void p_mostrar_con_valor(Pila p){
    if (p_es_vacia(p)) {
        printf("PILA VACIA !!! \n");
        return;
    }

    Pila Paux = p_crear();
    TipoElemento X = te_crear(0);

    printf("Contenido de la pila: ");

    // Recorro la pila desapilandola y pasandola al auxiliar
    while (p_es_vacia(p) != true) {
        X = p_desapilar(p);
        printf("%d:%d ", X->clave, *(int*)X->valor);
        p_apilar(Paux, X);
    }

    // Recorro la pila auxiliar para pasarla a la original
    while (p_es_vacia(Paux) != true) {
        X = p_desapilar(Paux);
        p_apilar(p, X);
    }

    printf("\n");
}

void ejecutar_TP3_EJ08(){
    int opcion = 0;
    Pila P1 = p_crear();
    bool x = false;
    Pila Presultado;

    clearScreen();
    printf("Ejercicio 8: \n");
    printf("Ingresa 1 si desea realizar la carga manual de la pila\n");
    printf("Ingresa 2 si desea realizar la carga automatica de la pila\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        cargarPilaManual(P1);
        break;
    case 2:
        srand(time(NULL));    //para evitar tener la misma secuencia de numeros
        cargarPilaAutomatica(P1);
        break;
    default:
        break;
    }

    clearScreen();
    printf("Pila 1\n");
    p_mostrar(P1);
    
    Presultado = p_ej8_sacarrepetidos(P1);
    printf("\n");
    printf("Contenido de las pilas despues del procesamiento\n");
    printf("Pila 1\n");
    p_mostrar(P1);
    printf("Pila resultado\n");
    p_mostrar_con_valor(Presultado);
    printf("\n");
    printf("La complejidad del algoritmica de esta implementacion es de O(n^2) donde n es la cantidad de elementos de la pila, se recorre la pila y por cada elemento debo verificar si ya existe esa clave en mi resultado\n");
    system("pause");
}