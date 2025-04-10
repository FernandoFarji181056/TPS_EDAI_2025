#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
//#include "libs/validaciones/headers/Validacion_datos.h"

// ----- FUNCIONES DE VALIDACION ----- //
//#ifndef Validacion_datos
//#define Validacion_datos



//Prototipo de funcion
int sumaConjunto(int* conjunto, int longitud, int indice);
void imprimirConjunto(int* conjunto, int longitud, int indice);
void subconjuntos(int* conjunto,int longitud, int suma_buscada, int indiceConjunto, int* subconjunto, int indiceSubconjunto, int longitudSubconjunto);



bool validarEntero(char* cadena)
{
	//printf("entramos a validar entero\n");
    int i;
    bool esNumero = false;
    int longitud = strlen(cadena);

    if (cadena[0] == '-') i = 1;
    else i = 0;

    for (i; i < longitud; i++)
    {
        //Valido que el input sea un NUMERO
        if (cadena[i] >= 48 && cadena[i] <=57)
        {
            if (cadena[i] != ' ') esNumero = true;
            else return false;
            
        }
        else return false;
    }

    return esNumero;
}




/*
    Funcion recursiva 1
    Suma conjuntos recursivamente y devuelve el resultado
*/
int sumaConjunto(int* conjunto, int longitud, int indice)
{
    if (indice == longitud){
        return 0;
    }
    else
    {
        //printf("%d\n", conjunto[indice]);
        return conjunto[indice] + sumaConjunto(conjunto,longitud, indice + 1);
    }
}

/*
    Funcion recursiva 2
    Dado un conjunto, su longitud y su indice de comienzo los imprime en pantalla
*/
void imprimirConjunto(int* conjunto, int longitud, int indice)
{
    if (indice == longitud){
        return;
    }
    else
    {
        printf("%d,", conjunto[indice]);
        imprimirConjunto(conjunto,longitud, indice + 1);
    }
}


/*
    Funcion recursiva 3
    Recorre todo el array y prueba todas posibilidades de suma para encontrar el numero pedido 
*/
void subconjuntos(int* conjunto,int longitud, int suma_buscada, int indiceConjunto, int* subconjunto, int indiceSubconjunto, int longitudSubconjunto)
{
    int i;
    //Caso base: Si la suma del subconjunto encontrado es igual al numero buscado
    if (indiceConjunto == longitud)
    {

        int sumaSub = 0;
        sumaSub = sumaConjunto(subconjunto,indiceSubconjunto, 0);

        if (sumaSub == suma_buscada)
        {

            printf("{");
            imprimirConjunto(subconjunto,indiceSubconjunto,0);
            printf("}\n");   
        }
        
        return;

    }
    else
    {
        //Apila llamadas de funcion sin agregar nada al subconjunto
        subconjuntos(conjunto,longitud,suma_buscada,indiceConjunto+1, subconjunto, indiceSubconjunto, longitudSubconjunto);
        
        //Agrego elementos al subconjunto
        subconjunto[indiceSubconjunto] = conjunto[indiceConjunto];
        subconjuntos(conjunto,longitud,suma_buscada,indiceConjunto+1, subconjunto, indiceSubconjunto +1, longitudSubconjunto);
    }


}



