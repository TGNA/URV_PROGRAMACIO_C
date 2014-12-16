#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{

    FILE *llegir,*escriure,*escriureBinari;
    float volum, radi;
    int i;

    llegir=fopen("25radi_esfera.txt", "r");

    if(llegir){
        escriure=fopen("25vol_esfera.txt", "w");
        escriureBinari=fopen("25vol_esfera.dat", "wb");

        for(i=0; i<25; i++){
            fscanf(llegir, "%f", &radi);
            volum = (((powf(radi, 3))*4*M_PI)/3);
            fwrite(&volum, sizeof(float), 1, escriureBinari);
            fprintf(escriure, "radi %.3f => volum %.3f \n", radi, volum);
        }

        fclose(escriure);
        fclose(escriureBinari);

        printf("\n\n S'ha llegit correctament el fitxer anomenat \"25radi_esfera.txt\" i s'ha desat els resultats al fitxer \"25vol_esfera.txt\" i '25vol_esfera.dat'\n\n");

    }else{
        printf("\n\n No s´ha trobat el fitxer a llegir \n\n");
    }

    fclose(llegir);

    return 0;
}
