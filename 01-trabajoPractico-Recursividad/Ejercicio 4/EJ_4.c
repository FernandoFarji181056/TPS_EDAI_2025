#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

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





float division(int m, int n)
{
    static int contador = 0;

    //Caso base cuando m < n
    if (m < n)
    {
        //La division es exacta no hay decimales
        if (m == 0) return 0;
        //else printf("RESTO= %d\n", m); return 0;
        
        if (m < n)
        {
            //Contador hace de flag para saber cuando parar la recursion
            contador++;

            //Multiplico m * 10 porque para calcular los decimales hay que agregar un 0 adelante del resto
            m = m*10;
            //Cuando m-n llego a un resultado que es menor a n, se divide por 10
            return  division(m,n) / 10;
        }
   
    }
    else
    {
        //El 1 va sumando la cantida de veces que se llama la funcion
        //por lo que cuando retorna retorna el total de llamadas
        if (contador == 0) return (1 + division(m-n,n)); 

        
        if (contador > 0)
        {
            if (contador > 4) return 0;
            return  1 + division(m-n,n); //Sumo la cantidad de veces que se resto m-n
        }
        
    }
}



int main()
{
    //int m =2;
    //int n = -3;

    int longitud,m,n;
    float resultado;
    bool negativo = false;

    //---------- INGRESO Y VALIDACION DE DATOS ----------//

    char* dividendo = (char*) malloc(50 * sizeof(char));
    char* divisor = (char*) malloc(50 * sizeof(char));
    char* numero_validado = (char*) malloc(11 * sizeof(char));
    bool esValido1 = false;
    bool esValido2 = false;

    printf("---------- Multiplicacion recursiva ----------\n\n");
    
    
    while (!esValido1 || !esValido2) //Mientras esValido sea falso entra al while
    {
        //Ingreso primer numero (multiplicando)
        if (esValido1 == false)
        {
            printf("Ingrese el dividendo (X para salir): ");
            gets(dividendo);
            //Condicion de salida
            if ((dividendo[0] == 88  || dividendo[0] == 120) && strlen(dividendo) == 1){ system("pause"); return 0;}
        }

        if (validarEntero(dividendo) || esValido1)
        {
            esValido1 = true;
            //Pido numero 2
            printf("Ingrese el divisor (X para salir): ");
            gets(divisor);

            //Condicion de salida
            if ((divisor[0] == 88  || divisor[0] == 120) && strlen(divisor) == 1) break;

            if (validarEntero(divisor))
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
            m = strtol(dividendo,NULL,10);
            n = strtol(divisor,NULL,10);

            if (m == __LONG_MAX__ || n == __LONG_MAX__)
            {
                esValido1 = false;
                esValido2 = false;
                printf("Los numeros ingresados fueron demasiado altos\n");
            }
        }
     

    }

    // ----- CONTROL DE NUMEROS NEGATIVOS ----- //
    
    if (m < 0 && n >= 0) //Si M es negativo se pasa a positivo
    {
        m = m*-1;
        resultado = division(m,n);
        negativo = true;
    }
    else if (n < 0 && m >= 0)//Si N es negativo se pasa a positivo
    {
        n = n*-1;
        resultado = division(m,n);
        negativo = true;
    }
    else if (n < 0 && m < 0) //Si AMBOS son negativos se pasan a positivo
    {
        m = m*-1;
        n = n*-1;
        resultado = division(m,n);
        
    }
    else //Si no cumple ninguna condicion por descarte son positivos
    {
        resultado = division(m,n);
    }
    // ----- CONTROL DE NUMEROS NEGATIVOS ----- //  


    if (negativo)
    {
        //Con %.4f limito los decimales a 4
        printf("El resultado de dividir %d/%d = -%.4f\n", m,n,resultado);
    }
    else
    {
        //Con %.4f limito los decimales a 4
        printf("El resultado de dividir %d/%d = %.4f\n", m,n,resultado);
    }


    system("pause");
    return 0;
}