#include <stdio.h>
#include <stdlib.h>
//#include "listas.h"
//#include "tipo_elemento.h"
#include "libs/listas/headers/main_tp3.h"
#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/Tp_2_listas.h"
#include "libs/tipoElemento/headers/tipo_elemento.h"


//---------------------------------------------------
// Encabezados
//---------------------------------------------------
bool esSublista(Lista L1, Lista L2);
bool buscarElemento(Lista lista, int valor);


//---------------------------------------------------
// MAIN PRINCIPAL
//---------------------------------------------------
void ejecutar_TP2_EJ06()
{
    TipoElemento X;
    Lista L1 = l_crear();
    Lista L2 = l_crear();
    bool sublista;

    printf("---------- ejercicio de sublistas ----------------!\n");

    // Lleno la lista 1
    X = te_crear(7);
    l_agregar(L1, X);
    X = te_crear(3);
    l_agregar(L1, X);
    X = te_crear(4);
    l_agregar(L1, X);
    X = te_crear(9);
    l_agregar(L1, X);
    X = te_crear(5);
    l_agregar(L1, X);
    X = te_crear(9);
    l_agregar(L1, X);


    // Lleno la lista 2
    X = te_crear(4);
    l_agregar(L2, X);
    X = te_crear(7);
    l_agregar(L2, X);
    X = te_crear(2);
    l_agregar(L2, X);


    // Muestro la lista
    printf("---------- Lista 1 ----------------!\n");
    l_mostrar(L1);
    printf("---------- Lista 2 ----------------!\n");
    l_mostrar(L2);

    printf("\n");

    sublista = esSublista(L1, L2);

    if (sublista) 
    {
        printf("Lista 2 es sublista de Lista 1 \n");
    }
    else
    {
        printf("Lista 2 no es sublista de Lista 1 \n");
    }

    printf("\n");
    printf("la complejidad algoritmica de este ejercicio es cuadratica,\n");
    printf("ya que recorre Lista 2 con un while y en cada iteracion realiza un while de Lista 1\n");
    

    system("pause");

}


//---------------------------------------------------------------------------------
// Funciones del Ejercicio 2
//---------------------------------------------------------------------------------

// Función para verificar si un elemento está presente en la lista
bool buscarElemento(Lista lista, int valor) {
    // esta variable booleana la uso para saber si el elemento esta en lista 1
    // será falsa mientras no encuentre el valor en la lista 1
    // si termina como falsa significa que no esta en lista, sino cambiará a true 
    bool esta_en_lista1 = false;
    Iterador I1 = iterador(lista);
    TipoElemento x1;
    // recorro mientras la lista tenga elementos o mientras esta_en_lista1 sea falso
    while(hay_siguiente(I1) && esta_en_lista1 == false)
    {
        x1 = siguiente(I1);
        if (x1->clave == valor)
        {
            
            esta_en_lista1 = true;
        }

    }

    return esta_en_lista1;
}

// Función para determinar si ListaB es sublista de ListaA (sin importar el orden)
bool esSublista(Lista L1, Lista L2) {
    // este booleano lo uso para saber si L2 es sublista de L1
    // si termina como true significa que es sublista, si cambia a false no lo es y retornara false
    bool es_sub = true;
    Iterador I2 = iterador(L2);
    TipoElemento x1, x2;

    while (es_sub && hay_siguiente(I2))
    {
        x2 = siguiente(I2);
        es_sub = buscarElemento(L1, x2->clave);
    }
    
    return es_sub; // Si todos los elementos de ListaB se encontraron en ListaA
}
