#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1


int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
int esAlfaNumerico(char str[])
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


int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}




void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    fflush(stdin);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
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
int getStringNumeros(char mensaje[],char input[])
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


int getPassword(char mensaje[],char input[])
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


int getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


int esNumericoFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (i == 0 && str[i] == '-')
       {
           i++;
           continue;

       }
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


int EPersona_alta(EPersona listado[],int limite)
{
    char auxiliarNombreStr[50];
    char auxEdadStr[50];
    char auxDni[50];
    int dni;
    int edad;
    int retorno = -2;

    int indice;

    if(limite > 0 && listado != NULL)
    {
        retorno = -1;
       indice=obtenerEspacioLibre(listado,limite);

        if(indice >= 0)
        {

              if(!getStringLetras("Ingrese nombre de persona : ",auxiliarNombreStr))
              {
                printf ("ERROR:Ingrese solo letras!! \n");
                return -2;
              }
             if(!getStringNumeros("Ingrese la edad : ",auxEdadStr))
                {
                    printf ("ERROR:Ingrese numeros!! \n");
                    return -2;
                }
              edad=atoi(auxEdadStr);
             if(!getStringNumeros("Ingrese el numero de dni: ",auxDni))
             {
                 printf ("ERROR:Ingrese numeros!! \n");
                    return -2;
             }
               dni=atoi(auxDni);

               listado[indice].estado = OCUPADO;
               strcpy(listado[indice].nombre,auxiliarNombreStr);
               listado[indice].edad=edad;
               listado[indice].dni=dni;
               retorno=0;

        }

    }
    return retorno;
}


int EPersona_baja(EPersona listado [],int limite)
{
    char auxdni[30];
    char auxpersona[1];
    int dni;
    int indice;
   printf(" Nombre  EDAD     DNI      ");
EPersona_mostrarListado( listado,limite);
    if(!getStringNumeros("Ingrese el dni a dar de baja : ",auxdni))
    {
        printf("Error , ingrese un valor numerico");
        return -2;
    }
    dni=atoi(auxdni);
      indice=buscarPorDni(listado,limite,dni);
      if(indice>=0)
      {

          if(!getStringLetras("Seguro que desea eliminar persona ?s/n",auxpersona))
          {
              printf("Error ingrese la respuesta en letras ");
              return -2;
          }
             if(auxpersona[0]=='s')
             {
               listado[indice].estado=LIBRE;
             }
             else{
                printf("Baja cancelada");
                indice=-2;
             }

      }
      else{

      }
return indice;
}

int obtenerEspacioLibre(EPersona listado [],int limite)
{

    int retorno = -1;
    int i;
    if(limite > 0 && listado != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(listado[i].estado==LIBRE )
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int iniciarEstado( EPersona listado[],int limite)
{
    int retorno = -1;
    int i;

        retorno = 0;
        for(i=0; i<limite; i++)
        {
            listado[i].estado= LIBRE;

        }

    return retorno;
}


int buscarPorDni(EPersona listado [], int limite,int dni )
{

int i;
int retorno=-1;
for(i=0;i<limite;i++)
{
    if(listado[i].dni==dni)
    {
        retorno=i;
    }
}
return retorno;
}


void EPersona_mostrarUno(EPersona parametro)
{

     printf("\n %s   - %d     - %d\n",parametro.nombre,parametro.edad,parametro.dni);

}

void EPersona_mostrarListado(EPersona listado[],int limite)
{

    int i;
    if(limite > 0 && listado != NULL)
    {

        for(i=0; i<limite; i++)
        {
            if(listado[i].estado==OCUPADO)
            {

                EPersona_mostrarUno(listado[i]);
            }
        }
    }

}

void ordenarPersona(EPersona persona[],int limite)
{
int i;
int j;
EPersona auxpersona;

for (i=0;i<limite-1;i++)
{
    for (j=i+1;j<limite;j++)
    {
        if(strcmp(persona[i].nombre,persona[j].nombre)>0)
        {
            auxpersona=persona[i];
           persona[i]=persona[j];
           persona[j]=auxpersona;

        }
    }
}
}


