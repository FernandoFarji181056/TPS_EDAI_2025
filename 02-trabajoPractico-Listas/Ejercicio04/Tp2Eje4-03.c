#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/main_tp3.h"
#include "libs/listas/headers/Tp_2_listas.h"

#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"


int CompararListas(Lista l1, Lista l2){
    int longitud=l_longitud(l1);
    int valor1=0;
    int valor2=0;
    int acumuladoLista1=0;
    int acumuladoLista2=0;

    TipoElemento X;

    printf("la longitud de ambas listas es de %d: \n\n",longitud);

    for (int i=1;i<=longitud;i++){
				
        X = l_recuperar(l1, i);			
        valor1=X->clave;
        //printf("igreso L1: %d \n",valor1);

        X = l_recuperar(l2, i);				
        valor2=X->clave;
        //printf("ingreso L2: %d \n",valor2);
        if (valor1>valor2){
            acumuladoLista1++;

        }
        if (valor1<valor2){
            acumuladoLista2++;
        }
        }
        //printf("acumuladoLista1: %d \n",acumuladoLista1);
        //printf("acumuladoLista2: %d \n",acumuladoLista2);

        if (acumuladoLista1>acumuladoLista2){
          
            return 1;
        }
        if (acumuladoLista1<acumuladoLista2){
       

            return 2;
        }
        if (acumuladoLista1==acumuladoLista2){
        
            return 0;
        }


}
