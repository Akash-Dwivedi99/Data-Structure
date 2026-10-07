#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int length;

    printf("Enter a string: ");
    gets(str);

    length = strlen(str);

    char *start = &str[0];
    char *end = &str[length-1];

    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    printf("Reverse of string: ");
    printf("%s" , str);
    return 0;
}