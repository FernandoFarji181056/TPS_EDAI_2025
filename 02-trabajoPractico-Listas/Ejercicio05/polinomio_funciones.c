#include <stdlib.h>
#include <math.h>
#include "libs/listas/headers/Tp_2_listas.h"
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/listas/headers/listas.h"

float evaluarPoliomio(Lista list, float x) {
    float resultado = 0;
    Iterador it = iterador(list);
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        int exp = te->clave;
        float coef = *((float*)te->valor);
        resultado += coef * powf(x, exp);
    }
    return resultado;
}

Lista calcularRango(Lista list, double x, double y, double paso) {
    Lista listaResultados = l_crear();
    for (double i = x; i <= y + 0.0001; i += paso) {  // +0.0001 para incluir y por precisión
        float* resultado = malloc(sizeof(float));
        *resultado = evaluarPoliomio(list, (float)i);
        TipoElemento te = te_crear_con_valor(0, resultado); // clave no se usa acá
        l_agregar(listaResultados, te);
    }
    return listaResultados;
}
