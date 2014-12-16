#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, recompte;

    recompte=0;

    printf("Introdueix el valor");
    scanf("%d", &numero);

    while(numero != -50){
        if(numero < 0){
            recompte+=1;
        }
        printf("Introdueix el valor");
        scanf("%d", &numero);
    }

    if(recompte>5){
        printf("Hi han %d que son negatius en la sequencia", recompte);
    }else{
        printf("Hi han menys de 5 valors negatius en la sequencia");
    }

    return 0;
}
