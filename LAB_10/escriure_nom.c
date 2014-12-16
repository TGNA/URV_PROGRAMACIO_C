/* Arxiu escriure_nom.c  */
#include <stdio.h>
#include <string.h>              /* defineix la funció strcpy() i strcat()*/
#define NOM 20
#define NOMC 60

int main()
{
int i;
char nom[NOM];
char cognom1[NOM];
char cognom2[NOM];
char nomcomplet[NOMC], nomcomplet2[NOMC];

for (int e = 0; e < NOMC; ++e)
{
  nomcomplet[e]='\0';
}

            /* lectura de noms i congnoms, per separat */
 printf("Escriu el teu nom:");
 scanf("%s", nom);
 printf("Escriu el teu primer cognom:");
 scanf("%s", cognom1);
 printf("Escriu el teu segon cognom:");
 scanf("%s", cognom2);

 strcpy(nomcomplet,nom);
 strcat(nomcomplet,cognom1);
 strcat(nomcomplet,cognom2);

 printf("El teu nom complet es: %s\n", nomcomplet);
 for (i=0; i<NOMC; i++)
       printf("\'%c\' ASCII %d \n",nomcomplet[i],nomcomplet[i]);

    /* lectura de noms i cognoms, tot junt */
 printf("Escriu el teu nom complert:");
 scanf("%s", nomcomplet2);

 printf("El teu nom complet es: %s\n", nomcomplet2);

 return(0);
}
