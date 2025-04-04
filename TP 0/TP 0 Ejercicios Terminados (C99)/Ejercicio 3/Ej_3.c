#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <TP0_Repaso.h>

enum Referencia dondeEstaElPuntoBis(struct Punto centroC, int rc, struct Punto p){

    //Uso teoria de pitagoras para saber si esta adentro, fuera o sobre el ciruclo
    double x = pow(p.x-centroC.x,2);
    double y = pow(p.y-centroC.y,2);

    double d = sqrt((x+y));

    if (d < rc){
        return INTERNO;
    }
    else if(d == rc){
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

    struct Punto centro = {0,0};
    struct Punto punto = {1,1};
    int radio = 2;
    
    ubicacion = dondeEstaElPuntoBis(centro,radio,punto);
    imprimir(ubicacion);

    radio = 1;
    ubicacion = dondeEstaElPuntoBis(centro,radio,punto); 
    imprimir(ubicacion);

    punto.x = 1;
    punto.y = 0;
    ubicacion = dondeEstaElPuntoBis(centro,radio,punto); 
    imprimir(ubicacion);
  
    system("pause");
    return 0;
}