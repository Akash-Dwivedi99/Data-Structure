#include <stdio.h>

#define MAX 10

void MIN_push(int MIN_stack[], int *top2 , int val) {
    if(*top2 == -1 || MIN_stack[*top2] >= val)  {
        (*top2)++;
        MIN_stack[(*top2)] = val;
    }
}

void push(int stack[] , int *top, int MIN_stack[], int *top2) {
    int val;
    if(*top == MAX-1) {
        printf("Stack Overflow\n");
        return;
    }
    
    printf("Enter the value : ");
    scanf("%d" , &val);
    (*top)++;
    stack[*top] = val;
    MIN_push(MIN_stack, top2, val);
}

int pop(int stack[] , int *top, int *top2){
    if(*top == -1) {
        printf("Stack Underflow \n");
        return -1;
    }
    (*top2)--;
    return stack[(*top)--];
}

void display(int stack[], int *top) {
    for(int i = *top ; i >= 0 ; i--) {
        printf("%d " , stack[i]);
    }
}


int main() {
    int choice ;
    int top = -1 , top2 = -1;
    int stack[MAX], MIN_stack[MAX];

    do {
    printf("\n1 : Push\n");
    printf("2 : Pop\n");
    printf("3 : Display\n");
    printf("0 : Exit\n");

    printf("Enter your Choice : ");
    scanf("%d", &choice);
    switch (choice)
    {

    case 1:
        push(stack, &top , MIN_stack, &top2);
        break;
    
    case 2:
       pop(stack, &top, &top2);
       break;

    case 3:
      display(stack , &top);
      break;

    case 0:
      break;

    default :
        printf("\nInvalid Choice\n");
        break;
    }

    } while(choice != 0);

    printf("Minimum Element : %d\n" , MIN_stack[top2]);

    return 0;
}