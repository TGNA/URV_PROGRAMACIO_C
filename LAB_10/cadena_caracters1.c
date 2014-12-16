/* Arxiu cadeana_caracters1.c */
#include <stdio.h>

int main()
{
int i;
char s1[20];                     /* declara s1 com una cadena de caracters */
char s2[]="hola\tadios\n";       /* declara e inicialitza la
                                    cadena de caracters s2 (amb 13 caràcters en total, s'inclou el sentinella) */
  i=0;
  while (s2[i]!='\0')
  {
       s1[i]=s2[i];     /* copia la cadena s1 sobre s2, caràcter a caràcter */
       i++;
  }
  s1[i]=s2[i];
  /* mostra per pantalla el contingut de s1 en forma caracter i el seu valor ASCII*/
  for (i=0; i<20; i++)
      printf("\'%c\'\tcodi ASCII %d\n",s1[i],s1[i]);

  return(0);
}
