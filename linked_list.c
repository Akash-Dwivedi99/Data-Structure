#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newnode, *temp;
    int choice = 1;

    while (choice) {
        // Create a new node
        newnode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter Data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        // If list is empty
        if (head == NULL) {
            head = temp = newnode;
        }
        else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue? (1 = Yes, 0 = No): ");
        scanf("%d", &choice);
    }

    // Display the linked list
    printf("\nLinked List:\n");

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}