#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

void mostrar_taula(int fila, int columna){
    int i, e;
    char caracter;

    printf("   |");
    for (i = 0; i < columna; ++i){
        caracter = i+65;
        printf(" %c |", caracter);
    }
    printf("\n");
    for (e = 0; e < columna+1; ++e){
        printf("---*");
    }
    printf("\n");

    for (i = 0; i < fila; ++i){ 
        for (e = 0; e < columna; ++e){
            if (e == 0){
                printf(" %d |", i);
            }
            printf(" X |");
        }
        printf("\n");
        for (e = 0; e < columna+1; ++e){
            printf("---*");
        }
        printf("\n");
    }
}

int main()
{
    int fila, columna, parellesCartes;

    printf("Introdueix el numero de parelles:");
    scanf("%d", &parellesCartes);

    calcular_dimensio(&fila, &columna,parellesCartes);

    int taula[fila][columna];

    // barrejar_cartes();

    mostrar_taula(fila, columna);
    
    printf("%d %d", fila, columna);

    return 0;
}
