#include <stdio.h>
#define MAX 50

void enqueue(int queue[], int *rear, int value) {
    if (*rear == MAX - 1) {
        return;
    }

    (*rear)++;
    queue[*rear] = value;
}

int dequeue(int queue[], int *rear, int *front) {
    if (*front > *rear) {
        return -1;
    }

    return queue[(*front)++];
}

int exists(int queue[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (queue[i] == value) {
            return 1;
        }
    }
    return 0;
}

void display(int queue[], int rear, int front) {
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}


int main() {
    int queue[MAX], temp[MAX];
    int front = 0, rear = -1;
    int n, i, value, j = 0;

    printf("Enter the number of elements: ");
    scanf("%d" , &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        enqueue(queue, &rear, value);
    }

    while (front <= rear) {
        value = dequeue(queue, &rear, &front);
        temp[j++] = value;
    }

    front = 0;
    rear = -1;

    for (i = 0; i < j; i++) {
        if (!exists(queue, rear + 1, temp[i])) {
            enqueue(queue, &rear, temp[i]);
        }
    }

    display(queue, rear, front);

    return 0;
}
