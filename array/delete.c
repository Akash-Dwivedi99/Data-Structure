#include <stdio.h>
int main () {
    int arr[10];
    int n;
    printf("Enter the size of array : ");
    scanf("%d" , &n);

    printf("Enter elements of array : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d" , &arr[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        printf("%d " , arr[i]);
    }

    int index ;
    printf("\nEnter the index to delete element : ");
    scanf("%d" ,&index);
    if (index > n)
    {
        printf("Invalid Index !");
        return 0;
    }
    
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i+1];
    }
    n--;

    printf("\nArray After Deletion : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d " , arr[i]);
    }
    return 0;
}