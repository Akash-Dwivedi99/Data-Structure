#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

struct node *top = 0;

void push() {
    int x;
    printf("Enter Element : ");
    scanf("%d" , &x);
    struct node *newnode;
    newnode = (struct node *) malloc (sizeof(struct node));
    newnode->data = x;
    newnode->link = top;
    top = newnode;
}

void pop() {
    struct node *temp ;
    temp = top;
    if(top == 0)
       printf("\nStack Underflow\n");
    else {
        printf("\nPoped Element is %d\n", top->data);
        top = top->link;
        free(temp);
    }
}

void peek() {
    if(top == 0)
       printf("\nStack Underflow\n");
    else { 
        printf("\nTopmost Element is %d\n", top->data);
    }
}

void display() {
    struct node *temp ;
    temp = top;
    if(top == NULL)
       printf("\nStack Underflow\n");
    else {
        while(temp != 0){
        printf("%d  ", temp->data);
        temp = temp->link;
    }
}
}

int main() {
    int ch;
    do
    {
        printf("\n1 : Push\n");
        printf("2 : Pop\n");
        printf("3 : Peek\n");
        printf("4 : Display\n");
        printf("0 : Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {

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
        break; }

    } while (ch != 0);
    
    return 0;
}
