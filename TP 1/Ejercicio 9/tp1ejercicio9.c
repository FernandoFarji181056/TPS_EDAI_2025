#include<stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Escribir una función recursiva que implemente el método que se describe para saber si
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente,
hasta que el resultado obtenido sea un número menor a 70. El número original será
múltiplo de 7 si el resultado da cero o múltiplo de 7.
*/

int multiplo (int n);

int validarIngreso(char* input, int longitud);

//funcion recursiva
int multiplo(int n){
	if (n<70){
		if ((n%7)==0){
			return 1;}
	
		else {				
				return 0;
		}
	}
	else {
		return multiplo( (n/10) - (n-(n/10)*10)*2  );
	}	
 }

//valida que todos los caracteres ingresados sean numeros
//devuelve 0 si algun caracter no lo es, y devuelve 1 si se ingresaron todos numeros
int validarIngreso(char* input, int longitud)
{
    int i;
    int j;
    int valido=1;	
    if (input[0]=='-'){
 		input[0]='0';
		}
 	for ( i = 0; i<longitud; i++) {

 		j=input[i];
 		 if ( j<48 || j>57 ) 	//valida que todos los caracteres ingresados sean numeros
	   		{ 
			   valido = 0 ;
			       } 
			}			
	return valido;
}


 int main(){

	int validacion=0;	
	int entero2;
	int salida=0;
	char string2[1000];
	
		do{	
	printf ("CODIGO PARA SABER SI UN NUMERO ES DIVISIBLE POR 7: \n\n");
	printf ("INTRODUZCA UN NUMERO ENTERO ENTRE -140.000 Y 140.000 (SOLO NUMEROS, sin espacio ni otro caracter),\n");
	printf ("O INTRODUZCA CERO PARA SALIR: ");

	fgets(string2,1000,stdin);		
	int longitud2 = strlen(string2);
	string2[longitud2-1]='\0';// quita el caracter \n que fgets agrega al final de string
	longitud2=strlen(string2);

	if (longitud2!=0){	//entra a validar si el ingreso no fue vacio
	validacion=validarIngreso(string2,longitud2);
	}
			
		if (validacion==1){ 
			entero2=(int) strtol(string2,NULL,10);//si el ingreso es valido, lo pasa a entero

			
			if (entero2<(-1400000) || entero2>140000){//valida que el ingreso este dentro del rango permitido
			
				validacion=0;
			}
						if (entero2==0){	
						salida=1;			//variables para salir del programa si el ingreso fue cero
						validacion=1;	}			
					
			}
		

		if (validacion==0){
			printf ("\n\n");
			printf ("EL INGRESO NO CUMPLE CON LOS REQUISITOS,\nPRESIONE ENTER Y VUELVA A INTENTARLO\n\n\n");
			system ("pause");
			printf ("\n\n");
			}
	system ("cls"); //borra pantalla
	system ("cls");
	
	}while(validacion==0); //sale del while si el ingreso fue invalido o si el ingreso fue cero
	
	if (salida==0){
		
			int res = multiplo(entero2);// manda el ingreso a resolver con recursividad
		//	printf ("\nEl numero ingresado es %d\n\n",entero2);
			
			if (res==1){	//muestra los mensajes finales
			//	printf("%i ES DIVISIBLE POR 7\n\n",entero2);
				printf("ES DIVISIBLE POR 7\n\n",entero2);
				printf ("\nMUCHAS GRACIAS POR UTILIZAR SISTEMAS UNLu \n\n");
				
			}
			else {
				//printf("%i NO ES DIVISIBLE POR 7\n\n",entero2);
				printf("NO ES DIVISIBLE POR 7\n\n");
				printf ("\nMUCHAS GRACIAS POR UTILIZAR SISTEMAS UNLu \n\n");
			}
		}						
			
		else{
			printf ("\nHA SALIDO CON EXITO \n");
			printf ("\nMUCHAS GRACIAS POR UTILIZAR SISTEMAS UNLu \n\n");	
		}
			
		system("pause")	;
		return 0;

}


 
