#include <stdio.h>
#include <stdbool.h>

bool hasTrailingZeros(int* nums, int numsSize) {
    int count = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] % 2 == 0)
            count++;
        if(count >= 2)
            return true;
    }
    
    return false;
}

int main(int argc, char** argv)
{
    int input1[5] = {1, 2, 3, 4, 5};
    int input2[4] = {2, 4, 8, 16};
    int input3[5] = {1, 3, 5, 7, 9};
    int input4[2] = {1, 2};

    printf("%d\n", hasTrailingZeros(input1, 5));
    printf("%d\n", hasTrailingZeros(input2, 4));
    printf("%d\n", hasTrailingZeros(input3, 5));
    printf("%d\n", hasTrailingZeros(input4, 2));


    return 0;
}