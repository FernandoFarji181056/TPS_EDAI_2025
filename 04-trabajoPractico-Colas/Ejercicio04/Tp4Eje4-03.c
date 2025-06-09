#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "../tp_colas.h"

/**
4.	Dada una cola de números enteros, no ordenada,
	construir un algoritmo que permita pasar a otra cola todos los elementos que no se repiten en la primera,
	sin destruir el contenido de la cola original y dejándola en su estado inicial.
    Determinar la complejidad algorítmica de la solución.
    Ejemplo: si "C" contiene (12,6, 8, 5, 8, 12, 12) la cola resultado del proceso sería (6,5).
 */
// Retorna la cola con las claves que no tienen repeticiones, caso contrario si todas se repiten retorna cola vacia.
Cola  c_ej4_colanorepetidos(Cola c){
    int cantidad = 0;
    TipoElemento te, te2,teaux;
    Cola Caux = c_crear();
    Cola Cresultado = c_crear();
    bool repite;

    //primero cuento los elementos de la cola y restauro la cola a su original
    while (!c_es_vacia(c)){
        te = c_desencolar(c);
        c_encolar(Caux, te);
        cantidad = cantidad + 1;
    }
    while (!c_es_vacia(Caux)){
        te = c_desencolar(Caux);
        c_encolar(c, te);
    }

    //Recorro la cola y comparo el elemento contra sus siguientes para verificar si no se repite, encolo nuevamente el elemento en su final
    for (int i = 0; i < cantidad; i++){
        te = c_desencolar(c);
        repite = false;
        //recorro sus siguientes 
        for (int j = 1; j < cantidad; j++){
            te2 = c_desencolar(c);
            if (te->clave == te2->clave){
                repite = true;
            }
            c_encolar(c, te2);
        }
        c_encolar(c,te);
        
        //Si no se repitio entonces lo agrego en la cola resultado si es que no existe
        if (!repite){
            //verificar si existe en la cola resultado, lo hago despues, ignorar
            teaux = te_crear(te->clave);
            c_encolar(Cresultado, teaux);
        }
    }
    
    return Cresultado;
}