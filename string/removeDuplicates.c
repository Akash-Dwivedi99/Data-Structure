#include <stdio.h>
#include <strings.h>
#define MAX 100

void push(char str[], int *top, char ch){
    if(*top >= 0 && ch == str[*top]) {
        (*top)--;
    }

    (*top)++;
    str[*top] = ch;
}


int main() {
    char str[100];
    int top = -1;
    printf("Enter a string : ");
    gets(str);

    for(int i = 0 ; str[i] != '\0' ; i++) {
        push(str, &top, str[i]);
    }

    if(top == -1) {
        str[top] = '\0';
    }
    else {
        str[top+1] = '\0';
    }
    printf("String After Removing Duplicates : %s", str);
}