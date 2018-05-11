
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 10

/** \brief Funcion que permite graficar los datos de edades <18  19-35  >35
 * \param [] EPersona Array de personas a buscar los datos de edades
 * \param int Longitud del array
 * \return void
 *
 */
void graficar(EPersona [], int );

int main()
{
    EPersona persona[TAM];

    char seguir='s';
    int opcion=0;
    int indice;
    int alta;
    int baja;


     indice =iniciarEstado(persona,TAM);
        if(indice==-1)
        {
            printf("Espacios ocupados");
        }

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);


        switch(opcion)
        {
            case 1:
               alta= EPersona_alta(persona,TAM);
               if(alta==-1)
               {
                   printf("No quedan mas espacios\n");
               }
               else if(alta==-2)
               {

               }
               else{
                printf("Persona ingresada\n");
               }
                break;
            case 2:
                baja= EPersona_baja(persona,TAM);
                    if(baja==-1)
               {
                   printf("Ingrese un dni correcto\n");
               }
               else if(baja==-2)
               {

               }
               else{
                printf("Baja realizada\n");
               }

                break;
            case 3:
           ordenarPersona(persona,TAM);
           EPersona_mostrarListado(persona,TAM);

                break;
            case 4:
                printf("   ");
           graficar(persona,TAM);
                break;
            case 5:
                seguir = 'n';
                break;
            default:
                 printf("ERROR:Ingrese una opciones indicadas\n");
                break;
        }
         system("pause");
        system("cls");
    }

    return 0;
}









void graficar(EPersona persona[], int limite)
{
    int i, j;
    int  dieciocho=0;
    int treinta=0;
    int cincuenta=0;
    int flag=0;
    int total;

    for(i=0; i<limite; i++)
    {
        if(persona[i].edad<18 && persona[i].edad>0)
        {
            dieciocho++;
        }
          else if( persona[i].edad > 18)
        {
            treinta++;
        }

          else if(persona[i].edad>35&&persona[i].edad<100)
        {
           cincuenta++;
        }
    }

    if(dieciocho >=treinta && dieciocho >= cincuenta)
    {
        total = dieciocho;
    }
    else
    {
        if(treinta >= dieciocho && treinta >= cincuenta)
        {
            total = treinta;
        }
        else
        {
           total = cincuenta;
        }
    }

    for(j=total; j>0; j--)
    {


        if(j<= dieciocho)
        {
            printf("*");
        }
        if(j<= treinta)
        {
           flag=1;
            printf("\t*");
        }
        if(j<= cincuenta)
        {
            if(flag==0)
            {
                printf("\t\t*");
            }

            else if(flag==1)
            {
                printf("\t*");
            }
        }
        printf("\n");
    }
    printf("                        ");
    printf("\n  |<18\t19-35\t>35\n\n");

}
