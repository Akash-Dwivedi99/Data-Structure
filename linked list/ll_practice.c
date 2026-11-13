#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAtBeg(struct node **head) {
    int val;
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter the data  : ");
    scanf("%d" , &val);

    newnode->data = val;
    newnode->next = NULL;

    if(*head == NULL) {
        *head = newnode;
        return;
    }
    newnode->next = *head;
    *head = newnode;
}

void insertAtEnd(struct node **head) {
    if(*head == NULL)  {
        insertAtBeg(head);
        return;
    }
    int val;
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d" , &val);
    newnode->data = val;
    newnode->next = NULL;

    struct node *temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void insertAtPos(struct node **head, int pos) {
    if(pos == 1) {
        insertAtBeg(head);
        return ;
    }
    int val;
    struct node *newnoode = malloc(sizeof(struct node)), *temp;
    printf("Enter the data : ");
    scanf("%d" , &val);
    newnoode->data = val;
    newnoode->next = NULL;

    temp = *head;
    for(int i = 1; i < pos-1; i++) {
        temp = temp->next;
    }
    newnoode->next = temp->next;
    temp->next = newnoode;
}

void deletefromBegining(struct node **head) {
    struct node *temp = *head;;
    if(temp == NULL) {
        printf("List is Empty");
        return;
    }
    *head = temp->next;
    free(temp);
}

void deletefromEnd(struct node **head) {
    if(*head == NULL) {
        printf("List is Empty");
        return;
    }
    struct node *temp = *head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deletefromPos(struct node **head, int pos) {
    if(pos == 1) {
        deletefromBegining(head);
        return;
    }
    struct node *temp = *head;
    for(int i = 1 ; i < pos-1; i++) {
        if(temp -> next == NULL) {
            printf("Invalid Position");
            return;
        }
        temp = temp->next;
    }
    
    struct node *del = temp->next;
    temp->next = del->next;
    free(del);
}

void reverse(struct node **head) {
    struct node *prev, *current, *nextnode;
    prev = NULL; current = *head; nextnode = *head;

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
    while(temp != NULL) {
        printf("%d -> " , temp->data);
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
            deletefromBegining(&head);
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