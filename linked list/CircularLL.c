#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

void insertatstart(struct node **head) {
    int value;

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(*head == NULL) {
        *head = newnode; 
        return;  
    }
    newnode->next = *head;
    newnode->prev = NULL;
    *head = newnode;
}

void insertatend(struct node **head){
    int value;

    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter Data : ");
    scanf("%d", &value);
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;

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
    newnode->prev = temp;
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

int main() {
    struct node *head = NULL;
    //int pos, choice;

    insertatstart(&head);
    insertatend(&head);
    insertatend(&head);
    insertatend(&head);
    insertatend(&head);
    insertatpos(&head, 3);
    display(&head);
    /*do {
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

    } while(choice);*/
}