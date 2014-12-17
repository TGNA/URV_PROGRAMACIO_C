/* -------------------------------------------------*/
/* Nom de l'autor dels procediments :               */
/* Jordi Maijo Peris                                */
/*                                                  */
/* Data: 17/desembre/2014                           */
/* -------------------------------------------------*/
#include "funcions.h"

bool comparar_cartes(numero taula[MAX_FILA][MAX_COLUMNA], int carta1x, int carta1y, int carta2x, int carta2y){
  bool encertat = false;
  if(taula[carta1x][carta1y].valor == taula[carta2x][carta2y].valor)
    encertat = true;

  return(encertat);
}
