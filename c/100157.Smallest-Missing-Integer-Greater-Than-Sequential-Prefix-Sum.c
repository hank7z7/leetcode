#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int missingInteger(int *nums, int numsSize)
{
	if (numsSize == 1)
		return *nums + 1;

	bool is_sequential = true;
	bool is_find = false;
	int sum = nums[0];

	for (int i = 1; i < numsSize; i++) {
		if (is_sequential && nums[i] == (nums[i - 1] + 1)) {
			sum += nums[i];
		} else if (is_sequential) {
			is_sequential = false;
			qsort(&(nums[i]), numsSize - i, sizeof(int), cmp);
			for (int j = i - 1; j < numsSize; j++) {
				if (nums[j] == sum)
					sum++;
			}
			break;
		}
	}

	return sum;
}

int main(int argc, char **argv)
{
	int size_1 = 5;
	int input_1[] = { 1, 2, 3, 2, 5 };
	int size_2 = 7;
	int input_2[] = { 3, 4, 5, 1, 12, 14, 13 };
	int size_3 = 1;
	int input_3[] = { 3 };
	int size_4 = 15;
	int input_4[] = { 46, 8, 2, 4, 1, 4, 10, 2, 4, 10, 2, 5, 7, 3, 1 };

	printf("%d = 6\n", missingInteger(input_1, size_1));
	printf("%d = 15\n", missingInteger(input_2, size_2));
	printf("%d = 4\n", missingInteger(input_3, size_3));
	printf("%d = 47\n", missingInteger(input_4, size_4));

	return 0;
}
