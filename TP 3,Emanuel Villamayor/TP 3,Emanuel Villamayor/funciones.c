#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LIBRE 0
#define OCUPADO 1

int mostrarPunteroArray(EMovie* listado ,int limite)
{
    int i;
    int retorno=0;
    if(listado!=NULL&&limite>0)
    {
      retorno=1;
      ordenarPeliculasId( listado,limite);
        for (i=0;i<limite;i++)
      {
          if((listado+i)->estado==OCUPADO)
          {
            if(!mostrarpunteroUno(listado+i))
              {
                 printf("No se pudo mostrar array");
              }
          }
       }
    }
    return retorno;
}


int mostrarpunteroUno(EMovie* listado)
{
    int retorno=0;


    if(listado!=NULL)
    {
        retorno=1;

        printf("ID : %d\n",listado->id);
        printf("Titulo : %s\n",listado->titulo);
        printf("Genero : %s\n",listado->genero);
        printf("Duracion : %d min\n",listado->duracion);
        printf("Descripcion : %s\n",listado->descripcion);
        printf("Puntaje : %d\n",listado->puntaje);
        printf("Link de Imagen : %s\n",listado->linkImagen);
        printf("--------------------------------------------------------------------------\n");




    }
    return retorno;
}
void ordenarPeliculasId(EMovie* listado,int limite)
{
    int i,j;
    EMovie aux;
    for(i=0;i<limite-1;i++)
       for(j=i+1;j<limite;j++)
      if(((listado+i)->id)>((listado+j)->id))
         {
           aux=listado[i];
          listado[i]=listado[j];
          listado[j]=aux;
         }
}
int obtenerEspacioLibre(EMovie* listado,int limite)
{

    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if((listado+i)->estado==LIBRE )
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int iniciarEstado( EMovie* listado,int limite)
{
    int retorno = -1;
    int i;

        retorno = 0;
        for(i=0; i<limite; i++)
        {
            if((listado+i)->estado!=OCUPADO)
            {
                (listado+i)->estado=LIBRE;
                (listado+i)->id=0;
            }

        }

    return retorno;
}


int siguienteId(EMovie* listado,int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if((listado+i)->estado == OCUPADO)
            {
                    if((listado+i)->id>retorno)
                    {
                         retorno=(listado+i)->id;
                    }
            }
        }
    }

    return retorno+1;
}

int buscarPorId(EMovie* listado, int limite,int id )
{

int i;
int retorno=-1;
for(i=0;i<limite;i++)
{
    if((listado+i)->id==id)
    {
        retorno=i;
    }
}
return retorno;
}



int agregarPelicula(EMovie* listado,int limite)
{
    int id;
    char auxtitulo[50];
    char auxgenero[50];
    char auxduracion[20];
    int duracion;
    char auxdescripcion[200];
    char auxpuntaje[20];
    int puntaje;
    char auxlinkImagen[1500];

    int init;
    int retorno=-2;
    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno=-1;

        id=siguienteId(listado,limite);

        indice=obtenerEspacioLibre(listado,limite);
        if(indice>=0)
        {
            if((listado+indice)->estado!=OCUPADO)
            {
                init=iniciarEstado(listado,limite);
            }
            else{

                return -2;
            }
            if(!getAlfaNumerico("Ingrese el titulo : ",auxtitulo))
        {
            printf("Error , ingrese solo letras y numeros!!");
            return -2;
        }
            if(!getStringLetras("Ingrese genero de la pelicula : ",auxgenero))
            {
                printf("Error , ingrese solo letras !!\n");
                return -2;
            }
            if(!getStringNumeros("Ingrese duracion de la pelicula (min): ",auxduracion))
            {
                printf("Error , ingrese solo numeros!!\n");
                return -2;
            }
            duracion=atoi(auxduracion);

            if(!getAlfaNumerico("Ingrese una breve descripcion  : ",auxdescripcion))
            {
                printf("Error , ingrese solo letras !!\n");
                return -2;
            }
            if(!getStringNumeros("Ingrese un puntaje (0-10) : ",auxpuntaje))
            {
                printf("Error , ingrese solo numeros!!\n");
                return -2;
            }
            puntaje=atoi(auxpuntaje);
            if(!(puntaje>=0&&puntaje<=10))
            {
                printf("Error ingrese uno de los puntajes indicados!!\n");
                return -2;
            }

            printf("Ingrese link de la imagen: ");
            fflush(stdin);
            gets(auxlinkImagen);

            (listado+indice)->id=id;
            strcpy((listado+indice)->titulo,auxtitulo);
            strcpy((listado+indice)->genero,auxgenero);
            (listado+indice)->duracion=duracion;
            strcpy((listado+indice)->descripcion,auxdescripcion);
            (listado+indice)->puntaje=puntaje;
            strcpy((listado+indice)->linkImagen,auxlinkImagen);
            (listado+indice)->estado=OCUPADO;



             retorno=0;
        }


    }
    return retorno;
}

