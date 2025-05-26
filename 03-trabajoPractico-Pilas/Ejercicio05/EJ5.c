/*
     Invertir el contenido de una pila sin destruir la pila original. Se debe retornar la nueva 
    pila invertida y la original no se debe perder. Determinar la complejidad algorítmica 
    de la solución. 
*/

//#include "pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/Tp_pilas.h"
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"

Pila invertir(Pila p)
{

    Pila p_invertida = p_crear();
    Pila paux1 = p_crear();
    Pila paux2 = p_crear();
    TipoElemento elemento;
    if (p_es_vacia(p))
    {
        printf("[ERROR] la pila es vacias\n");
        return p_invertida;
    }

    while (p_es_vacia(p) != true)
    {
        
        elemento = p_desapilar(p);
        p_apilar(paux1,elemento);
        p_apilar(paux2,elemento);
    }

    //Vuelvo a cargar la pila original
    while (p_es_vacia(paux1) != true)
    {
        elemento = p_desapilar(paux1);
        p_apilar(p,elemento);
    }

    return paux2;
}


//int main()
void ejecutar_TP2_EJ06()
{

    Pila p1 = p_crear();
    Pila p_invertida = p_crear();

    p_apilar(p1,te_crear(1));
    p_apilar(p1,te_crear(2));
    p_apilar(p1,te_crear(3));
    p_apilar(p1,te_crear(4));
    p_apilar(p1,te_crear(5));
    p_apilar(p1,te_crear(6));
    p_apilar(p1,te_crear(7));

    p_mostrar(p1);

    p_invertida = invertir(p1);
    p_mostrar(p_invertida);

    system("pause");
    return 0;
}