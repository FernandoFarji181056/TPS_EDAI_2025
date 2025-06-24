#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"

/**
2.	Desarrollar un algoritmo que dado dos conjuntos de elementos tipo numérico (clave) 
	verifique las operaciones de Unión,  Intersección,  Diferencia y Pertenencia. 
*/
Conjunto c_ej2_union(Conjunto A, Conjunto B){
    Conjunto resultado = cto_union(A,B);
}

Conjunto c_ej2_interseccion(Conjunto A, Conjunto B){
    Conjunto resultado = cto_interseccion(A,B);
}

Conjunto c_ej2_diferencia(Conjunto A, Conjunto B){
    Conjunto resultado = cto_diferencia(A, B);
}

