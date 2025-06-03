#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"
#include "libs/listas/headers/listas.h"

/*
7. Dada dos pilas realizar una función que permita determinar los elementos que tienen
en común. Debe retornar una nueva pila con esos elementos (que están en ambas
pilas) sin perder las pilas originales. Determinar la complejidad algorítmica de la
solución.
Ejemplo: si “P1” contiene (1, 4, 7, 9, 8) y “P2” contiene (4,1,6,9,3) el resultado será la
pila “PR” = (1,4,9).
*/

// retornar la nueva pila con las claves en comun de ambas Pilas recibidas por parametro. Si no hay claves en comun retornar una pila vacia.
Pila p_ej7_elementoscomunes(Pila p1, Pila p2){
    Pila resultado = p_crear();
    Pila p1aux = p_crear();
    Pila p2aux = p_crear();
    Lista lista = l_crear();
    TipoElemento te1, te2;
    bool existe;
    //recorro p1 y por cada elemento verifico si está en p2, si cumple y aun no lo agregue a la lista entonces lo agrego.
    while (!p_es_vacia(p1)){
        te1 = p_desapilar(p1);
        p_apilar(p1aux, te1);

        existe = false;
        while (!p_es_vacia(p2) && !existe){   //recorro p2
            te2 = p_desapilar(p2);
            p_apilar(p2aux, te2);

            if (te1->clave == te2->clave){  //comparo las claves
                existe = true;
                if (l_buscar(lista, te1->clave) == NULL){ //antes de agregar el elemento en la lista verifico que aun no exista en ella
                    l_agregar(lista, te1);
                }
            }
        }

        //debo regresar a su estado original p2 
        while (!p_es_vacia(p2aux)){
            te2 = p_desapilar(p2aux);
            p_apilar(p2, te2);
        }

    }

    //debo regresar a su estado original p1
    while (!p_es_vacia(p1aux)){
        te1 = p_desapilar(p1aux);
        p_apilar(p1, te1);
    }
    
    //agrego los elementos de la lista a la pila resultado, si no hay elementos en comun la pila resultado será vacia
    for (int i = l_longitud(lista); i > 0; i--){
        te1 = l_recuperar(lista, i);
        p_apilar(resultado, te1);
    }

    return resultado;
}