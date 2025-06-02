#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"


/**
 3.	Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas.
	Utilizar para la resolución del problema una única pila auxiliar.
	Determinar la complejidad algorítmica de la solución.
 */
// retorna true si son exactamente iguales, caso contrario retorna false
bool p_ej3_iguales(Pila p1, Pila p2){
    bool iguales = true;
    TipoElemento te_p1, te_p2;
    Pila paux = p_crear();
    
    while (!p_es_vacia(p1) && !p_es_vacia(p2) && iguales){
        te_p1 = p_desapilar(p1);
        te_p2 = p_desapilar(p2);
        if (te_p1->clave != te_p2->clave){
            iguales = false;
            p_apilar(p1, te_p1); //apilo nuevamente los elementos de la comparación ya que son distintos
            p_apilar(p2, te_p2);
        } else p_apilar(paux, te_p1); // dado que son iguales solo me basta con apilar en el auxiliar el elemento de una sola pila
    }

    //si una de las pilas aun tiene elementos entonces no son iguales
    if (!p_es_vacia(p1) || !p_es_vacia(p2)){
        iguales = false;
    }
    
    //regreso lo de paux a las pilas p1 y p2
    while (!p_es_vacia(paux)){
        te_p1 = p_desapilar(paux);
        p_apilar(p1, te_p1);
        p_apilar(p2, te_p1);
    }

    return iguales;
}