#include <stdio.h>
#define MAX 50

void push(char ch, char stack[], int *top) {
    if (*top == MAX - 1) {
        return;
    }
    stack[++(*top)] = ch;
}

char pop(char stack[], int *top) {
    if (*top == -1) {
        return -1;
    }
    return stack[(*top)--];
}

int precedence(char ch) {
    if(ch == '(') {
        return 0;
    }
    if (ch == '+' || ch == '-') {
        return 1;
    }
    if (ch == '*' || ch == '/') {
        return 2;
    }
    return -1;
}

int main() {
    char stack[MAX];
    char exp[MAX];
    char ch, *e;
    int top = -1;

    printf("Enter expression : ");
    gets(exp);
    e = exp;

    while (*e != '\0') {

        if ((*e >= 'A' && *e <= 'Z') ||
            (*e >= 'a' && *e <= 'z') ||
            (*e >= '0' && *e <= '9')) {
            printf("%c ", *e);
        }


        else if (*e == '(') {
            push(*e, stack, &top);
        }


        else if (*e == ')') {
            while ((ch = pop(stack, &top)) != '(') {
                if (ch == -1) {
                    break;
                }
                printf("%c ", ch);
            }
        }


        else if (*e == '+' || *e == '-' || *e == '*' || *e == '/') {
            while (top != -1 && precedence(stack[top]) >= precedence(*e)) {
                printf("%c ", pop(stack, &top));
            }
            push(*e, stack, &top);
        }

        
        e++;
    }

    while(top != -1){
        printf("%c " , pop(stack , &top));

    }
    return 0;
} 
