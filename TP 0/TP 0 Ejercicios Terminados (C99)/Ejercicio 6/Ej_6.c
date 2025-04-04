#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** splitDatos(char cadena[255])
{
    //Variables para el split
    char delimitador[] = "\t"; //El 9 es el codigo ascii para el tabulador
    char** matrizPalabras; //ARRAY DE STRINGS = {"string1", "string2", "string3", "string4"}
    int contador = 0; //Hace de indice para la matriz (o array) de strings
    char* token;

    //Le asigno un valor en memoria a la matriz
    matrizPalabras = (char**) malloc(4 * sizeof(char *));

    for (int i = 0; i < 4; i++){
        matrizPalabras[i] = (char *) malloc(255 * sizeof(char));
    }


    //Hago el split del vector cadena
    token = strtok(cadena,delimitador); //strtok agarra la primer palabra separada por comas
    if (token != NULL){
        while(token != NULL){
            
            //printf("Token: %s\n", token);

            //Guardo todo en un array
            strcpy(matrizPalabras[contador], token);
            token = strtok(NULL, delimitador); //El NULL aca es IMPORTANTISIMO porque 1) mantiene la cadena anterior 2) sin el null entraria en loop infinito
            contador++;
        }
    } 

    return matrizPalabras; 
}


void corte_control_NIVEL2(FILE* archivo)
{
    int contador_lineas = 0;

    //Variables
    char cadena[255]; //Puntero de char (es un array)
    char** matrizPalabras; //ARRAY DE STRINGS = {"string1", "string2", "string3", "string4"}

    //Variables de corte de control
    int suma = 0;
    int sumaTotal = 0;

    int cod_emp;
    int cod_emp_anterior;
    int anio;
    int anio_anterior;
    double minutos;

    //Array de enteros
    int HorasTotales[10] = {0,0,0,0,0,0,0,0,0,0};
    int SumaColumnaAnios[10] = {0,0,0,0,0,0,0,0,0,0};
    int contadorValores = 0;

    //------------
    int MatrizResultados [10][15];
    //Inicializo la matriz
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 15; j++){
            MatrizResultados[i][j] = 0;
        }
    }

    //------------

    //variables de espacio en tabla consola
    int anchoColumnaCliente = -23;
    int anchoColumnaAnio = -4;
    int anchoColumnaHoras = 7;
    int anchoTotalGeneral = 15;

    //===================================================================
    //              Imprime las primeras filas de la tabla 
    //===================================================================

    printf("+-----------------------+-------------------------------+");
    for (int i = 0; i < 7; i++){
    printf("-------+");
    }
    printf("---------------+");
    printf("\n");
    printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|", 
    anchoColumnaCliente, "    Suma de Tiempo", 
    anchoColumnaCliente, " Etiquietas de columna",
    anchoColumnaHoras, "",
    anchoColumnaHoras, "",
    anchoColumnaHoras, "",
    anchoColumnaHoras, "",
    anchoColumnaHoras, "",
    anchoColumnaHoras, "",
    anchoColumnaHoras, "",
    anchoColumnaHoras, "",
    anchoTotalGeneral, "");
    printf("\n");
    printf("+-----------------------+-----------------------+");
    for (int i = 0; i < 8; i++){
    printf("-------+");
    }
    printf("---------------+");
    printf("\n");

    printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|%*s|", 
    anchoColumnaCliente, "    Etiquetas de fila", 
    -anchoColumnaCliente, " 2015",
    anchoColumnaHoras, "2016",
    anchoColumnaHoras, "2017",
    anchoColumnaHoras, "2018",
    anchoColumnaHoras, "2019",
    anchoColumnaHoras, "2020",
    anchoColumnaHoras, "2021",
    anchoColumnaHoras, "2022",
    anchoColumnaHoras, "2023",
    anchoTotalGeneral, "Total General");
    printf("\n");
    printf("+-----------------------+-----------------------+");
    for (int i = 0; i < 8; i++){
    printf("-------+");
    }
    printf("---------------+");
    printf("\n");
    //===================================================================      
    //===================================================================


    //====================================================================//
    //                        COMIENZO CORTE DE CONTROL                   //
    //====================================================================//

    //Leo la primer linea
    fgets(cadena,255,archivo);
    //Aplico SPLIT
    matrizPalabras = splitDatos(cadena);

    cod_emp = atoi(matrizPalabras[0]);
    
    while(!feof(archivo)) //si se llego al final del archivo se sale del bucle
    {
        int aniosTotales = 9; //de 2015 a 2023
       //Aca cambia de empleado
        cod_emp_anterior = cod_emp;

        if (cod_emp == cod_emp_anterior && cod_emp != 0){
            printf("|%*d", anchoColumnaCliente, cod_emp);
        }

        while (!feof(archivo) && (cod_emp == cod_emp_anterior))
        {
            
            //Aca cambia de año
            anio = atoi(matrizPalabras[1]); //Atoi convierte un string (array char) a un entero/doble
            anio_anterior = anio;

        
            while (!feof(archivo) && anio == anio_anterior && cod_emp == cod_emp_anterior)
            {
                minutos = atoi(matrizPalabras[3]);
                suma = suma + minutos;    
                sumaTotal = sumaTotal + minutos;

                //Vuelvo a leer una linea y a dividirla
                fgets(cadena,255,archivo);

                if (!feof(archivo)){
                    contador_lineas++;
                    //Aplico SPLIT
                    matrizPalabras = splitDatos(cadena);
                    cod_emp = atoi(matrizPalabras[0]);
                    anio = atoi(matrizPalabras[1]);
                } 

            }

            //Este switch guarda en cada array la cantidad de horas de cada empleado segun el año
            switch (anio_anterior)
            {
            case 2015:
                HorasTotales[0] = suma;
                SumaColumnaAnios[0] = SumaColumnaAnios[0] + suma;
                break;
            case 2016:
                HorasTotales[1] = suma;
                SumaColumnaAnios[1] = SumaColumnaAnios[1] + suma;
                break;
            case 2017:
                HorasTotales[2] = suma;
                SumaColumnaAnios[2] = SumaColumnaAnios[2] + suma;
                break;
            case 2018:
                HorasTotales[3] = suma;
                SumaColumnaAnios[3] = SumaColumnaAnios[3] + suma;
                break;
            case 2019:
                HorasTotales[4] = suma;
                SumaColumnaAnios[4] = SumaColumnaAnios[4] + suma;
                break;
            case 2020:
                HorasTotales[5] = suma;
                SumaColumnaAnios[5] = SumaColumnaAnios[5] + suma;
                break;
            case 2021:
                HorasTotales[6] = suma;
                SumaColumnaAnios[6] = SumaColumnaAnios[6] + suma;
                break;
            case 2022:
                HorasTotales[7] = suma;
                SumaColumnaAnios[7] = SumaColumnaAnios[7] + suma;
                break;
            case 2023:
                HorasTotales[8] = suma;
                SumaColumnaAnios[8] = SumaColumnaAnios[8] + suma;
                break;                                     
            default:
                break;
            }

            suma = 0;  //Limpio el array que suma las horas por año
        }

        //============================================================
        //Imprime la tabla desde el empleado 1000 al 1900
        if (cod_emp_anterior != 0 ){

 
            printf("|%*d|%*d|%*d|%*d|%*d|%*d|%*d|%*d|%*d|%*d|",
            -anchoColumnaCliente ,HorasTotales[0],
            anchoColumnaHoras ,HorasTotales[1],
            anchoColumnaHoras ,HorasTotales[2],
            anchoColumnaHoras ,HorasTotales[3],
            anchoColumnaHoras ,HorasTotales[4],
            anchoColumnaHoras ,HorasTotales[5],
            anchoColumnaHoras ,HorasTotales[6],
            anchoColumnaHoras ,HorasTotales[7],
            anchoColumnaHoras ,HorasTotales[8],
            anchoTotalGeneral, sumaTotal);
            printf("\n");
            
        }
        //============================================================

        //Limpio el array que almacena las horas totales de cada empleado
        for (int i = 0; i < 10; i++)
        {
            HorasTotales[i] = 0;
        }
        
        sumaTotal = 0; //Limpio la variable que suma todas las horas de cada empleado
    }

    //===============================================================================//
    //                        FIN CORTE DE CONTROL                                   //
    //===============================================================================//


    //============================================================
    //Imprime la ultima fila de la tabla

        for (int i = 0; i < 10; i++)
        {
            sumaTotal = sumaTotal + SumaColumnaAnios[i];
        }

    printf("|%*s|%*d|%*d|%*d|%*d|%*d|%*d|%*d|%*d|%*d|%*d|\n", 
    anchoColumnaCliente, "Total General",
    -anchoColumnaCliente, SumaColumnaAnios[0],
    anchoColumnaHoras, SumaColumnaAnios[1],
    anchoColumnaHoras, SumaColumnaAnios[2],
    anchoColumnaHoras, SumaColumnaAnios[3],
    anchoColumnaHoras, SumaColumnaAnios[4],
    anchoColumnaHoras, SumaColumnaAnios[5],
    anchoColumnaHoras, SumaColumnaAnios[6],
    anchoColumnaHoras, SumaColumnaAnios[7],
    anchoColumnaHoras, SumaColumnaAnios[8],
    anchoTotalGeneral, sumaTotal);
    printf("+-----------------------+-----------------------+");
    for (int i = 0; i < 8; i++){
    printf("-------+");
    }
    printf("---------------+");
    printf("\n");
    //----------------------------------------------------------------------

    
    fclose(archivo); //Cierra el archivo
    free(matrizPalabras); //Libera la memoria que reserve para la matriz

}

int main() 
{
    //Declaro constantes
    const char* PathArchivo = "practica-0-ejercicio-6.txt";

    //Declaro variables
    FILE* archivo; //Puntero a un archivo x

    archivo = fopen(PathArchivo, "r"); //Abro el archivo en modo lectura y retorna si fue abierto con exito o fallo

    if (archivo == NULL){
        printf("Fallo al abrir el archivo");
        return -1; //El return -1 cierra el programa indicando error
    }else{
        corte_control_NIVEL2(archivo);
    }

    fclose(archivo);
    system("pause");
    return 0;
}