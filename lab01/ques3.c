// Program to find the largest number using poiners
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
    int max = *p;
    for(int i = 0; i < size; i++){
        if(*(p+i) > max){
            max = *(p+i);
        }
    }
    printf("largest Number in array is %d \n" , max);
}

