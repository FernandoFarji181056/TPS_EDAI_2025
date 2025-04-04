#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        //if ((codigoAscii>= 65 && codigoAscii <= 90) || (codigoAscii>= 97 && codigoAscii <= 122))
          if ((codigoAscii>= 65 && codigoAscii <= 90) || (codigoAscii>= 97 && codigoAscii <= 122) || codigoAscii== 32  )
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


//Funcion prototipo
bool palindromo(char* palabra, int longitud, int comienzo);

//Desarrollo la funcion
bool palindromo(char* palabra, int longitud, int comienzo)
{

    //Caso base cuando longitud llega a 0
    if (longitud == 0)
    {
        return true; //la palabra es palindromo
    }
    else
    {
        if (palabra[comienzo] == palabra[longitud-1])
        {
            palindromo(palabra,longitud-1,comienzo+1);
        }
        else{
            return false; //La palabra NO es palindromo
        }
    }
}



int main(){


    int longitud;
    char* palabra = (char*) malloc(50 * sizeof(char));
    char* palabra_procesada = (char*) malloc(50 * sizeof(char));
    bool esValido = false;
    bool esPalindromo = false;

    printf("----- Palabras palindromas -----\n");

    while (esValido == false)
    {
        printf("Ingrese una palabra u oracion (X para salir): ");
        gets(palabra);
        longitud = strlen(palabra);

        //Si el texto ingresado es mas largo que lo que admite el array lo informa
        //y vuelve a pedir un texto
        if (longitud > 49){ printf("Excedio el limite de caracteres\n");}

        //Si el texto ingresado es una "x" o "X" y solamente se ingreso una letra
        //Sale del programa
        if ((palabra[0] == 88  || palabra[0] == 120) && longitud == 1) break;
        
        /* 
            Uso la funcion "validarLetras" para ver que solo se hayan ingresados
            caracteres alfabeticos. Caracteres numericos y especiales (como tildes, comas, guines)
            se devuelve como erroneo. 
            Si el input empieza con un 'espacio' tambien devuelve error
        */
        if (validarLetras(palabra) && longitud > 1 && longitud < 49 && palabra[0] != 32)
        {
            /*
                Paso toda la oracion a mayusculas para que los caracteres a comparar
                sean iguales
            */
            palabra_procesada = pasarAMayuscula(palabra);
       
            /*
                Calculo la longitud del array ya procesado sin espacios
                y compruebo que sea palindromo
            */

            longitud = strlen(palabra_procesada);
            esPalindromo = palindromo(palabra_procesada,longitud,0);

            if (esPalindromo) printf("Es palindromo\n");
            else printf("No es palindromo\n");

        }
        else
        {
            printf("Entrada incorrecta, no puede ingresar numeros, espacios ni caracteres especiales. Vuelva a intentarlo\n");
        }


    }

    printf("Fin de programa.\n");

    system("pause");
    return 0;
}
