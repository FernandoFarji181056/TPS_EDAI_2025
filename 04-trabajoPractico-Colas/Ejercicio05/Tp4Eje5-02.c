#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "libs/listas/headers/listas.h"
#include "../tp_colas.h"
#include "../main_tp4.h"

void c_mostrar_con_divisores(Cola c){
    if (c_es_vacia(c)) {
        printf("COLA VACIA !!! \n");
        return;
    }

    Cola Caux = c_crear();
    TipoElemento X = te_crear(0);

    printf("Contenido de la cola de divisores: \n");

    // La cola se debe desencolar y guardar en una auxiliar
    while (c_es_vacia(c) != true) {
        X = c_desencolar(c);
        if (*(bool*)X->valor){
           printf("Clave:  %d - Divisor total\n", X->clave); 
        } else{
            printf("Clave:  %d - Divisor parcial\n", X->clave);
        }
        c_encolar(Caux, X);
    }

    // ahora paso la auxiliar a la cola de nuevo para dejarla como estaba
    while (c_es_vacia(Caux) != true) {
        X = c_desencolar(Caux);
        c_encolar(c, X);
    }

    printf("\n");
}

//Elimina los elementos repetidos y los menores a 2
Cola c_preparar_cola(Cola c){
    TipoElemento te, te2;
    Cola Cresultado = c_crear();
    Lista lista = l_crear();
    Pila pila = p_crear();

    //paso los elementos a la lista
    while (!c_es_vacia(c)){
        te = c_desencolar(c);
        l_agregar(lista, te);
        p_apilar(pila, te);
    }

    //recorro la pila y busco si existe el elemento en la lista
    while (!p_es_vacia(pila)){
        te = p_desapilar(pila);
        Iterador ite = iterador(lista);
        int repetido = 0;
        while (hay_siguiente(ite)){
            te2 = siguiente(ite);
            if (te->clave == te2->clave){
                repetido++;
            }
        }
        if (te->clave >= 2 && repetido < 2){
            c_encolar(Cresultado, te);
        }
    }    
    return Cresultado;
}

void ejecutar_TP4_EJ05(){
    
    int opcion = 0;
    bool x = false;
    Cola C1 = c_crear();
    Cola Caux;

    clearScreen();
    printf("Ejercicio 5: \n");
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
    C1 = c_preparar_cola(C1);
    printf("Cola sin repeticiones y mayores o iguales a 2\n");
    c_mostrar(C1);
    Caux = c_ej5_divisortotal(C1);
    printf("Cola con los divisores totales y parciales\n");
    c_mostrar_con_divisores(Caux);
    printf("\n");
    printf("La complejidad del algoritmica de esta implementacion es de O(n^2) donde n es la cantidad de elementos de las colas, esto porque por cada elemento se recorre toda la cola nuevamente\n");
    system("pause");

}