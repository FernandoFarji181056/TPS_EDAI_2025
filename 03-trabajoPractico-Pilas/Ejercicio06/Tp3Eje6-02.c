#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"

/**
6.	Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado ítem sin perder la pila original.
	Deberá retornar una nueva pila sin el ítem en consideración.
	Resolver iterativamente y recursivamente.
	Determinar la complejidad algorítmica de ambas soluciones.
 */
// retornar la nueva pila sin la clave que se debe sacar (eliminar). Si la clave no esta se retorna la pila recibida.
// La definicion vale para ambas resoluciones

void ejecutar_TP3_EJ06(){
    int opcion = 0;
    Pila P1 = p_crear();
    bool x = false;
    Pila Presultado;
    int entero1;

    clearScreen();
    printf("Ejercicio 6: \n");
    printf("Ingresa 1 si desea realizar la carga manual de la pila\n");
    printf("Ingresa 2 si desea realizar la carga automatica de la pila\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        cargarPilaManual(P1);
        break;
    case 2:
        srand(time(NULL));    //para evitar tener la misma secuencia de numeros
        cargarPilaAutomatica(P1);
        break;
    default:
        break;
    }

    clearScreen();
    printf("Pila 1\n");
    p_mostrar(P1);
    printf("Ingrese la clave a eliminar de la pila:\n");
    entero1 = ingresaEnteroTeclado(&x);
    while (x){
        printf("Ingreso incorrecto, intente nuevamente\n");
        entero1 = ingresaEnteroTeclado(&x);
    }
    
    Presultado = p_ej6_eliminarclave(P1, entero1);
    printf("\n");
    printf("Contenido de las pilas despues del procesamiento\n");
    printf("Pila original\n");
    p_mostrar(P1);
    printf("Pila resultado\n");
    p_mostrar(Presultado);
    printf("\n");
    printf("La complejidad del algoritmica de esta implementacion iterativa es de O(n) donde n es la cantidad de elementos de la pila, se recorre la pila dos veces, una para extraer y otra para restaurar\n");
    printf("La complejidad del algoritmica de esta implementacion recursiva es de O(n) donde n es la cantidad de elementos de la pila, en cada llamada recursiva se desapila un elemento y al volver hacia atras lo vuelve a apilar\n");
    printf("\n");
    system("pause");
}