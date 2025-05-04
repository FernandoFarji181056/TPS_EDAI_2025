#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif
*/


#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/main_tp3.h"
#include "libs/listas/headers/Tp_2_listas.h"
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
/*
void clearScreen() {
	system(CLEAR_COMMAND);
 }
*/

void ejecutar_TP2_EJ04()
{	
		
	printf ("SOY EL EJERCICIO 4 DE LISTAS,\n\n");


        clearScreen();
  
		bool salida01=false;
		bool salida02=false;
		//int validacion1=0;
		bool validacion1=false;
		bool validacion2=false;
		bool listasVacias=false;
		int entero1;
		int entero2;
		char string1[1000];
		char string2[1000];
		//int longitud01;

		int i=0;
		TipoElemento X;
		Lista L;
		Lista L2;
		
		L =l_crear();
		L2 =l_crear();
		printf ("AHORA CARGAREMOS 2 LISTAS CON NUMEROS ENTEROS COMPRENDIDOS ENTRE 1 Y 1000,\n");
		printf ("LAS LISTA TIENEN QUE TENER EL MISMO TAMANIO Y NO PUEDE ESTAR VACIAS,\n");
		printf ("LUEGO SE INFORMARA SI LA SEGUNDA LISTA ES MULTIPLO DE LA PRIMERA Y SI ADEMAS ES ESCALAR,\n\n");
		printf ("INTRODUZCA NUMEROS ENTEROS PARA CREAR UNA LISTA (SOLO NUMEROS, sin espacio ni otro caracter),\n");
        printf("INGRESE 'x' SALIR\n");

		do{			
		
		printf ("\nIntroduzca un numero entero entre 1 y 1000 para agregar a la primera Lista o X para salir y cargar otra Lista: ");

		fgets(string1,1000,stdin); // pide por pantalla el ingreso
		int longitud1 = strlen(string1);
		string1[longitud1-1]='\0'; // quita el caracter \n que fgets agrega al final de string
		longitud1=strlen(string1);
		validacion1=validarEntero(string1); //valida el ingreso controlando que solo se hayan ingresado numeros

		if (  (string1[0] == 'X' || string1[0] == 'x') && longitud1==1   ){
			salida01=true;
			}

		if( validacion1==false && salida01==false ) 
		 {printf("la entrada NO fue validada\n\n");}

		if (validacion1){
			entero1=(int) strtol(string1,NULL,10); //pasa string a entero
			 if (entero1 <1 || entero1 > 1000){
				printf("El numero ingresado no cumple con los requisitos, intentelo nuevamente\n");
				salida01=false;
			 }
			 else{
			X = te_crear(entero1);
			l_agregar(L, X);
			//system ("cls");
			clearScreen();
			l_mostrar(L);
			 }
		}
		}while(!salida01);

		//system("pause");
		system ("cls");
		printf("AHORA CARGAMOS LA SEGUNDA LISTA\n");

				do{		
			
		printf ("\nIntroduzca un numero entre 1 y 1000 para agregar a la segunda Lista o X para salir: ");
		fgets(string2,1000,stdin); // pide por pantalla el ingreso
		int longitud2 = strlen(string2);
		string2[longitud2-1]='\0'; // quita el caracter \n que fgets agrega al final de string

		longitud2=strlen(string2);

		validacion2=validarEntero(string2); //valida el ingreso controlando que solo se hayan ingresado numeros

		if (  (string2[0] == 'X' || string2[0] == 'x') && longitud2==1   ){
			salida02=true;
			}

		if( validacion2==false && salida02==false ) 
		 {printf("la entrada NO fue validada\n\n");}

		if (validacion2){
			entero2=(int) strtol(string2,NULL,10); //pasa string a entero

			 if (entero2 < 1 || entero2 > 1000){
				printf("El numero ingresado NO cumple con los requisitos, intentelo nuevamente\n");
				salida01=false;
			 }
			 else{
			X = te_crear(entero2);
			l_agregar(L2, X);
			system ("cls");

			printf("Contenido de la primer Lista: \n");
			l_mostrar(L);

			printf("\nContenido de la segunda Lista: \n");
			l_mostrar(L2);
		

			}


		}


		}while(!salida02);

		system ("cls");
		printf("MOSTRAMOS AMBAS LISTAS\n\n");

		printf("Contenido de la primer Lista: \n");
		l_mostrar(L);

		printf("\nContenido de la segunda Lista: \n");
		l_mostrar(L2);
		printf("\n");

		if ( l_es_vacia (L) || l_es_vacia(L2) || l_longitud(L) != l_longitud(L2)){
			listasVacias=true;
			printf("NO PUEDE HABER LISTAS VACIAS Y LAS LISTAS TIENEN QUE TENER EL MISMO TAMANIO\n");
			printf("INTENELO NUEVAMENTE CUANDO QUIERA, GRACIAS\n");
			system("pause");}

			else {

				int resultado= CompararListas(L,L2);

				
				if ( resultado == 1 ){
					printf("LA PRIMERA LISTA ES MAYOR QUE LA SEGUNDA\n\n");
				}
				else if ( resultado == 2 ){
					printf("LA SEGUNDA LISTA EL MAYOR QUE LA PRIMERA\n\n");
				}
				else if ( resultado== 0 ){
					printf("AMBAS LISTAS SON IGUALES\n\n");
				}

				/*
				printf("ahora comparamos las listas\n");
				ResultadosMul resultado = multiplo(L, L2);

				if (resultado.esMultiplo) {
					printf("La segunda lista ES multiplo de la primera.\n");
				} else {
					printf("La segunda lista NO es multiplo de la primera.\n");
				}
			
				// Verificación de escalar
				if (resultado.escalar) {
					printf("Ademas, ES escalar. El numero escalar es: %d\n", resultado.numEscalar);
					//printf("El escalar es: %d", resultado.numEscalar);
				} else {
					printf("No es escalar.\n");
				}*/

			}



    }
		