int borrarPelicula(EMovie* listado,int limite)
{
    int retorno=-2;
    char auxid[20];
    char auxRespuesta[2];
    int id;
    int indice;
     if(limite > 0 && listado != NULL)
    {
        retorno=-1;
      if(!getStringNumeros("Ingrese el Id a dar de baja : ",auxid))
        {
        printf("Error ingrese un valor numerico !!\n");
        return -2;
        }
         id=atoi(auxid);
         indice=buscarPorId(listado,limite,id);
         if(indice>=0)
           {
               if(!getStringLetras("Seguro desea dar de baja? (s/n): ",auxRespuesta))
               {
                   printf("Error ,ingrese solo letras !!");
               }
               if(auxRespuesta[0]=='s')
               {
                   (listado+indice)->estado=LIBRE;
                   (listado+indice)->id=-1;
                   retorno=0;
               }
           }
           else
           {
               printf("Id inexistente!!\n");
               return -2;
           }
   }

return retorno;
}

int modificarPelicula(EMovie* listado,int limite)
{
    int id;
    int indice;
    int resultado;


    int retorno=-2;
    char auxId[20];
    if(limite > 0 && listado != NULL)
    {
     retorno=-1;

     if(!getStringNumeros(" \nIngrese el id a modificar: ",auxId))
                {
                    printf("ERROR:Ingrese un valor numerico!!\n");
                    return -2;
                }

               id=atoi(auxId);
               indice=buscarPorId(listado,limite,id);
               if(indice>=0)
               {
                   resultado=menuModificar(listado,indice);
                   retorno=resultado;
               }
               else
               {
                   printf("Ingrese un Id existente\n!!");
               }
    }
return retorno;
}

