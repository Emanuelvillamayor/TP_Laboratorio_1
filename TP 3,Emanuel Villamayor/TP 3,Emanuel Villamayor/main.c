#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM 10

int main()
{
    EMovie pelicula[TAM];
    char seguir='s';
    char auxopcion[20];
    int opcion=0;
    int alta;
    int baja;
    int mostrar;
    int modificar;

if(cargarDesdeArchivo(pelicula,TAM))
	{
		printf("No se pudo abrir el fichero");
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");

	}

      system("pause");
      system("cls");


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web y guardar datos en archivo\n");
        printf("5-Salir\n");


       if(!getStringNumeros("Ingrese una opcion : ",auxopcion))
       {
           printf("Error , ingrese solo numeros!!\n");
       }
       else{
       opcion=atoi(auxopcion);

        switch(opcion)
        {
            case 1:
                alta=agregarPelicula(pelicula,TAM);
                if(alta>=0)
                {
                    printf("Carga exitosa\n");
                }
                else if(alta==-1)
                {
                    printf("No quedan mas espacios\n");
                }
                else{}
                break;
            case 2:
               mostrar=mostrarPunteroArray(pelicula,TAM);
               baja=borrarPelicula(pelicula,TAM);
               if(baja>=0)
                {
                    printf("Baja exitosa\n");
                }
                else if(baja==-1)
                {
                    printf("Baja cancelada \n");
                }
                else{}

                break;
            case 3:
                 mostrar=mostrarPunteroArray(pelicula,TAM);
                 modificar=modificarPelicula(pelicula,TAM);
                 if(modificar>=0)
                 {
                     printf("Modificacion realizada\n");
                 }
                 else if (modificar==-1)
                 {
                     printf("Modificacion cancelada\n");
                 }
                 else{}
               break;
            case 4:
                crearHtml(pelicula,TAM);
                if(guardarEnArchivo(pelicula,TAM))
					{
						printf("\nNo se pudo abrir el fichero\n");
					}
					else
					{
						printf("-Se guardo la informacion con exito\n");
					}


                break;
            case 5 :
                  seguir = 'n';
                 break;
            default:
                printf("ERROR:Ingrese una de las opciones indicadas!!\n");
                break;
        }
       }
        system("pause");
        system("cls");
    }

    return 0;
}

