#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"
#include "libs/conjuntos/headers/conjuntos.h"
#include "../tp_conjunto.h"
#include "../main_tp5.h"


/*
2.	Desarrollar un algoritmo que dado dos conjuntos de elementos tipo numérico (clave) 
	verifique las operaciones de Unión,  Intersección,  Diferencia y Pertenencia. 

*/

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

void ejecutar_TP5_EJ02(){
    
    int entero1;
    int opcion = 0;
    bool x = false;
    Conjunto C1 = cto_crear();
    Conjunto C2 = cto_crear();
    Conjunto C3 = cto_crear();
    TipoElemento te;

    clearScreen();
    printf("Ejercicio 2: \n");
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

    do{ //Submenu ejercicio 2
        clearScreen();
        cto_mostrar(C1);
        cto_mostrar(C2);
        printf("\n");
        printf("1: Union\n");
        printf("2: Interseccion\n");
        printf("3: Diferencia\n");
        printf("Ingrese la opcion deseada o 'X' para salir\n");

        opcion = ingresaEnteroTeclado(&x);
        while ((opcion < 1 || opcion > 3) && !x){
            printf("Ingreso invalido, intente nuevamente\n");
            opcion = ingresaEnteroTeclado(&x);
        }

        switch (opcion){
        case 1:
            printf("Union: ");
            C3 = c_ej2_union(C1, C2);
            cto_mostrar(C3);
            system("pause");
            break;
        case 2:
            printf("Interseccion: ");
            C3 = c_ej2_interseccion(C1, C2);
            cto_mostrar(C3);
            system("pause");
            break;
        case 3:
            printf("Diferencia: ");
            C3 = c_ej2_diferencia(C1, C2);
            cto_mostrar(C3);
            system("pause");
            break;
        default:
            break;
        }

    } while (!x);

}