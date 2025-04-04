#include <TP0_Repaso.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>



enum Referencia dondeEstaElPunto(int xc, int yc, int radio, int xp, int yp ){

    //Uso teoria de pitagoras para saber si esta adentro, fuera o sobre el ciruclo
    double x = pow(xp-xc,2);
    double y = pow(yp-yc,2);
    double d = sqrt((x+y));

    if (d < radio){
        return INTERNO;
    }
    else if(d == radio){
        return EN_CIRCUNFERENCIA;
    }
    else{
        return EXTERNO;
    }
}
void imprimir(enum Referencia ubicacion){

    switch (ubicacion)
    {
    case INTERNO:
        printf("INTERNO\n");
        break;
    case EXTERNO:
        printf("EXTERNO\n");
        break;
    case EN_CIRCUNFERENCIA:
        printf("EN CIRCUNFERENCIA\n");
        break;
    
    default:
        break;
    }
}

int main(){

    enum Referencia ubicacion;

    ubicacion = dondeEstaElPunto(0, 0, 2, 1, 1 );// => INTERNO 
    imprimir(ubicacion);
    ubicacion = dondeEstaElPunto(0, 0, 1, 1, 1 );// => EXTERNO 
    imprimir(ubicacion);
    ubicacion = dondeEstaElPunto(0, 0, 1, 1, 0 );// => EN_CIRCUNFERENCIA
    imprimir(ubicacion);

    system("PAUSE");
}
