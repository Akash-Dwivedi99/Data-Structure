#include <stdio.h>
#define MAX 50

void eneque(int queue[], int *rear , int value) {
    if(*rear == MAX-1){
        printf("Queue is Full");
        return;
    }
    else{
        (*rear)++;
        queue[*rear] = value;
    }
}

int dequeue(int queue[], int *rear, int *front){
    if(*front > *rear){
        return -1;
    }
    else{
        return queue[(*front)++];
    }
}

void display(int queue[], int *rear , int *front){
    int i;
    printf("Queue Elements : ");
    for(i = *front; i <= *rear; i++){
        printf("%d " , queue[i]);
    }
}


int main() {
    int queue[MAX];
    int temp[MAX];
    int front = 0 ; //int tempFront = 0;
    int rear = -1; int tempRear = -1;
    int value , n, i;

    printf("Enter the number of elemets : ");
    scanf("%d" ,&n);

    printf("Enter Elements \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &value);
        eneque(queue, &rear , value);
    }

    while( front <= rear) {
        tempRear++;
        temp[tempRear] = dequeue(queue, &rear, &front);
    }

    for(i = 0; i < n-1; i++){
        for(int j = 0 ; j < n-1-i; j++){
            if(temp[j] > temp[j+1]){
                int swap = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = swap;
            }
        }
    }

    front = 0;
    rear = -1;
    for(i = 0 ; i < n; i++){
        eneque(queue, &rear, temp[i]);
    }
    display(queue, &rear, &front);
    
}