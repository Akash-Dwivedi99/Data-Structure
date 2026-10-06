#include <stdio.h>
#define MAX 50

void enqueue(int queue[], int *rear , int value){
    if(*rear == MAX-1){
        printf("Queue is Full");
        return;
    }
    else {
        (*rear)++;
        queue[*rear] = value;
    }
}

int dequeue(int queue[], int *front, int *rear){
    if(*front > *rear){
        return -1;
    }
    else {
        return queue[(*front)++];
    }
}

void display(int queue[], int *rear , int *front){
    int i;
    for(i = *front; i <= *rear ; i++){
        printf("%d ", queue[i]);
    }
}

int exits(int temp[], int size, int value){
    int i;
    for(i = 0 ; i < size ; i++){
        if(temp[i] == value){
            return 1;
        }
    }
    return 0;
}


int main() {
    int queue[MAX];
    int temp[MAX];
    int front = 0; int tempFront = 0;
    int rear = -1; int tempRear = -1;
    int n, i , value;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter Elements \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(queue, &rear, value);
    }

    while(front <= rear){
        value = dequeue(queue, &front, &rear);
        if(!exits(temp, tempRear+1, value)){
            enqueue(temp, &tempRear, value);
        }
    }

    printf("Queue : ");
    display(temp, &tempRear, &tempFront);
}