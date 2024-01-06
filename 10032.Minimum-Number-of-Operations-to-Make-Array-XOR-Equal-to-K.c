#include <stdio.h>

int minOperations(int *nums, int numsSize, int k)
{
	int result = 0;
	unsigned int xor_result = k;
	for (int i = 0; i < numsSize; i++) {
		xor_result = xor_result ^ nums[i];
	}

	// Count the bits
	for (unsigned int i = 0; i < sizeof(int) * 8; i++) {
		if (xor_result & (1 << i))
			result++;
	}

	return result;
}

int main(int argc, char **argv)
{
	int k_1 = 1;
	int size_1 = 4;
	int input_1[] = { 2, 1, 3, 4 };
	printf("%d\n", minOperations(input_1, size_1, k_1));

	int k_2 = 0;
	int size_2 = 4;
	int input_2[] = { 2, 0, 2, 0 };
	printf("%d\n", minOperations(input_2, size_2, k_2));

	return 0;
}
