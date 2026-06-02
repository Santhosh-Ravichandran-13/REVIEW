/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define SIZE 5

int queue[SIZE];
int f=-1,r=-1;
void enq(int d){
    if((r+1)%SIZE==f){
        printf("Queue is full:");
        return ;
    }
    if(f==-1){
        f=0;
    }
    r=(r+1)%SIZE;
    queue[r]=d;
}

void deq(){
 if(f==-1){
     printf("Queue is empty:");
     return;
 }   
 printf("The deleted element is :%d\n",queue[f]);
 
 if(f==r){
     f=r=-1;
 }
 else{
     f=(f+1)%SIZE;
 }
}
void dis(){
    if(f==-1){
        printf("Queue is empty.");
        return ;
    }
    int i=f;
    while(i!=r){
        printf("%d",queue[i]);
        i=(i+1)%SIZE;
    }
    printf("%d\n",queue[r]);
}
int main()
{
    int n;
    printf("Enter the no of elements to be inserted:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int s;
        scanf("%d",&s);
        enq(s);
    }
    deq();
    deq();
    dis();
    return 0;
    
    
    

    return 0;
}