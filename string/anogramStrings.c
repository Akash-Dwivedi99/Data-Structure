#include <stdio.h>
#include <string.h>

int main() {
    char str1[100];
    char str2[100];
    char freq1[256] = {0}, freq2[256] = {0};
    int i;

    printf("Enter string 1 : ");
    gets(str1);

    printf("Enter string 2 : ");
    gets(str2);

    if(strlen(str1) != strlen(str2)){
        printf("Strings are not Anogram");
        return 0;
    }

    for (i = 0; str1[i] != '\0'; i++)
    {
        freq1[(unsigned char)str1[i]]++;
    }

    for (i = 0; str2[i] != '\0'; i++)
    {
        freq2[(unsigned char)str2[i]]++;
    }

    for (i = 0; i < 256; i++)
    {
        if (freq1[i] != freq2[i])
        {
            printf("Strings are not anagrams.\n");
            return 0;
        }
    }

    printf("Strings are anagrams.\n");

    return 0;
}