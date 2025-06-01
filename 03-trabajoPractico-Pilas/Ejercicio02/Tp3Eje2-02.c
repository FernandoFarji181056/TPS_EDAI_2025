#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/pilas/headers/pilas.h"
#include "libs/pilas/headers/tp_pilas.h"




/*
2. Dada una pila cargada con valores al azar realizar los siguientes ejercicios:
    a. Buscar una clave y determinar si existe en la Pila (sin perder la pila).
    b. Colocar en una posición ordinal determinada, recibida por parámetro, un
    nuevo elemento (Insertar un elemento nuevo).
    c. Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la
    clave).
    d. Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la
    2da con la 4ta.
    e. Duplicar el contenido de una pila.
    f. Contar los elementos de la pila.
*/

static const int num_min = 0;
static const int num_max = 20;

bool cargarPilaManual(Pila P1) {
    int entero;
    bool x = false;
    TipoElemento te;

    while (!p_es_llena(P1) && !x){
        clearScreen();
        printf("Contenido de la pila: ");
        p_mostrar(P1);
        printf("Ingrese un numero entero entre %d y %d o ingrese 'X' para finalizar: \n", num_min, num_max);
        entero = ingresaEnteroTeclado(&x);
        if (!x && (entero >= num_min && entero <= num_max)) {
            te = te_crear(entero);
            p_apilar(P1, te);
        }
    }
    return true;
}

bool cargarPilaAutomatica(Pila P1) {
    int entero;
    TipoElemento te;

    while (!p_es_llena(P1)){
        te = te_crear(rand() % (num_max - num_min + 1) + num_min); //aleatorio entre num_min y num_max
        p_apilar(P1, te);
    }
    return true;
}

void ejecutar_TP3_EJ02() {

    int entero1, entero2;
    int opcion = 0;
    bool x = false;
    Pila P1 = p_crear();
    TipoElemento te;

    clearScreen();
    printf("Ejercicio 2: \n");
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

    do{ //Submenu ejercicio 2
        clearScreen();
        p_mostrar(P1);
        printf("\n");
        printf("1: Buscar clave\n");
        printf("2: Insertar nuevo elemento\n");
        printf("3: Eliminar elemento a partir de clave\n");
        printf("4: Intercambiar valores de 2 posiciones\n");
        printf("5: Duplicar contenido\n");
        printf("6: Contar elementos\n");
        printf("Ingrese la opcion deseada o 'X' para salir\n");

        opcion = ingresaEnteroTeclado(&x);
        while ((opcion < 1 || opcion > 6) && !x){
            printf("Ingreso invalido, intente nuevamente\n");
            opcion = ingresaEnteroTeclado(&x);
        }

        switch (opcion){
        case 1:
            printf("Ingrese la clave a buscar en la pila: ");
            entero1 = ingresaEnteroTeclado(&x);
            while (x){
                printf("Ingreso incorrecto, intente nuevamente\n");
                entero1 = ingresaEnteroTeclado(&x);
            }
            if (p_ej2_existeclave(P1, entero1)){
                printf("La clave existe en la pila\n");
            } else printf("La clave no existe en la pila\n");
            system("pause");
            break;
        case 2:
            printf("Ingrese la clave a insertar en la pila, valores entre %d y %d:\n", num_min, num_max);
            entero1 = ingresaEnteroTeclado(&x);
            while((entero1 < num_min || entero1 > num_max) || (x)){
                printf("Ingreso incorrecto, intente nuevamente\n");
                entero1 = ingresaEnteroTeclado(&x);
            }
            te = te_crear(entero1);
            printf("Ingrese la posicion donde desee a insertar el elemento:\n");
            entero1 = ingresaEnteroTeclado(&x);
            P1 = p_ej2_colocarelemento(P1, entero1, te);
            p_mostrar(P1);
            system("pause");
            break;
        case 3:
            printf("Ingrese la clave a eliminar en la pila:\n");
            entero1 = ingresaEnteroTeclado(&x);
            while (x){
                printf("Ingreso incorrecto, intente nuevamente\n");
                entero1 = ingresaEnteroTeclado(&x);
            }
            P1 = p_ej2_eliminarclave(P1, entero1);
            p_mostrar(P1);
            system("pause");
            break;
        case 4:
            printf("Ingrese la primera posicion a intercambiar:\n");
            entero1 = ingresaEnteroTeclado(&x);
            while (x){
                printf("Ingreso incorrecto, intente nuevamente\n");
                entero1 = ingresaEnteroTeclado(&x);
            }
            printf("Ingrese la segunda posicion a intercambiar:\n");
            entero2 = ingresaEnteroTeclado(&x);
            while (x){
                printf("Ingreso incorrecto, intente nuevamente\n");
                entero2 = ingresaEnteroTeclado(&x);
            }
            P1 = p_ej2_intercambiarposiciones(P1, entero1, entero2);
            p_mostrar(P1);
            system("pause");
            break;
        case 5:
            P1 = p_ej2_duplicar(P1);
            p_mostrar(P1);
            system("pause");
            break;
        case 6:
            printf("La cantidad de elementos de la pila es: %d\n", p_ej2_cantidadelementos(P1));
            system("pause");
            break;
        default:
            break;
        }

    } while (!x);


    
/*  a. Buscar una clave y determinar si existe en la Pila (sin perder la pila).
    b. Colocar en una posición ordinal determinada, recibida por parámetro, un
    nuevo elemento (Insertar un elemento nuevo).
    c. Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la
    clave).
    d. Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la
    2da con la 4ta.
    e. Duplicar el contenido de una pila.
    f. Contar los elementos de la pila.
*/

}
