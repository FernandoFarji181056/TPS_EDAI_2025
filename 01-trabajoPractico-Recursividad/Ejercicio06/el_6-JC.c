#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "libs/validaciones/headers/Validacion_datos.h"

void ondaDigitalRec(const char *entrada, int indice, char Anterior) {
    // Caso base: si llegamos al final de la cadena
    if (entrada[indice] == '\0') {
        return;
    }
    
    if (indice == 0) {
        if (entrada[indice] == 'L') {
            printf("_");
        } else if (entrada[indice] == 'H') {
            //printf("¯");
            printf("-");
        } else {
            printf("Error: letra no válida");
            system("pause");
            return;
        }
    } else {
        // Si se cambia de H a L o al revéz, se imprime "|"
        if (entrada[indice] != Anterior) {
            printf("|");
        }
        
        //termina de imprimr la parte de la onda correspondiente
        if (entrada[indice] == 'L') {
            printf("_");
        } else if (entrada[indice] == 'H') {
            //printf("¯");
            printf("-");
        }
    }

    // Llamado recursivo con el siguiente carácter
    ondaDigitalRec(entrada, indice + 1, entrada[indice]);
}

//int main() {
char *ondaDigital(char seniales[]) {
    char entrada[100];
    printf("Ingrese la senial digital (L/H): ");
    scanf("%s", entrada);
    //convierte la cadena a mayusculas
    entrada[0]=toupper(entrada[0]);
    for (int i = 1; entrada[i] != '\0'; i++) {
        entrada[i] = toupper(entrada[i]);
    }
    //conpreueba que la cadena solo contenga L y H
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != 'L' && entrada[i] != 'H') {
            printf("Error: letra no valida\n");
            system("pause");
            return NULL;
        }
    }
    printf("Onda digital: ");
    ondaDigitalRec(entrada, 0, '\0');
    printf("\n");
    system("pause");
    return NULL;
}
