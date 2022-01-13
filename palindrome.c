#include <stdio.h>
#include <string.h>
#include<stdlib.h>

int main()
{
    char str[20];
    printf("\nENter the string: ");
    scanf("%s", str);

    int i = 0, j = strlen(str)-1;

    while (i < j)
    {
        
        if (str[i] != str[j])
        {
            printf("String not palindrome");
            exit(0);
        }
        i++;
        j--;
    }
    printf("String is palindrome");
}