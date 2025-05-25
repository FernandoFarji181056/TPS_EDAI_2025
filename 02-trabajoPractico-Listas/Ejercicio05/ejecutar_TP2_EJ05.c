#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "libs/listas/headers/listas.h"
//#include "libs/listas/headers/main_tp3.h"
#include "libs/listas/headers/Tp_2_listas.h"

#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

void clearScreen_05() {
    system(CLEAR_COMMAND);
}

void ejecutar_TP2_EJ05() {
    clearScreen_05();
    printf("EJERCICIO 5 - POLINOMIO\n\n");

    Lista poli = l_crear();
    char buffer[100];
    int grado;
    bool valido = false;

    //CARGA DEL POLINOMIO
    do {
        printf("Ingrese el grado del polinomio (entero >= 0): ");
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = 0;
        if (validarEntero(buffer)) {
            grado = atoi(buffer);
            if (grado >= 0) {
                valido = true;
            } else {
                printf("El grado debe ser mayor o igual a 0.\n");
            }
        } else {
            printf("Entrada no valida. Ingrese un numero entero.\n");
        }
    } while (!valido);

    for (int i = 0; i <= grado; i++) {
        float* coef = malloc(sizeof(float));
        printf("Coeficiente para x^%d: ", i);
        fgets(buffer, 100, stdin);
        *coef = atof(buffer);

        TipoElemento te = te_crear_con_valor(i, coef);
        l_agregar(poli, te);
    }

    clearScreen_05();
    printf("Polinomio cargado correctamente.\n");
    printf("Coeficientes (forma: [coef, exp]):\n");
    Iterador it = iterador(poli);
    while (hay_siguiente(it)) {
        TipoElemento te = siguiente(it);
        printf("[%.2f, x^%d] ", *((float*)te->valor), te->clave);
    }
    printf("\n");

    // EVALUAR UN VALOR DE X 
    float x;
    printf("\nIngrese un valor de X para evaluar el polinomio: ");
    fgets(buffer, 100, stdin);
    x = atof(buffer);

    float resultado = evaluarPoliomio(poli, x);
    printf("F(%.2f) = %.2f\n", x, resultado);

    // RANGO DE VALORES 
    float desde, hasta, paso;
    printf("\nIngrese el valor inicial del rango: ");
    fgets(buffer, 100, stdin);
    desde = atof(buffer);

    printf("Ingrese el valor final del rango: ");
    fgets(buffer, 100, stdin);
    hasta = atof(buffer);

    printf("Ingrese el incremento (paso): ");
    fgets(buffer, 100, stdin);
    paso = atof(buffer);

    Lista resultados = calcularRango(poli, desde, hasta, paso);
    printf("\nResultados del polinomio en el rango:\n");

    Iterador it2 = iterador(resultados);
    float xi = desde;
    while (hay_siguiente(it2)) {
        TipoElemento te = siguiente(it2);
        float y = *((float*)te->valor);
        printf("F(%.2f) = %.2f\n", xi, y);
        xi += paso;
    }

    printf("\nPresione ENTER para continuar...");
    fgets(buffer, 100, stdin);
}
