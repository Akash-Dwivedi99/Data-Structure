#include <stdio.h>

// STACK IMPLEMENTATIONN USING ARRAY

#define N 5
int top = -1;
int stack[N];

void push(){
    int x;
    printf("Enter Data : ");
    scanf("%d", &x);

    if(top == N-1) {
        printf("\nStack Overflow\n");
    }
    else {
        top++;
        stack[top] = x;
    }
}

void pop(){
    if(top==-1){
        printf("\nStack Underflow\n");
    }
    else {
        int  item = stack[top];
        top-- ;
        printf("\nPoped element : %d\n", item);
    }
}

void peek() {
    if(top == -1) {
        printf("\nStack Underflow\n");
    }
    else {
        printf("\nTopmost Element : %d\n", stack[top]);
    }
}

void display() {
    int i;
    for(i=top; i >= 0; i--){
        printf("%d  ", stack[i]);
    }
}


int main () {
    int choice ;
    do {
    printf("\n1 : Push\n");
    printf("2 : Pop\n");
    printf("3 : Peek\n");
    printf("4 : Display\n");
    printf("0 : Exit\n");

    printf("Enter your Choice : " , &choice);
    scanf("%d", &choice);
    switch (choice)
    {

    case 1:
        push();
        break;
    
    case 2:
       pop();
       break;

    case 3:
      peek();
      break;
    
    case 4:
      display();
      break;

    case 0:
      printf("\nTHANK YOU !\n");
      break;

    default :
        printf("\nInvalid Choice\n");
        break;
    }

    } while(choice != 0);
    return 0;
}