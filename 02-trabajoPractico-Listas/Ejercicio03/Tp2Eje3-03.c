#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/main_tp3.h"
#include "libs/listas/headers/Tp_2_listas.h"

#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"


ResultadosMul multiplo(Lista l1, Lista l2) {
    ResultadosMul res;

    
    res.esMultiplo=true;
    res.escalar=true;
    res.numEscalar=7;
    
    return res;
}

/*
typedef struct
{
    bool esMultiplo;
    bool escalar;
    int numEscalar;
} ResultadosMul;
ResultadosMul multiplo(Lista l1, Lista l2);
 
*/