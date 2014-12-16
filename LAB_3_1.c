#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tempUsuari1,tempUsuari2,tempUsuari3,dif1,dif2,novaTemp;
    int tempMitja;
    FILE *arxiu;

    printf("Predictor de Temperatures\n");
    printf("Indica tres temperatures:");

    scanf("%f", &tempUsuari1);
    scanf("%f", &tempUsuari2);
    scanf("%f", &tempUsuari3);

    dif1=tempUsuari2-tempUsuari1;
    dif2=tempUsuari3-tempUsuari2;

    tempMitja=(tempUsuari1+tempUsuari2+tempUsuari3)/10.0;

    novaTemp=tempMitja+((dif1+dif2)/2.0);
    arxiu=fopen("Predicio.txt","w");
    if (arxiu == NULL){               /* Error al obrir l'arxiu*/
	   printf("Error no puc obrir el fitxer\n");
    }else{           /* guardem les dades a l'arxiu */
      fprintf(arxiu, "La temperatura prevista es : %f ", novaTemp);
      fprintf(arxiu, "La temperatura mitjana es:%d \n", tempMitja);
      fclose(arxiu);
      if(novaTemp>=tempMitja){
        printf("Treu-te el barret i el basto!");
      }else{
        printf("Agafa l'abric que s'acosta el fred!");
      }
    }

    return(0);
}
