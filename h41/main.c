/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#define SIZE 100
int s1[SIZE],s2[SIZE];
int top1=-1,top2=-1;

void push(int d){
    s1[++top1]=d;    
}
void push2(int x){
    s2[++top2]=x;
}

int pop1(){
    return s1[top1--];
}
int pop2(){
    return s2[top2--];
}

void enq(int d){
    push(d);
}

void deq(){
    if(top1==-1 && top2==-1){
        printf("Queue is empty");
        return;
    }
    if(top2==-1){
        while(top1!=-1){
            push2(pop1());
        }
        printf("Deleted :%d\n",pop2());
    }
}
void dis() {

    printf("\nQueue elements:\n");
    for (int i = top2; i >= 0; i--) {
        printf("%d\n", s2[i]);
    }
    for (int i = 0; i <= top1; i++) {
        printf("%d\n", s1[i]);
    }
}
int main()
{
    enq(90);
    enq(10);
    enq(80);
    enq(17);
    deq();
    deq();
    dis();

    return 0;
}
