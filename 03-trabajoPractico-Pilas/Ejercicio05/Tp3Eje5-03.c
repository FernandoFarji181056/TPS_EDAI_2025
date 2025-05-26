#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"

Pila p_ej5_invertir(Pila p) {
    Pila aux1 = p_crear();
    Pila invertida = p_crear();
    TipoElemento elem;

    // Paso 1: pasar de p a aux1
    while (!p_es_vacia(p)) {
        elem = p_desapilar(p);
        p_apilar(aux1, elem);
        p_apilar(invertida, elem);
    }

    // Paso 2: pasar de aux1 a invertida y restaurar p
    while (!p_es_vacia(aux1)) {
        elem = p_desapilar(aux1);
        //p_apilar(invertida, elem); // armar invertida
        p_apilar(p, elem);         // restaurar original
    }

    return invertida;
}