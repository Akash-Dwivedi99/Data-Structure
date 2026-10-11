#include <stdio.h>

struct employee {
    int id;
    char name[50];
    int salary;
};

int main() {
    int n;
    printf("Enter the employee count : ");
    scanf("%d" , &n);

    struct employee emp[n];

    printf("\n-- Enter Employee Details --\n");
    for(int i = 0; i < n; i++) {
        printf("\nEnter details of employee %d\n" , i+1);
        printf("Enter id : ");
        scanf("%d", &emp[i].id);
        printf("Enter name : ");
        scanf("%s",emp[i].name);
        printf("Enter salary : ");
        scanf("%d" , &emp[i].salary);
    }

    printf("\n-- Employee Details --\n");
    for(int i = 0; i < n; i++) {
        printf("\nDetails of employee %d" , i+1);
        printf("\nId : %d", emp[i].id);
        printf("\nNAME : %s", emp[i].name);
        printf("\nSALARY : %d", emp[i].salary);
        printf("\nSLARY AFTER BONUS : %f" , emp[i].salary + emp[i].salary*0.1);
    }
}