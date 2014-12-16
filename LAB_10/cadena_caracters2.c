/*  Arxiu cadena_caracters2.c */
#include <stdio.h>

int main()
{
char sal[5];              /* vector de 5 caràcters */

   sal[0]='h';               /* el primer element del vector és sal[0] */
   sal[1]='o';
   sal[2]='l';
   sal[3]='a';
   sal[4]='\0';              /* posem el sentinella a mà, també es pot posar sal[4]=0; */
   printf("%s\n",sal);       /* %s indica el tipus string */

   return(0);
}
