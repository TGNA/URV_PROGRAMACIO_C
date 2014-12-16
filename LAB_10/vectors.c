/* Arxiu vectors.c  */
#include <stdio.h>

int main()
{
int i;
int s1[10];       /* declaracio del vector s1 de 10 enters */

 i=0;
        /* s'iniciatiza el vector */
 while (i<=10)
 {
    s1[i]=i+1;
    i++;
 }

    /* mostra per pantalla  el contingut del vector s1 en cada posicio */
 for (i=0; i<10; i++)
     printf("el valor del vector a la posicio %d es %d\n",i,s1[i]);

 return(0);
}
