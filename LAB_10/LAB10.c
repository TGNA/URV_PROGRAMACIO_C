#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_NOMCOMPLERT 30
#define MAX_SETMANA 7

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

char * retorna_nom_complert(){
  char *nom_complert = (char *) malloc(sizeof(char) * MAX_NOMCOMPLERT);

  for (int e = 0; e < MAX_NOMCOMPLERT; ++e){
    nom_complert[e]='\0';
  }
  
  printf("Escriu el teu nom complert: ");
  fgets(nom_complert, MAX_NOMCOMPLERT, stdin);

  for (int q = 0; q < MAX_NOMCOMPLERT; ++q){
    nom_complert[q]= convertir_minuscula(nom_complert[q]);// putchar(tolower(nom_complert[q])); or strlwr(nom_complert[q]);
  }
  
  return nom_complert;
}

float calcul_promig(int dia1,int dia2,int dia3,int dia4,int dia5,int dia6,int dia7){
  float promig;

  promig = ((dia1 + dia2 + dia3 + dia4 + dia5 + dia6 + dia7)/7);

  return promig;
}

float retorna_mig(){
  float mig;
  int minuts_setmana[MAX_SETMANA];

  for (int i = 0; i < MAX_SETMANA; ++i){
    minuts_setmana[i]=0;
  }

  for (int a = 0; a < MAX_SETMANA; ++a)
  {
    printf("Escriu els minuts: ");
    scanf("%d",  &minuts_setmana[a]);
  }

  char dia1 = minuts_setmana[0];
  char dia2 = minuts_setmana[1];
  char dia3 = minuts_setmana[2];
  char dia4 = minuts_setmana[3];
  char dia5 = minuts_setmana[4];
  char dia6 = minuts_setmana[5];
  char dia7 = minuts_setmana[6];

  mig = calcul_promig(dia1, dia2, dia3, dia4, dia5, dia6, dia7);

  return mig;
}

int main(){

  printf("Introdueix el empleat numero 1 \n");

  char *nom_complert_empleat_1 = retorna_nom_complert();
  printf("%s\n", nom_complert_empleat_1);

  float mig_empleat_1 = retorna_mig();
  printf("%.2f", mig_empleat_1);
  
  return 0;
}
