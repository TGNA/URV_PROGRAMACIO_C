#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Factorial (int num){
    int numero, i;
    numero = 1;

    for(i=1; i<=num; i++){
        numero = numero*i;
    }

    return numero;
}

void positiu_petit(int *posp)
{
    int valor, min;
    min= INT_MAX;
    printf("Introdueix el valor: ");
    scanf("%d",&valor);
    while(valor != 0){
        if ((valor<min) && (valor>0))
        {
            min=valor;
        }
        printf("Introdueix el valor: ");
        scanf("%d",&valor);
    }

    *posp=min;
}

int Combinacions (int m, int n){
    int resultat;

    if(m>=n){
        resultat = Factorial(m)/(Factorial(n)*Factorial(m-n));
    }
    else{
        resultat=0;
    }

    return resultat;
}

void menu (){
    printf("1 - Calcular el factorial d'un numero \n");
    printf("2 - Calcular positiu mes petit \n");
    printf("3 - Calcular les combinacions \n");
    printf("4 - Sortir del programa \n\n");
    printf("Quina opcio vols? ");
}

int main()
{
   int posp=0,m=0,n=0,c, op=0, num=0;

    menu();
    scanf("%d", &op);

    while (op!=4){
        switch (op){
            case 1: printf("\nIntrodueix el numero per calcular el factorial: ");
                    scanf("%d",&num);
                    if(num >= 0){
                        num=Factorial(num);
                        printf("El factoral del numero es: %d\n\n",num);
                    }else{
                        printf("El factoral d'un numero negatiu no existeix\n\n");
                    }
            break;
            case 2: positiu_petit(&posp);
                    if(posp == INT_MAX){
                        printf("No hi han numeros petits positius\n\n");
                    }else{
                        printf("El numero mes petit es:  %d\n\n",posp);
                    }
            break;
            case 3: printf("\nDonam el valor de m: ");
                    scanf("%d",&m);
                    printf("Dame el valor de n: ");
                    scanf("%d",&n);

                    c=Combinacions(m,n);
                    printf("La combinacio es :%d\n\n",c);
            break;
            case 4: break;
        }
        menu();
        scanf("%d", &op);
    }
    return 0;
}
