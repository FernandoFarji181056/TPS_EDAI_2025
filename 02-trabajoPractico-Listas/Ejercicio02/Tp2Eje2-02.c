#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/tp_2_listas.h"
#include "libs/validaciones/headers/Validacion_datos.h"



/*
Dada una 2 listas (L1 y L2) cargadas con valores al azar (en la clave) realizar los siguientes
ejercicios:
a. Que retorne una lista con los valores de L1 que no están en L2.
b. Que retorne una lista con los valores de L2 que no están en L1.
c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
d. Que retorne los promedios de ambas listas.
e. Que retorne el valor mínimo de ambas listas y su posición ordinal.
*/

static const int max_elementos = 10;
static const int num_max = 100;
static const int num_min = 0;

int ingresaEntero(){
    int a, c;
    float f;
    do{
        fflush(stdin);
        c = scanf(" %f", &f);
        a = f;
        if ((a != f) || (c != 1)){
            printf("Ingreso incorrecto, intente nuevamente: ");
        }
    } while ((a != f) || (c != 1));
    return a;
}

bool cargaListaManual(Lista L1){
    int entero;
    int continuar = 1; //1 = Seguir ingresando, 2 = finalizar ingreso
    TipoElemento Y;
    printf("Cargue la lista con numeros enteros del %d al %d\n", num_min, num_max);
    while ( (l_es_llena(L1) == false) && (continuar == 1) ){
        printf("Ingrese un numero entero (%d a %d): ", num_min, num_max);
        //scanf(" %d", &entero);
        entero = ingresaEntero();

        while (entero < num_min || entero > num_max){
            printf("Ingreso invalido, ingrese un numero entero (%d a %d): ", num_min, num_max);
            //scanf(" %d", &entero);
            entero = ingresaEntero();
        }

        Y = te_crear(entero);
        l_agregar(L1, Y);

        printf("Desea ingresar otro numero?\n");
        printf("En caso afirmativo ingrese 1, sino ingrese 2: ");
        //scanf(" %d", &continuar);
        continuar = ingresaEntero();

        while (continuar < 1 || continuar > 2){
            printf("Ingreso invalido\n");
            printf("En caso afirmativo ingrese 1, sino ingrese 2: ");
            //scanf(" %d", &continuar);
            continuar = ingresaEntero();
        }
    }
    return true;
}

bool cargaListaAutomatica(Lista L1){
    //srand(time(NULL));    llamar a la función en una función mas generica para evitar tener la misma secuencia de numeros
    int cant_elementos = rand() % (max_elementos) + 1; //aleatorio entre 1 y 10
    
    TipoElemento Y;
    for (int i = 0; i < cant_elementos; i++){
        if (!l_es_llena(L1)){
            Y = te_crear(rand() % (num_max - num_min + 1) + num_min); //aleatorio entre num_min y num_max
            l_agregar(L1,Y);
        } else{
            return true;
        }
    }
    return true;
}


void ejecutar_TP2_EJ02(){
    clearScreen();
    printf("Ejercicio 2:\n");
    int opcion;
    Lista L1 = l_crear();
    Lista L2 = l_crear();

    printf("Ingresa 1 si desea realizar la carga manual de las listas\n");
    printf("Ingresa 2 si desea realizar la carga automática de las listas\n");
    opcion = ingresaEntero();
    while (opcion < 1 || opcion > 2){
        printf("Ingreso invalido\n");
        printf("Ingresa 1 si desea realizar la carga manual de las listas\n");
        printf("Ingresa 2 si desea realizar la carga automática de las listas\n");
        opcion = ingresaEntero();
    }
    
    switch (opcion)
    {
    case 1:
        printf("\n");
        printf("Lista L1\n");
        cargaListaManual(L1);
        printf("\n");
        printf("Lista L2\n");
        cargaListaManual(L2);
        break;
    case 2:
        srand(time(NULL));
        cargaListaAutomatica(L1);
        cargaListaAutomatica(L2);
        break;
    default:
        break;
    }
    printf("\n");
    printf("Lista L1\n");
    l_mostrar(L1);
    printf("\n");
    printf("Lista L2\n");
    l_mostrar(L2);

    printf("\n");
    printf("Los valores de L1 que no estan en L2 son:\n");
    l_mostrar(verElementosQueNoSeRepiten(L1,L2));

    printf("\n");
    printf("Los valores de L2 que no estan en L1 son:\n");
    l_mostrar(verElementosQueNoSeRepiten(L2,L1));

    printf("\n");
    printf("Los valores repetidos son:\n");
    l_mostrar(verElementosRepetidos(L1,L2));

    printf("\n");
    printf("El promedio de L1 es %2f\n", promedio(L1));
    printf("El promedio de L2 es %2f\n", promedio(L2));

    printf("\n");
    ResultadoValorMinimo puntoe = valorMinimo(L1, L2);
    printf("El valor minimo de L1 es %d y esta en la posicion %d\n", puntoe.valor, puntoe.pos);
    printf("El valor minimo de L2 es %d y esta en la posicion %d\n", puntoe.valor_2, puntoe.pos_2);

}

