#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "libre.h"

//elevo al cuadrado un numero




int main(){
    int x=4;
    int resultado;

    resultado=cuadrado(x);

    printf("\n\nel resultado de elevar al cuadrado %i es: %i\n\n", x,resultado);

    system("pause");
    return 0;
    

}