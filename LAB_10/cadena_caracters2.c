/*  Arxiu cadena_caracters2.c */
#include <stdio.h>

int main()
{
char sal[5];              /* vector de 5 car�cters */

   sal[0]='h';               /* el primer element del vector �s sal[0] */
   sal[1]='o';
   sal[2]='l';
   sal[3]='a';
   sal[4]='\0';              /* posem el sentinella a m�, tamb� es pot posar sal[4]=0; */
   printf("%s\n",sal);       /* %s indica el tipus string */

   return(0);
}
