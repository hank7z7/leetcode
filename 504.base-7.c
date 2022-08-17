/*
 * @lc app=leetcode id=504 lang=c
 *
 * [504] Base 7
 *
 * https://leetcode.com/problems/base-7/description/
 *
 * algorithms
 * Easy (47.41%)
 * Likes:    512
 * Dislikes: 195
 * Total Accepted:    90.9K
 * Total Submissions: 190.3K
 * Testcase Example:  '100'
 *
 * Given an integer num, return a string of its base 7 representation.
 * 
 * 
 * Example 1:
 * Input: num = 100
 * Output: "202"
 * Example 2:
 * Input: num = -7
 * Output: "-10"
 * 
 * 
 * Constraints:
 * 
 * 
 * -10^7 <= num <= 10^7
 * 
 * 
 */

// @lc code=start

char *convertToBase7(int num)
{
	if (num == 0)
		return "0";
	char *result = (char *)malloc(sizeof(char) * 20);
	int index = 0;
	bool is_positive = (num >= 0);
	int abs = is_positive ? num : -num;
	while (abs != 0) {
		result[index++] = '0' + abs % 7;
		abs = abs / 7;
	}
	if (!is_positive)
		result[index++] = '-';
	result[index] = '\0';
	int half = index / 2;
	for (int i = 0; i < half; i++) {
		char c = result[index - 1 - i];
		result[index - 1 - i] = result[i];
		result[i] = c;
	}
	return result;
}

// @lc code=end

// Accepted
// 241/241 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 70 % of c submissions (5.5 MB)
