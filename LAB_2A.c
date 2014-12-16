
#include <stdio.h>

int main()
{
    float celsius, farenheit, r_celsius, r_farenheit;

    printf("Introdueix els graus centigrats ");
    scanf("%f", &celsius);
    printf("Introdueix els graus farenheit ");
    scanf("%f", &farenheit);

    r_celsius = (farenheit - 32) * 5/9;
    r_farenheit = celsius * 9/5 + 32;

    printf("%f graus centigrats son %f graus farenheit i %f graus farenheit son %f graus centigrats", celsius, r_farenheit, farenheit, r_celsius );

    return 0;
}
