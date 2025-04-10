/*
Generar un algoritmo recursivo que calcule el k-�simo n�mero de la serie de Fibonacci.
Ejemplos:
terminoSeridFibonacci (1) => 1
terminoSeridFibonacci (6) => 8 
*/


#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/validaciones/headers/Validacion_datos.h"

int Fibo (int n);

int validarIngreso(char* input, int longitud);


/*
    La funcion devuelve un booleano (entero que 0 false o 1 true, que uso como booleano) 
	para validar si el string ingresado es un numero int valido o no
    Se compara con el codigo ASCII del 48 al 57 que son los numeros del 0 al 9
	si es valido devuelvo 1, si no devuelve 0
*/
int validarIngreso(char* input, int longitud)
{
    int i;
    int j;
    int valido=1;	
 	for ( i = 0; i<longitud; i++) {
 		j=input[i];
		//Valido que el input sea un NUMERO
 		 if ( j<48 || j>57 ) 	
	   		{ 
			   valido = 0 ;
			       } 
			}			
	return valido;
}

/*
    La funcion recursiva Fibo, devuelve un entero con el resultado
*/
int Fibo(int n){
	if (n<=1){
		
			return n;}
	else {
		return Fibo(n-1)+ Fibo (n-2);
	}	
 }

 //int main(){
	int terminoSeridFibonacci(int k) {
		(void)k; // Para evitar advertencias por no usar el parámetro


	int validacion=0;	
	int entero2;
	int salida=0;
	char string2[1000];
	
		do{				//Mientras Validacion sea cero (false) entra al while
	printf ("Calcule el k-enesimo numero de la serie Fibonacci: \n\n");	
	printf ("INTRODUZCA UN NUMERO ENTERO ENTRE 1 Y 30 (SOLO NUMEROS, sin espacio ni otro caracter),\n");
	printf ("O INTRODUZCA CERO PARA SALIR: ");

	fgets(string2,1000,stdin);		
	int longitud2 = strlen(string2);
	string2[longitud2-1]='\0'; //quita el espacio que pone fgets al final del string
	longitud2=strlen(string2);

	if (longitud2!=0){	//si fue un ingreso vacio no va entra a validar, validacion queda en cero
	validacion=validarIngreso(string2,longitud2);
	}			
		if (validacion==1){ //entra si el ingreso es valido
			entero2=(int) strtol(string2,NULL,10); //pasa el string a entero

			
			if (entero2<1 || entero2>30){ //entra si el numero ingresado NO esta dentro de los parametros permitidos y pone a validacion en cero
			
				validacion=0;
			}
						if (entero2==0){	//si se ingreso un cero, deja las variables de la forma para que salga del programa
						salida=1; //esta variable hace que al salir del white no se ejecute el recursivo fibonacci, sale del sistema
						validacion=1;	}	//pone validacion en verdadera para salir del while pero no ejecuta el programa por Salida=1		
					
			}
		

		if (validacion==0){
			printf ("\n\n");
			printf ("EL INGRESO NO CUMPLE CON LOS REQUISITOS,\nPRESIONE ENTER Y VUELVA A INTENTARLO\n\n\n");
			system ("pause");
			printf ("\n\n");
			}
	system ("cls");
	
	}while(validacion==0);
	
	if (salida==0){ //si el numero es valida y salida = 0 hace el calculo Fibo
			int res= Fibo(entero2);
			printf ("\nEl numero ingresado es %d\n",entero2);
			printf ("\nEl resultado es %d\n\n",res);
			printf ("MUCHAS GRACIAS POR UTILIZAR SISTEMAS UNLu \n\n");
	
			printf(" \n");

			system ("pause");
			return 0;
			}
			
			else{
			printf ("\nHA SALIDO CON EXITO \n");
			printf ("\nMUCHAS GRACIAS POR UTILIZAR SISTEMAS UNLu \n\n");	
			}
	system("pause");
	return 0;

}
