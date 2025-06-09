#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "../tp_colas.h"

/**
3.	3. Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en
datos (solo comparar por la clave), sin destruirlas. Utilizar para la resolución del
problema una sola cola auxiliar. Determinar la complejidad algorítmica del problema.
 */
// retorna true si son exactamente iguales, caso contrario retorna false.
bool c_ej3_iguales(Cola c1, Cola c2){
    bool resultado = true;
    Cola Caux = c_crear();
    TipoElemento te, te2;
    int cantidad1 = 0;
    int cantidad2 = 0;

    //cuento los elementos de C1
    while (!c_es_vacia(c1)){
        te = c_desencolar(c1);
        c_encolar(Caux, te);
        cantidad1 = cantidad1 + 1;
    }

    //restauro C1 a su estado original
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c1, te);
    }

    //cuento los elementos de C2
    while (!c_es_vacia(c2)){
        te = c_desencolar(c2);
        c_encolar(Caux, te);
        cantidad2 = cantidad2 + 1;
    }

    //restauro C2 a su estado original
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c2, te);
    }

    //Si la cantidades de elementos son distintas entonces ya son distintas las colas
    if (cantidad1 != cantidad2){
        resultado = false;
    } else{
        for (int i = 0; i < cantidad1; i++){
            te = c_desencolar(c1);
            te2 = c_desencolar(c2);
            if(te->clave != te2->clave){
                resultado = false;
            }
            c_encolar(c1, te);
            c_encolar(c2, te2);
        }
    }
    
    return resultado;
}