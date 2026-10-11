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

void display(int stack[], int top) {
    printf("Stack After Reversing : ");
    for(int i = top; i >= 0 ; i--) {
        printf("%d ", stack[i]);
    }
}


int main() {
    int stack[MAX], temp[MAX];
    int top = -1;
    int n , i, j = 0, value;

    printf("Enter the number of elements : ");
    scanf("%d" , &n);

    printf("Enter Element : \n");
    for(i = 0; i <n; i++) {
        scanf("%d" , &value);
        push(stack , &top, value);
    }

    while(top != -1) {
        temp[j] = pop(stack, &top);
        j++;
    }
    
    for(i = 0; i < j; i++){
        push(stack, &top , temp[i]);
    }

    display(stack , top);
}