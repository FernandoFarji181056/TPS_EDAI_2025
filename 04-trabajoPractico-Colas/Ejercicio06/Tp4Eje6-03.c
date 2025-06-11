#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "libs/listas/headers/listas.h"
#include "libs/pilas/headers/pilas.h"
#include "../tp_colas.h"

/**
6.	Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
	y en qué posición ordinal se encontró cada uno en su estructura.  Si existe mas de una vez la primer posicion encontrada.
	No se deben destruir las estructuras originales.
 */
// retornar una lista con los valores comunes segun las especificaciones del ejercicio.
// Si no existen valores comunes retornar la lista vacia.
Lista c_ej6_comunesapilaycola(Pila p, Cola c){
	int cantidad = 0;
	TipoElemento te, tep, tec;
	Cola Caux = c_crear();
	Pila paux = p_crear();
	Lista lista = l_crear();

    //cuento los elementos
    while (!c_es_vacia(c)){
        te = c_desencolar(c);
        c_encolar(Caux, te);
        cantidad = cantidad + 1;
    }
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c, te);
    }

	int posicionp = 1;
	while (!p_es_vacia(p)){
		tep = p_desapilar(p);
		//busco si el elemento se encuentra en la cola
		for (int i = 1; i <= cantidad; i++){
			tec = c_desencolar(c);
			if (tep->clave == tec->clave){
				char* valor = malloc(12 * sizeof(char));
				sprintf(valor, "%d:%d", posicionp, i);
				te = te_crear_con_valor(tep->clave, valor);
				l_agregar(lista, te);
			}
			c_encolar(c, tec);
		}
		posicionp++;
		p_apilar(paux, tep);
	}


	//restauro la pila
	while (!p_es_vacia(paux)){
		te = p_desapilar(paux);
		p_apilar(p, te);
	}

    return lista;
}