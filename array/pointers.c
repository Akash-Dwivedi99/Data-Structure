#include <stdio.h>
#include <stdlib.h>

struct Pair
{
    int value;
    int index;
};

int compare(const void *a, const void *b)
{
    struct Pair *p1 = (struct Pair *)a;
    struct Pair *p2 = (struct Pair *)b;

    return p1->value - p2->value;
}

int main()
{
    int arr[] = {7, 2, 11, 15};
    int n = 4;
    int target = 9;

    struct Pair pairs[n];

    // Store value and original index
    for(int i = 0; i < n; i++)
    {
        pairs[i].value = arr[i];
        pairs[i].index = i;
    }

    // Sort by value
    qsort(pairs, n, sizeof(struct Pair), compare);

    int left = 0;
    int right = n - 1;

    while(left < right)
    {
        int sum = pairs[left].value + pairs[right].value;

        if(sum == target)
        {
            printf("Indices: %d and %d\n",
                   pairs[left].index,
                   pairs[right].index);

            break;
        }
        else if(sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    return 0;
}