#include <stdio.h>
#define max 20
#include<stdbool.h>
int top=-1;
char stack[max];

void push(char x) {
	if(top==max-1) {
		printf("Stack is Full:");
		return;
	}
	stack[++top]=x;

}
char pop() {
	if(top==-1) {
		printf("Invlaid :");
		return '\0';
	}
	char c=stack[top];
	top--;
	return c;
}
bool check(char s1,char s2) {
	if((s1=='}'&&s2=='{')||(s1==']'&&s2=='[')||(s1==')'&&s2=='(')) {
		return true;
	}
	return false;
}
int main()
{
	char s[20];
	scanf("%s",s);
	for(int i=0; s[i]!='\0'; i++) {
		if(s[i]=='{'||s[i]=='('||s[i]=='[') {
			push(s[i]);
		}
		if(s[i]=='}'||s[i]==']'||s[i]==')') {
			if (top == -1) {
				printf("Invalid parentheses");
				return 0;
			}

			char op = pop();
			if (!check(s[i], op)) {
				printf("Invalid parentheses");
				return 0;
			}
		}
	}
	if(top==-1) {
		printf("Valid parantheses");
	} else {
		printf("Invalid parantheses");
	}
	return 0;
}
