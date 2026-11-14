#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *createNode() {
    int val;
    printf("Enter the data : ");
    scanf("%d" , &val);

    struct node *newnode = malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("Memory Allocation Failed");
        return NULL;
    }
    newnode->data = val;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

void insertAtBeg(struct node **head) {
    struct node *newnode = createNode();

    if(*head == NULL){
        *head = newnode;
        newnode->next = newnode;
        newnode->prev = newnode;
        return;
    }
    struct node *last = (*head)->prev;
    newnode->next = *head;
    newnode->prev = last;

    last->next = newnode;

    (*head)->prev = newnode;
    *head = newnode;
}

void insertAtEnd(struct node **head) {
    if(*head == NULL) {
        insertAtBeg(head);
        return;
    }
    struct node *newnode = createNode();
    struct node *last = (*head)->prev;
    newnode->prev = last;
    newnode->next = last->next;

    last->next = newnode;
    (*head)->prev = newnode;
}

void insertAtPos(struct node **head, int pos) {
    if(pos == 1) {
        insertAtBeg(head);
        return;
    }
    if(pos < 1) {
        printf("Invalid Position");
        return;
    }

    struct node *newnode = createNode();
    struct node *temp = *head;
    for(int i = 1 ; i < pos-1 && temp->next != *head ; i++) {
        temp = temp->next;
    }
    if(temp != NULL) {
        newnode->next = temp->next;
        temp->next->prev = newnode;
        newnode->prev = temp;
        temp->next = newnode;
        return;
    }
    printf("Inavlid Position");
}

void deletefromBeg(struct node **head) {
    if(*head == NULL) {
        printf("Empty List");
        return;
    }
    if((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    struct node *temp = *head;
    struct node *last = (*head)->prev;

    last->next = temp->next;
    *head = temp->next;
    (*head)->prev = last;
    free(temp);
}

void deletefromEnd(struct node **head) {
    if(*head == NULL) {
        printf("Empty List");
        return;
    }
    if((*head)->next == *head) {
        free(*head);
        *head = NULL;
        return;
    }
    
    struct node *temp = (*head)->prev;
    temp->prev->next = *head;
    (*head)->prev = temp->prev;
    free(temp);
    temp = NULL;
}

void deletefromPos(struct node **head, int pos) {
    if(pos == 1) {
        deletefromBeg(head);
        return;
    }
    if(pos < 1) {
        printf("Invalid position");
        return;
    }
    if(*head == NULL) {
        printf("Empty List");
        return;
    }

    struct node *temp = *head;
    for(int i = 1; i < pos-1 && temp-> next != *head ; i++) {
        temp = temp->next;
    }
    if(temp->next != *head) {
        struct node *del = temp->next;
        temp->next = del->next;
        del->next->prev = temp;
        free(del);
        del = NULL;
        return;
    }
    printf("Invalid position");
}

void reverse(struct node **head) {
    if(*head == NULL) {
        printf("Empty List");
        return;
    }

    struct node *current , *nextnode = NULL, *last = (*head)->prev;
    current = *head;
    do
    {
        nextnode = current->next;
        current->next = current->prev;
        current->prev = nextnode;

        current = nextnode;
    } while (current != *head);
    
    *head = last;
}

void display(struct node **head) {
    struct node *temp = *head;
    while(temp->next != *head) {
        printf("%d <-> " , temp->data);
        temp = temp->next;
    }
    printf("%d " , temp->data);
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