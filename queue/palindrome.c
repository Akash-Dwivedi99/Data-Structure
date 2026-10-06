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


int main() {
    int queue[MAX];
    int arr[MAX];
    int front = 0; int rear = -1;
    int n, i = 0, flag = 1 , value;

    printf("Enter the number of elements : ");
    scanf("%d", &n);

    printf("Enter Elements \n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(queue, &rear, value);
    }

    i = 0;
    while(front <= rear){
        arr[i]= dequeue(queue, &front, &rear);
        i++;
    }
    for (i = 0; i < n/2; i++)
    {
            if(arr[i] != arr[n-1-i]){
                flag = 0;
                break;
            }
    }
    
    if(flag){
        printf("Queue Elements are Palindrome");
    }
    else {
        printf("Queue Elements are not Palindrome");
    }
}
