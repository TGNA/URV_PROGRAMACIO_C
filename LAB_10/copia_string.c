/* Arxiu copia_string.c */
#include <stdio.h>
#include <string.h>              /* defineix la funció strcpy() */

int main()
{
int i;
char sa[20];                 /* string de 20 caràcters, sentinella inclòs */

strcpy(sa,"hola\tadios\n");  /* el 2on paràmetre és un string constant */
                                       /* els símbols "\t" i "\n" són un únic caràcter */
for (i=0; i<12; i++)
     printf("\'%c\'\t ASCII %d\n",sa[i],sa[i]);

return(0);
}
