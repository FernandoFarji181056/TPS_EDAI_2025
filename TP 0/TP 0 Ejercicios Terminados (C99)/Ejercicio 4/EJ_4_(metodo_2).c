#include <stdio.h>
#include <stdlib.h>
#include <TP0_Repaso.h>

//----------------- FUNCIONES DE COMPARACION PARA USAR QSORT ----------------------
int cmpJugadorCantidadPartidos(const void * vj1, const void * vj2)
{
    struct Jugador * pj1 = (struct Jugador *) vj1;
    struct Jugador * pj2 = (struct Jugador *) vj2;

    return ((*pj1).partidosJugados - (*pj2).partidosJugados); 
}

int cmpJugadorEdad(const void * vj1, const void * vj2)
{
    struct Jugador * pj1 = (struct Jugador *) vj1;
    struct Jugador * pj2 = (struct Jugador *) vj2;

    return ((*pj1).partidosJugados - (*pj2).partidosJugados); 
}

//----------------- FIN FUNCIONES DE COMPARACION PARA USAR QSORT ----------------------


struct Jugador *jugadoresOrdenadosPorCantDePartidos(struct Jugador equipo[])
{

    int i = 0;
    struct Jugador* VectorEquipo_ordenado = (struct Jugador*) malloc(CANT_JUGADORES * sizeof(struct Jugador));


    //COPIO el vector original a un vector que puedo modificar
    for (i; i < CANT_JUGADORES; i++){
        VectorEquipo_ordenado[i] = equipo[i];
    }

    //Uso QSORT para ordenar el vector
    qsort(VectorEquipo_ordenado, CANT_JUGADORES, sizeof(struct Jugador), cmpJugadorCantidadPartidos);

    return VectorEquipo_ordenado;
}


struct Jugador *jugadoresOrdenadosPorEdad(struct Jugador equipo[])
{
    int i = 0;
    struct Jugador* VectorEquipo_ordenado = (struct Jugador*) malloc(CANT_JUGADORES * sizeof(struct Jugador));

    //COPIO el vector original a un vector que puedo modificar
    for (i; i < CANT_JUGADORES; i++){
        VectorEquipo_ordenado[i] = equipo[i];
    }

    //Uso QSORT para ordenar el vector
    qsort(VectorEquipo_ordenado, CANT_JUGADORES, sizeof(struct Jugador), cmpJugadorEdad);

    return VectorEquipo_ordenado;
    
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


    int i;

    struct Jugador* VectorResultado_CantidadPartidos;
    struct Jugador* VectorResultado_Edad;
    
    VectorResultado_CantidadPartidos = jugadoresOrdenadosPorCantDePartidos(equipo);
    VectorResultado_Edad = jugadoresOrdenadosPorEdad(equipo);

    for (i=0; i < CANT_JUGADORES; i++){
        printf("%s: %d\n", VectorResultado_CantidadPartidos[i].nombre, VectorResultado_CantidadPartidos[i].partidosJugados);
    } 

    printf("\n----------------------------------------------------------------------------------------\n");
    for (i=0; i < CANT_JUGADORES; i++){
        printf("%s: %d\n", VectorResultado_Edad[i].nombre, VectorResultado_Edad[i].edad);
    }    

    system("pause");
    return 0;
}