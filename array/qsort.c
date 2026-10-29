#include <stdio.h>
#include <stdlib.h>

int cmp (const void *p1, const void *p2) {
    int x = *(int *)p1;
    int y = *(int *)p2;

    return x - y;
}
int main() {
    int arr[] = {23, 56, 12, 43, 9, 1001, 20};
    int n = sizeof(arr)/sizeof(int);

    qsort(arr, n, sizeof(int), cmp);

    printf("Array After Sorting : \n");
    for(int i = 0 ; i < n; i++) {
        printf("%d " , arr[i]);
    }

    return 0;
}