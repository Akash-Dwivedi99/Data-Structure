#include <stdio.h>

// STACK IMPLEMENTATIONN USING ARRAY

#define N 5

int search(int stack[], int * top, int key){
    for(int i = *top; i >= 0 ; i--){
        if(stack[i] == key){
            return 1;
        }
    }
    return 0;
}

int isFull(int *top){
    if(*top == N-1){
        return 1;
    }
    return 0;
}

int isEmpty(int *top){
    if(*top == -1){
        return 1;
    }
    return 0;
}

void push(int stack[], int *top){
    int x;
    printf("Enter Data : ");
    scanf("%d", &x);

    if(isFull(top)) {
        printf("\nStack Overflow\n");
    }
    else {
        (*top)++;
        stack[*top] = x;
    }
}

void pop(int stack[], int *top){
    if(isEmpty(top)){
        printf("\nStack Underflow\n");
    }
    else {
        int  item = stack[*top];
        (*top)-- ;
        printf("\nPoped element : %d\n", item);
    }
}

void peek(int stack[], int *top) {
    if(*top == -1) {
        printf("\nStack Underflow\n");
    }
    else {
        printf("\nTopmost Element : %d\n", stack[*top]);
    }
}

void display(int stack[], int *top) {
    int i;
    for(i=*top; i >= 0; i--){
        printf("%d  ", stack[i]);
    }
}


int main () {
    int choice , key;
    int top = -1;
    int stack[N];

    do {
    printf("\n1 : Push\n");
    printf("2 : Pop\n");
    printf("3 : Peek\n");
    printf("4 : Display\n");
    printf("0 : Exit\n");

    printf("Enter your Choice : ");
    scanf("%d", &choice);
    switch (choice)
    {

    case 1:
        push(stack, &top);
        break;
    
    case 2:
       pop(stack, &top);
       break;

    case 3:
      peek(stack ,&top);
      break;
    
    case 4:
      display(stack , &top);
      break;

    case 0:
      printf("\nTHANK YOU !\n");
      break;

    default :
        printf("\nInvalid Choice\n");
        break;
    }

    } while(choice != 0);
    printf("Enter the element to search in the stack : ");
    scanf("%d" , &key);
    if(search(stack , &top , key)){
        printf("Element is found in the stack");
    }
    else {
        printf("Element is not found in the stack");
    }
    return 0;
}