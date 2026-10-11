#include <stdio.h>
#define MAX 50

void push(int stack[] , int *top, int value) {
    if(*top == MAX-1) {
        return;
    }
    (*top)++;
    stack[*top] = value;
}

int pop(int stack[], int *top) {
    if(*top == -1) {
        return -1;
    }
    return stack[(*top)--];
}


int main() {
    int stack[MAX], even[MAX] , odd[MAX];
    int top = -1;
    int n ,i, value;
    int even_count = 0, odd_count = 0;

    printf("Enter the number of elements : ");
    scanf("%d" , &n);

    printf("Enter Element : \n");
    for(i = 0; i <n; i++) {
        scanf("%d" , &value);
        push(stack , &top, value);
    }

    while(top != -1) {
        value = pop(stack, &top);
        if(value % 2 == 0) {
            even[even_count] = value;
            even_count++;
        }
        else {
            odd[odd_count] = value;
            odd_count++;
        }
    }

    printf("Even Element : ");
    for(i = 0 ; i < even_count ; i++){
        printf("%d " , even[i]);
    }

    printf("\nOdd Elements : ");
    for(i = 0 ; i < odd_count ; i++) {
        printf("%d ", odd[i]);
    }
}