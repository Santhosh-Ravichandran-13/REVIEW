

#include <stdio.h>
#include <string.h>

int main()
{
    char string[100];
    int length;
    int i;
    
    printf("String Length and Operations\n");
    printf("============================\n\n");

    printf("Enter a string: ");
    fgets(string, sizeof(string), stdin);
    
    if (string[strlen(string) - 1] == '\n')
    {
        string[strlen(string) - 1] = '\0';
    }
 
    length = strlen(string);
    
    printf("\n--- String Analysis ---\n\n");
    printf("Original string: %s\n", string);
    printf("Length: %d characters\n\n", length);

    printf("Characters:\n");
    for (i = 0; i < length; i++)
    {
        printf("Position %d: '%c' (ASCII: %d)\n", i, string[i], string[i]);
    }

    printf("\nString in reverse: ");
    for (i = length - 1; i >= 0; i--)
    {
        printf("%c", string[i]);
    }
    printf("\n");
    int vowels = 0;
    int consonants = 0;
    int spaces = 0;
    
    for (i = 0; i < length; i++)
    {
        char ch = string[i];
        
        if (ch == ' ')
        {
            spaces++;
        }
        else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }
    }
    
    printf("\n--- Statistics ---\n");
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    printf("Spaces: %d\n", spaces);
    
    return 0;
}

