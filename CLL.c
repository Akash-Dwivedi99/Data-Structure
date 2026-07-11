#include <stdio.h>
#include <stdlib.h>


int main () {
    struct node {
    int data;
    struct node *next;

}; 
   struct node *head, *temp, *newnode; /*end*/

    head = 0;
    int choice = 1;

    while(choice) {
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter Data : " );
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if (head==0) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want add more nodes ? : ");
        scanf("%d", &choice);
    }

    if (head != NULL){
        //end = temp;          
        temp->next=head;
        //end->next = head;
    }


    printf("\nLinked List\n");
    temp = head;
    while(temp->next != head){
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    
    printf("%d", temp->data);
    return 0;

}