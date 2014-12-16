#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int valorPrimer, valorSegon;
    bool creixent = false;
    bool decreixent = false;
    bool ordenat = true;

    printf("Introdueix el valor");
    scanf("%d", &valorPrimer);

    printf("Introdueix el seguent valor");
    scanf("%d", &valorSegon);

    //tenint en compte que hem d'avaluar una sequencia i una sequencia ha de tenir un minim de dos valors no fa falta que controlem els 2 primers casos

    while(valorSegon != -200) {
        if(ordenat){
            if(valorPrimer < valorSegon){
                creixent = true;
                if(creixent && decreixent){
                    ordenat = false;
                    creixent = false;
                    decreixent = false;
                }
            }else if(valorPrimer > valorSegon){
                decreixent = true;
                if(creixent && decreixent){
                    ordenat = false;
                    creixent = false;
                    decreixent = false;
                }
            }else if(valorPrimer = valorSegon){
                ordenat = false;
                creixent = false;
                decreixent = false;
            }
        }

        valorPrimer = valorSegon;

        printf("Introdueix el seguent valor");
        scanf("%d", &valorSegon);
    }

    if(creixent){
        printf("La sequencia es creixent");
    }else if(decreixent){
        printf("La sequencia es decreixent");
    }else if(!ordenat){
        printf("La sequencia no esta ordenada");
    }

    return 0;
}
