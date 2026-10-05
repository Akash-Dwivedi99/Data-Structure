#include <stdio.h>
#define N 5

void enqueue(int queue[], int *rear, int *front) {
    int value;

    if (*rear == N - 1) {
        printf("Queue is full\n");
        return;
    }

    if (*front == -1) {
        *front = 0;
    }

    (*rear)++;
    printf("Enter the Element : ");
    scanf("%d", &value);
    queue[*rear] = value;
}

void dequeue(int queue[], int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is Empty\n");
        *front = -1;
        *rear = -1;
        return;
    }

    printf("Popped Element : %d\n", queue[*front]);
    (*front)++;

    if (*front > *rear) {
        *front = -1;
        *rear = -1;
    }
}

void display(int queue[], int *rear, int *front) {
    if (*front == -1 || *front > *rear) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = *front; i <= *rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[N];
    int rear = -1;
    int front = -1;
    int choice;

    do {
        printf("\n1 : Enqueue\n2 : Dequeue\n3 : Display\n0 : Exit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enqueue(queue, &rear, &front);
            break;

        case 2:
            dequeue(queue, &rear, &front);
            break;

        case 3:
            display(queue, &rear, &front);
            break;

        case 0:
            printf("Thank you !\n");
            break;

        default:
            printf("Invalid Choice\n");
            break;
        }
    } while (choice != 0);

    return 0;
}