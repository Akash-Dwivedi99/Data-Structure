#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int digit)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = digit;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    int num, digit;

    printf("Enter an integer: ");
    scanf("%d", &num);

    while (num > 0)
    {
        digit = num % 10;
        push(digit);
        num = num / 10;
    }

    printf("Number in reverse order: ");

    while (top != -1)
    {
        printf("%d", pop());
    }

    return 0;
}