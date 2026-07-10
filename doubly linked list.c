#include <stdio.h>
#include <stdlib.h>

int main () {

    struct node {
        int data;
        struct node *prev;
        struct node *next;
    };

    struct node *head = 0;
    struct node *newnode, *temp, *tail, *current;

    int choice = 1;
    while(choice){
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode -> data);

        newnode -> prev = 0;
        newnode -> next = 0;

        if ( head == NULL){
            head = temp = newnode;
        }else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }

        printf("Do you want to continue ? : ");
        scanf("%d" , &choice);
    }

    tail = temp;

    temp = head;
    printf("\n---- Doubly linked list ----\n");

    while(temp != 0) {
        printf(" <-  %d ->  " , temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    

    printf("head -> %d\n" , head->data);

    temp = head;
    while(temp!=0) {
        current = temp->next;
        temp->next = temp->prev;
        temp->prev = current;
        temp = current; 

    }

    current = head;
    head = tail;
    tail = current;

    printf("After Reversing\n");
    printf("head -> %d " , head->data);
    
    return 0;
}