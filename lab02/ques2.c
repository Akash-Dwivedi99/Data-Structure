#include <stdio.h>

struct student
{
    int roll_no;
    char name[50];
    int age;
};

int main()
{
    struct student s;

    printf("Enter roll number: ");
    scanf("%d", &s.roll_no);

    getchar();

    printf("Enter name: ");
    gets(s.name);

    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("\n--- Student Details ---\n");
    printf("Roll Number: %d\n", s.roll_no);
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);

    return 0;
}