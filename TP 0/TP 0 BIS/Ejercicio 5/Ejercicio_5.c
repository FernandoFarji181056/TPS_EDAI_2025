//Incluir libreria TIME
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

//----------------------- EJERCICIO 5 ---------------------------------//
enum Unidades_fecha
{
    DIAS, HORAS, MINUTOS, SEGUNDOS
};

enum Comparacion_Fechas
{
    ANTERIOR, POSTERIOR, IGUAL
};

struct Fecha
{
    int dia,mes,anio;
};

bool verificarFecha(struct Fecha fecha);
struct Fecha suma_Dias(struct Fecha fecha, int dias);
long int diferencia_Fechas(struct Fecha fecha1, struct Fecha fecha2, enum Unidades_fecha unidad);
bool es_Anio_Bisiesto(struct Fecha fecha);

//----------------------- FIN EJERCICIO 5 -------------------------------//
//----------------------------------------------------------------------//


bool verificarFecha(struct Fecha fecha)
{

    if (fecha.dia > 31 || fecha.dia < 1) return false;

    if (fecha.mes > 12 || fecha.mes < 1) return false;

    //Calculo si el anio es bisiesto o no
    double x = fecha.anio % 4;
    double y = fecha.anio % 100;
    double z = fecha.anio % 400;
    if (((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0)))
    {
        //printf("ANIO BISIESTO\n");
        //el año es bisiesto
        if (fecha.dia <= 29 && fecha.mes == 2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        //printf("ANIO NO BISIESTO\n");
        //No es bisiesto.
        //printf("El anio no es bisiesto.\n");

        //Como el año no es bisiesto el 29 de febrero no existe.
        if (fecha.dia > 28 && fecha.mes == 2){
            return false;
        }else{
            return true;
        }
    }

    //Ahora analizo el resto de las fechas
    //MESES CON 31 DIAS
    switch (fecha.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:

        if (fecha.dia <= 31)
        {
            return true;
        }
        else
        {
            return false;
        }  
    default:
        break;
    }


    //MESES CON 30 DIAS
    switch (fecha.mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        if (fecha.dia <= 30)
        {
            return true;
        }
        else
        {
            return false;
        }  
    default:
        break;
    }
}


struct Fecha suma_Dias(struct Fecha fecha, int dias)
{
    //La funcion tiene en cuenta que la fecha se valida antes
    int contador;
    int sumador;
    if (dias > 0){ contador = dias; sumador = 1; }; 
    if (dias < 0){ contador = dias*-1; sumador = -1;};
    

    //Validacion de que fecha != 0
    if ((fecha.dia + dias) == 0)
    {
        printf("Error al restar los dias.\n");
        return fecha;
    }

    while (contador > 0)
    {

        contador--;
        //FEBRERO
        if (fecha.mes == 2)
        {
            if (((fecha.anio % 4 == 0 && fecha.anio % 100 != 0) || (fecha.anio % 400 == 0)))
            {
                //ANIO BISIESTO
                fecha.dia = fecha.dia + sumador;
                
                if (fecha.dia == 0 && sumador < 0)
                {
                    fecha.mes = fecha.mes + sumador;
                    fecha.dia = 31; 
                    contador = contador - 1;
                }


                //Si llega a 29 dias incremento el mes
                if (fecha.dia == 29)
                {
                    fecha.mes = fecha.mes + sumador;
                    fecha.dia = 0; 
                }
            }
            else{
                //ANIO NO BISIESTO
                fecha.dia = fecha.dia + sumador;

                if (fecha.dia == 0 && sumador < 0)
                {
                    fecha.mes = fecha.mes + sumador;
                    fecha.dia = 31; 
                    contador = contador - 1;
                }

                //Si llega a 28 dias incremento el mes
                if (fecha.dia == 28)
                {
                    fecha.mes = fecha.mes + sumador;
                    fecha.dia = 0;
                }
            }

        }

        
        //MESES CON 31 DIAS
        switch (fecha.mes)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:

            fecha.dia = fecha.dia + sumador;
            
            if (fecha.dia == 0 && sumador < 0)
            {
                fecha.mes = fecha.mes + sumador;
                fecha.dia = 30; 
                if (fecha.mes == 7) fecha.dia = 31;
                contador = contador - 1;
            }

            //Si llega a 31 dias incremento el mes
            if (fecha.dia > 31)
            {
                fecha.mes = fecha.mes + sumador;
                fecha.dia = 0;
                
            }

        default:
            break;
        }


        //MESES CON 30 DIAS
        switch (fecha.mes)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            fecha.dia = fecha.dia + sumador;
            
            if (fecha.dia == 0 && sumador < 0)
            {

                fecha.mes = fecha.mes + sumador;
                fecha.dia = 30; 
                if (fecha.mes == 7) fecha.dia = 31;
                contador = contador - 1;
            }


            //Si llega a 30 dias incremento el mes
            if (fecha.dia > 30)
            {
                fecha.mes = fecha.mes + sumador;
                fecha.dia = 0;
                
            }
        default:
            break;
        }
        


    }

    return fecha;


}


int main()
{
    struct Fecha f1;
    struct Fecha f2;
    f1.anio =  2019;
    f1.dia = 5;
    f1.mes = 4;
    bool x = verificarFecha(f1);

    if (x)
    {
        f2 = suma_Dias(f1,-6);
        printf("%d - %d - %d\n", f2.dia, f2.mes, f2.anio);
    } else{
        printf("Fecha incorrecta\n");
    }
    

    // if (x){
    //     printf("fecha valida\n");
    // }else{
    //     printf("Fecha incorrecta\n");
    // }

    qsort()
    

    system("pause");
    return 0;
}