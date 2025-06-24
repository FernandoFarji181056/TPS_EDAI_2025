#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"

/**
4.	Desarrollar un algoritmo que dado tres conjuntos puedan demostrar la propiedad de la transitividad:  
	“si A es subconjunto de B y B a su vez es subconjunto de C, entonces A es subconjunto de C”.
*/
bool c_es_subconjunto(Conjunto A, Conjunto B){
    int cantidad = cto_cantidad_elementos(A);
    TipoElemento te;
    for (int i = 1; i <= cantidad; i++){
        te = cto_recuperar(A, i);
        if (!cto_pertenece(B, te->clave)) return false;
    }
    return true;
}

bool c_ej4_transitividad(Conjunto A, Conjunto B, Conjunto C){
    if (c_es_subconjunto(A, B) && c_es_subconjunto(B, C) && c_es_subconjunto(A, C)){
        return true;
    } else return false;
}