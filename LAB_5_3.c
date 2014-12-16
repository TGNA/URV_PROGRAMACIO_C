#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *binari;
    float volum;

    binari=fopen("25vol_esfera.dat", "r");

    if(binari){
        fread(&volum, sizeof(float), 1, binari);

        while(!feof(binari)){
            printf("el volum es %f \n", volum);
            fread(&volum, sizeof(float), 1, binari);
        }
    }else{
        printf("\n\n No s´ha trobat el fitxer a llegir \n\n");
    }

    fclose(binari);

    return 0;
}
