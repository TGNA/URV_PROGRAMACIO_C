/* -------------------------------------------------*/
/* Nom de l'autor dels procediments :               */
/*                   */
/*                                                  */
/* Data: 17/desembre/2014                           */
/* -------------------------------------------------*/
#include "funcions.h"

void barrejar_cartes(numero taula[MAX_FILA][MAX_COLUMNA],int fila,int columna, int parellesCartes){
    int i, x, y, a, b, j, k, comptador, valorAux;

    comptador = 0;
    for (j = 0; j < fila; ++j){
        for (k = 0; k < columna; ++k){
            taula[j][k].valor = comptador;
            if (comptador==(parellesCartes-1)){
                comptador = -1;
            }
            comptador++;
        }
    }

    for(i = 0; i < 800; ++i){
        x = rand()% fila;
        y = rand()% columna;
        a = rand()% fila;
        b = rand()% columna;

        valorAux = taula[x][y].valor;
        taula[x][y].valor = taula[a][b].valor;
        taula[a][b].valor = valorAux;
    }
}

void mostrar_guanyador(int jugador1, int jugador2, char nom1[MAX_NOM], char nom2[MAX_NOM]){
    if(jugador1<jugador2){
        printf("%s %s Has guanyat!!! %s", KGRN, nom2,KNRM);
    }
    else if(jugador2<jugador1){
        printf("%s %s Has guanyat!!! %s", KGRN, nom1, KNRM);
    }
    else{
        printf("Eu empatat!");
    }
}
