/*
    Dados dos números enteros m y n, construir una función recursiva que devuelva el 
    producto de ambos, calculando el mismo como sumas sucesivas. Esto es: 
    m*n=m+m+...+m, n veces. 
    Ejemplos: 
    producto(5, 3) => 15 
    producto (10, 4) => 40 
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
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



//Prototipo de la funcion
int producto(int m, int n);


int producto(int m, int n)
{
    //Casos bases:
    //1) cuando N es igual a 0 quiere decir que ya se hicieron todas las sumas
    if (n == 0)
    {    
        return 0;
    }
    else
    {
        return (m + producto(m,n-1));
    }

}


int main()
{

    int x,y;
    int resultado;
    char* numero1 = (char*) malloc(50 * sizeof(char));
    char* numero2 = (char*) malloc(50 * sizeof(char));
    char* numero_validado = (char*) malloc(11 * sizeof(char));
    bool esValido1 = false;
    bool esValido2 = false;
    bool esNegativo = false;

    printf("---------- Multiplicacion recursiva ----------\n\n");
    
    
    while (!esValido1 || !esValido2) //Mientras esValido sea falso entra al while
    {
        //Ingreso primer numero (multiplicando)
        if (esValido1 == false)
        {
            printf("Ingrese el multiplicando (X para salir): ");
            gets(numero1);
            //Condicion de salida
            if ((numero1[0] == 88  || numero1[0] == 120) && strlen(numero1) == 1){ system("pause"); return 0;}
        }

        if (validarEntero(numero1) || esValido1)
        {
            esValido1 = true;
            //Pido numero 2
            printf("Ingrese el multiplicador (X para salir): ");
            gets(numero2);

            //Condicion de salida
            if ((numero2[0] == 88  || numero2[0] == 120) && strlen(numero2) == 1) break;

            if (validarEntero(numero2))
            {
                esValido2 = true;
            }
            else
            {
                printf("Error en el dato ingresado. Vuelva a ingresar los datos\n");
            }        
        }
        else
        {
            printf("Error en el dato ingresado. Vuelva a ingresar los datos\n");
        } 


        if (esValido1 && esValido2)
        {
            x = strtol(numero1,NULL,10);
            y = strtol(numero2,NULL,10);

            if (x == __LONG_MAX__ || y == __LONG_MAX__)
            {
                esValido1 = false;
                esValido2 = false;
                printf("Los numeros ingresados fueron demasiado altos\n");
            }
        }
     

    }


    // ----- CONTROL DE NUMEROS NEGATIVOS ----- //

    if (x < 0 && y >= 0)
    {
        x = x*-1;
        resultado = producto(x,y);
        if (resultado != 0) esNegativo = true;
    }
    else if(y < 0 && x >= 0)
    {
        y = y*-1;
        resultado = producto(x,y);
        if (resultado != 0) esNegativo = true;
    }
    else if (x < 0 && y < 0)
    {
        x = x*-1;
        y = y*-1;
        resultado = producto(x,y);

    }
    else
    {
        resultado = producto(x,y);
    }

    
    if (esNegativo)
    {
        printf("Resultado: -%d\n",resultado);
    }
    else
    {
        printf("Resultado: %d\n",resultado);
    }
    
    

    system("pause");
    return 0;
}
