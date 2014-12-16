#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float area, volum, radi, resultat;
    int operacio;

    printf("Introdueix 1 per calcular l'area i 2 pel volum: ");
    scanf("%d", &operacio);

    switch(operacio){
    case 1:
        printf("\n Ha selecionat l'area \n\n Introdueixi el radi per calcular l'area: ");
        scanf("%f", &radi);
        resultat = ((powf(radi, 2))*4*M_PI);
        printf("L'area del radi %.3f es %.3f", radi, resultat);
        break;
    case 2:
        printf("\n Ha selecionat el volum \n\n Introdueixi el radi per calcular el volum: ");
        scanf("%f", &radi);
        resultat = (((powf(radi, 3))*4*M_PI)/3);
        printf("El volum del radi %.3f es %.3f", radi, resultat);
        break;
    default:
        printf("Valor invalid");
    }
    return 0;
}
