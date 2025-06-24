#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"

/**
7.	Dados 3 conjuntos determinar si alguno es un subconjunto parcial o total del otro.  
	Se considera un subconjunto parcial cuando al menos la mitad de los elementos de uno están en el otro.  
	Determinar la complejidad algorítmica.
	Imprimir el resultado en la función.
    
*/

bool cto_subconjunto(Conjunto A, Conjunto B){
    int cantidad = cto_cantidad_elementos(A);
    TipoElemento te;
    for (int i = 1; i <= cantidad; i++){
        te = cto_recuperar(A, i);
        if (!cto_pertenece(B, te->clave)) return false;
    }
    
    return true;
}

bool cto_parcial(Conjunto A, Conjunto B){
    int pertenece = 0;
    int cantidad = cto_cantidad_elementos(A);
    TipoElemento te;
    for (int i = 1; i <= cantidad; i++){
        te = cto_recuperar(A, i);
        if (cto_pertenece(B, te->clave)){
            pertenece++;
        }
    }

    return pertenece >= (cantidad + 1)/2;
}

void c_ej7_subconjtotalparcial(Conjunto A, Conjunto B, Conjunto C){
    // A con respecto a B
    if (cto_subconjunto(A, B)) {
        printf("A es subconjunto total de B\n");
    } else if (cto_parcial(A, B)) {
        printf("A es subconjunto parcial de B\n");
    }

    // A con respecto a C
    if (cto_subconjunto(A, C)) {
        printf("A es subconjunto total de C\n");
    } else if (cto_parcial(A, C)) {
        printf("A es subconjunto parcial de C\n");
    }

    // B con respecto a A
    if (cto_subconjunto(B, A)) {
        printf("B es subconjunto total de A\n");
    } else if (cto_parcial(B, A)) {
        printf("B es subconjunto parcial de A\n");
    }

    // B con respecto a C
    if (cto_subconjunto(B, C)) {
        printf("B es subconjunto total de C\n");
    } else if (cto_parcial(B, C)) {
        printf("B es subconjunto parcial de C\n");
    }

    // C con respecto a A
    if (cto_subconjunto(C, A)) {
        printf("C es subconjunto total de A\n");
    } else if (cto_parcial(C, A)) {
        printf("C es subconjunto parcial de A\n");
    }

    // C con respecto a B
    if (cto_subconjunto(C, B)) {
        printf("C es subconjunto total de B\n");
    } else if (cto_parcial(C, B)) {
        printf("C es subconjunto parcial de B\n");
    }
}