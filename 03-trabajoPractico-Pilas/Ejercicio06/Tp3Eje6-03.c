#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"

/**
6.	Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado ítem sin perder la pila original.
	Deberá retornar una nueva pila sin el ítem en consideración.
	Resolver iterativamente y recursivamente.
	Determinar la complejidad algorítmica de ambas soluciones.
 */
// retornar la nueva pila sin la clave que se debe sacar (eliminar). Si la clave no esta se retorna la pila recibida.
// La definicion vale para ambas resoluciones


//funcion interna iterativa
Pila p_ej6_eliminarclave_iterativo(Pila p, int clave){
    Pila Pauxresultado = p_crear();
    Pila Paux = p_crear();
    Pila resultado = p_crear();
    TipoElemento te;
    while (!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(Paux, te);
    }

    // recorro la pila auxiliar y restauro p, en resultado apilo los valores que correspondan
    while (!p_es_vacia(Paux)){
        te = p_desapilar(Paux);
        p_apilar(p, te);
        if(te->clave != clave){
            p_apilar(resultado, te);
        }
    }
    return resultado;
}

//funcion interna recursiva
Pila p_ej6_eliminarclave_recursivo(Pila p, int clave){
    if (p_es_vacia(p)){
        Pila resultado = p_crear();
    } else{
        TipoElemento te = p_desapilar(p);
        Pila resultado = p_ej6_eliminarclave_recursivo(p, clave);
        p_apilar(p, te);
        if (te->clave != clave){
            p_apilar(resultado, te);
        }
        return resultado;
    }
}

//funcion general
Pila p_ej6_eliminarclave(Pila p, int clave){
    int opcion = 0;
    bool x = false;
    Pila PilaResultado;
    printf("Ingrese 1 si desea resolverlo iterativamente\n");
    printf("Ingrese 2 si desea resolverlo recursivamente\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        PilaResultado = p_ej6_eliminarclave_iterativo(p, clave);
        break;
    case 2:
        PilaResultado = p_ej6_eliminarclave_recursivo(p, clave);
        break;
    default:
        break;
    }
    return PilaResultado;
}