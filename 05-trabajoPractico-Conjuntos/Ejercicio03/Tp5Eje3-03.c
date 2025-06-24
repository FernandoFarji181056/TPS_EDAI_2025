#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"
#include "libs/listas/headers/listas.h"

/**
3.	Desarrollar un algoritmo que dada una colección de conjuntos de elementos tipo numérico (clave) 
	realice las operaciones de Unión e Intersección.
	La lista contendra la coleccion de conjuntos.  Cada campo void apunta a un conjunto.
*/
Conjunto c_ej3_uniones(Lista l_de_conjuntos){
    Conjunto resultado = cto_crear();
    Iterador ite = iterador(l_de_conjuntos);
    TipoElemento te;
    Conjunto C;
    while (hay_siguiente(ite)){
        te = siguiente(ite);
        C = (Conjunto) te->valor;
        resultado = cto_union(resultado, C);
    }
    
    return resultado;
}

Conjunto c_ej3_intersecciones(Lista l_de_conjuntos){
    Conjunto resultado = cto_crear();
    if (l_es_vacia(l_de_conjuntos)) return resultado;

    //primer conjunto lo unimos a resultado
    Iterador ite = iterador(l_de_conjuntos);
    TipoElemento te = siguiente(ite); 
    Conjunto C = (Conjunto)te->valor;
    resultado = cto_union(C, resultado);

    while (hay_siguiente(ite)){
        te = siguiente(ite);
        C = (Conjunto) te->valor;
        resultado = cto_interseccion(C, resultado);
    }
    
    return resultado;
}