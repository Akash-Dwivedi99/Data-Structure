#include <stdio.h>
int main() {
    int arr[10];
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d " , arr[i]);
    }

    int value , index;
    printf("\nEnter the index where you want to insert the element : ");
    scanf("%d" ,&index);

    if(index > n) {
        printf("Invalid index !");
        return 0;
    }
    
    printf("Enter the value : ");
    scanf("%d" , &value);

    for (int i = n-1; i >= index; i--)
    {
        arr[i+1] = arr[i];
    }
    arr[index] = value;
    n++;
    
    printf("Array After Insertion : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d " , arr[i]);
    }
    return 0;
}