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
3.	Desarrollar un algoritmo que dada una colección de conjuntos de elementos tipo numérico (clave) 
	realice las operaciones de Unión e Intersección.
	La lista contendra la coleccion de conjuntos.  Cada campo void apunta a un conjunto.
*/

//static const int num_min = 0;
//static const int num_max = 20;

/*
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

void ejecutar_TP5_EJ03(){
    
    int entero1;
    int opcion = 0;
    bool x = false;
    Lista lista_conjuntos = l_crear();
    Conjunto C;
    Conjunto C2 = cto_crear();
    //Conjunto C3 = cto_crear();
    TipoElemento te;

    clearScreen();
    printf("Ejercicio 3: \n");
    printf("¿Cuantos conjuntos desea crear? Entre 2 y 10\n");
    int cantidad = 0;
    do {
        cantidad = ingresaEnteroTeclado(&x);
        if  (cantidad < 2 || cantidad > 10) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (cantidad < 2 || cantidad > 10);

    printf("Ingresa 1 si desea realizar la carga manual de los conjuntos\n");
    printf("Ingresa 2 si desea realizar la carga automatica de los conjuntos\n");
    do {
        opcion = ingresaEnteroTeclado(&x);
        if  (opcion < 1 || opcion > 2) {
            printf("Ingreso invalido, intente nuevamente\n");
        }
    } while (opcion < 1 || opcion > 2);

    for (int i = 0; i < cantidad; i++)
    {
        C = cto_crear();
        printf("Conjunto %d:\n", i+1);
        switch (opcion){
        case 1:
            cargarConjuntoManual(C);
            break;
        case 2:
            srand(time(NULL));    //para evitar tener la misma secuencia de numeros
            cargarConjuntoAutomatica(C);
            break;
        default:
            break;
        }

        te = te_crear_con_valor(i, C);
        l_agregar(lista_conjuntos, te);
    }

    do{ //Submenu ejercicio 2
        clearScreen();

        //mostrar todos los conjuntos
        Iterador ite = iterador(lista_conjuntos);
        int i = 1;
        while (hay_siguiente(ite)){
            TipoElemento te = siguiente(ite);
            C = (Conjunto) te->valor;
            printf("Conjunto %d: ", i);
            cto_mostrar(C);
            i++;
        }

        printf("\n");
        printf("1: Union\n");
        printf("2: Interseccion\n");
        printf("Ingrese la opcion deseada o 'X' para salir\n");

        opcion = ingresaEnteroTeclado(&x);
        while ((opcion < 1 || opcion > 2) && !x){
            printf("Ingreso invalido, intente nuevamente\n");
            opcion = ingresaEnteroTeclado(&x);
        }

        switch (opcion){
        case 1:
            printf("Union: ");
            C2 = c_ej3_uniones(lista_conjuntos);
            cto_mostrar(C2);
            system("pause");
            break;
        case 2:
            printf("Union: ");
            C2 = c_ej3_intersecciones(lista_conjuntos);
            cto_mostrar(C2);
            system("pause");
            break;
        default:
            break;
        }

    } while (!x);

}