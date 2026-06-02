/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
    int f=0;
     int arr[10];
     printf("Enter the array elemnets:");
     for(int i=0;i<10;i++){
         scanf("%d",&arr[i]);
     }
    int x;
    printf("Enter the numbber to be searched :");
    scanf("%d",&x);
   for(int i=0;i<10;i++){
       if(arr[i]==x){
           printf("Elemnet found at %d",i);
           f=1;
           break;
       }
       f=0;
   }
   if(f==0){
       printf("Element not in the array");
       return 0;
   }
    
}