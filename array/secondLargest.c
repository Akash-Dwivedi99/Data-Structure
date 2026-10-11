#include <stdio.h>

int secondLargest(int arr[], int n) {
    int max = arr[0], second_max = arr[0];

    for(int i = 1 ; i < n; i++){
        if(arr[i] > max) {
            second_max = max;
            max = arr[i];
        }
        else if(arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }
    return second_max;
}

int main() {
    int n;
    printf("Enter the number of elements : ");
     scanf("%d", &n);

    int arr[n];

    printf("-- Enter Array Elements --\n");
    for(int i = 0; i < n; i++) {
        scanf("%d" , &arr[i]);
    }

    printf("Second Largest Element in array : %d",secondLargest(arr, n));
    return 0;
}
