
#include <stdio.h>

int main()
{
    float c;
    printf("Enter the celsius:");
    scanf("%f",&c);
    float f=c*(1.8)+32;
    printf("The fahrenheit is %.1f",f);
    return 0;
}
