// el departamento que más habitantes tiene de todo el edificio. 
// - Recorrer toda la matriz y mostrar el valor mas alto
//----------------------------------
// El piso que mas habitantes tiene de todo el edificio
// - Recorrer la matriz y sumar todas las filas y mostrar la de mayor resultado
//-----------------------------------
// Cantidad de viviendas vacias
// - Sumar la cantidad de 0 y mostrar
//------------------------------------
// Promedio de habitantes por departamento
// - Sumar todos los habitantes y dividirlos por la cantidad de departamentos


#include <stdio.h>

 struct Vivienda { 
 short piso; 
 char depto; 
 };


int pisoConMasHabitantes(int edificio[8][5]){

    int i = 0;
    int j = 0;

    int pisos = 8;
    int departamentos = 5;

    int mayor = 0;
    int piso = 0;
    int Pisoactual = 0;
    int PisoPrevio = 0;



    for (i; i< 8; i++){
        j = 0; //Hay que resetear la J cada vuelta de bucle porque sino no entra nunca al segundo for
        for (j; j < 5; j++){

            Pisoactual += edificio[i][j]; //Sumo todos los habitantes de cada piso
        }

        if (Pisoactual >= mayor){ //Comparo los habitantes de cada piso con el ultimo piso revisasdo
            mayor = Pisoactual; //Si el numero es mayor guardo el piso
            piso = i;
        }
        Pisoactual = 0;
    }
    //Le sumo 1 para que al imprimirlo salga igual que en el pdf. No afecta en nada
    //Esto es porque el bucle arranca en 0 y en el pdf los dptos se cuentan desde el 1
    return piso + 1; 

    
}


int cantidadDeViviendasVacias(int edificio[8][5]){

    int i = 0;
    int j = 0;

    int pisos = 8;
    int departamentos = 5;

    int Cantidad_vacias = 0;
    int actual = 0;

    for (i; i< pisos; i++){
        j = 0;
        for (j; j < departamentos; j++){

            actual = edificio[i][j]; //Guardo la cantidad de habitantes de cada departamento

            if (actual == 0){ //Si el numero es 0 sumo uno al contador
                Cantidad_vacias++;
            }

        }
    }

    return Cantidad_vacias;
}


float promedioHabitantesPorVivienda(int edificio[8][5]){

        int i = 0;
        int j = 0;

        int pisos = 8;
        int departamentos = 5;
        float HabitantesTotal = 0;
        float viviendasTotal = pisos * departamentos;

        //Sumo los habitantes total de todo el edificio
        for (int i = 0; i< 8; i++){
            j = 0;
            for (int j = 0; j < 5; j++){

                HabitantesTotal += edificio[i][j]; 
            }

        }
       
        //Retorno el resultado de la division de los habitantes

        //NOTA: C solo tiene 1 tipo de division. Si queres que la division sea con decimal tenemos
        //      que usar el tipo de dato FLOAT. Si queremos que sea entera hay que usar INT
        return HabitantesTotal / viviendasTotal;
}



struct Vivienda viviendaConMasHabitantes(int edificio[8][5]){
    
    struct Vivienda vivienda;
    int pisos = 8;
    int departamentos = 5;

    int habitantes = 0;
    int mayor = 0;
    int piso = 0;
    int dpto = 0;

    int i = 0;
    int j = 0;

    for (i; i< 8; i++){
        j = 0;
        for (j; j < 5; j++){

            habitantes = edificio[i][j]; //Guardo los habitantes de cada departamento

            if (habitantes >= mayor){ //Si es mayor al ultimo departamento se guarda, sino pasa de largo
                mayor = habitantes;
                piso = i;
                dpto = j;
            }

        }
    }

    
    vivienda.piso = piso + 1; //Se vuelve a sumar 1 solo para que quede igual que en el pdf

    //Dependiendo del numero que entre al switch se cambia por la letra correspondiente del piso
    //Se cambia el dato de la estructura
    switch (dpto)
    {
    case 0:
        vivienda.depto = 'A';
        break;
    case 1:
        vivienda.depto = 'B';
        break;
    case 2:
        vivienda.depto = 'C';
        break;
    case 3:
        vivienda.depto = 'D';
        break;
    case 4:
        vivienda.depto = 'E';
        break;
    default:
        break;
    }


    //Se retorna el STRUCT
    return vivienda;


}


int main(){

     int edificio[8][5] = { 
        {3, 5, 2, 1, 0}, 
        {2, 4, 3, 0, 2}, 
        {1, 0, 1, 2, 1}, 
        {0, 1, 0, 0, 0}, 
        {1, 3, 2, 1, 1}, 
        {2, 2, 0, 1, 3}, 
        {1, 0, 0, 2, 1}, 
        {0, 0, 1, 1, 1} 
        }; 


    int PisoConMayorHabitantes = pisoConMasHabitantes(edificio);
    int ViviendasVacias = cantidadDeViviendasVacias(edificio);
    float PromedioHabitantes = promedioHabitantesPorVivienda(edificio);
    struct Vivienda viviendas = viviendaConMasHabitantes(edificio);
    
    
    printf("Piso con mayor habitantes: %d", PisoConMayorHabitantes);
    printf("\n");
    printf("Cantidad de viviendas vacias: %d", ViviendasVacias);
    printf("\n");
    printf("Promedio de habitantes por vivienda: %f", PromedioHabitantes);
    printf("\n");
    printf("Vivienda con mas habitantes: %d", viviendas.piso);
    printf("-%c", viviendas.depto);
    printf("\n");
    getchar( );
    return 0;
}