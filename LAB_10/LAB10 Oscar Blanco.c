#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NUMERO_EMPLEATS 2
#define MAX_NOM 30
#define NOM 10

void calcul_promig(int minuts[7]){
  float promig;

  promig = ((minuts[0] + minuts[1] + minuts[2] + minuts[3] + minuts[4] + minuts[5] + minuts[6])/7);

  printf("El promig es %.2f\n", promig);
}

char convertir_minuscula(char lletra){
  char majuscula;
  
  if((lletra>='A') && (lletra<='Z')){
    majuscula = lletra + 32;
  }else{
    majuscula = lletra;
  }
  // majuscula = tolower(lletra); or strlwr(lletra);
  return majuscula;
}

void llegir_nom(char noms_complert[]){
  char nom[NOM];
  char cognom1[NOM];
  char cognom2[NOM];

  int comptadorMinuscula;

  printf("\nNom: ");
  scanf("%s", nom);
  printf("Primer cognom: ");
  scanf("%s", cognom1);
  printf("Segon cognom: ");
  scanf("%s", cognom2);

  strcpy(noms_complert,nom);
  strcat(noms_complert," ");
  strcat(noms_complert,cognom1);
  strcat(noms_complert," ");
  strcat(noms_complert,cognom2);

  for (comptadorMinuscula = 0; comptadorMinuscula < MAX_NOM; ++comptadorMinuscula){
    noms_complert[comptadorMinuscula]= convertir_minuscula(noms_complert[comptadorMinuscula]);
  }
}

void llegir_minuts(int minuts[]){
  int comptadorMinuts, minutTreballats;
  minutTreballats = 0;

  for (comptadorMinuts = 0; comptadorMinuts < 7; comptadorMinuts++){
    printf("Minuts del dia %d:", comptadorMinuts+1);
    scanf("%d", &minutTreballats);
    minuts[comptadorMinuts] = minutTreballats;
  }
}

void imprimir(int minuts[][7], char noms_complert[][MAX_NOM]){
  int r;

  for (r = 0; r < NUMERO_EMPLEATS; r++){
    printf("\nEmpleat: %s\n", noms_complert[r]);

    calcul_promig(minuts[r]);
  }
}

int main(){
  char noms_complert [NUMERO_EMPLEATS][MAX_NOM];
  int minuts [NUMERO_EMPLEATS][7];

  int comptadorEmpleats;

  for (comptadorEmpleats = 0; comptadorEmpleats < NUMERO_EMPLEATS; comptadorEmpleats++){
    printf("\nEmpleat %d\n", comptadorEmpleats+1);

    llegir_nom(noms_complert[comptadorEmpleats]);
    llegir_minuts(minuts[comptadorEmpleats]);
  }

  imprimir(minuts, noms_complert);

  return 0;
}