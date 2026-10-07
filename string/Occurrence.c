#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i;
    int freq[256] = {0};

    printf("Enter a string: ");
    gets(str);

    for(i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    for(i = 0 ; str[i] != '\0' ; i++) {
        if(freq[(unsigned char)str[i]] > 1) {
            printf("%c" , str[i]);
            break;
        }
    }
}
