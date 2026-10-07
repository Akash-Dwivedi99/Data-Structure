#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter Array Elements \n");
    for(int i = 0 ; i < n ; i++) {
        scanf("%d" , &arr[i]);
    }

    int d = (arr[n-1] - arr[0]) / n;

    for(int i = 0 ; i < n-1 ; i++) {
        printf("%d " , arr[i]);

        if(arr[i+1] - arr[i] != d) {
            printf("%d " , arr[i]+d);
        }
    }

    printf("%d" , arr[n-1]);
    return 0;
}