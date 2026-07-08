#include <stdio.h>
int main() {
    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        printf("Enter element at index %d : " , i);
        scanf("%d", &arr[i]);
    }

    printf("\nArray Elements : ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d " , arr[i]); }
    
    return 0;
}
