#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode() {
    int val;
    struct node *newnode = malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("Memory Allocation Failed");
        return NULL;
    }

    printf("Enter data : ");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL;

    return newnode;
}

void insertAtBeg(struct node **head) {
    struct node *newnode = createNode();

    if(*head == NULL) {
        *head = newnode;
        newnode->next = *head;
        return;
    }
    struct node *temp = *head;
    while(temp->next != *head) {
        temp = temp->next;
    }

    newnode->next = *head;
    *head = newnode;
    temp->next = newnode;
}

void insertAtEnd(struct node **head) {
    if(*head == NULL) {
        insertAtBeg(head);
        return;
    }
    struct node *newnode = createNode();
    struct node *temp = *head;
    while(temp->next != *head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = *head;
}

void insertAtPos(struct node **head, int pos) {
    if(pos == 1) {
        insertAtBeg(head);
        return;
    }
    if(pos < 1 || *head == NULL ) {
        printf("Inavlid Position");
        return;
    }
    struct node *newnode = createNode();
    struct node *temp = *head;
    for (int i = 1; i < pos-1 && temp->next != *head; i++)
    {
        temp = temp->next;
    }
    if(temp->next != *head) {
        newnode->next = temp->next;
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
        free((*head));
        *head = NULL;
        return;
    }

    struct node *temp = *head;

    while(temp->next != *head) {
        temp = temp->next;
    }
    temp->next = (*head)->next;
    struct node *del = *head;

    *head = del->next;

    free(del);
    del = NULL;
}

void deletefromEnd(struct node **head) {
    if(*head == NULL) {
        printf("Empty List");
        return;
    }

    if((*head)->next == *head) {
        free((*head));
        *head = NULL;
        return;
    }
    struct node *temp = *head;
    while(temp->next->next != *head) {
        temp = temp->next;
    }
    struct node *del = temp->next;
    temp->next = *head;
    free(del);
    del = NULL;
}

void deletefromPos(struct node **head , int pos) {
    if(*head == NULL) {
        printf("Empty List");
        return;
    }
    if(pos == 1) {
        deletefromBeg(head);
        return;
    }
    if(pos < 1) {
        printf("Inavlid Position");
        return;
    }
    struct node *temp = *head;
    for(int i = 1; i < pos-1 && temp->next != *head ; i++) {
        temp = temp->next;
    }
    if(temp->next != *head) {
        struct node *del = temp->next;
        temp->next = del->next;
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

    struct node *last = *head;

    while(last->next != *head) {
        last = last->next;
    }

    struct node *current = *head;
    struct node *nextnode = NULL;
    struct node *prev = last;

    do {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    } while(current != *head);

    *head = prev;
}

void display(struct node **head) {
    if(*head == NULL) {
        printf("Empty List");
        return;
    }

    struct node *temp = *head;
    do  {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while(temp != *head);
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