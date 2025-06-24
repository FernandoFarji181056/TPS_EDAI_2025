#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"

/**
5.	Desarrollar un algoritmo capaz de resolver la diferencia simétrica (por la clave) entre dos conjuntos. 
	La diferencia simétrica es una operación entre dos conjuntos donde el conjunto resultante está conformado 
	por los elementos no comunes a los dos conjuntos.
*/
Conjunto c_ej5_dif_simetrica(Conjunto A, Conjunto B){
    Conjunto C1 = cto_diferencia(A, B);
    Conjunto C2 = cto_diferencia(B, A);
    Conjunto resultado = cto_union(C1, C2);
    return resultado;
}