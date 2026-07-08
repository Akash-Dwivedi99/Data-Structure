#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {

    struct node *head = NULL;
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    head = newnode;
    printf("Entered Data : %d" , newnode -> data);
    return 0;
}