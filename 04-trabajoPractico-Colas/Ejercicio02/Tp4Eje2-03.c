#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "../tp_colas.h"

//  a.	Informar si un elemento dado se encuentra en la cola.
// Si la encuentra retorna true, caso contrario false
bool c_ej2_existeclave(Cola c, int clave){
    bool existe = false;
    TipoElemento te;
    Cola Caux = c_crear();
    while (!c_es_vacia(c)){  //recorro hasta el final de la cola aunque haya encontrado el elemento, esto con el fin de no cambiar el orden de la cola
        te = c_desencolar(c);
        c_encolar(Caux, te);
        if (te->clave == clave) existe = true;
    }
    //regreso la cola a su estado original
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c, te);
    }
    
    return existe;
}

//  b.	Agregar un nuevo elemento en una posición dada (colarse).
// Retorna la nueva cola con el elemento insertado, caso contrario la cola original recibida.
Cola c_ej2_colarelemento(Cola c, int posicionordinal, TipoElemento X){
    TipoElemento te;
    Cola Caux = c_crear();
    Cola Cresultado = c_crear();
    int i = 1;
    //coloco todos los valores en la cola auxiliar y cola resultado
    while (!c_es_vacia(c)){
        if (i == posicionordinal){ //si es la posición deseada agrego el elemento x
            c_encolar(Cresultado, X);
        }
        te = c_desencolar(c);
        c_encolar(Caux, te);
        c_encolar(Cresultado, te);
        i = i+1;
    }
    //Logica para agregar un elemento si se desea agregar un elemento al final de la cola, en este caso i va a coincidir con la posicion ordinal
    //esto tambien cubre el escenario de que se quiera encolar un elemento la posicion ordinal 1 y la cola está vacia
    if (i == posicionordinal){
        c_encolar(Cresultado, X);
    }
    
    //regreso la cola a su estado original
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c,te);
    }

    return Cresultado;
}

//  c.	Dado un elemento sacarlo de la cola todas las veces que aparezca.
// Retorna la nueva cola sin el/los elemento/s, caso contrario la cola original recibida.
Cola c_ej2_sacarelemento(Cola c, int clave){
    TipoElemento te;
    Cola Caux = c_crear();
    Cola Cresultado = c_crear();

    //coloco todos los valores en la cola auxiliar y cola resultado
    while (!c_es_vacia(c)){
        te = c_desencolar(c);
        c_encolar(Caux, te);
        if (te->clave != clave){ //descarto el elemento si es el que deseo eliminar
            c_encolar(Cresultado, te);
        }
    }
    //regreso la cola a su estado original
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c,te);
    }
    
    return Cresultado;
}

//  d.	Contar los elementos de la cola.
// Retorna la cantidad de elementos de la cola, o 0 (cero) si esta vacia.
int c_ej2_contarelementos(Cola c){
    TipoElemento te;
    Cola Caux = c_crear();
    int cantidad = 0;

    //coloco todos los valores en la cola auxiliar y cola resultado
    while (!c_es_vacia(c)){
        te = c_desencolar(c);
        c_encolar(Caux, te);
        cantidad = cantidad + 1;
    }
    //regreso la cola a su estado original
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c,te);
    }
    
    return cantidad;
}

//  e.	Realizar una función que realice una copia de una cola.
// Retorna la cola copia tal cual la original, no debe perserse la original.  Si es vacia retorna vacia.
Cola c_ej2_copiar(Cola c){
    TipoElemento te, te2;
    Cola Caux = c_crear();
    Cola Cresultado = c_crear();

    //coloco todos los valores en la cola auxiliar y cola resultado
    while (!c_es_vacia(c)){
        te = c_desencolar(c);
        te2 = te_crear(te->clave);
        c_encolar(Caux, te);
        c_encolar(Cresultado, te2);
    }
    //regreso la cola a su estado original
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c,te);
    }
    
    return Cresultado;
}

//  f.	Invertir el contenido de una cola sin destruir la cola original.
// Retorna la cola al reves (invertida), no debe perserse la original. Si es vacia retorna vacia.
Cola c_ej2_invertir(Cola c){
    TipoElemento te, te2;
    Cola Caux = c_crear();
    Pila pila = p_crear();
    Cola Cresultado = c_crear();

    //coloco todos los valores en la cola auxiliar y la pila
    while (!c_es_vacia(c)){
        te = c_desencolar(c);
        te2 = te_crear(te->clave);
        c_encolar(Caux, te);
        p_apilar(pila, te2);
    }
    //regreso la cola a su estado original
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c,te);
    }
    //completo la cola resultado
    while (!p_es_vacia(pila)){
        te = p_desapilar(pila);
        c_encolar(Cresultado, te);
    }
    
    return Cresultado;
}