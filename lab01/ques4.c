//Program to find sum of all elements in an array
#include <stdio.h>
int main (){
    int size;
    printf("Enter the size of array : ");
    scanf("%d" , &size);
    int arr[size];
    printf("-- Enter the Array Elements --\n");
    for(int i = 0; i < size; i++){
        scanf("%d" , &arr[i]);
    }
    int *p = arr;
    int sum = 0;
    for(int i = 0; i < size; i++){
        sum += *(p+i);
    }
    printf("Sum of Elements is %d\n", sum);
}