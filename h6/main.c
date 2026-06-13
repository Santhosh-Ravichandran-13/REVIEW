
#include <stdio.h>

int main()
{
    char ch;
    printf("Enter the character :");
    scanf("%c",&ch);
    if((ch=='a' ||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'||ch=='E' || ch=='I' ||ch=='O' ||ch=='U')){
        printf("Vowels");
    }
    else if(ch>='0' && ch<='9'){
        printf("Digits");
    }
    else if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')) {
        printf("Consonants");
    }else{
        printf("Symbols");
    }
    return 0;
}
