#include <stdio.h>
#include <stdlib.h>
int main (){

    struct node
    {
        int data;
        struct node *next;
    };

    struct node *head = NULL, *newnode, *temp;

    int choice = 1, lenght=0;
    while(choice) {

        newnode = (struct node *) malloc(sizeof(struct node));

        printf("Enter data for node : ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        printf("Enter Choice ( 1 : Add New Node , 0 : exit ) : ");
        scanf("%d", &choice);

        if( head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

    }

    temp = head;
    printf("\nLinked List\n");
    
    while (temp != NULL) {
        printf("%d | %d -> ", temp->data , temp->next);
        temp = temp->next;
        lenght++;
    }

   // printf("NULL\n");
    printf("\nLenght of linked list : %d" , lenght);

    return 0;
} 