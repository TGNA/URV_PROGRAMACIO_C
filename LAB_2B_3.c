#include <stdio.h>
#include <stdlib.h>

int main()
{
    float tarifaHora, horesTreballades, pagaBruta, tassaImpostos, impostos, pagaNeta;
    FILE *f;

    printf("L'ordre de les dades en el fitxer es el seguent: tarifaHora salt de linia hores treballades salt de linia tassa impostos ");

    f= fopen("C:\\Projectes\\LAB2B_3\\Dades.txt", "r");
        fscanf(f, "Tarifa=%f", &tarifaHora);
        fscanf(f, "\n");
        fscanf(f, "Horestreballades=%f", &horesTreballades);
        printf(f, "\n");
        fscanf(f, "Tassaimpostos=%f", &tassaImpostos);
    fclose(f);

    pagaBruta = horesTreballades * tarifaHora;
    impostos = pagaBruta * tassaImpostos;
    pagaNeta = pagaBruta - impostos;

    printf("\n");
    printf("La paga bruta es de %.2f. La paga neta es %.2f euros. Es paguen %.2f euros en impostos.", pagaBruta, pagaNeta, impostos);

    return 0;
}
