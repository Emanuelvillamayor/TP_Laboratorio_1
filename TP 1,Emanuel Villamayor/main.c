#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float num1;
    int entero;
    float num2;
    float totalDivision;
    int totalFactorial;
    int flag=0;


    while(seguir=='s')
    {
        if (flag==0)
        {
        printf("1- Ingresar 1er operando (A=x)\n");

printf("2- Ingresar 2do operando (B=y)\n");
flag=1;

        }
       else if(flag==1)
       {
        printf("1- Ingresar 1er operando (A=%.4f)\n",num1);
        printf("2- Ingresar 2do operando (B=y)\n");
        flag=2;
       }
        else
          {

            printf("1- Ingresar 1er operando (A=%.4f)\n",num1);

            printf("1- Ingresar 2do operando (B=%.4f)\n",num2);
          }



        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                    scanf("%f",&num1);

                break;
            case 2:
                   scanf("%f",&num2);

            break;
            case 3:

               printf("La suma  es : %.4f \n",suma(num1,num2));



                break;
            case 4:
                printf("La resta  es : %.4f \n",resta(num1,num2));

                break;
            case 5:
             if (num2==0)
             {
             printf("Error, no se puede dividir por cero\n");
             break;
             }
            totalDivision=division(num1,num2);

            printf("La division es : %.4f \n" ,totalDivision);
                break;

            case 6:
                printf("La multiplicacion  es : %.4f \n",multi(num1,num2));
                break;
            case 7:
                entero=(int)num1;
               if (num1-entero)
               {
                printf("Error , el numero es decimal\n");
                break;
                    }
                else{
                if (num1==0)
               {
                    num1=1;
                        }
                else if (num1<0)
                 {
                 printf("Error, el numero es negativo\n");
                 break;
                     }
                  else {}
                }
                totalFactorial=factorial(num1);
                printf("El factorial es A=%d \n",totalFactorial);
                break;
            case 8:
               printf("La suma es : %.4f \n",suma(num1,num2));
                printf("La resta  es : %.4f \n",resta(num1,num2));
               printf("La multiplicacion  es : %.4f \n",multi(num1,num2));
               if (num2==0)
               {
               printf("\nDivison: Error no se puede dividir por 0");

               }
               else{
              printf("\nLa division es : %.4f \n",division(num1,num2));
               }
                 entero=(int)num1;
               if (num1-entero)
               {
                printf("\nFactorial :Error , el numero es decimal\n");
                break;
                    }
                else{
                if (num1==0)
               {
                    num1=1;
                        }
                else if (num1<0)
                 {
                 printf("\nFactorial:Error, el numero es negativo\n");
                 break;
                     }
                  else {}
                }
              printf("\nEl factorial es : %d \n",factorial(num1));

                break;
            case 9:
                seguir = 'n';
                break;
        }


}
return 0;
}
