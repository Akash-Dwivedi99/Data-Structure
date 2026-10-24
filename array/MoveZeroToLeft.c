#include <stdio.h>

void moveZeros(int *arr, int n){
    int i, j = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] != 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

int main() {
    int arr[] = {2,1,2,3,0,0,1};
    int n = 7;
    
    moveZeros(arr, n);

    printf("Array After Moving Zeros to left : ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}