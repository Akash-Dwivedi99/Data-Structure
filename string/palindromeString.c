#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int length, flag = 1;

    printf("Enter a string: ");
    gets(str);

    length = strlen(str);

    char *start = &str[0];
    char *end = &str[length-1];

    while(start < end) {
        if(*start != *end){
            flag = 0;
            break;
        }
        start++;
        end--;
    }
    
    if(flag){
        printf("String is palindrome");
    }
    else {
        printf("String is not palindrome");
    }
    return 0;
}