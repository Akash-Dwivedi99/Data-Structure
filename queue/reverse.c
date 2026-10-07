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
}

int main()
{
    int queue[MAX];
    int temp[MAX];
    int front = 0, rear = -1;
    int j = 0;
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
        temp[j] = dequeue(queue, &front, rear);
        j++;
    }

    /* Enqueue elements back in reverse order */
    for (i = j-1 ; i >= 0; i--)
    {
        enqueue(queue, &rear, temp[i]);
    }

    printf("Reversed queue: ");
    display(queue, front, rear);

    return 0;
}