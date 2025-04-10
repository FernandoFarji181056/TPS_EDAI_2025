#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libs/validaciones/headers/Validacion_datos.h"
/*
Escribir una función recursiva que implemente el método que se describe para saber si
un número es divisible por 7. Se separa la primera cifra de la derecha, se la multiplica
por 2, y se resta este producto de lo que queda a la izquierda y así sucesivamente,
hasta que el resultado obtenido sea un número menor a 70. El número original será
múltiplo de 7 si el resultado da cero o múltiplo de 7.
*/


bool divisiblePor7(int n) {
    // Paso base: cuando el número es menor que 70
    if (abs(n) < 70) {
        return (n % 7 == 0);
    }
    
    // Separar el último dígito
    int ultimoDigito = abs(n) % 10;
    int restoDelNumero = abs(n) / 10;
    
    // Aplicar la regla: restoDelNumero - (2 * ultimoDigito)
    int nuevoNumero = restoDelNumero - (2 * ultimoDigito);
    
    // Llamada recursiva con el nuevo número
    return divisiblePor7(nuevoNumero);
}

