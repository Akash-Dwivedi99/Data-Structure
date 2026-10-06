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
    int queue1[MAX], queue2[MAX], merged[MAX];
    int front1 = 0; int rear1 = -1;
    int front2 = 0; int rear2 = -1;
    int front3 = 0; int rear3 = -1;
    int i , n1, n2, value;

    printf("Enter number of elements in queue 1 : " );
    scanf("%d", &n1);
    printf("Enter Elements \n");
    for(i = 0 ; i < n1; i++){
        scanf("%d", &value);
        enqueue(queue1, &rear1, value);
    }

    printf("Enter number of elements in queue 2 : " );
    scanf("%d", &n2);
    printf("Enter Elements \n");
    for(i = 0 ; i < n2; i++){
        scanf("%d", &value);
        enqueue(queue2, &rear2, value);
    }

    while(front1 <= rear1){
        value = dequeue(queue1, &front1, &rear1);
        enqueue(merged, &rear3, value);
    }

    while(front2 <= rear2){
        value = dequeue(queue2, &front2, &rear2);
        enqueue(merged, &rear3, value);
    }

    printf("Merged Queue : ");
    display(merged, &rear3, &front3);
}