#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


// ----- FUNCIONES DE VALIDACION ----- //
#ifndef Validacion_datos
#define Validacion_datos


/*
    La funcion devuelve un booleano para validar si el string ingresado es un numero int valido o no
    Se compara con el codigo ASCII del 48 al 57 que son los numeros del 0 al 9
*/
bool validarEntero(char* cadena)
{
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
    La funcion recibe como parametro una cadena CHAR que va a contener la oracion original
    con mayusculas y minusculas. Retorna una cadena nueva solo en mayusculas
*/

char* pasarAMayuscula(char* cadena)
{

    int i;
    int longitud = strlen(cadena);
    char* cadenaMayus = (char*) malloc(longitud * sizeof (char));
    cadenaMayus = cadena;
    for (i = 0; i < longitud; i++)
    {

        int CodigoAscii = toupper(cadena[i]);
        cadenaMayus[i] = CodigoAscii;

    }
    //Si no pongo el valor de fin de cadena al array se lleno de datos basura
    cadenaMayus[i] = 0; 

    return cadenaMayus;

}


/*
    La funcion recibe como parametro una cadena CHAR que va a contener la oracion con espacios
    y la longitud de dicha cadena. Retorna una cadena nueva con la cadena original sin espacios
*/

char* sacarEspacios(char* input)
{
    int i,j;
    int longitud = strlen(input);
    char* output = (char*) malloc(longitud * sizeof(char));
    //*output = *input;
    for (i = 0, j = 0; i<longitud; i++,j++)          
    {
        if (input[i]!=' ')                           
            output[j]=input[i];       //copia los valores de input a output pero sin los espacios              
        else
            j--;                                     
    }
    //Ingresa el caracter de fin de linea /000 en el ultimo hueco del array
    //si no se ingresa este caracter el array contiene datos basura
    output[j]=0; 
    return output;
}



/*
    La funcion recibe como parametro un array de char y valida si su contenido son letras, sin importar si son mayusculas o minusculas.
    - Numeros y caracteres especiales no son validos
*/

bool validarLetras(char* cadena)
{

    int i;
    bool esValido = false;

    for (i = 0; i < strlen(cadena); i++)
    {

        int codigoAscii = cadena[i];
        if ((codigoAscii>= 65 && codigoAscii <= 90) || (codigoAscii>= 97 && codigoAscii <= 122) || codigoAscii == 32)
        {
            esValido = true;
        }
        else
        {   
            //Si al menos 1 digito no es una letra retorna input invalido
            return false;
        }

    }

        return esValido;


}



/*
    La funcion recibe un string por parametro y retorna un nuevo string invertido
*/
char* invertirString(char* cadena)
{
    int i,j;
    int longitud = strlen(cadena);

    char* cadena_invertida = (char*) malloc(longitud * sizeof(char));

    for (i = longitud-1, j = 0; i >= 0; i--,j++)
    {
        cadena_invertida[j] = cadena[i];
    }

    cadena_invertida[j] = 0; //Pongo el caracter de fin de linea
    return cadena_invertida;
    
}


#endif
// ----- FUNCIONES DE VALIDACION ----- //


char* quitarCerosIzquierda(char* numero)
{
    char* numero_Sin_cero = (char*) malloc(50 * sizeof(char));

    //Lo convierto a entero
    int x = strtol(numero,NULL,10);
    //Lo vuelvo a convertir a char array
    sprintf(numero_Sin_cero,"%d", x);
    int longitud = strlen(numero_Sin_cero);
    numero_Sin_cero[longitud] = 0;

    return numero_Sin_cero;
}


void SeparardorMiles(char* , int ,char*, int );


void SeparadorMiles(char* numero, int longitud, char* resultado, int n)
{
    //El flag lo que va a hacer es darse cuenta cuando poner la coma.
    //Cada vez que llegue a 3 pone una coma
    static int flag = 1;
    //Caso base
    if (longitud == 0){
        resultado[n] = 0; //Pongo ultimo caracter de fin de linea
        return;
    }
    else
    {
        if (flag > 3) //Cada 3 numeros pone una coma
        { 
            //Si se contaron 3 numeros agrego la coma
            resultado[n] = '.';
            flag = 1;
            return SeparadorMiles(numero, longitud,resultado,n+1);

        }
        else
        {
            //Arranco de atras para delante
            resultado[n] = numero[longitud-1];
            flag++;
            return SeparadorMiles(numero,longitud-1,resultado,n+1);

        }

        

    }


}


int main()
{




    int i,longitud;
    char* numero = (char*) malloc(50 * sizeof(char));
    char* numero2 = (char*) malloc(100 * sizeof(char));
    bool esValido = false;
    printf("----- Colocar separador -----\n");


    while (!esValido) //Mientras esValido sea false
    {

        printf("Ingrese un Numero (X para salir): ");
        gets(numero);
        longitud = strlen(numero);

        //Condicion de salida
        if ((numero[0] == 88  || numero[0] == 120) && longitud == 1) break;

        //Validaciones
        if (validarEntero(numero) && longitud < 10 && numero[0] != 32)
        {
            //Elimino los 0 de adelante
            numero = quitarCerosIzquierda(numero);
            longitud = strlen(numero);
            esValido = true;
        }
        else
        {
            printf("Error en el ingreso de datos. No ingrese numeros de mas de 10 caracteres.\nTampoco pueden contener espacios, puntos o comas.\n");
        }


    }

    SeparadorMiles(numero,longitud,numero2,0);
    longitud = strlen(numero2);
    //Imprimo el numero invertido
    for (i = longitud; i >= 0; i--)
    {
        printf("%c", numero2[i]);
    }

    printf("\nFin de programa.\n");
    system("pause");
    return 0;
}