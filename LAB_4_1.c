#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float qt,qp,qpr,qpa,mtj,nota;
    qt = -1;qp = -1;qpr = -1;qpa = -1;

    while((qt<0 || qp<0 || qpr<0 || qpa<0 || mtj<0) || (qt>10 || qp>10 || qpr>10 || qpa>10 || mtj>10)) {
        printf("RECORDA Que les notes introduides no poden ser negatives o majors de 10 \n");
        printf("Introdueix la qualificacio teorica ");
        scanf("%f", &qt);
        printf("Introdueix la qualificacio problemes ");
        scanf("%f", &qp);
        printf("Introdueix la qualificacio practiques ");
        scanf("%f", &qpr);
        printf("Introdueix la qualificacio de participacio ");
        scanf("%f", &qpa);
        printf("\n\n");
    }

    mtj=((qt+qp)/2);

    if(mtj>=5 && qpr>=4){
        nota = (((mtj*80)/100)+((qpr*15)/100)+((qpa*5)/100));
        printf("La nota es %.2f", nota);
    }else{
        printf("Estas suspes");
    }

    return 0;
}
