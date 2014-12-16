#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int valor;
    bool encertat;
} numero;

typedef struct{
    int acerts;
    bool encertat;
} jugador;

void mostrar_taula(numero taula[10][10],int fila, int columna){
    int i, e;
    char caracter;

    printf("    |");
    for (i = 0; i < columna; ++i){
        caracter = i+65;
        printf("  %c |", caracter);
    }
    printf("\n");
    for (e = 0; e < columna+1; ++e){
        printf("----*");
    }
    printf("\n");

    for (i = 0; i < fila; ++i){ 
        for (e = 0; e < columna; ++e){
            if (e == 0){
                printf("  %d |", i);
            }
            printf(" %0.2d |",taula[i][e].valor);
        }
        printf("\n");
        for (e = 0; e < columna+1; ++e){
            printf("----*");
        }
        printf("\n");
    }
}


void calcular_dimensio(int *filaReferencia, int *columnaReferencia, int parellesCartes){
    int fila, columna, cartes, diferencia;
    diferencia=999;

    cartes = parellesCartes*2;

    fila = (int)sqrt(cartes);
    columna = cartes/fila;

    if (fila*columna!=cartes){
        for (int i = 0; i < cartes; ++i){
            for (int e = 0; e < cartes; ++e){
                if (i*e==cartes){
                    // printf("%d %d\n",i, e);
                    if (diferencia>abs(e-i)){
                        diferencia=abs(e-i);
                        fila=i;
                        columna=e;
                    }
                }
            }
        }
    }

    *filaReferencia = fila;
    *columnaReferencia = columna;
}

int main()
{
    int fila, columna, parellesCartes;

    printf("Introdueix el numero de parelles:");
    scanf("%d", &parellesCartes);

    calcular_dimensio(&fila, &columna,parellesCartes);
    printf("%d %d\n",fila, columna );
    numero taula[fila][columna];

    int a,b,comptador;

    comptador = 0;
    for (a = 0; a < fila; ++a){
        for (b = 0; b < columna; ++b){
            taula[a][b].valor = comptador;
            if (comptador==(parellesCartes-1)){
                comptador = -1;
            }
            comptador++;
        }
    }

    // barrejar_cartes();
    mostrar_taula(taula, fila, columna);

    printf("%d %d", fila, columna);

    return 0;
}
