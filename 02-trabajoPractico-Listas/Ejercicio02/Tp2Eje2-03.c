#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/tp_2_listas.h"


/*
Dada una 2 listas (L1 y L2) cargadas con valores al azar (en la clave) realizar los siguientes
ejercicios:
a. Que retorne una lista con los valores de L1 que no están en L2.
b. Que retorne una lista con los valores de L2 que no están en L1.
c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
d. Que retorne los promedios de ambas listas.
e. Que retorne el valor mínimo de ambas listas y su posición ordinal.
*/

static const int max_elementos = 10;
static const int num_max = 100;
static const int num_min = 0;


//a. Que retorne una lista con los valores de L1 que no están en L2.
//b. Que retorne una lista con los valores de L2 que no están en L1.
// Punto 2 a y b
Lista verElementosQueNoSeRepiten(Lista l1, Lista l2){
    Iterador ite_l1 = iterador(l1); //inicio el iterador para recorrer la lista l1
    Iterador ite_l2;
    TipoElemento te_l1, te_l2, te_l3;
    Lista l3 = l_crear();
    bool repetido;
    while (hay_siguiente(ite_l1)){
        te_l1 = siguiente(ite_l1); //obtengo el elemento de l1
        ite_l2 = iterador(l2);     //inicio el iterador para recorrer la lista l2
        repetido = false;

        while (hay_siguiente(ite_l2) && !repetido) {   //recorro todo l2 mientras haya un siguiente
            te_l2 = siguiente(ite_l2);    //obtengo el elemento de l2
            if (te_l1->clave == te_l2->clave){ 
                repetido = true;
            }
        }
        if (!repetido){
            te_l3 = te_crear(te_l1->clave);   //creo el tipo elemento con la clave de l1
            l_agregar(l3, te_l3);
        }
             
    }
    return l3;
}


//c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
// Punto 2 C
Lista verElementosRepetidos(Lista l1, Lista l2){
    Iterador ite_l1 = iterador(l1); //inicio el iterador para recorrer la lista l1
    Iterador ite_l2;
    TipoElemento te_l1, te_l2, te_l3;
    Lista l3 = l_crear();          
    bool repetido;
    //DEBO CREAR UN L1AUX SIN ELEMENTOS REPETIDOS Y UTILIZAR ESA PARA EL PROCESO
    Lista l1_aux = l_crear();
    while (hay_siguiente(ite_l1)){
        te_l1 = siguiente(ite_l1); //obtengo el elemento de l1
        if (l_buscar(l1_aux, te_l1->clave) == NULL){ //si el elemento no está en l1_aux entonces lo agrego
            te_l2 = te_crear(te_l1->clave);
            l_agregar(l1_aux, te_l2);
        }
    }
    
    //Proceso mi nueva l1_aux
    ite_l1 = iterador(l1_aux);
    while (hay_siguiente(ite_l1)){
        te_l1 = siguiente(ite_l1); //obtengo el elemento de l1_aux
        ite_l2 = iterador(l2);     //inicio el iterador para recorrer la lista l2
        repetido = false;

        while (hay_siguiente(ite_l2) && !repetido) {   //recorro todo l2 mientras haya un siguiente
            te_l2 = siguiente(ite_l2);    //obtengo el elemento de l2
            if (te_l1->clave == te_l2->clave){ 
                repetido = true;
            }
        }
        if (repetido){
            te_l3 = te_crear(te_l1->clave);   //creo el tipo elemento con la clave de l1
            l_agregar(l3, te_l3);
        }
             
    }
    return l3;
}


// Punto 2 D
//d. Que retorne los promedios de ambas listas.
float promedio(Lista l1){
    int suma = 0;
    TipoElemento te_l1;
    Iterador ite_l1 = iterador(l1); //Inicializo el iterador para recorrer l1
    while (hay_siguiente(ite_l1)){
        te_l1 = siguiente(ite_l1); //Obtengo el elemento de l1
        suma = suma + te_l1->clave;
    }
    if(l_longitud(l1) == 0) return 0; else return (float)suma/l_longitud(l1);
}


// Punto 2 E
//e. Que retorne el valor mínimo de ambas listas y su posición ordinal.
ResultadoValorMinimo valorMinimo(Lista l1, Lista l2){
    ResultadoValorMinimo resultado;
    Iterador ite = iterador(l1);
    TipoElemento te_l = siguiente(ite);
    resultado.valor = te_l->clave; //considero el primer valor como el minimo
    resultado.pos = 0;              //considero el primer valor como el minimo, esta en la posicion 0
    int i = 1;
    while (hay_siguiente(ite)){
        te_l = siguiente(ite);
        if (te_l->clave < resultado.valor){
            resultado.valor = te_l->clave;
            resultado.pos = i;
        }
        i++;
    }
    
    ite = iterador(l2);
    te_l = siguiente(ite);
    resultado.valor_2 = te_l->clave; //considero el primer valor como el minimo
    resultado.pos_2 = 0;              //considero el primer valor como el minimo, esta en la posicion 0
    i = 1;
    while (hay_siguiente(ite)){
        te_l = siguiente(ite);
        if (te_l->clave < resultado.valor_2){
            resultado.valor_2 = te_l->clave;
            resultado.pos_2 = i;
        }
        i++;
    }

    return resultado;
}

