#include <stdio.h>
#include <stdlib.h>

int main()
{
    float notaPrimera, notaSegona, notaTercera, notaFinal, alumnesSuspesPercentatge;
    int alumnesTotal, alumnesSuspes, alumnesSuspesSuperior4, alumnesAprovat;

    alumnesTotal = 0;
    alumnesSuspes = 0;
    alumnesSuspesSuperior4 = 0;
    alumnesAprovat = 0;

    printf("Introdueix la 1 nota");
    scanf("%f", &notaPrimera);

    while(notaPrimera != -20){
        alumnesTotal++;
    //Tenint enc compte que per tallar la sequencia ha de ser la 1 nota no fa falta controlar la 2 i
    //tercera pq si aquest fos el cas estaria afegint alumnes que li faltarian notes

        printf("Introdueix la 2 nota");
        scanf("%f", &notaSegona);

        printf("Introdueix la 3 nota");
        scanf("%f", &notaTercera);

        notaFinal = ((notaPrimera*20)/100)+((notaSegona*30)/100)+((notaTercera*50)/100);

        if((notaFinal >= 4) && (notaFinal < 5)){
            alumnesSuspesSuperior4++;
        }else if(notaFinal >= 5){
            alumnesAprovat++;
        }

        if(notaFinal < 5){
            alumnesSuspes++;
        }

        printf("Introdueix la 1 nota");
        scanf("%f", &notaPrimera);
    }

    if(alumnesTotal != 0){
        alumnesSuspesPercentatge = ((alumnesSuspes*100)/alumnesTotal);
        printf("Hi han %d, han aprovat %d, han suspes %d amb una nota superior a 4 i han suspes un  %.2f %% dels alumnes", alumnesTotal, alumnesAprovat, alumnesSuspesSuperior4, alumnesSuspesPercentatge);
    } else{
        printf("No s'han introduit dades");
    }
    return 0;
}
