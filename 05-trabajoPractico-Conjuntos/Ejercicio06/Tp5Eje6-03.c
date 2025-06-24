#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"

/**
6.	Dados dos conjuntos de números naturales se pide determinar si uno es subconjunto propio del otro.  
	Determinar la complejidad algorítmica
*/
bool c_ej6_subconjuntopropio(Conjunto A, Conjunto B){
    int cantidad = cto_cantidad_elementos(A);
    TipoElemento te;

    if (cantidad >= cto_cantidad_elementos(B)){
        return false;
    }

    for (int i = 1; i <= cantidad; i++){
        te = cto_recuperar(A, i);
        if (!cto_pertenece(B, te->clave)) return false;
    }
    
    return true;
}