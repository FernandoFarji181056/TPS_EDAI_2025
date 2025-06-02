#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"

/**
 4.	Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número decimal pasado como parámetro,
	a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal).
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).

void ejecutar_TP3_EJ04(){
    bool x = false;
    int decimal, base;

    clearScreen();
    printf("Ejercicio 3: \n");
    printf("Cambio de base\n");
    printf("Ingrese el numero decimal que desee cambiar de base:\n");
    decimal = ingresaEnteroTeclado(&x);
    while (x){
        printf("Ingreso incorrecto, intente nuevamente\n");
        decimal = ingresaEnteroTeclado(&x);
    }

    printf("Ingrese la base:\n");
    base = ingresaEnteroTeclado(&x);
    while (x){
        printf("Ingreso incorrecto, intente nuevamente\n");
        base = ingresaEnteroTeclado(&x);
    }

    printf("El numero %d en base %d es: %s\n", decimal, base, p_ej4_cambiarbase(decimal, base));
    system("pause");
}