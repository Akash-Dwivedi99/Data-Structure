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

int main()
{
    int stack[MAX];
    int top = -1;
    int num, digit;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num > 0)
    {
        digit = num % 10;
        push(stack, &top, digit);
        num = num / 10;
    }

    printf("Number in reverse order: ");

    while (top != -1)
    {
        printf("%d", pop(stack, &top));
    }

    return 0;
}