int menuModificar(EMovie* listado,int indice)
{
    char auxOpcion[20];
    char auxTitulo[50];
    char auxGenero[50];
    char auxDescripcion[200];
    char auxDuracion[20];
    char auxPuntaje[20];
    char auxLink[1500];
    int opcion;
    int duracion;
    int puntaje;
    int retorno=-1;

    if(!getStringNumeros("Que desea modificar ?: \n1-Titulo\n2-Genero\n3-Duracion\n-4Descripcion\n5-Puntaje\n6-Link Imagen\n",auxOpcion))
    {
     printf("Error , ingrese un valor numerico ") ;
     return -2;
    }
    opcion=atoi(auxOpcion);
    if(opcion>=1&&opcion<=6)
    {
    switch(opcion)
    {
    case 1:
        if(!getAlfaNumerico("Ingrese el nuevo titulo : ",auxTitulo))
        {
            printf("Error , ingrese solo letras y numeros!!");
            return -2;
        }
        strcpy((listado+indice)->titulo,auxTitulo);
        retorno=indice;
        break;
    case 2:
        if(!getStringLetras("Ingrese el nuevo genero : ",auxGenero))
        {
            printf("Error,Ingrese solo letras!!");
            return -2;
        }
        strcpy((listado+indice)->genero,auxGenero);
        retorno=indice;
        break;
    case 3:
        if(!getStringNumeros("Ingrese nueva duracion : ",auxDuracion))
        {
            printf("Error , ingrese un valor numerico!!");
            return -2;
        }
        duracion=atoi(auxDuracion);
        (listado+indice)->duracion=duracion;
        retorno=indice;
        break;
    case 4:
        if(!getAlfaNumerico("Ingrese la nueva descripcion : ",auxDescripcion))
        {
            printf("Error , ingrese solo letras!!");
            return -2;
        }
        strcpy((listado+indice)->descripcion,auxDescripcion);
        retorno=indice;
        break;
    case 5:
        if(!getStringNumeros("Ingrese el nuevo puntaje : ",auxPuntaje))
        {
            printf("Error , ingrese un valor numerico!!");
            return -2;
        }
        puntaje=atoi(auxPuntaje);
        if(!(puntaje>=0&&puntaje<=10))
            {
                printf("Error ingrese uno de los puntajes indicados!!\n");
                return -2;
            }

        (listado+indice)->puntaje=puntaje;
        retorno=indice;
        break;
    case 6:
            printf("Ingrese nuevo link de la imagen: ");
            fflush(stdin);
            gets(auxLink);
        strcpy((listado+indice)->linkImagen,auxLink);
        retorno=indice;
        break;
    default:
        printf("Error , ingrese una de las opciones indicadas!!");
        return -2;
        break;
    }

    }
    else
    {
        printf("Error , ingrese una de las opciones indicadas!!");
        return -2;
    }
    return retorno;
}

int esNumerico(char* str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < '0' || str[i] > '9')||(isspace(str[0])!=0))
           return 0;
       i++;
   }
   return 1;
}

int esAlfaNumerico(char* str)
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
       return 0;
       i++;
   }
   return 1;
}



int esSoloLetras(char* str)
{
   int i=0;

   while(str[i] != '\0')
   {
        if((str[i] != ' ') && (str[i] < 'a' ||str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 0;
        i++;
   }
   return 1;
}


void getString(char* mensaje,char* input)
{
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);

}

int getStringLetras(char* mensaje,char* input)
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char* mensaje,char* input)
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}



int getAlfaNumerico(char* mensaje,char* input)
{
    char aux[256];
    getString(mensaje,aux);
    if(esAlfaNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}





int cargarDesdeArchivo(EMovie* listado,int limite)
{
	int flag = 0;
	FILE *f;

	f=fopen("peli.dat", "rb");
	if(f==NULL)
	{
		f=fopen("peli.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(listado,sizeof(EMovie),limite,f);
    }

	fclose(f);
	return 0;
}

int guardarEnArchivo(EMovie * listado,int limite)
{

	FILE *f;

		f=fopen("peli.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(listado,sizeof(EMovie),limite,f);

	fclose(f);

	return 0;
}

void crearHtml(EMovie *listado, int limite)
{
     int i;
     FILE *f;
     f=fopen("movie.html", "w");

     if(f == NULL)
     {
          printf("No se pudo abrir el archivo\n");
     }
     else
     {
        fprintf(f,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible'content='IE=edge'><meta name='viewport'content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css'rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css'rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
         for(i=0; i<limite; i++)
         {
                  if((listado+i)->estado != 0 && (listado+i)->id>=0)
                  {
                 fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero:%s</li><li>Puntaje:%d</li><li>Duracion:%d</li></ul><p>%s</p></article>",listado[i].linkImagen,listado[i].titulo,listado[i].genero,listado[i].puntaje,listado[i].duracion,listado[i].descripcion);
                  }
         }
         fprintf(f,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='.'js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
      }



      fclose(f);

      printf("-Html creado con exito\n");

}
