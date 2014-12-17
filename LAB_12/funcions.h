/* -------------------------------------------------*/
/* Nom de l'equip de desenvolupadors:               */
/* Oscar Blanco Castan                              */
/* Roger Queralt Prunera                            */
/* Jordi Maijo Peris                                */
/* Eva Gorbano Pinet                                */
/*                                                  */
/* Data: 17/desembre/2014                           */
/* -------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
// #include <windows.h>//Nomes windows 

#ifndef FUNCIONS_H_INCLUDED
#define FUNCIONS_H_INCLUDED

#define MAX_FILA 10
#define MAX_COLUMNA 47
#define MAX_NOM 50

#define KNRM  "\x1B[0m"   // negre 
#define KRED  "\x1B[31m"  // vermell
#define KGRN  "\x1B[32m"  // verd
#define KYEL  "\x1B[33m"  // groc
#define KBLU  "\x1B[34m"  // blau
#define KMAG  "\x1B[35m"  // magenta
#define KCYN  "\x1B[36m"  // cyan
#define KWHT  "\x1B[37m"  // blanc

typedef struct{
    int valor;
    bool encertat;
    bool escollida;
} numero;

typedef struct{
    char alias[MAX_NOM];
    int acerts;
} jugador;

#define MAX 7

void memory();
void barrejar_cartes(numero taula[MAX_FILA][MAX_COLUMNA],int fila,int columna, int parellesCartes);
void mostra_taula(numero taula[MAX_FILA][MAX_COLUMNA],int fila, int columna, bool mostrarTot, int jugador1, int jugador2, char alias1Referencia[MAX_NOM], char alias2Referencia[MAX_NOM]);
void calcular_dimensio(int *filaReferencia, int *columnaReferencia, int parellesCartes);
void mostrar_guanyador(int jugador1, int jugador2, char nom1[MAX_NOM], char nom2[MAX_NOM]);
void escollir_cartes(numero taula[MAX_FILA][MAX_COLUMNA],int *fila1, int *columna1, int *fila2, int *columna2, int fila, int columna, int jugador1, int jugador2, char alias1Referencia[MAX_NOM], char alias2Referencia[MAX_NOM]);
bool comparar_cartes(numero taula[MAX_FILA][MAX_COLUMNA], int carta1x, int carta1y, int carta2x, int carta2y);


#endif /* FUNCIONS_H_INCLUDED */
