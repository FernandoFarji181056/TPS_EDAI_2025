#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"
#include "libs/listas/headers/listas.h"

/**
8.	Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los valores (sin repetición) y la cantidad de veces que aparecen.
	No debe perderse la pila original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves unicas (no deben existir repetidas) y por cada una la cantidad de veces que aparecia en la Pila recibida por parametro
// Si la pila estavacia retorna pila vacia.
Pila p_ej8_sacarrepetidos(Pila p){
    Pila paux = p_crear();
    Pila resultado = p_crear();
    Lista lista = l_crear();
    TipoElemento te_p1, teRes;
    int *repeticion;

    while (!p_es_vacia(p)){
        te_p1 = p_desapilar(p);
        p_apilar(paux, te_p1);

        //verifico si la clave ya se encuentra en la lista, si está le sumo 1 al valor, sino agrego el elemento con 1 en valor
        teRes = l_buscar(lista, te_p1->clave);
        if (teRes == NULL){
            repeticion = malloc(sizeof(int));
            *repeticion = 1;
            teRes = te_crear_con_valor(te_p1->clave, repeticion);
            l_agregar(lista, teRes);
        } else {
            repeticion = (int*) teRes->valor;
            *repeticion = *repeticion +1;
        }

    }

    //regreso p a su estado original
    while (!p_es_vacia(paux)){
        te_p1 = p_desapilar(paux);
        p_apilar(p, te_p1);
    }

    //paso la lista a la pila resultado
    for (int i = l_longitud(lista); i > 0; i--){
        teRes = l_recuperar(lista, i);
        p_apilar(resultado, teRes);
    }

    return resultado;
}
