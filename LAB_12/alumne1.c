/* -------------------------------------------------*/
/* Nom de l'autor dels procediments :               */
/* Oscar Blanco Castan                              */
/*                                                  */
/* Data: 17/desembre/2014                           */
/* -------------------------------------------------*/
#include "funcions.h"

void memory(){
  system("clear"); // Mac
  // system("cls"); // Windows
  printf("        _\\|/_                                    \n");
  printf("        (o o)                                    \n");
  printf("+----oOO-{_}-OOo-------------------------------------------------------------+\n");
  printf("|%s     /////  /////  ///////  /////  /////  ///////////  ////////   ///   /// %s|\n", KGRN, KNRM);
  printf("|%s    /// //// ///  ///      /// //// ///  ///     ///  ///   ///  ///   ///  %s|\n", KGRN, KNRM);
  printf("|%s   ///  //  ///  //////   ///  //  ///  ///     ///  ////////    /// ///    %s|\n", KGRN, KNRM);
  printf("|%s  ///      ///  ///      ///      ///  ///     ///  /// ///       ///       %s|\n", KGRN, KNRM);
  printf("|%s ///      ///  ///////  ///      ///  ///////////  ///   ///     ///        %s|\n", KGRN, KNRM);
  printf("+----------------------------------------------------------------------------+\n\n");
}

void mostra_taula(numero taula[MAX_FILA][MAX_COLUMNA],int fila, int columna, bool mostrarTot, int jugador1, int jugador2, char alias1Referencia[MAX_NOM], char alias2Referencia[MAX_NOM]){
    int i, e;
    char caracter;
    char alias1[MAX_NOM], alias2[MAX_NOM];

    i = 0;
    while(alias1Referencia[i] != '\n'){
      alias1[i] = alias1Referencia[i];
      i++;
    }
    while(i < MAX_NOM+4){
      alias1[i] = ' ';
      i++;
    }

    i = 0;
    while(alias2Referencia[i] != '\n'){
      alias2[i] = alias2Referencia[i];
      i++;
    }
    while(i < MAX_NOM+4){
      alias2[i] = ' ';
      i++;
    }

    printf("%s Acerts:%.2d\n", alias1, jugador1);
    printf("%s Acerts:%.2d\n\n", alias2, jugador2);
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
            if (taula[i][e].encertat || mostrarTot){
                printf("%s %0.2d %s|", KMAG, taula[i][e].valor,KNRM);
            }else if(taula[i][e].escollida){
                printf("%s %0.2d %s|", KGRN, taula[i][e].valor,KNRM);
            }else{
                printf("  X |");
            }
        }
        printf("\n");
        for (e = 0; e < columna+1; ++e){
            printf("----*");
        }
        printf("\n");
    }
}

void calcular_dimensio(int *filaReferencia, int *columnaReferencia, int parellesCartes){
    int fila, columna, cartes, diferencia, i, e;
    diferencia=999;

    cartes = parellesCartes*2;

    fila = (int)sqrt(cartes);
    columna = cartes/fila;

    if (fila*columna!=cartes){
        for (i = 0; i < cartes; ++i){
            for (e = 0; e < cartes; ++e){
                if (i*e==cartes){
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
