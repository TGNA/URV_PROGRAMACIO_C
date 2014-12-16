#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    FILE *f;

    printf("Introdueix el valor enter a: ");
    scanf("%d", &a);
    printf("Introdueix el valor enter b: ");
    scanf("%d", &b);
    printf("Introdueix el calor enter c: ");
    scanf("%d", &c);

    f= fopen("C:\\Projectes\\LAB2B_1\\Resultats.txt", "w");
        fprintf(f, "%d", a);
        fprintf(f, "\n");
        fprintf(f, "%d", b);
        fprintf(f, "\n");
        fprintf(f, "%d", c);
    fclose(f);

    return 0;
}
