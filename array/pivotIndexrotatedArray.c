#include <stdio.h>

int pivotIndex(int nums[], int n) {
    int low = 0;
    int high = n-1;

    if(nums[low] <= nums[high]) {
        return -1;
    }

    while (low < high)
    {
        int mid = low + (high - low)/2;
        
        if(nums[mid] < nums[high]) {
            high = mid;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}


int main () {
    int nums[] = {1,2,3,4,5};
    int n = sizeof(nums)/sizeof(int);
    printf("pivotIndex : %d", pivotIndex(nums, n));
}