#include <stdio.h>
#include <stdlib.h>
#include <TP0_Repaso.h>

void imprimir(bool resultado){

    if (resultado){

        printf("Hay coincidencia");
        printf("\n");
    }else{
        printf("No hay coincidencia");
        printf("\n");
    }
}

bool digitoEnNumero(long n, short d){


    char numero[20]; //Array de char de longitud 20
    char decimal[1]; //Array de char de longitud 1

    //Inicializo el char que va a contener el decimal
    decimal[0] = 0;

    //Inicializo el array char
    for (int i = 0; i < 20; i++){
        numero[i] = '\n';
    }

    //Array, formato del char, numero entero
    //Convierto los enteros a char
    sprintf(numero, "%d", n);
    sprintf(decimal, "%d", d);

    for (int i = 0; i < 20; i++){

        if (numero[i] != '\n'){

            if (numero[i] == decimal[0]){
                return true;
            }
        }

    }

    return false;
}

int main(){

    imprimir(digitoEnNumero(987, 7));
    imprimir(digitoEnNumero(987, 6));

    system("pause");

}