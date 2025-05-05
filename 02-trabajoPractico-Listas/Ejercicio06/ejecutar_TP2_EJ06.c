#include <stdio.h>
#include <stdlib.h>
//#include "listas.h"
//#include "tipo_elemento.h"
#include "libs/listas/headers/main_tp3.h"
#include "libs/listas/headers/listas.h"
#include "libs/listas/headers/Tp_2_listas.h"
#include "libs/tipoElemento/headers/tipo_elemento.h"
#include "libs/validaciones/headers/Validacion_datos.h"


//---------------------------------------------------
// Encabezados
//---------------------------------------------------
bool esSublista(Lista L1, Lista L2);
bool buscarElemento(Lista lista, int valor);

//Carga de listas
bool cargarListasManual(Lista L, Lista L2){	

    clearScreen();

    bool salida01=false;
    bool salida02=false;
    //int validacion1=0;
    bool validacion1=false;
    bool validacion2=false;
    bool listasVacias=false;
    int entero1;
    int entero2;
    char string1[1000];
    char string2[1000];
    //int longitud01;

    int i=0;
    TipoElemento X;

    int min = 1;
    int max = 1000;

    printf ("AHORA CARGAREMOS 2 LISTAS CON NUMEROS ENTEROS COMPRENDIDOS ENTRE %d Y %d,\n", min, max);
    printf ("LAS LISTA NO PUEDEN ESTAR VACIAS,\n");
    printf ("LUEGO SE INFORMARA SI UNA LISTA ES SUBLISTA DE LA OTRA,\n\n");
    printf ("INTRODUZCA NUMEROS ENTEROS PARA CREAR UNA LISTA (SOLO NUMEROS, sin espacio ni otro caracter),\n");
    printf("INGRESE 'x' SALIR\n");

    do{			
        printf ("\nIntroduzca un numero entero entre %d y %d para agregar a la primera Lista o X para salir y cargar otra Lista: ", min, max);

        fgets(string1,1000,stdin); // pide por pantalla el ingreso
        int longitud1 = strlen(string1);
        string1[longitud1-1]='\0'; // quita el caracter \n que fgets agrega al final de string
        longitud1=strlen(string1);
        validacion1=validarEntero(string1); //valida el ingreso controlando que solo se hayan ingresado numeros

        if (  (string1[0] == 'X' || string1[0] == 'x') && longitud1==1   ){
            salida01=true;
        }

        if( validacion1==false && salida01==false ) {
            printf("la entrada NO fue validada\n\n");
        }

        if (validacion1){
            entero1=(int) strtol(string1,NULL,10); //pasa string a entero
            if (entero1 < min || entero1 > max){
                printf("El numero ingresado no cumple con los requisitos, intentelo nuevamente\n");
                salida01=false;
            } else{
                X = te_crear(entero1);
                l_agregar(L, X);
                //system ("cls");
                clearScreen();
                l_mostrar(L);
            }
        }
    }while(!salida01);

    //system("pause");
    system ("cls");
    printf("AHORA CARGAMOS LA SEGUNDA LISTA\n");

    do{		
        printf ("\nIntroduzca un numero entre %d y %d para agregar a la segunda Lista o X para salir: ", min, max);
        
        fgets(string2,1000,stdin); // pide por pantalla el ingreso
        int longitud2 = strlen(string2);
        string2[longitud2-1]='\0'; // quita el caracter \n que fgets agrega al final de string
        longitud2=strlen(string2);
        validacion2=validarEntero(string2); //valida el ingreso controlando que solo se hayan ingresado numeros

        if (  (string2[0] == 'X' || string2[0] == 'x') && longitud2==1   ){
            salida02=true;
        }

        if( validacion2==false && salida02==false ) {
            printf("la entrada NO fue validada\n\n");
        }

        if (validacion2){
            entero2=(int) strtol(string2,NULL,10); //pasa string a entero
            if (entero2 < min || entero2 > max){
                printf("El numero ingresado NO cumple con los requisitos, intentelo nuevamente\n");
                salida01=false;
            } else{
                X = te_crear(entero2);
                l_agregar(L2, X);
                system ("cls");

                printf("Contenido de la primer Lista: \n");
                l_mostrar(L);

                printf("\nContenido de la segunda Lista: \n");
                l_mostrar(L2);
            }
        }
    }while(!salida02);

    system ("cls");
    printf("MOSTRAMOS AMBAS LISTAS\n\n");

    printf("Contenido de la primer Lista: \n");
    l_mostrar(L);

    printf("\nContenido de la segunda Lista: \n");
    l_mostrar(L2);
    printf("\n");

    if ( l_es_vacia (L) || l_es_vacia(L2)){
        printf("NO PUEDE HABER LISTAS VACIAS Y LAS LISTAS TIENEN QUE TENER EL MISMO TAMANIO\n");
        printf("INTENELO NUEVAMENTE CUANDO QUIERA, GRACIAS\n");
        return false;
    }
    
    return true;
}

//---------------------------------------------------
// MAIN PRINCIPAL
//---------------------------------------------------
void ejecutar_TP2_EJ06(){
    TipoElemento X;
    Lista L1 = l_crear();
    Lista L2 = l_crear();
    bool sublista, resulCarga;
    
    resulCarga = cargarListasManual(L1, L2);

    if (resulCarga){

        printf("\n");

        if (esSublista(L1,L2)) {
            printf("Lista 2 es sublista de Lista 1 \n");
        } else {
            if (esSublista(L2,L1)){
                printf("Lista 1 es sublista de Lista 2 \n");
            } else {
                printf("No son sublistas \n");
            }
        }

        printf("\n");
        printf("la complejidad algoritmica de este ejercicio es cuadratica,\n");
        printf("ya que recorre Lista 2 con un while y en cada iteracion realiza un while de Lista 1\n");
        

        system("pause");
    }   

}


//---------------------------------------------------------------------------------
// Funciones del Ejercicio 2
//---------------------------------------------------------------------------------

// Función para verificar si un elemento está presente en la lista
bool buscarElemento(Lista lista, int valor) {
    // esta variable booleana la uso para saber si el elemento esta en lista 1
    // será falsa mientras no encuentre el valor en la lista 1
    // si termina como falsa significa que no esta en lista, sino cambiará a true 
    bool esta_en_lista1 = false;
    Iterador I1 = iterador(lista);
    TipoElemento x1;
    // recorro mientras la lista tenga elementos o mientras esta_en_lista1 sea falso
    while(hay_siguiente(I1) && esta_en_lista1 == false)
    {
        x1 = siguiente(I1);
        if (x1->clave == valor)
        {
            
            esta_en_lista1 = true;
        }

    }

    return esta_en_lista1;
}

// Función para determinar si ListaB es sublista de ListaA (sin importar el orden)
bool esSublista(Lista L1, Lista L2) {
    // este booleano lo uso para saber si L2 es sublista de L1
    // si termina como true significa que es sublista, si cambia a false no lo es y retornara false
    bool es_sub = true;
    Iterador I2 = iterador(L2);
    TipoElemento x1, x2;

    while (es_sub && hay_siguiente(I2))
    {
        x2 = siguiente(I2);
        es_sub = buscarElemento(L1, x2->clave);
    }
    
    return es_sub; // Si todos los elementos de ListaB se encontraron en ListaA
}

