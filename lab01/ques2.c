// Program to swap two numbers using double pointers
#include <stdio.h>

void swap(int **p1, int **p2)
{
    int temp = **p1;
    **p1 = **p2;
    **p2 = temp;
}

int main(void)
{
    int x, y;
    printf("Enter First Number: ");
    scanf("%d", &x);

    printf("Enter Second Number: ");
    scanf("%d", &y);

    int *ptr1 = &x;
    int *ptr2 = &y;
    swap(&ptr1, &ptr2);

    printf("---- After Swapping ----\n");
    printf("%d %d\n", x, y);

    return 0;
}