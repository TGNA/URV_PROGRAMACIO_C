#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define CIUTATS 10
#define MAX_CHAR 20

typedef char mes_taula[MAX_CHAR];

void menu_accio(){
    printf("\n\nMenu:\n");
    printf("Opcio 0 - Mostra les ciutats durant el mes d'agost que han tingut una temperatura superior a una temperatura donada.\n");
    printf("Opcio 1 - Mostra un llistat de les ciutats que als mesos d'hivern (desembre, gener i febrer) han tingut una temperatura inferior a un determinat nombre de graus.\n");
    printf("Opcio 2 - Mostra quina ciutat i mes s'ha obtingut la temperatura mes baixa.\n");
}

void llegir_temperatues(int temperatures[CIUTATS][12]){
    FILE *f;
    int fila, columna, temperatura;
    char comma;

    f = fopen("/Users/oscarblancocastan/Google Drive/URV/Asignatures/FONAMENTS DE PROGRAMACIÓ /LAB/LAB_11A/Temperatures.txt","r");
        for (fila = 0; fila < CIUTATS; ++fila){
            for (columna = 0; columna < 12; ++columna){
                fscanf(f, "%d %c", &temperatura, &comma);
                temperatures[fila][columna]=temperatura;
            }
        }
    fclose(f);
}

void agost(int temperatura, int mes, int temperatures[CIUTATS][12]){
    int fila, columna, comptador;
    comptador =0;

    mes_taula mesos[12] = {"Gener", "Febrer", "Marc", "Abril", "Maig", "Juny", "Juliol", "Agost", "Septembre", "Octubre", "Novembre", "Desembre"};

    for (fila = 0; fila < CIUTATS; ++fila){
        for (columna = 0; columna < 12; ++columna){
            if ((columna == mes) && (temperatures[fila][columna] >= temperatura)){
                comptador ++;
            }
        }
    }

    printf("Hi han %d ciutats amb una temperatura superior a %d el mes %s.\n", comptador, temperatura, mesos[mes]);
}

void temperatura_baixa(int temperatures[CIUTATS][12]){
    int temperatura_baixa[3]; //[ciutat, mes, temperatura]
    int fila, columna;
    mes_taula mesos[12] = {"Gener", "Febrer", "Marc", "Abril", "Maig", "Juny", "Juliol", "Agost", "Septembre", "Octubre", "Novembre", "Desembre"};

    temperatura_baixa[0]= 0;
    temperatura_baixa[1]= 0;
    temperatura_baixa[2]= INT_MAX;

    for (fila = 0; fila < CIUTATS; ++fila){
        for (columna = 0; columna < 12; ++columna){
            if (temperatura_baixa[2] >= temperatures[fila][columna]){
                temperatura_baixa[0] = fila;
                temperatura_baixa[1] = columna;
                temperatura_baixa[2] = temperatures[fila][columna];
            }
        }
    }

    printf("La ciutat amb la temperatura mes baixa es la ciutat %d al mes %s amb %d graus.\n", temperatura_baixa[0], mesos[temperatura_baixa[1]], temperatura_baixa[2]);
}

void hivern(int temperatures[CIUTATS][12], int temperatura){
    int fila, columna, comptador, imprimir;
    int llistat[CIUTATS * 3];

    comptador = 0;
    for (imprimir = 0; imprimir < CIUTATS*3; ++imprimir){
        llistat[imprimir] = -1;
    }

    for (fila = 0; fila < CIUTATS; ++fila){
        for (columna = 0; columna < 12; ++columna){
            if ((columna == 0) || (columna == 1) || (columna == 11)){
                if (temperatures[fila][columna]<temperatura){
                    llistat[comptador] = fila;
                    comptador++;
                }
            }
        }
    }

    printf("Aquestes son les ciutats on a l'hivern hi ha hagunt una temperatura inferior a %d graus\n", temperatura);
    for (imprimir = 0; imprimir < CIUTATS; ++imprimir){
        if (llistat[imprimir] != -1){
            printf("Ciutat %d\n", llistat[imprimir]);
        }
    }
}

int main(){
    int temperatures[CIUTATS][12];
    int menu,temperaturaAgost, temperatura, fila, columna;
    char continuar_char;
    bool continua = false;

    llegir_temperatues(temperatures);

    menu_accio();
    while(!continua){
        

    for (fila = 0; fila < CIUTATS; ++fila){
        for (columna = 0; columna < 12; ++columna){
            printf("Ciutat:%d  Mes:%d Temperatura:%d\n", fila, columna, temperatures[fila][columna]);
        }
    }

    return 0;
}
