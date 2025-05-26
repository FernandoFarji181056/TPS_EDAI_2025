#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"



void ejecutar_TP3_EJ05() {
    /*
    Invertir el contenido de una pila sin destruir la pila original. Se debe retornar la nueva
pila invertida y la original no se debe perder. Determinar la complejidad algorítmica
de la solución. 
    */
    char string1[1000];
    bool validacion1=false;
    int entero1;
    bool salida01=false;

    clearScreen();

    printf("\nIngresaste al ejercicio 5 de Pilas, cargaremos un pila manualmente y la invertiremos\n");
    Pila p;
    Pila p_invertida;
    //TipoElemento elemento;
    TipoElemento X;
    p = p_crear();
    p_invertida = p_crear();

    printf("\nCargue la pila antes de empezar con el programa\n");

    do{	
        p_mostrar(p); 
    	printf ("\nIntroduzca un numero entero entre -1000 y 1000 para agregar a la primera Lista o X para salir: ");

		fgets(string1,1000,stdin); // pide por pantalla el ingreso
		int longitud1 = strlen(string1);
		string1[longitud1-1]='\0'; // quita el caracter \n que fgets agrega al final de string
		longitud1=strlen(string1);
		validacion1=validarEntero(string1); //valida el ingreso controlando que solo se hayan ingresado numeros

        if (  (string1[0] == 'X' || string1[0] == 'x') && longitud1==1   ){
			salida01=true;
			}


        if (validacion1){
            printf("es un entero valido\n");
            entero1=(int) strtol(string1,NULL,10); //pasa string a entero
           // p_mostrar(p); 

        if( validacion1==false && salida01==false ) 
		     {printf("la entrada NO fue validada\n\n");}

        if (entero1 <-1000 || entero1 > 1000){
			        	printf("El numero ingresado no cumple con los requisitos, intentelo nuevamente\n");
			        	//salida01=false;
                        //system("pause");
			         }
			         else{
			        X = te_crear(entero1);
                    //system("pause");
                    if(p_apilar(p,X)){
                        printf("se apilo correctamente\n");
                        //system("pause");
                    }

		        	 }
                     //p_mostrar(p); 
                    
                     //system("pause");
                        



        }
        //else {printf("NO es un entero valido\n");}
        clearScreen();
   }while(!salida01);


    p_mostrar(p); 
    printf("\n");
                    
 }
