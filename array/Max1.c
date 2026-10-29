#include <stdio.h>

int Max_ones(int nums[], int n) {
    int count = 0, max = 0;

    for(int i = 0; i < n; i++) {
        if(nums[i] == 1) {
            count++;
            if(count > max) {
                max = count;
            }
        }
        else {
            count = 0;
        }
    }
    return max;

}

int main() {
    int nums[] = {1,0,1,1,1,0,1,1};
    int n = sizeof(nums)/sizeof(nums[0]);
    int max_ones = Max_ones(nums, n);

    printf("Maximum Consecutive Ones : %d" , max_ones);

    return 0;
}