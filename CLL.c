#include <stdio.h>
#include <stdlib.h>


int main () {
    struct node {
    int data;
    struct node *next;

}; 
   struct node *head, *temp, *newnode, *end ;

    head = 0;
    int choice = 1, ch;

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
        end = temp;          //temp->next=head;
        end->next = head;
    }


    printf("\nLinked List\n");
    temp = head;
    while(temp->next != head){
        printf("%d -> ", temp->data);
        temp = temp -> next;
    }
    
    printf("%d -> ", end->data);

    printf("\nDo you want to delete node from the begining (1 for begining , 2 for end, 3 to reverse list)? : ");
    scanf("%d", &ch);

    if(ch==1){
        temp = head;
        head = head->next;
        end->next = head;
        free(temp);

        printf("\nAfter deletion : Linked List\n");
        temp = head;
        while(temp->next != head){
           printf("%d -> ", temp->data);
           temp = temp -> next;
        }
        printf("%d", temp->data);
    }

    else if(ch==2){
        if(head==NULL){
            printf("\nList is empty\n");
        } 
        else{

            temp = head;
            while(temp->next != head)
            {
            end = temp;
            temp = temp->next;
            }

            end->next = head;
            free(temp);

        printf("\nAfter deletion : Linked List\n");
        temp = head;
        while(temp->next != head){
           printf("%d -> ", temp->data);
           temp = temp -> next;
        }
        printf("%d", temp->data);

    }}
    else{
        struct node *prev, *current, *nextnode;

prev = end;
current = head;

do
{
    nextnode = current->next;
    current->next = prev;

    prev = current;
    current = nextnode;

} while(current != head);

head = prev;

        printf("\nAfter reversing : Linked List\n");
        temp = head;
        while(temp->next != head){
           printf("%d -> ", temp->data);
           temp = temp -> next;
        }
        printf("%d", temp->data);

    }
    return 0;

    
}