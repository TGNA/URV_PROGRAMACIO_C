#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  float preu, diners, ct, canvi_imprimir;
  int canvi, preu_int, diners_int, euros, centims, m2, m1, m50, m20, m5;

  printf("Indica el preu del producte ");
  scanf("%f",&preu);
  printf("Indica els diners que dones ");
  scanf("%f",&diners);
  diners=diners * 100;
  preu=preu*100;
  diners_int=round(diners) ;
  preu_int=round(preu);
  canvi=diners_int-preu_int;
        /* en aquest moment suposem que donem mes diners que el preu */
        /* i per tant el canvi sera positiu */

    if(diners > 500){
        printf("Siusplau, introdueixi una cantitad de diners menor a 5(amb la finalitat de preservar el canvi)");
    }else if(diners >= preu){
        canvi_imprimir= (float)canvi/100;
        euros=canvi/100;  /* agafem la part entera */
        ct= canvi % 100;    /* agafem els centims */
        centims=ct;    /* per a poder aplicar la divisio entera i el modul cal treballar amb enters */

        m2=euros/2;
        m1=euros%2;
        m50=centims/50;
        centims=centims%50;
        m20=centims/20;
        centims=centims%20;
        m5=centims/5;

        printf("El canvi es %.2f i hem de tornar:\n",canvi_imprimir);
        printf("\t%d monedes de 2 euros\n",m2);
        printf("\t%d monedes de 1 euros\n",m1);
        printf("\t%d monedes de 50 centims\n",m50);
        printf("\t%d monedes de 20 centims\n",m20);
        printf("\t%d monedes de 5 centims\n",m5);
    }else
        printf("Diners insufucients per al pagament del producte");

  return(0); /* acabem el programa amb exit */
}
