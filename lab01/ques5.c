#include <stdio.h>
int main(){
    int size;
    printf("Enter the size of array : ");
    scanf("%d" , &size);
    int arr[size];
    printf("-- Enter the Array Elements --\n");
    for(int i = 0; i < size; i++){
        scanf("%d" , &arr[i]);
    }

    int *start = arr;
    int *end = arr+size-1;
    while(start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
    printf("-- Reverse of an Array --\n");
    for(int i = 0; i < size; i++){
        printf("%d  " , arr[i]);
    }
}