int main()
{	int i=0;
	int longitud;
	int longitud1; 
	int enteroASumar;
	int entero2;

	char ingreso;
	char string1[1000];
	char string2[1000];
   
    int* conjuntoInicial = (int*) malloc(50 * sizeof(int));
    char* palabra_procesada = (char*) malloc(50 * sizeof(char));
    bool esValido = false;
	bool salir01 = false;
	bool salir02 = false;
	bool salir03 = false;
	bool validar = false;
 
    
    while (esValido == false)
         
    { 
	printf("Ingrese numeros enteros entre -99 y 99 para crear un conjunto con esos numeros, \nmaximo 99 numeros, minimo 6 numeros (X para salir): \n\n");

	printf("Ingrese un numero: \n");
	
		do{	
		
		fgets(string1,1000,stdin); // pide por pantalla el ingreso
		int longitud1 = strlen(string1);
		string1[longitud1-1]='\0'; // quita el caracter \n que fgets agrega al final de string
		int longitud2 = strlen(string1);
		
		
		if (   (string1[0]==88 || string1[0]==120) && longitud2==1   ){
			salir01=true;
			//salir02=true;
			//esValido=true;
		}else{
		
		validar=validarEntero(string1);
		int entero1=(int) strtol(string1,NULL,10); //pasa string a entero
		if (entero1<(-99) || entero1>99){validar=false;		}
		
		if (validar){
			printf("Ingreso valido\n\n");
			conjuntoInicial[i]=entero1;			

			i++;
			 printf("Cantidad actual de numeros validos ingresados: %i\n\n",i);
			printf("Ingrese otro numero (o X para salir y cargar el valor a sumar): \n");
		}else {	printf("Ingreso INVALIDO\n\n");
		 printf("Cantidad actual de numeros validos ingresados: %i\n",i);
				printf("Ingrese otro numero (o X para salir y cargar el valor a sumar): \n");	}
		

		 }

	//fin del while interno	 
}while (!salir01);



//system("pause");
	printf("\nAhora ingrese un numero entre 1 y 100 \npara formar los subconjuntos que sumen esta cifra ingresada a continuacion (X para salir del sistema)\n");
		do	{
	
		
		fgets(string2,1000,stdin); // pide por pantalla el ingreso
		int longitud3 = strlen(string2);
		string2[longitud3-1]='\0'; // quita el caracter \n que fgets agrega al final de string
		int longitud4 = strlen(string2);
		
		//validar ingreso
		//printf("string cargado con: %s\n",string1);
		
		
		if (   (string2[0]==88 || string2[0]==120) && longitud4==1   ){
		//	printf("se ingreso una X\n",string1);
			salir01=true;
			salir02=true;
			salir03=true;
			//esValido=true;
		}else{
		
				validar=validarEntero(string2);
		
		
					if (validar){
				
						entero2=(int) strtol(string2,NULL,10); //pasa string a entero
								if (entero2<1 || entero2>100){
								validar=false;	
								printf("ingreso INVALIDO\n");
								
								}
						
							else{
								//printf("ingreso valido\n");
							//	printf("ingrese otro numero o X para salir del sistema: \n");
								salir02=true;
								
			
								}
				
				}
				
										else{
								validar=false;	
								printf("ingreso INVALIDO\n");
								printf("ingrese otro numero o X para salir: \n");
				
			
								}

		}
	//fin del while interno	 
		 }while (!salir02);
		 
		esValido = true;
		
//fin del while externo

    }


    if (salir03==false && i!=0){     	
 
	int longitudConjunto = i;  	
	
    int subconjunto[6];        

	int longitudSubConjunto = i;

    int sumaBuscada = entero2;
    
	int indiceConjunto = 0;
    
	int indiceSubconjunto = 0;
	
	int q=0;
	printf("\n");

printf("Los numeros ingresados fueron: \n");
	for (q=0; q<i ; q++) {


	printf("%i ",conjuntoInicial[q]);

	
	
	}
	printf("\n");
 	printf("\nSi hay subconjuntos que sumen esa cifra se mostraran a continuacion: \n");
    subconjuntos(conjuntoInicial,longitudConjunto,sumaBuscada,indiceConjunto,subconjunto,indiceSubconjunto,longitudSubConjunto);    
    
    
    printf("\nGRACIAS POR UTILIZAR SISTEMAS UNLu\n");
    
}
else if(salir03==false && i==0){
	printf("\nNO HA INGRESADO NINGUN NUMERO VALIDO EN EL CONJUNTO DE NUMEROS\n");
	printf("\nSI LO VUELVE A INTENTAR, RECUERDE QUE EL CONJUNTO DEBE TENER AL MENOS UN INGRESO VALIDO\n");
	
	printf("\nHA SALIDO CON EXITO DEL SISTEMA\nGRACIAS POR UTILIZAR SISTEMAS UNLu\n");	
}

else{
	printf("\nHA SALIDO CON EXITO DEL SISTEMA\nGRACIAS POR UTILIZAR SISTEMAS UNLu\n");
}
		printf(" \n");
    system("pause");
    return 0;
}
