#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define EMPLEAT 2

#define NOM 10
#define COGNOM 10

#define NOMCOMPLERT NOM+COGNOM+COGNOM

#define MAX_NOMCOMPLERT NOMCOMPLERT*EMPLEAT

#define MAX_SETMANA 7*EMPLEAT

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

void calcul_promig(int dia1,int dia2,int dia3,int dia4,int dia5,int dia6,int dia7){
  float promig;

  promig = ((dia1 + dia2 + dia3 + dia4 + dia5 + dia6 + dia7)/7);

  printf("El promig es %f\n", promig);

}

int main(){

  char nom_complert[MAX_NOMCOMPLERT];
  int minuts_setmana[MAX_SETMANA];

  for (int e = 0; e < MAX_NOMCOMPLERT; ++e){
    nom_complert[e]='\0';
  }

  for (int i = 0; i < MAX_SETMANA; ++i){
    minuts_setmana[i]=0;
  }

  int a=1;
  int b=0;

  while(a < (EMPLEAT+1)){
    char nom[NOM];
    char cognom1[COGNOM];
    char cognom2[COGNOM];

    for (int s = 0; s < NOM; ++s){
      nom[s]='\0';
    }

    for (int u = 0; u < COGNOM; ++u){
      cognom1[u]='\0';
      cognom2[u]='\0';
    }

    printf("Empleat %d\n\n", a);
  
    printf("Escriu el teu nom: ");
    fgets(nom, NOM, stdin);
    printf("Escriu el teu primer cognom: ");
    fgets(cognom1, COGNOM, stdin);
    printf("Escriu el teu segon cognom: ");
    fgets(cognom2, COGNOM, stdin);

    strcat(nom_complert,nom);
    strcat(nom_complert,cognom1);
    strcat(nom_complert,cognom2);
    strcat(nom_complert,"-");
  
    int c = b+7;
    while(b < c){
      printf("Escriu els minuts: ");
      scanf("%d",  &minuts_setmana[b]);

      b++;
    }
    a++;
  }

  for (int q = 0; q < MAX_NOMCOMPLERT; ++q){
    nom_complert[q]= convertir_minuscula(nom_complert[q]);// putchar(tolower(nom_complert[q])); or strlwr(nom_complert[q]);
  }

  for (int t = 0; t < count; ++t)
  {
    puts(nom_complert);
    calcul_promig(minuts_setmana[0],minuts_setmana[1],minuts_setmana[2],minuts_setmana[3],minuts_setmana[4],minuts_setmana[5],minuts_setmana[6]);
  }

  return 0;
}
