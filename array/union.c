
#include <stdio.h>

int array_union(int *arr1, int n1, int *arr2, int n2, int *Union) {
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        int value;

        if (arr1[i] < arr2[j]) {
            value = arr1[i++];
        }
        else if (arr1[i] > arr2[j]) {
            value = arr2[j++];
        }
        else {
            value = arr1[i];
            i++;
            j++;
        }

        if (k == 0 || Union[k - 1] != value) {
            Union[k++] = value;
        }
    }

    while (i < n1) {
        if (k == 0 || Union[k - 1] != arr1[i]) {
            Union[k++] = arr1[i];
        }
        i++;
    }

    while (j < n2) {
        if (k == 0 || Union[k - 1] != arr2[j]) {
            Union[k++] = arr2[j];
        }
        j++;
    }
    return k;
}

int main() {
    int arr1[] = {1, 2, 4, 5, 7};
    int arr2[] = {1, 2, 3, 4, 6, 7, 8, 9};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);\
    int Union[n1 + n2];

    int n3 = array_union(arr1, n1, arr2, n2, Union);

    printf("Union: ");

    for(int i = 0; i < n3; i++) {
        printf("%d " , Union[i]);
    }
    return 0;
}
