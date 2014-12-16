#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LLIBRE 34

typedef struct {
    int dia;
    int mes;
    int any;
} data;

typedef struct {
    data prestec;
    char tema;
} llibre;

typedef struct {
    data prestec;
    int recompte;
} estructuraOpcio2;

void llegir_llibres(llibre llibres[MAX_LLIBRE]){
    FILE *f;
    int dia, mes, any, i;
    char tema;

    f = fopen("/Users/oscarblancocastan/Google Drive/URV/Asignatures/FONAMENTS DE PROGRAMACIÓ /LAB/LAB_11B/llibres.txt","r");


    for (i = 0; i < MAX_LLIBRE; ++i){
        fscanf(f,"%d-%d-%d %c", &dia, &mes, &any, &tema);
        llibres[i].prestec.dia = dia;
        llibres[i].prestec.mes = mes;
        llibres[i].prestec.any = any;
        llibres[i].tema = tema;
    }
    
    fclose(f);
}

void menu_accio(){
    printf("\n\nMenu:\n");
    printf("Opcio 1 - Mostrar el tema que mes prestecs ha tingut.\n");
    printf("Opcio 2 - Comprovar si s'han prestat llibres d'algun tema indicat.\n");
    printf("Opcio 3 - Mostra en quina data s'han prestat mes llibres.\n");
}

void opcio1(llibre llibres[MAX_LLIBRE]){
    int j, M, I, T, F, B, Q;
    char tema;
    M=I=T=F=B=Q=0;
    for (j = 0; j < MAX_LLIBRE; ++j){
        tema = llibres[j].tema;
        switch(tema){
            case 'M':M++;
                    break;
            case 'I':I++;
                    break;
            case 'T':T++;
                    break;
            case 'F':F++;
                    break;
            case 'B':B++;
                    break;
            case 'Q':Q++;
                    break;
        }
    }

    if ((M>I)&&(M>T)&&(M>F)&&(M>B)&&(M>Q))
        printf("Els llibres mes prestats son els de Medicina, %d llibres prestats\n\n", M);
    if ((I>M)&&(I>T)&&(I>F)&&(I>B)&&(I>Q))
        printf("Els llibres mes prestats son els de Informatica, %d llibres prestats\n\n", I);
    if ((T>M)&&(T>I)&&(T>F)&&(T>B)&&(T>Q))
        printf("Els llibres mes prestats son els de Matematiques, %d llibres prestats\n\n", T);
    if ((F>M)&&(F>I)&&(F>T)&&(F>B)&&(F>Q))
        printf("Els llibres mes prestats son els de Fisica, %d llibres prestats\n\n", F);
    if ((B>M)&&(B>I)&&(B>T)&&(B>F)&&(B>Q))
        printf("Els llibres mes prestats son els de Biologia, %d llibres prestats\n\n", B);
    if ((Q>M)&&(Q>I)&&(Q>T)&&(Q>F)&&(Q>B))
        printf("Els llibres mes prestats son els de Quimica, %d llibres prestats\n\n", Q);
}

void opcio2(llibre llibres[MAX_LLIBRE]){
    char tema;
    int i, comptador;

    comptador = 0;

    printf("Introdueix el tema:");
    scanf(" %c", &tema);

    for (i = 0; i < MAX_LLIBRE; ++i){
        if (llibres[i].tema == tema){
            comptador++;
        }
    }

    printf("S'han prestat %d llibres del tema %c\n\n", comptador, tema);
}

void opcio3(llibre llibres[MAX_LLIBRE]){
    estructuraOpcio2 maxim;
    estructuraOpcio2 llista[MAX_LLIBRE];
    int recompte, posicio, i, j, k, l;
    bool trobat;

    recompte = 0;
    posicio = 0;

    for (l = 0; l < MAX_LLIBRE; ++l){
        llista[l].prestec.dia = 0;
        llista[l].prestec.mes = 0;
        llista[l].prestec.any = 0;
        llista[l].recompte = 0;
    }

    for (i = 0; i < MAX_LLIBRE; ++i){
        trobat = false;
        j = 0;

        while((j < MAX_LLIBRE) && !trobat){
            if((llista[j].prestec.dia == llibres[i].prestec.dia) && (llista[j].prestec.mes == llibres[i].prestec.mes) && (llista[j].prestec.any == llibres[i].prestec.any)){
                trobat = true;
                llista[j].recompte++;
                // printf("Trobat\n");
                // printf("%d-%d-%d %d\n", llista[j].prestec.dia, llista[j].prestec.mes, llista[j].prestec.any, llista[j].recompte);
            }
            ++j;
        }

        if(!trobat){
            llista[posicio].prestec.dia = llibres[i].prestec.dia;
            llista[posicio].prestec.mes = llibres[i].prestec.mes;
            llista[posicio].prestec.any = llibres[i].prestec.any;
            llista[posicio].recompte++;
            // printf("Creat\n");
            // printf("%d-%d-%d %d\n", llista[posicio].prestec.dia, llista[posicio].prestec.mes, llista[posicio].prestec.any, llista[posicio].recompte);
            posicio ++;
        }
    }

    for (k = 0; k < MAX_LLIBRE; ++k){
        if (recompte < llista[k].recompte){
            maxim.prestec.dia = llista[k].prestec.dia;
            maxim.prestec.mes = llista[k].prestec.mes;
            maxim.prestec.any = llista[k].prestec.any;
            maxim.recompte = llista[k].recompte;

            recompte = llista[k].recompte;
        }
    }

    printf("El dia que s'han prestat mes llibres es %d-%d-%d amb %d prestecs.\n", maxim.prestec.dia, maxim.prestec.mes, maxim.prestec.any, maxim.recompte);
}

int main(){
    char continuar_char;
    bool continua = false;
    int menu;
    llibre llibres[MAX_LLIBRE];

    llegir_llibres(llibres);

    menu_accio();
    while(!continua){
        printf("Seleccioni una opcio: ");
        scanf("%d", &menu);
        while(menu != 1 && menu != 2 && menu != 3){
            printf("Opcio incorrecta\n");
            printf("Seleccioni una opcio: ");
            scanf("%d", &menu);
        }
        switch(menu){
            case 1: opcio1(llibres);
                    break;
            case 2: opcio2(llibres);
                    break;
            case 3: opcio3(llibres);
                    break;
        }
        printf("Vols continuar?(s/n): ");
        scanf(" %c", &continuar_char);
        if (continuar_char != 'n'){
            menu_accio();
        }else{
            continua = true;
        }
    }

    return 0;
}
