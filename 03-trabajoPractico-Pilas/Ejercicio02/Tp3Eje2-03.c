#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"

bool p_ej2_existeclave(Pila p, int clave){
    bool existe = false;
    TipoElemento te;
    Pila paux = p_crear();
    while (!p_es_vacia(p) && !existe){
        te = p_desapilar(p);
        p_apilar(paux, te);
        if (te->clave == clave) existe = true;
    }
    //regreso la pila a su estado original
    while (!p_es_vacia(paux)){
        te = p_desapilar(paux);
        p_apilar(p, te);
    }
    
    return existe;
}

//  b.	Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).
// Retorna la nueva pila con el nuevo elemento, caso contrario la pila original recibida.
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x){
    TipoElemento te;
    Pila paux = p_crear();
    int i = 1;
    //coloco todos los valores en la pila auxiliar
    while (!p_es_vacia(p)){
        te = p_desapilar(p);
        p_apilar(paux, te);
    }
    //regreso la pila a su estado original, agregando el elemento en la posicion deseada
    while (!p_es_vacia(paux)){
        if (i == posicionordinal){ //si es la posición deseada agrego el elemento x
            p_apilar(p, x);
        }
        te = p_desapilar(paux);
        p_apilar(p, te);
        i = i+1;
    }
    //Logica para agregar un elemento si pila está vacia y se desea insertar un elemento en la posición 1
    if (p_es_vacia(p) && posicionordinal == 1){
        p_apilar(p, x);
    }
    
    return p;
}

//  c.	Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave).
// retorna la nueva pila sin la clave, si la encuentra, sino retorna la misma pila que recibio.
Pila p_ej2_eliminarclave(Pila p, int clave){
    bool existe = false;
    TipoElemento te;
    Pila paux = p_crear();
    while (!p_es_vacia(p) && !existe){
        te = p_desapilar(p);
        if (te->clave == clave) {
            existe = true;
        } else p_apilar(paux, te);
    }
    //regreso la pila a su estado original
    while (!p_es_vacia(paux)){
        te = p_desapilar(paux);
        p_apilar(p, te);
    }
    
    return p;
}

//  f.	Contar los elementos de la pila.
// retorna la cantidad de elementos de la pila. Si esta vacia retorna 0 (cero).
int p_ej2_cantidadelementos(Pila p){
    if (p_es_vacia(p)){
        return 0;
    } else {
        TipoElemento te = p_desapilar(p);
        int cantidad = p_ej2_cantidadelementos(p) + 1;
        p_apilar(p, te);
        return cantidad;
    }
}

//  d.	Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta.
// retorna la nueva pila con las posiciones cambiadas, siempre que sea posible haerlo, caso contrario retorna la pila recibida.
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    TipoElemento te, te1, te2;
    int cantidad = p_ej2_cantidadelementos(p);
    Pila paux = p_crear();
    int posicion = cantidad;
    //verifico que las posiciones sean correctas
    if ((pos1 >= 1 && pos1 <= cantidad) && (pos2 >= 1 && pos2 <= cantidad) && (pos1 != pos2)){
        while (!p_es_vacia(p)){
            if (posicion != pos1 && posicion != pos2){
                te = p_desapilar(p);
                p_apilar(paux, te);
            } else {
                if (posicion == pos1){
                    te1 = p_desapilar(p);
                } else {
                    if (posicion == pos2){
                        te2 = p_desapilar(p);
                    }
                }

            }
            posicion--;
        }
        
        for (posicion = 1; posicion <= cantidad; posicion++){
            if (posicion != pos1 && posicion != pos2){
                te = p_desapilar(paux);
                p_apilar(p, te);
            } else {
                if (posicion == pos1){
                    p_apilar(p, te2);
                }
                if (posicion == pos2){
                    p_apilar(p, te1);
                }
            }
        }        
    }
    return p;
}

//  e.	Duplicar el contenido de una pila.
// retorna la nueva pila. Si esta vacia retorna otra vacia.
Pila p_ej2_duplicar(Pila p){
    if (p_es_vacia(p)){
        return p;
    } else {
        TipoElemento te = p_desapilar(p);
        te->clave = te->clave * 2;
        p = p_ej2_duplicar(p);
        p_apilar(p, te);
        return p;
    }
}