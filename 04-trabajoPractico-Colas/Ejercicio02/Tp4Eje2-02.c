#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/colas/headers/colas.h"
#include "../tp_colas.h"


/*
2) Resolver los siguientes puntos:
    a. Informar si un elemento dado se encuentra en la cola.
    b. Agregar un nuevo elemento en una posición dada (colarse).
    c. Dado un elemento sacarlo de la cola todas las veces que aparezca.
    d. Contar los elementos de la cola.
    e. Realizar una función que realice una copia de una cola.
    f. Invertir el contenido de una cola sin destruir la cola original.
*/

static const int num_min = 0;
static const int num_max = 20;

bool cargarColaManual(Cola C1) {
    int entero;
    bool x = false;
    TipoElemento te;

    while (!c_es_llena(C1) && !x){
        clearScreen();
        printf("Contenido de la Cola: ");
        c_mostrar(C1);
        printf("Ingrese un numero entero entre %d y %d o ingrese 'X' para finalizar: \n", num_min, num_max);
        entero = ingresaEnteroTeclado(&x);
        if (!x && (entero >= num_min && entero <= num_max)) {
            te = te_crear(entero);
            c_encolar(C1, te);
        }
    }
    return true;
}

bool cargarColaAutomatica(Cola C1) {
    int entero;
    TipoElemento te;
    bool x;
    
    printf("Ingrese la cantidad deseada de elementos de la cola:\n");
    entero = ingresaEnteroTeclado(&x);
    while (entero < 1){
        printf("Ingreso incorrecto, intente nuevamente\n");
        entero = ingresaEnteroTeclado(&x);
    }
    
    while (!c_es_llena(C1) && entero != 0){
        te = te_crear(rand() % (num_max - num_min + 1) + num_min); //aleatorio entre num_min y num_max
        c_encolar(C1, te);
        entero = entero - 1;
    }
    return true;
}

void ejecutar_TP4_EJ02(){
    
    int entero1;
    int opcion = 0;
    bool x = false;
    Cola C1 = c_crear();
    Cola Caux = c_crear();
    TipoElemento te;

    clearScreen();
    printf("Ejercicio 2: \n");
    printf("Ingresa 1 si desea realizar la carga manual de la cola\n");
    printf("Ingresa 2 si desea realizar la carga automatica de la cola\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        cargarColaManual(C1);
        break;
    case 2:
        srand(time(NULL));    //para evitar tener la misma secuencia de numeros
        cargarColaAutomatica(C1);
        break;
    default:
        break;
    }

    do{ //Submenu ejercicio 2
        clearScreen();
        c_mostrar(C1);
        printf("\n");
        printf("1: Buscar clave\n");
        printf("2: Agregar nuevo elemento\n");
        printf("3: Eliminar elemento a partir de clave\n");
        printf("4: Contar elementos\n");
        printf("5: Copiar cola\n");
        printf("6: Invertir cola\n");
        printf("Ingrese la opcion deseada o 'X' para salir\n");

        opcion = ingresaEnteroTeclado(&x);
        while ((opcion < 1 || opcion > 6) && !x){
            printf("Ingreso invalido, intente nuevamente\n");
            opcion = ingresaEnteroTeclado(&x);
        }

        switch (opcion){
        case 1:
            printf("Ingrese la clave a buscar en la cola: ");
            entero1 = ingresaEnteroTeclado(&x);
            while (x){
                printf("Ingreso incorrecto, intente nuevamente\n");
                entero1 = ingresaEnteroTeclado(&x);
            }
            if (c_ej2_existeclave(C1, entero1)){
                printf("La clave existe en la cola\n");
            } else printf("La clave no existe en la cola\n");
            system("pause");
            break;
        case 2:
            printf("Ingrese la clave a colar en la cola, valores entre %d y %d:\n", num_min, num_max);
            entero1 = ingresaEnteroTeclado(&x);
            while((entero1 < num_min || entero1 > num_max) || (x)){
                printf("Ingreso incorrecto, intente nuevamente\n");
                entero1 = ingresaEnteroTeclado(&x);
            }
            te = te_crear(entero1);
            printf("Ingrese la posicion donde desee a insertar el elemento:\n");
            entero1 = ingresaEnteroTeclado(&x);
            Caux = c_ej2_colarelemento(C1, entero1, te);
            c_mostrar(Caux);
            system("pause");
            break;
        case 3:
            printf("Ingrese la clave a eliminar de la cola:\n");
            entero1 = ingresaEnteroTeclado(&x);
            while (x){
                printf("Ingreso incorrecto, intente nuevamente\n");
                entero1 = ingresaEnteroTeclado(&x);
            }
            Caux = c_ej2_sacarelemento(C1, entero1);
            c_mostrar(Caux);
            system("pause");
            break;
        case 4:
            printf("La cantidad de elementos de la cola es: %d\n", c_ej2_contarelementos(C1));
            system("pause");
            break;
        case 5:
            Caux = c_ej2_copiar(C1);
            c_mostrar(Caux);
            system("pause");
            break;
        case 6:
            Caux = c_ej2_invertir(C1);
            printf("La cola invertida es:\n");
            c_mostrar(Caux);
            system("pause");
            break;
        default:
            break;
        }

    } while (!x);

}