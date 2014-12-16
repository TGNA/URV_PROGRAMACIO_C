#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float n, resultat;
    int i;

    printf("Introdueix el valor ");
    scanf("%f", &n);

    resultat=0;
    for(i=0; i<n; i++){
        resultat+=(1/(pow(2,(i+1))));
    }
    printf("El resultat es %f", resultat);

    return 0;
}
