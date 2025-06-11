#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "libs/listas/headers/listas.h"
#include "libs/pilas/headers/pilas.h"
#include "../tp_colas.h"
#include "../main_tp4.h"
#include "libs/pilas/headers/main_tp3.h"

static const int num_min = 0;
static const int num_max = 20;

void l_mostrar_con_void(Lista lista){
    printf("Contenido de la lista resultado: ");

    if (l_es_vacia(lista)) {
        printf("LISTA VACIA !!! \n");
        return;
    }

    Iterador ite = iterador(lista);
    TipoElemento te;
    while (hay_siguiente(ite)){
        te = siguiente(ite);
        printf("%d:%s ", te->clave, (char*)te->valor);
    }
    printf("\n");
}

bool cargarPila(Pila P1) {
    int entero;
    bool x = false;
    TipoElemento te;

    while (!p_es_llena(P1) && !x){
        clearScreen();
        printf("Contenido de la pila: ");
        p_mostrar(P1);
        printf("Ingrese un numero entero entre %d y %d o ingrese 'X' para finalizar: \n", num_min, num_max);
        entero = ingresaEnteroTeclado(&x);
        if (!x && (entero >= num_min && entero <= num_max)) {
            te = te_crear(entero);
            p_apilar(P1, te);
        }
    }
    return true;
}

bool cargarPilaRandom(Pila P1) {
    int entero;
    TipoElemento te;

    while (!p_es_llena(P1)){
        te = te_crear(rand() % (num_max - num_min + 1) + num_min); //aleatorio entre num_min y num_max
        p_apilar(P1, te);
    }
    return true;
}


void ejecutar_TP4_EJ06(){
    
    int opcion = 0;
    bool x = false;
    Cola C1 = c_crear();
    Pila P1 = p_crear();
    Lista L1 = l_crear();
    Cola Caux;

    clearScreen();
    printf("Ejercicio 6: \n");
    printf("Ingresa 1 si desea realizar la carga manual de la pila y cola\n");
    printf("Ingresa 2 si desea realizar la carga automatica de la pila y cola\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        cargarPila(P1);
        cargarColaManual(C1);
        break;
    case 2:
        srand(time(NULL));    //para evitar tener la misma secuencia de numeros
        cargarPilaRandom(P1);
        cargarColaAutomatica(C1);
        break;
    default:
        break;
    }

    clearScreen();
    printf("Lista con los valores en comun\n");
    L1 = c_ej6_comunesapilaycola(P1, C1);
    l_mostrar_con_void(L1);
    printf("\n");
    printf("La complejidad del algoritmica de esta implementacion es de O(n^2) porque se recorre la pila y por cada elemento debemos recorrer la cola\n");
    printf("\n");
    p_mostrar(P1);
    printf("\n");
    c_mostrar(C1);
    system("pause");

}