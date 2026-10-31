#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

void insertatBeg(struct node **head) {
    int val;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter the data : ");
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

void insertatEnd(struct node **head) {
    int val;
    if(*head == NULL) {
        insertatBeg(head);
        return;
    }

    
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
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

void insertatPos(struct node **head, int pos) {
    int val;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d" , &val);
    newnode->data = val;
    newnode->next = NULL;

    if(pos == 1) {
        insertatBeg(head);
        return;
    }
    struct node *temp = *head;
    for(int i = 1 ; i < pos; i++) {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;

}

void display(struct node **head) {
    struct node *temp = *head;

    while(temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL;
    int choice, pos;

    do {
        printf("1. insert at begining\n2. insert at end\n3. insert at position\n4. display\n0. Exit\n");
        printf("Enter your choice : ");
        scanf("%d\n", &choice);

        switch (choice)         
        {
        case 1:
            insertatBeg(&head);
            break;
        
        case 2:
            insertatEnd(&head);
            break;
        case 3:
            printf("Enter position : ");
            scanf("%d" , &pos);
            insertatPos(&head, pos);
            break;
        case 4:
            display(&head);
            break;
        case 0:
            break;

        default:
            printf("Invaild Choice !\n");
            break;
        }

    } while(choice);
    return 0;
}