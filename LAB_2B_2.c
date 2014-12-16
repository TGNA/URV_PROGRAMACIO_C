#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    FILE *f;

    f= fopen("C:\\Projectes\\LAB2B_2\\Dades.txt", "r");
        fscanf(f, "%d", &a);
        fscanf(f, "%d", &b);
        fscanf(f, "%d", &c);
    fclose(f);

    printf("El valor a es %d", a);
    printf("\n");
    printf("El valor b es %d", b);
    printf("\n");
    printf("El valor c es %d", c);

    return 0;
}
