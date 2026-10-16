#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insertatend(struct node **head){
    int value;

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;

    if(*head == NULL) {
        *head = newnode; 
        return;  
    }

    struct node *temp = *head;
    while (temp-> next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertatstart(struct node **head) {
    int value;

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;

    if(*head == NULL) {
        *head = newnode; 
        return;  
    }
    newnode->next = *head;
    *head = newnode;

}

void insertatpos(struct node **head, int pos) {
    int value;

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertatstart(head);
        return;
    }

    struct node *temp = *head;
    for(int i = 1; i < pos-1; i++){
        temp = temp->next;
        if(temp == NULL) {
            printf("Invalid position\n");
            return;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void deletefromstart(struct node **head) {
    if(*head == NULL) {
        printf("No Element in linked list\n");
        return;
    }
    struct node *temp = *head;
    *head = temp->next;
    temp->next = NULL;
}

void deletefromend(struct node **head) {
    if(*head == NULL) {
        printf("No Element in linked list\n");
        return;
    }

    struct node *temp = *head;
    while(temp->next->next != NULL ){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}


void deletefrompos(struct node **head, int pos)
{
    struct node *temp, *del;

    if (*head == NULL)
    {
        printf("Linked List is empty\n");
        return;
    }
    if (pos < 1)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        deletefromstart(head);
        return;
    }

    temp = *head;

    for (int i = 1; i < pos - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    del = temp->next;
    temp->next = del->next;
    free(del);
}

void reverse(struct node **head){
    struct node *prev, *current, *nextnode;
    prev = 0;
    current = *head, nextnode = *head;

    while(nextnode != NULL) {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    *head = prev;
}

void display(struct node **head) {
    struct node *temp = *head;

    if(*head == NULL) {
        printf("No Element in linked list\n");
        return;
    }

    while(temp != NULL ){
        printf("%d -> " , temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main () {
    struct node *head = NULL;
    int pos, choice;

    do {
        printf("1. Insert at Start\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Start\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Pos\n");
        printf("7. Display\n");
        printf("8. Reverse\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");
        scanf("%d" , &choice);

        switch (choice)
        {
        case 1:
            insertatstart(&head);
            break;
        
        case 2:
            insertatend(&head);
            break;

        case 3:
            printf("Enter Position : ");
            scanf("%d" , &pos);
            insertatpos(&head, pos);
            break;
        
        case 4:
            deletefromstart(&head);
            break;

        case 5:
            deletefromend(&head);
            break;
        
        case 6:
            printf("Enter position to delete element : ");
            scanf("%d", &pos);
            deletefrompos(&head, pos);
            break;

        case 7:
            display(&head);
            break;
        
        case 8:
            reverse(&head);
            break;
        
        case 0:
            break;
        
        default:
            printf("Invalid Choice\n");
            break;
        }           

    } while(choice);

    printf("LINKED LIST : ");
    while(head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
    return 0;
}