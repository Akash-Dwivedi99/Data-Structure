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

    int *start = &arr[0];
    int *end = &arr[n-1] ;

    while(start < end ) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    printf(" \n-- After Reversing --\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}