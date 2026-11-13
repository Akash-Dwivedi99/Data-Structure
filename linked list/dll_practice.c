#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct  node *prev, *next;
};

void insertAtBeg(struct node **head) {
    int val;
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d" , &val);
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*head == NULL) {
        *head = newnode;
        return;
    }
    newnode->next = *head;
    (*head)->prev = newnode;
    *head = newnode;
}

void insertAtEnd(struct node **head) {
    int val;
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d" , &val);
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;

    if(*head == NULL) {
        *head = newnode;
        return;
    }
    struct node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
}

void insertAtPos(struct node **head, int pos) {
    if(pos == 1) {
        insertAtBeg(head);
        return;
    }
    int val;
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp = *head;
    
    for(int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid Position");
        return;
    }
    printf("Enter data : ");
    scanf("%d" , &val);
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
    
    for(int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    if(temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
}

void deletefromBeg(struct node **head) {
    if(*head == NULL) {
        printf("Empty List");
        return;
    }
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *del = *head;
    *head = (*head)->next;
    free(del);
    del = NULL;
}

void deletefromEnd(struct node **head) {
    if(*head == NULL) {
        printf("Empty List");
        return;
    }
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void deletefromPos(struct node **head , int pos) {
    if(*head == NULL || pos < 1) {
        printf("Invalid position");
        return;
    }
    if(pos == 1) {
        deletefromBeg(head);
        return;
    }
    struct node *temp = *head;
    for(int i = 1; i < pos-1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if(temp == NULL) {
        printf("Invalid position");
        return;
    }
    struct node *del = temp->next;
    temp->next = del->next;
    if(del->next != NULL) {
        del->next->prev = temp;
    }
    free(del);
}

void reverse(struct node **head) {
    struct node *current = *head;
    struct node *nextnode = NULL;
    struct node *last = NULL;

    while(current != NULL) {
        nextnode = current->next;

        current->next = current->prev;
        current->prev = nextnode;

        last = current;
        current = nextnode;
    }

    *head = last;
}

void display(struct node **head) {
    struct node *temp = *head;

    while(temp != NULL) {
        printf("%d ->  ", temp->data);
        temp = temp->next;
    }
}
int main () {
    struct node *head = NULL;
    int choice, pos;
    do
    {
        printf("\n1. Insert at Begining\n2. Insert at End\n3. Insert at Specific Position\n4. Delete from Begining\n5. Delete from End\n6. Delete from Specific Position\n7. Reverse \n8. Display\n0. Exit\n");
        printf("Enter your choice : ");
        scanf("%d" , &choice);
        switch (choice)
        {
        case 1:
            insertAtBeg(&head);
            break;
        case 2:
            insertAtEnd(&head);
            break;
        case 3:
            printf("Enter position : ");
            scanf("%d", &pos);
            insertAtPos(&head, pos);
            break;
        case 4:
            deletefromBeg(&head);
            break;
        case 5:
            deletefromEnd(&head);
            break;
        case 6:
            printf("Enter Position : ");
            scanf("%d", &pos);
            deletefromPos(&head, pos);
            break;
        case 7:
            reverse(&head);
            break;
        case 8:
            display(&head);
            break;
        default:
            break;
        }
    } while (choice);
    return 0;
}