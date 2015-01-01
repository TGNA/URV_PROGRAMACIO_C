/* -------------------------------------------------*/
/* Nom de l'autor dels procediments :               */
/*                          */
/*                                                  */
/* Data: 17/desembre/2014                           */
/* -------------------------------------------------*/
#include "funcions.h"

void escollir_cartes(numero taula[MAX_FILA][MAX_COLUMNA],int *fila1, int *columna1, int *fila2, int *columna2, int fila, int columna, int jugador1, int jugador2, char alias1Referencia[MAX_NOM], char alias2Referencia[MAX_NOM]){
  int fil,col;
  char temp;

  printf("Digues la lletra: ");
  scanf(" %c", &temp);
  printf("Digues el numero: ");
  scanf("%d", &fil);
  col = (int)temp - 'A';
  *columna1 = col;
  *fila1 = fil;
  taula[fil][col].escollida = true;

  mostra_taula(taula, fila, columna, false, jugador1, jugador2, alias1Referencia, alias2Referencia);

  printf("Digues la lletra: ");
  scanf(" %c", &temp);
  printf("Digues el numero: ");
  scanf("%d", &fil);
  col = (int)temp - 'A';
  *columna2 = col;
  *fila2= fil;
  taula[fil][col].escollida = true;

  memory();
  mostra_taula(taula, fila, columna, false, jugador1, jugador2, alias1Referencia, alias2Referencia);
}
