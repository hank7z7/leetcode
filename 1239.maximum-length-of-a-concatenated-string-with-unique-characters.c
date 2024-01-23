/*
 * @lc app=leetcode id=1239 lang=c
 *
 * [1239] Maximum Length of a Concatenated String with Unique Characters
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_1 3
#define SIZE_2 4
#define SIZE_3 1
#define SIZE_4 3

// @lc code=start
#define LETTER_SIZE 26

int countSetBits(unsigned int n)
{
	int count = 0;
	while (n) {
		count += n & 1;
		n >>= 1;
	}
	return count;
}

int maxLength(char **arr, int arrSize)
{
	int result = 0;
	unsigned int *bitset =
	    (unsigned int *)malloc(sizeof(unsigned int) * arrSize);
	unsigned int mask = 1;
	int *valid = (int *)malloc(sizeof(int) * arrSize);
	memset(valid, 0, sizeof(int) * arrSize);
	for (int i = 0; i < arrSize; i++) {
		bitset[i] = 0;
		for (size_t j = 0; j < strlen(arr[i]); j++) {
			if ((bitset[i] & (mask << (arr[i][j] - 'a'))))
				valid[i] = -1;
			bitset[i] |= (mask << (arr[i][j] - 'a'));
		}
		// printf("%s %x\n",arr[i], bitset[i]);
	}

	// Make combination
	unsigned int combination = 0;
	for (int j = 0; j < arrSize; j++)
		combination |= (mask << j);
	// printf("Combination %x\n", combination);

	// Traversal all combination
	unsigned int bitset_concate = 0;
	printf("Total Combination %x\n", combination);
	for (unsigned int i = 0; i <= combination; i++) {
		bitset_concate = 0;
		int valid_comibation = 1;
		// Traversal all arr
		for (int j = 0; j < arrSize; j++) {
			// Determine pick or not by the combination
			if (i & (mask << j)) {
				// Determine the picked one is a valid string
				if (valid[j] == -1) {
					valid_comibation = 0;
					break;
				}
				// Duplicate letter, not valid
				if (bitset_concate & bitset[j]) {
					valid_comibation = 0;
					break;
				} else {
					bitset_concate |= bitset[j];
				}
			}
		}
		// printf("%x\n", bitset_concate);
		if (valid_comibation) {
			int bitcounts = countSetBits(bitset_concate);
			// printf("Combination %x, bitcounts = %d\n", i, bitcounts);
			if (bitcounts > result) {
				result = bitcounts;
			}
		}
	}

	free(bitset);
	free(valid);
	return result;
}

// @lc code=end

int main(int argc, char **argv)
{
	// Test 1
	char *arr1[SIZE_1] = { "un", "iq", "ue" };
	printf("%d\n", maxLength(arr1, SIZE_1));

	// Test 2
	char *arr2[SIZE_2] = { "cha", "r", "act", "ers" };
	printf("%d\n", maxLength(arr2, SIZE_2));

	// Test 3
	char *arr3[SIZE_3] = { "abcdefghijklmnopqrstuvwxyz" };
	printf("%d\n", maxLength(arr3, SIZE_3));

	// Test 4
	char *arr4[SIZE_4] = { "zog", "nvwsuikgndmfexxgjtkb", "nxko" };
	printf("%d\n", maxLength(arr4, SIZE_4));
}

// Accepted
// 89/89 cases passed (14 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 100 % of c submissions (5.6 MB)
