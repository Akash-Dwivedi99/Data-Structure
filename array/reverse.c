#include <stdio.h>
int main() {
    int n;
    printf("Enter the size of array : ");
    scanf("%d" , &n);
    int arr[n];


    printf("Enter the array elements : \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf(" -- Before Reversing -- \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    int start = 0;
    int end = n-1 ;

    while(start < end ) {
        arr[start] = arr[end];
        arr[end] = arr[start];
        start++;
        end--;
    }

    printf(" \n-- After Reversing --\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}