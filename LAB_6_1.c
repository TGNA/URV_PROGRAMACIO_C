#include <stdio.h>
#include <stdlib.h>

int main()
{
    int recompte, numero, primerValor, valor, i;
    float percentatge;

    recompte = 0;

    printf("Introdueix el numero de notes");
    scanf("%d", &numero);

    printf("Introdueixi el 1 valor");
    scanf("%d", &primerValor);

    for(i=1; i< numero; i++){
        printf("Introdueixi el %d valor", i+1);
        scanf("%d", &valor);
        if(valor > primerValor){
            recompte+=1;
        }
    }

    percentatge = ((recompte*100)/(numero-1)); //el percentatge es calculat sense tenir en compte el primer resultat
    printf("El percentatge es %.2f", percentatge);

    return 0;
}
