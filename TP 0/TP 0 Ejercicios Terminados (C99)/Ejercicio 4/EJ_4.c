#include <stdio.h>
#include <stdlib.h>
#include <TP0_Repaso.h>




struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[])
{

    int i = 0;
    int j = 0;

    struct Jugador* VectorEquipo = (struct Jugador*) malloc(CANT_JUGADORES * sizeof(struct Jugador));
    struct Jugador jugadorTemp;
    for (i; i < CANT_JUGADORES; i++){
        VectorEquipo[i] = equipo[i];
    }

    for (i; i < CANT_JUGADORES; i++){
        j = 0;
        for (j; j < CANT_JUGADORES - i; j++){

            if (VectorEquipo[j].partidosJugados > VectorEquipo[j+1].partidosJugados){
                jugadorTemp = VectorEquipo[j];
                VectorEquipo[j] = VectorEquipo[j+1];
                VectorEquipo[j+1] = jugadorTemp;
            }
        }
    }


    return VectorEquipo;
}


struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[])
{

    int i = 0;
    int j = 0;

    struct Jugador* VectorEquipo = (struct Jugador*) malloc(CANT_JUGADORES * sizeof(struct Jugador));
    struct Jugador jugadorTemp;

    for (i; i < CANT_JUGADORES; i++){
        VectorEquipo[i] = equipo[i];
    }
    
    i = 0;
    for (i; i < CANT_JUGADORES; i++){
        j = 0;
        for (j; j < CANT_JUGADORES - i; j++){

            if (VectorEquipo[j].edad > VectorEquipo[j+1].edad){
                jugadorTemp = VectorEquipo[j];
                VectorEquipo[j] = VectorEquipo[j+1];
                VectorEquipo[j+1] = jugadorTemp;
            }
        }
    }

    return VectorEquipo;
}


int main()
{
    struct Jugador equipo[] = { 
    {"Messi", 34, 800}, 
    {"Ronaldo", 37, 900}, 
    {"Neymar Jr.", 29, 500}, 
    {"Mbappe", 22, 200}, 
    {"Lewandowski", 33, 700}, 
    {"Salah", 29, 400}, 
    {"De Bruyne", 30, 600}, 
    {"van Dijk", 30, 400}, 
    {"Ramos", 35, 650}, 
    {"Neuer", 35, 800}, 
    {"Davies", 20, 100} 
    };


    int i = 0;
    int j = 0;

    struct Jugador* VectorResultado_CantidadPartidos;
    struct Jugador* VectorResultado_Edad;
    
    VectorResultado_CantidadPartidos = jugadoresOrdenadosPorCantDePartidos(equipo);
    //free(VectorEquipo);
    VectorResultado_Edad = jugadoresOrdenadosPorEdad(equipo);

    for (i; i < CANT_JUGADORES; i++){
        printf("%s: %d\n", VectorResultado_CantidadPartidos[i].nombre, VectorResultado_CantidadPartidos[i].partidosJugados);
    } 

    //free(VectorResultado_CantidadPartidos); 
    i = 0;
    printf("\n----------------------------------------------------------------------------------------\n");
    for (i; i < CANT_JUGADORES; i++){
        printf("%s: %d\n", VectorResultado_Edad[i].nombre, VectorResultado_Edad[i].edad);
    }    

    system("pause");
    return 0;
}