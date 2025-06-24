#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"
#include "../main_tp5.h"


/**
6.	Dados dos conjuntos de números naturales se pide determinar si uno es subconjunto propio del otro.  
	Determinar la complejidad algorítmica
*/

/*
static const int num_min = 0;
static const int num_max = 20;

bool cargarConjuntoManual(Conjunto C1) {
    int entero;
    bool x = false;
    TipoElemento te;

    while (!cto_es_lleno(C1) && !x){
        clearScreen();
        printf("Contenido del Conjunto: ");
        cto_mostrar(C1);
        printf("Ingrese un numero entero entre %d y %d o ingrese 'X' para finalizar: \n", num_min, num_max);
        entero = ingresaEnteroTeclado(&x);
        if (!x && (entero >= num_min && entero <= num_max)) {
            te = te_crear(entero);
            cto_agregar(C1, te);
        }
    }
    return true;
}

bool cargarConjuntoAutomatica(Conjunto C1) {
    int entero;
    TipoElemento te;
    bool x;
    
    printf("Ingrese la cantidad deseada de elementos del conjunto:\n");
    entero = ingresaEnteroTeclado(&x);
    while (entero < 1){
        printf("Ingreso incorrecto, intente nuevamente\n");
        entero = ingresaEnteroTeclado(&x);
    }
    
    while (!cto_es_lleno(C1) && entero != 0){
        te = te_crear(rand() % (num_max - num_min + 1) + num_min); //aleatorio entre num_min y num_max
        cto_agregar(C1, te);
        entero = entero - 1;
    }
    return true;
}
*/

void ejecutar_TP5_EJ06(){
    
    int entero1;
    int opcion = 0;
    bool x = false;
    Conjunto C1 = cto_crear();
    Conjunto C2 = cto_crear();
    Conjunto C3;
    TipoElemento te;

    clearScreen();
    printf("Ejercicio 6: \n");
    printf("Ingresa 1 si desea realizar la carga manual de los conjuntos\n");
    printf("Ingresa 2 si desea realizar la carga automatica de los conjuntos\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    switch (opcion){
    case 1:
        cargarConjuntoManual(C1);
        cargarConjuntoManual(C2);
        break;
    case 2:
        srand(time(NULL));    //para evitar tener la misma secuencia de numeros
        cargarConjuntoAutomatica(C1);
        cargarConjuntoAutomatica(C2);
        break;
    default:
        break;
    }

    
    clearScreen();
    printf("Conjunto 1:\n");
    cto_mostrar(C1);
    printf("Conjunto 2:\n");
    cto_mostrar(C2);
    printf("\n");

    if(c_ej6_subconjuntopropio(C1, C2)){
        printf("El conjunto 1 es un subconjunto propio del conjunto 2\n");
    } else {
        if(c_ej6_subconjuntopropio(C2, C1)){
            printf("El conjunto 2 es un subconjunto propio del conjunto 1\n");
        } else {
            printf("No es un subconjunto\n");
        }
    }
    printf("La complejidad algoritmica es O(n^2) en el peor de los casos\n");

    system("pause");
        
}