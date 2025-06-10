#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "../tp_colas.h"

/**
5.	Dada una cola de valores enteros no repetidos y mayores o iguales a 2,
	obtener todos los valores que son Divisores Totales o parciales.
	Se dice que un valor es Divisor Total si permite dividir a todos los demás valores de la cola en forma exacta.
	Se dice que un divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola (es decir a la mitad de los elementos).
    Determinar la complejidad algorítmica de la solución.
    Ejemplo: si “C” contiene (8, 12, 2, 6, 4) se dice que “2” es el divisor total de la cola
    porque divide al resto en forma exacta. Y “4” es divisor parcial por divide a 8,12 y el
    mismo.
 */
// retorna una cola con los divisores totales o parciales.   Si no hay debe retornar cola vacia.
// En el atributo valor del tipolemento pondremos un True cuando el divisor es TOTAL, caso contrario false.
Cola c_ej5_divisortotal(Cola c){
    TipoElemento te, te2;
    Cola Caux = c_crear();
    Cola Cresultado = c_crear();
    int cantidad = 0;

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

    int divide;
    bool *total;
    //Recorro la cola y comparo el elemento contra sus siguientes para verificar si no se repite, encolo nuevamente el elemento en su final
    for (int i = 0; i < cantidad; i++){
        te = c_desencolar(c);
        divide = 1;
        //recorro sus siguientes 
        for (int j = 1; j < cantidad; j++){
            te2 = c_desencolar(c);
            if (te2->clave % te->clave == 0){
                divide++;
            }
            c_encolar(c, te2);
        }
        c_encolar(c,te);
        
        //Verifico si es divisor total
        if (divide == cantidad){
            total = malloc(sizeof(bool));
            *total = true;
            te = te_crear_con_valor(te->clave, total);
            c_encolar(Cresultado, te);
        } else {
            if (divide > (cantidad/2)){
                total = malloc(sizeof(bool));
                *total = false;
                te = te_crear_con_valor(te->clave, total);
                c_encolar(Cresultado, te);
            }
        }
    }
    return Cresultado;
}