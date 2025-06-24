#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"

/**
8.	Dados dos conjuntos de números naturales se pide determinar si son iguales sin importar la posición 
	de sus elementos.  
	Determinar la complejidad algorítmica.
*/
bool c_ej8_soniguales(Conjunto A, Conjunto B){
    int cantA = cto_cantidad_elementos(A);
    int cantB = cto_cantidad_elementos(B);
    TipoElemento te;

    if (cantA != cantB){
        return false;
    } else {
        // Verificamos que todos los elementos de A estén en B
        for (int i = 1; i <= cantA; i++){
            te = cto_recuperar(A, i);
            if(!cto_pertenece(B, te->clave)) return false;
        }
    }

    return true;
}