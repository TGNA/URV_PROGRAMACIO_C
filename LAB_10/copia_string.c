/* Arxiu copia_string.c */
#include <stdio.h>
#include <string.h>              /* defineix la funci� strcpy() */

int main()
{
int i;
char sa[20];                 /* string de 20 car�cters, sentinella incl�s */

strcpy(sa,"hola\tadios\n");  /* el 2on par�metre �s un string constant */
                                       /* els s�mbols "\t" i "\n" s�n un �nic car�cter */
for (i=0; i<12; i++)
     printf("\'%c\'\t ASCII %d\n",sa[i],sa[i]);

return(0);
}
