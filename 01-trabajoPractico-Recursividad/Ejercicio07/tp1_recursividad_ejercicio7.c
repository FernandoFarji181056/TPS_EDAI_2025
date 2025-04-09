#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "tp_1_recursividad.h"
#include "../tp_1_recursividad.h"



char * reunionMafia(int nivel){
    //mi caso base es nivel 1 "(-.-)"
    if (nivel == 1) {
        char *base = malloc(6);
        strcpy(base, "(-.-)");
       
        return base;
    } else {
        char *subMafia = reunionMafia(nivel - 1);
        // Se arma la nueva cadena: "(-." + subReunion + ".-)"
        int size = strlen(subMafia) + 6; // 3 para "(-.", 3 para ".-)", más lo anterior
        char *resultado = malloc(size);
        sprintf(resultado, "(-.%s.-)", subMafia); //Armo la cadena

        free(subMafia); // liberamos la memoria del string anterior
      
        return resultado;
    }
}

char * espacios(int i, int nivel){
    if (i == nivel){
        //Caso base: no hay mas espacios que agregar
        char *vacio = malloc(1);
        vacio[0] = '\0';
      
        return vacio;
    } else {
        char *esp = espacios(i+1, nivel);
        char *resultado = malloc(strlen(esp)+3); //3 espacios + '\0'
        sprintf(resultado, "   %s", esp); 
        free(esp);
     
        return resultado;
    }
}

void ejercicio7(){
    int nivel, c;
    float f;
    printf("Ingresar nivel de mafia(Solo numeros enteros del 1 al 8): ");
    do{
        fflush(stdin);
        c = scanf("%f", &f);
        nivel = f;
    } while ((nivel != f)||(c != 1)||(nivel < 1 || nivel > 8));
    
    for (int i = 1; i <= nivel; i++) {
        char *reunion = reunionMafia(i);
        char *espacio = espacios(i, nivel);
        printf("Nivel %d: %s%s\n", i, espacio, reunion);
        free(reunion); // liberar memoria
        free(espacio);// liberar memoria
    
    }
    
    system("pause");

}
/*
// FUNCION MAIN AGREGADA
int main() {
    ejercicio7();
    return 0;
}
*/
