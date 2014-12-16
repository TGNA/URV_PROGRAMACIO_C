/*-------------------------------------------------------------------
|	Autor: Professors de FP                                         |
|	Data: Octubre 2014                Versio: 1.0	               |
|-------------------------------------------------------------------|
|	Nom projecte: penjat                                            |
|	Nom fitxer: penjat.c        Funcions auxiliars.                 |
|   Fitxers auxiliars:          penjat.h, libpenjat.h, libpenjat.a  |
| ------------------------------------------------------------------*/

#include "penjat.h"
#include "libpenjat.h"
#include "stdbool.h"
/* **********************************************
    char convertir_majuscula (char lletra);

    Comprova si la lletra es valida.
    Si no es una lletra valida retorna FALS (0)
    Si es una lletra valida retoran
    la mateixa lletra pero convertida a majuscules.
    ******************************************* */
char convertir_majuscula(char lletra)
{
    char majuscula;

    if((lletra>='a') && (lletra<='z')){
        majuscula = ('A'+lletra-'a');
    }else if(((lletra>='A') && (lletra<='Z'))){
        majuscula = lletra;
    }else{
        majuscula = 0;
    }

    return majuscula;
}
/* *********************************************
    int lletra_encertada (char lletra);

    Comprova si la lletra que rep per parametre (lletra)
    es o no al fitxer de lletres encertades.
    Si es al fitxer retorna VERDADER (1).
    Si no es al fitxer retorna FALS (0).
    ***************************************** */
boolea lletra_encertada (char lletra)
{
    FILE *f;
    char lletra_fitxer;
    bool trobat;

    trobat = fals;

    f = fopen(FITX_LLETRES, "r");

    if(f){
        fscanf(f, "%c", &lletra_fitxer);
        while(!feof(f) && !trobat){
            if(lletra == lletra_fitxer){
                trobat=cert;
            }
            fscanf(f, "%c", &lletra_fitxer);
        }
    }

    fclose(f);

    return (trobat);
}

/* ******************************************************
    int comprovar_lletra (char lletra);

    Comprova si la lletra que rep per parametre (lletra)
    es o no a la paraula que es troba al fitxer "paraula.txt".
    Si la lletra ja esta al fitxer de lletres encertades
    retorna el valor -1 i finalitza.
    Si la lletra es a la paraula retorna el numero de vegades
    que apareix a la paraula.
    Si la lletra NO es a la paraula retorna un 0 (FALS)
    ****************************************************** */
int comprovar_lletra(char lletra)
{
    int existeix;

    /* Llamada a la libreria */
    existeix = comprovar_lletra_lib(lletra);
    return existeix;
}

/* **********************************************
    int comprovar_paraula (char *paraula);

    Comprova si la parula es valida.
    Si no es valida retorna FALS (0)
    Si es valida retoran VERDADER (1)
    ******************************************* */
int comprovar_paraula(char *paraula)
{
    int i,valid;
    char lletra, lletraMaj;
    FILE *f;

    valid = VERDADER;
    i = 0;
    while (i<(strlen(paraula)) && (valid))
    {
        lletra = paraula[i];
        lletraMaj=convertir_majuscula(lletra);
        paraula[i]=lletraMaj;
        if (lletraMaj == 0)
            valid = FALS;
        i++;
    }
    if (valid)
    {
        /* Emmagatzemar en el fichero */
        f = fopen(FITX_PARAULES,"w");
        fputs(paraula, f);
        fclose(f);
    }
    return valid;
}

/* ***********************************************
    void escriure_espais (void);

    Reserva els espais per la paraula.
    Si la lletra esta encertada, la posa.
    Si la lletra no esta encertada posa una ratlla.
    ********************************************** */
void escriure_espais (void)
{
    FILE *f;
    char lletra;
    int existeix;

    existeix = 0;
    f = fopen(FITX_PARAULES,"r");
    /* Llegir la primera lletra */
    lletra = fgetc(f);
    while (!feof(f))
    {
        existeix = lletra_encertada (lletra);
        if (existeix)
            printf("%c ", lletra);
        else
            printf("_ ");
        /* Llegir la resta de les lletres */
        lletra = fgetc(f);
    }
    fclose(f);
}

/* ***********************************************
    void mostrar_penjat (int errors);

    Imprimeix el penjat segons el numero de errors.
    El numero de errors es pasa por parametro (errors).
    ********************************************** */
void mostrar_penjat (int errors)
{
    switch (errors)
    {
    case 0:
        printf("\n   -------");
        printf("\n   |     |");
        printf("\n   |     ");
        printf("\n   |    ");
        printf("\n   |    ");
        printf("\n __|__ ");
        printf("\n\n");
        break;
    case 1:
        printf("\n   -------");
        printf("\n   |     |");
        printf("\n   |     O");
        printf("\n   |    ");
        printf("\n   |    ");
        printf("\n __|__ ");
        printf("\n\n");
        break;
    case 2:
        printf("\n   -------");
        printf("\n   |     |");
        printf("\n   |     O");
        printf("\n   |     |");
        printf("\n   |    ");
        printf("\n __|__ ");
        printf("\n\n");
        break;
    case 3:
        printf("\n   -------");
        printf("\n   |     |");
        printf("\n   |     O");
        printf("\n   |    /|");
        printf("\n   |    ");
        printf("\n __|__ ");
        printf("\n\n");
        break;
    case 4:
        printf("\n   -------");
        printf("\n   |     |");
        printf("\n   |     O");
        printf("\n   |    /|\\");
        printf("\n   |    ");
        printf("\n __|__ ");
        printf("\n\n");
        break;
    case 5:
        printf("\n   -------");
        printf("\n   |     |");
        printf("\n   |     O");
        printf("\n   |    /|\\");
        printf("\n   |   _/");
        printf("\n __|__ ");
        printf("\n\n");
        break;
    case 6:
        printf("\n   -------");
        printf("\n   |     |");
        printf("\n   |     O");
        printf("\n   |    /|\\");
        printf("\n   |   _/ \\_");
        printf("\n __|__");
        printf("\n\nEstas PENJAT!!!\n");
        break;
    default:
        printf(" ");
    }
}


