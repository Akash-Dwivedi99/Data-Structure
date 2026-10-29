#include <stdio.h>

int Max(int currSum , int MaxSum) {
    if(currSum > MaxSum) {
        return currSum;
    }
    return MaxSum;
}

int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int n = 9;
    int currSum = 0, MaxSum = nums[0];
    for(int i = 0 ; i < n; i++) {
        currSum += nums[i];
        MaxSum = Max(currSum, MaxSum);

        if(currSum < 0) {
            currSum = 0;
        }
    }

    printf("Maximum SubArray Sum : %d\n" , MaxSum);
    return 0;
}