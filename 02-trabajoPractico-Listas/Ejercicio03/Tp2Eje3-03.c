#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "libs/listas/headers/listas.h"
//#include "libs/listas/headers/main_tp3.h"
#include "libs/listas/headers/Tp_2_listas.h"

#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"


ResultadosMul multiplo(Lista l1, Lista l2) {
    ResultadosMul res;
    res.esMultiplo=true;
    res.escalar=true;
    res.numEscalar=1000;

    int longit=l_longitud(l1);
    printf("la longitud de ambas listas es de %d: \n\n",longit);

    bool esMultiplo=true;
    int valor1;
    int valor2;
    int resto;
    int escalar01=0;
    int escalar02=0;
   // float multiplo01;
    TipoElemento X;


			for (int i=1;i<=longit;i++){
				
				X = l_recuperar(l1, i);			
				valor1=X->clave;
				//printf("igreso L1: %d \n",valor1);

				X = l_recuperar(l2, i);				
				valor2=X->clave;
				//printf("ingreso L2: %d \n",valor2);

                resto = valor2 % valor1;

                 if (resto!=0){
                    //bool esMultiplo=false;
                    res.esMultiplo=false;
                    res.escalar=false;

                }
                if (resto==0){
                    if (i == 1){
                        escalar01=valor2/valor1;
                        escalar02=escalar01;
                        res.numEscalar=escalar01;
                    }

                    
         
                    if (i != 1){
                        escalar01=valor2/valor1;
                        if (escalar01!=escalar02){
                            res.escalar=false;
                        }

                    }
                }
          
            }



/*
				printf("el valor guargado es: %i",valor1);
				printf("i= %i\n",i);
				float multiplo02=valor1 / valor2;
				if (multiplo01 != multiplo02)
					{ esMultiplo=false; }
			} if (esMultiplo){printf("\nUNA LISTA ES MULTIPLO DE LA OTRA\n\n");
			}else{printf("\nNO SON MULTIPLO\n\n");}
*/


    
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