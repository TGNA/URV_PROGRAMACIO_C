/* -------------------------------------------------*/
/* Nom de l'equip de desenvolupadors:               */
/* Oscar Blanco Castan                              */
/* Roger Queralt Prunera                            */
/* Eva Gorbano Pinet                                */
/* Jordi Maijo Peris                                */
/*                                                  */
/* Data: 17/desembre/2014                           */
/* -------------------------------------------------*/
#include "funcions.h"

int main(){
  int fila, columna, parellesCartes, i, j, torn, fila1, columna1, fila2, columna2;
  numero taula[MAX_FILA][MAX_COLUMNA];
  jugador jugador1, jugador2;

  torn = 0;
  jugador1.acerts = jugador2.acerts = 0;

  for (i = 0; i < MAX_FILA; ++i){
    for (j = 0; j < MAX_COLUMNA; ++j){
      taula[i][j].encertat = false;
      taula[i][j].escollida = false;
    }
  }

  memory();
  printf("Escriu el nom del jugador 1: ");
  fgets (jugador1.alias, MAX_NOM, stdin);
  printf("Escriu el nom del jugador 2: ");
  fgets (jugador2.alias, MAX_NOM, stdin);

  printf("\n");
  printf("Introdueix el numero de parelles: ");
  scanf("%d", &parellesCartes);
  while(parellesCartes>51||parellesCartes<3){
    printf("Reintrodueix el numero de parelles(Max:50 Min:3): ");
    scanf("%d", &parellesCartes);
  }

  calcular_dimensio(&fila, &columna,parellesCartes);
  barrejar_cartes(taula, fila, columna, parellesCartes);

  printf("\nA continuacio es mostrara el taullel destapat.\n");
  printf("\nRecorda que tindras 8 segons per memoritzar les parelles.\n");
  system( "read -n 1 -s -p \"\nPrem qualsevol tecla per continuar...\"" );

  memory();
  mostra_taula(taula, fila, columna, true, jugador1.acerts, jugador2.acerts, jugador1.alias, jugador2.alias);

  sleep(8); // MAC
  // Sleep(8000); //Windows Mirar funcions .h
  memory();

  while((jugador1.acerts+jugador1.acerts)<parellesCartes){
    memory();
    if (torn == 0){
      printf("Es el torn de %s\n", jugador1.alias);
    }else{
      printf("Es el torn de %s\n", jugador2.alias);
    }
    mostra_taula(taula, fila, columna, false, jugador1.acerts, jugador2.acerts, jugador1.alias, jugador2.alias);
    escollir_cartes(taula, &fila1, &columna1, &fila2, &columna2, fila, columna, jugador1.acerts, jugador2.acerts, jugador1.alias, jugador2.alias);

    if(comparar_cartes(taula, fila1, columna1, fila2, columna2)){
      printf("\n%sEncertada!!!%s\n", KGRN, KNRM);
      taula[fila1][columna1].encertat = true;
      taula[fila2][columna2].encertat = true;
      if (torn == 0){
        jugador1.acerts++;
      }else{
        jugador2.acerts++;
      }
    }else{
      printf("\n%sError!!!%s\n", KRED, KNRM);
      taula[fila1][columna1].escollida = false;
      taula[fila2][columna2].escollida = false;
      if(torn == 0){
        torn = 1;
      }else{
        torn = 0;
      }
    }
    system( "read -n 1 -s -p \"\nPrem qualsevol tecla per continuar...\"" );
  }

  memory();
  mostrar_guanyador(jugador1.acerts, jugador2.acerts, jugador1.alias, jugador2.alias);
}
