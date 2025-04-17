#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/main_tp3.h"
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"







//--------------------------------------------------------------------
//MAIN PRINCIPAL
//--------------------------------------------------------------------
//int main ()
void ejecutar_TP2_EJ03()
{		//int salida=0;
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

		printf ("INTRODUZCA NUMEROS ENTEROS PARA CREAR UNA LISTA (SOLO NUMEROS, sin espacio ni otro caracter),\n");
        printf("INGRESE CERO EN AMBAS ENTRADAS O AMBAS ENTRADAS VACIAS PARA SALIR\n");
		do{		
		//printf("EL SEGUNDO NUMERO EXPLOTARA AL PRIMERO\n\n");
		
		printf ("\nIntroduzca un numero entero entre 2 y 1000 para agregar a la primera Lista o X para salir y cargar otra Lista: ");
		fgets(string1,1000,stdin); // pide por pantalla el ingreso
		int longitud1 = strlen(string1);
		string1[longitud1-1]='\0'; // quita el caracter \n que fgets agrega al final de string

		longitud1=strlen(string1);

		validacion1=validarEntero(string1); //valida el ingreso controlando que solo se hayan ingresado numeros

		if (  (string1[0] == 'X' || string1[0] == 'x') && longitud1==1   ){
			salida01=true;
			}

		if( validacion1==false && salida01==false ) 
		 {printf("la entrada NOOOOOO fue validada\n\n");}

		if (validacion1){
			entero1=(int) strtol(string1,NULL,10); //pasa string a entero
			 if (entero1 <2 || entero1 > 1000){
				printf("El numero ingresado no cumple con los requisitos, intentelo nuevamente\n");
				salida01=false;
			 }
			 else{
			X = te_crear(entero1);
			l_agregar(L, X);
			system ("cls");
			//l_mostrarLista(L);
			 }
		}
		}while(!salida01);

		//system("pause");
		system ("cls");
		printf("AHORA CARGAMOS LA SEGUNDA LISTA\n");

				do{		
			
		printf ("\nIntroduzca un numero entre 2 y 1000 para agregar a la segunda Lista o X para salir: ");
		fgets(string2,1000,stdin); // pide por pantalla el ingreso
		int longitud2 = strlen(string2);
		string2[longitud2-1]='\0'; // quita el caracter \n que fgets agrega al final de string

		longitud2=strlen(string2);

		validacion2=validarEntero(string2); //valida el ingreso controlando que solo se hayan ingresado numeros

		if (  (string2[0] == 'X' || string2[0] == 'x') && longitud2==1   ){
			salida02=true;
			}

		if( validacion2==false && salida02==false ) 
		 {printf("la entrada NOOOOOO fue validada\n\n");}

		if (validacion2){
			entero2=(int) strtol(string2,NULL,10); //pasa string a entero

			 if (entero2 <2 || entero2 > 1000){
				printf("El numero ingresado no cumple con los requisitos, intentelo nuevamente\n");
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
		
			if ( l_es_vacia (L) && l_es_vacia(L2) ){
			listasVacias=true;
			printf("ambas listas son vacias\n");
			system("pause");}



		}while(!salida02);

		system ("cls");
		printf("MOSTRAMOS AMBAS LISTAS\n\n");

		printf("Contenido de la primer Lista: \n");
		l_mostrar(L);

		printf("\nContenido de la segunda Lista: \n");
		l_mostrar(L2);
		printf("\n");

		if (  (l_longitud(L)==l_longitud(L2) ) && !listasVacias ){
			//printf("tienen el mismo tamano\n");
			int longit=l_longitud(L);

			X = l_recuperar(L, 1);
			float valor1=X->clave;
			//printf("valor1: %f \n",valor1);
			X = l_recuperar(L2, 1);
			float valor2=X->clave;
			//printf("valor2: %f \n",valor2);

			float multiplo = valor1 / valor2;
			//printf("el multiplo es: %f \n",multiplo);
		
			bool esMultiplo=true;
			for (i=2;i<=longit;i++){
				
				X = l_recuperar(L, i);			
				valor1=X->clave;
				//printf("igreso L1: %f \n",valor1);

				X = l_recuperar(L2, i);				
				valor2=X->clave;
				//printf("Ingreso L2: %f \n",valor2);

				//printf("el valor cuargado es: %i",valor1);
				//printf("i= %i\n",i);
				float multiplo2=valor1 / valor2;
				if (multiplo!=multiplo2)
					{ esMultiplo=false; }
			} if (esMultiplo){printf("\nUNA LISTA ES MULTIPLO DE LA OTRA\n\n");
			}else{printf("\nNO SON MULTIPLO\n\n");}

		}else {
			printf ("Las listas ingresadas NOOOO tienen el mismo tamanio o ambas son vacias, si lo desea puede velver a intertarlo\n\n");
			printf ("GRACIAS POR UTILIZAR SISTEMAS UNLu\n\n");
		
		}


		system("pause");
		return;
		
}
