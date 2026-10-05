#include <stdio.h>
#define MAX 50

void enqueue(int queue[], int *rear, int *front, int value) {
    if (*rear == MAX - 1) {
        printf("Queue is Full\n");
        return;
    }

    if (*rear == -1 && *front == -1) {
        (*rear)++;
        (*front)++;
        queue[*rear] = value;
        return;
    }

    (*rear)++;
    queue[*rear] = value;
}

int dequeue(int queue[], int *front, int *rear) {
    int value;

    if (*front == -1 || *front > *rear) {
        printf("Queue is Empty\n");
        return 0;
    }

    value = queue[*front];
    (*front)++;

    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }

    return value;
}

void reverse(int temp[], int queue[], int *rear, int *front, int *tempRear, int n){
    for(int i = 0 ; i < n ; i++){
        (*tempRear)++; 
        temp[*tempRear] = dequeue(queue, front, rear);
    }
    for(int i = *tempRear ; i >= 0; i-- ){
        printf("%d " , temp[i]);
    }
}

int main() {
    int rear = -1, front = -1, tempRear = -1;
    int queue[MAX];
    int temp[MAX];
    int value, n, i;

    printf("Enter the number of element : ");
    scanf("%d", &n);

    printf("Enter Elements\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(queue, &rear, &front, value);
    }

    reverse(temp , queue, &rear, &front, &tempRear, n);
    return 0;
}