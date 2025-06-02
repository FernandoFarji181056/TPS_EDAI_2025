#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"

/**
 4.	Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número decimal pasado como parámetro,
	a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal).
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){
    TipoElemento te;
    Pila p = p_crear();
    int resto;
    char* resultado = malloc(35);
    const char* mapeo = "0123456789ABCDEF";
    
    //valido si la base no esta entre 2 y 16
    if (nrootrabase < 2 || nrootrabase > 16){
        sprintf(resultado, "%d", nrobasedecimal);
        return resultado;
    }

    while (nrobasedecimal > 0){
        resto = nrobasedecimal % nrootrabase;
        te = te_crear(resto);
        p_apilar(p, te);
        nrobasedecimal = nrobasedecimal/nrootrabase;
    }

    int i = 0;
    while (!p_es_vacia(p)){
        te = p_desapilar(p);
        resultado[i++] = mapeo[te->clave];
    }

    resultado[i] = '\0';
    
    return resultado;
}