
#include "funciones.h"
#include "stdio.h"

float suma(float n1,float n2)
{
    float suma;

    suma=n1+n2;
    return suma;
}


float resta(float n1,float n2)
{
    float resta;
    resta=n1-n2;
    return resta;
}


float multi(float n1,float n2)
{
    float multi;
    multi=n1*n2;
    return multi;
}

float division(float num1,float num2)
{
  float division;
    division=num1/num2;
    return division;
}


int factorial(float num1)
{
    int factor=1;
    int i;
    for (i=num1;i>=1;i--)
    // for (i=1;i<=5;i++)
    {
        factor=factor*i;
    }
      //  }
    return factor;

}





