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

int main(){
  char noms_complert [NUMERO_EMPLEATS][MAX_NOM];
  int minuts [NUMERO_EMPLEATS][7];

  char nom[NOM];
  char cognom1[NOM];
  char cognom2[NOM];

  int comptadorEmpleats, comptadorConversor, comptadorMinuts, comptadorImprimir, minutTreballats;
  minutTreballats = 0;

  for (comptadorEmpleats = 0; comptadorEmpleats < NUMERO_EMPLEATS; comptadorEmpleats++){
    printf("\nEmpleat %d\n", comptadorEmpleats+1);

    printf("\nNom: ");
    scanf("%s", nom);
    printf("Primer cognom: ");
    scanf("%s", cognom1);
    printf("Segon cognom: ");
    scanf("%s", cognom2);

    strcpy(noms_complert[comptadorEmpleats],nom);
    strcat(noms_complert[comptadorEmpleats]," ");
    strcat(noms_complert[comptadorEmpleats],cognom1);
    strcat(noms_complert[comptadorEmpleats]," ");
    strcat(noms_complert[comptadorEmpleats],cognom2);
    // fgets(noms_complert[comptadorEmpleats], sizeof(char)*MAX_NOM, stdin); No funciona a partir del segon cop

    for (comptadorConversor = 0; comptadorConversor < MAX_NOM; comptadorConversor++){
      noms_complert[comptadorEmpleats][comptadorConversor]= convertir_minuscula(noms_complert[comptadorEmpleats][comptadorConversor]);// putchar(tolower(noms_complert[comptadorEmpleats][comptadorConversor])); or strlwr(noms_complert[comptadorEmpleats][comptadorConversor]);
    }

    for (comptadorMinuts = 0; comptadorMinuts < 7; comptadorMinuts++){
      printf("Minuts del dia %d:", comptadorMinuts+1);
      scanf("%d", &minutTreballats);
      minuts[comptadorEmpleats][comptadorMinuts] = minutTreballats;
    }
  }

  for (comptadorImprimir = 0; comptadorImprimir < NUMERO_EMPLEATS; comptadorImprimir++){
    printf("\nEmpleat: %s\n", noms_complert[comptadorImprimir]);

    calcul_promig(minuts[comptadorImprimir]);
  }

  return 0;
}