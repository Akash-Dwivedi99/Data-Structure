#include <stdio.h>

// IMPLEMENTATION OF STACK

#define n  5
int queue[n];
int front, rear = -1;


void enqueue(){
    int x;
    printf("Enter data : ");
    scanf("%d", &x);
    if(rear == n-1){
        printf("\nOverFlow Condition\n");
    }
    else if(front == -1 && rear == -1){
        rear = front = 0;
        queue[rear] = x;
    }
    else {
        rear ++;
        queue[rear] = x;
    }
}

void dequeue() {
    if(front ==-1 && rear == 1){
        printf("\nUnderflow Condition\n");
    }
    else if(front == rear){
        printf("Dequeued Element : %d\n", queue[rear]);
        front = rear = -1;
    }
    else{
        printf("Dequeued Element : %d\n", queue[rear]);
        front++;
    }
}


void peek() {
    if(front ==-1 && rear == 1){
        printf("\nUnderflow Condition\n");
    }
    else {
        printf("%d\n", queue[rear]);
    }
}
void display() {
    if(front ==-1 && rear == 1){
        printf("\nUnderflow Condition\n");
    }
    else{
        for (int i = front; i <= rear; i++)
        {
            printf("%d  ", queue[i]);
        }
        printf("\n");
        
    }
}


int main () {
    int ch;
    do
    {
        printf("\n1 : Enqueue\n");
        printf("2 : Dequeue\n");
        printf("3 : Peek\n");
        printf("4 : Display\n");
        printf("0 : Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &ch);

        switch (ch) {

    case 1:
        enqueue();
        break;
    
    case 2:
       dequeue();
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
