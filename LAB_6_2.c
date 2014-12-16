#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero, recompte;

    recompte=0;

    printf("Introdueix el valor");
    scanf("%d", &numero);

    while(numero != -1){
        if(((numero%3 == 0) || (numero%5 == 0)) && (numero%15 != 0)){
            recompte+=1;
        }
        printf("Introdueix el valor");
        scanf("%d", &numero);
    }

    printf("Hi han %d que son divisibles per 3 o per 5 pero que no son divisibles per 15", recompte);

    return 0;
}
