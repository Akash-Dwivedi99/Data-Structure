#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
}; 
struct node *head = 0;
struct node *tail = 0;

void createDCLL() {
    struct node *newnode ;
    int choice = 1;
    head=0;
    while(choice) {
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data : ");
        scanf("%d", &newnode->data);

        if(head==0){
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else{
            tail->next = newnode;
            newnode->prev = tail;
            newnode ->next = head;
            head ->prev = newnode;
            tail=newnode; 
        }
        printf("do you want to add more nodes ? (1 for yes , 0 for no) : ");
        scanf("%d", &choice);
        }
}

void display() {
    struct node *temp;
    temp = head;
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while(temp != head);
}

void insertatbeg(){
    struct node *newnode;
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data to insert at begining : ");
        scanf("%d", &newnode->data);

        if(head==0){
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else{ 
            newnode->next = head;
            head->prev = newnode;
            newnode->prev = tail;
            tail->next = newnode;
            head = newnode;
        }
        display();
}
void insertatend(){
    struct node *newnode;
        newnode = (struct node *) malloc(sizeof(struct node));
        printf("Enter data to insert at end : ");
        scanf("%d", &newnode->data);

        if(head==0){
            head = tail = newnode;
            head->next = head;
            head->prev = head;
        }
        else{ 
            newnode->prev = tail;
            tail->next = newnode ;
            newnode->next = head;
            tail = newnode;
        }
        display();
}

void insertatpos() {
    struct node *newnode, *temp;
    int pos, i=1;
    printf("Enter Position to insert node : ");
    scanf("%d", &pos);

    newnode = (struct node *) malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d", &newnode->data);

    if (pos<1){
        printf("Invalid position");
    }
    else if(pos == 1){
        insertatbeg();   
    }
    else {
        temp = head;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        }
        display();
}

int main() {
    int ch;
    printf("--Creating Doubly Circular Linked List--\n");
    createDCLL();

    printf("\n--Doubly Circular Linked List--\n");
    display();

    printf("\n1 : insert at begining\n2 : insert at end \n3 : insert at specific position");
    printf("\nEnter Your Choice : ");
    scanf("%d" , &ch);

    switch (ch)
    {
    case 1:
        insertatbeg();
        break;
    
    case 2:
        insertatend();
        break;
    
    case 3:
       insertatpos();
       break;
    
    default:
        break;
    }
    return 0;
}