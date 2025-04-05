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


void ondaDigital(char*, int,int);

void ondaDigital(char* senial, int longitud, int n)
{
    //Tengo un array char ['L','H','L']
    //Leo el array

    //Caso base cuando longitud llega a 1

    if (longitud == -1)
    {
        printf("\n");
        return;
    }
    else
    {
        if (senial[n] == 'L'){
            printf("_");
        }

        if (senial[n] == 'H'){
            //printf("%c", 196); //codigo ascii —
            printf("-");
            
        }

        if (longitud > 1 && senial[n+1] != senial[n] && (senial[n] == 'L' || senial[n] == 'H'))
        {
            printf("%c", 173); //codigo ascii de |
        }


        return ondaDigital(senial, longitud -1, n + 1);
    }

}



int main()
{

    int i;
    char* senial = (char*) malloc(50 * sizeof(char));
    char* senial_procesada;
    int longitud;
    bool esValido = false;
    bool esValido2 = true;


    //INPUT DE DATOS
    while (esValido == false)
    {
        esValido2 = true;
        printf("Ingrese L (low) o H (High) para graficar una onda digital (X para salir): ");
        gets(senial);
        longitud = strlen(senial);

        //Si el texto ingresado es mas largo que lo que admite el array lo informa
        //y vuelve a pedir un texto
        if (longitud > 49){ printf("Excedio el limite de caracteres\n"); esValido2 = false;}

        //Si el texto ingresado es una "x" o "X" y solamente se ingreso una letra
        //Sale del programa
        if ((senial[0] == 88  || senial[0] == 120) && longitud == 1) break;
        
        senial = pasarAMayuscula(senial);
        senial = sacarEspacios(senial);
        longitud = strlen(senial);
        //Hago un FOR
        for (i = 0; i < longitud; i++)
        {
            if (senial[i] != 'L' && senial[i] != 'H')
            {
                esValido2 = false;
            }

        }

        if (validarLetras(senial) && longitud >= 1 && longitud < 49 && esValido2 == true)
        {

            longitud = strlen(senial);
            ondaDigital(senial,longitud,0);

        }
        else
        {
            printf("ERROR solo puede ingresar L y H. El limite de caracteres es de 50, tampoco ingrese numeros ni caracteres especiales.\n");
        }



    }

    system("pause");
    return 0;
}