#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//imprimirParentesisIzquierdo(int i);
//imprimirParentesisDerecho(int d);
void imprimirParentesisIzquierdo(int i);
void imprimirParentesisDerecho(int i);

int validarIngreso(char* input, int longitud);

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




	
void imprimirParentesisIzquierdo(int i){
	if (i==1){
	printf("(-");
			return;
	}
	else {
		printf("(");
		imprimirParentesisIzquierdo(i-1);
	}
}
	
void imprimirParentesisDerecho(int i){
	if (i==1){
		printf(")");
		return;
	}
	else {
		printf(")");
		imprimirParentesisDerecho(i-1);
	}
}




int main(){	
	
	int validacion=0;	
	int entero2;
	int salida=0;
	char string2[1000];
	
		do{				//Mientras Validacion sea cero (false) entra al while
//	printf ("Calcule el k-enesimo numero de la serie Fibonacci: \n\n");	
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
						salida=1;
						validacion=1;	}	//pone validacion en verdadera para salir del while pero no ejecuta el programa por Salida=1 (true)		
					
			}
		

		if (validacion==0){
			printf ("\n\n");
			printf ("EL INGRESO NO CUMPLE CON LOS REQUISITOS,\nPRESIONE ENTER Y VUELVA A INTENTARLO\n\n\n");
			system ("pause");
			printf ("\n\n");
			}
	system ("cls");
	
	}while(validacion==0);	
	
		
if (salida==0){ //si el numero es valida y salida = 0 (false) hace la recursividad
			
		printf("Nivel: %i\n",entero2);
		printf(" \n");
	
		imprimirParentesisIzquierdo(entero2);
	
		//printf("-");
	
		imprimirParentesisDerecho(entero2);
	
		printf(" \n");
		printf(" \n");
	
		system ("pause");
		return 0;	
			
	}
			
			else{
			printf ("\nHA SALIDO CON EXITO \n");
			printf ("\nMUCHAS GRACIAS POR UTILIZAR SISTEMAS UNLu \n\n");	
			}
			
		system ("pause");
		return 0;	

}


