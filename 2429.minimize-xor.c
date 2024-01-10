/*
 * @lc app=leetcode id=2429 lang=c
 *
 * [2429] Minimize XOR
 */
#include <stdio.h>
// @lc code=start
int minimizeXor(int num1, int num2)
{
	int num2_bitcounts = 0;
	unsigned int mask = 1;
	for (int i = 0; i < sizeof(int) * 8; i++) {
		if ((unsigned int)num2 & (mask << i))
			num2_bitcounts++;
	}
	unsigned int result = 0;
	for (int i = 31; i >= 0; i--) {
		if (((unsigned int)num1 & (mask << i)) && (num2_bitcounts > 0)) {
			result |= (mask << i);
			num2_bitcounts--;
		}
		if (num2_bitcounts == 0)
			break;
	}

	for (int i = 0; i < sizeof(int) * 8 && num2_bitcounts > 0; i++) {
		if (((unsigned int)result & (mask << i)) == 0) {
			result |= (mask << i);
			num2_bitcounts--;
		}
		if (num2_bitcounts == 0)
			break;
	}

	return (int)result;
}

// @lc code=end

int main(int argc, char **argv)
{
	printf("%d\n", minimizeXor(3, 5));
	printf("%d\n", minimizeXor(1, 12));
	printf("%d\n", minimizeXor(25, 72));

	return 0;
}

// Accepted
// 277/277 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 83.33 % of c submissions (6.3 MB)
