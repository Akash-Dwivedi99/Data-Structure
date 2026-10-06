#include <stdio.h>

#define MAX 100

void enqueue(int queue[], int *rear, int value)
{
    if (*rear == MAX - 1)
    {
        printf("Queue Overflow\n");
    }
    else
    {
        (*rear)++;
        queue[*rear] = value;
    }
}

int dequeue(int queue[], int *front, int rear)
{
    if (*front > rear)
    {
        return -1;
    }

    return queue[(*front)++];
}

void display(int queue[], int front, int rear)
{
    int i;

    for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    int queue[MAX];
    int temp[MAX];
    int front = 0, rear = -1;
    int tempFront = 0, tempRear = -1;
    int n, i, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &value);
        enqueue(queue, &rear, value);
    }

    /* Dequeue elements and store them in temporary array */
    while (front <= rear)
    {
        tempRear++;
        temp[tempRear] = dequeue(queue, &front, rear);
    }

    /* Enqueue elements back in reverse order */
    for (i = tempRear; i >= tempFront; i--)
    {
        enqueue(queue, &rear, temp[i]);
    }

    printf("Reversed queue: ");
    display(queue, front, rear);

    return 0;
}