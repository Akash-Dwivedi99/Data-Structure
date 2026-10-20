#include <stdio.h>

int binarySerach(int arr[], int low, int high, int key) {
    if(low > high) {
        return -1;
    }

    int mid = low + (high - low)/2;
    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[mid] < key)
    {
        return binarySerach(arr, mid+1, high, key);
    }

    return binarySerach(arr, low, mid-1, key);
    
    
}

int main() {
    int arr[] = {5, 10, 15, 20, 23, 30, 35};
    int n = 7;
    int key = 23;
    printf("Element is found at  : %d", binarySerach(arr, 0, n-1, key));

    return 0;
}
