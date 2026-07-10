#include <stdio.h>
#include <stdlib.h>


int main () {
    struct node {
    int data;
    struct node *next;

}; 
   struct node *head, *temp, *newnode, *end;

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

    end = temp;


    printf("\nLinked List\n");
    temp = head;
    while(temp != 0){
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    

    end->next = head;

    
    printf("%d", end->next->data);
    return 0;

}