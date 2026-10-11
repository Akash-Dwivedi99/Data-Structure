#include <stdio.h>
#define MAX 100

void push(int stack[], int *top, int digit)
{
    if (*top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        (*top)++;
        stack[*top] = digit;
    }
}

int pop(int stack[], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[(*top)--];
    }
}

void display(int stack[], int top) {
    for(int i = top ; i >= 0 ; i--) {
        printf("%d", stack[i]);
    }
}

int main()
{
    int stack[MAX], arr[MAX];
    int top = -1 , i,j = 0;
    int num, digit;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num > 0)
    {
        digit = num % 10;
        push(stack, &top, digit);
        num = num / 10;
    }

    while (top != -1)
    {
        digit = pop(stack, &top);
        arr[j] = digit;
        j++;
    }

    for(i = 0; i < j; i++) {
        push(stack , &top , arr[i]);
    }

    printf("Number in reverse order: ");
    display(stack, top);
    return 0;
}