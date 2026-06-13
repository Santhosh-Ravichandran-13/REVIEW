
#include <stdio.h>

int main()
{
    int y;
    printf("Enter the year:");
    scanf("%d",&y);
    if((y%4==0 && y%100!=0)||y%400==0){
        printf("Leap year");
    }
    else{
        printf("Not Leap year");
    }
    return 0;
}
