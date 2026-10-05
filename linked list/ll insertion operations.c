#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Display Linked List
void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("\nLinked List is Empty.\n");
        return;
    }

    printf("\nLinked List:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// Insert at Beginning
void insertBeginning()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node Inserted Successfully.\n");
}

// Insert at End
void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;

    printf("Node Inserted Successfully.\n");
}

// Insert at Specific Position
void insertPosition()
{
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter Position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertBeginning();
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid Position.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Node Inserted Successfully.\n");
}

// Delete from Beginning
void deleteBeginning()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);

    printf("Node Deleted Successfully.\n");
}

// Delete from End
void deleteEnd()
{
    struct node *temp, *prevnode;

    if (head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prevnode = temp;
        temp = temp->next;
    }

    prevnode->next = NULL;

    free(temp);

    printf("Node Deleted Successfully.\n");
}

// Delete from Specific Position
void deletePosition()
{
    struct node *temp, *nextnode;
    int pos, i;

    printf("Enter Position: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }

    if (pos == 1)
    {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid Position.\n");
        return;
    }

    nextnode = temp->next;

    temp->next = nextnode->next;

    free(nextnode);

    printf("Node Deleted Successfully.\n");
}

// Main Function
int main()
{
    int choice;

    while (1)
    {
        printf("\n========== LINKED LIST MENU ==========\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");

        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertBeginning();
            break;

        case 2:
            insertEnd();
            break;

        case 3:
            insertPosition();
            break;

        case 4:
            deleteBeginning();
            break;

        case 5:
            deleteEnd();
            break;

        case 6:
            deletePosition();
            break;

        case 7:
            display();
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid Choice.\n");
        }
    }

    return 0;
}