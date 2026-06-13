
#include <stdio.h>

int main()
{
    int n,sum=1;
    printf("enter the Number:");
    scanf("%d",&n);
    if(n==0 ||n==1){
        printf("%d",n);
    }
    else{
        for(int i=1;i<=n;i++){
            sum=sum*i;
        }
    }
    printf("Factorial is %d",sum);
    return 0;
}
