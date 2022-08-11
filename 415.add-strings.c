/*
 * @lc app=leetcode id=415 lang=c
 *
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (51.94%)
 * Likes:    3590
 * Dislikes: 585
 * Total Accepted:    500.3K
 * Total Submissions: 954K
 * Testcase Example:  '"11"\n"123"'
 *
 * Given two non-negative integers, num1 and num2 represented as string, return
 * the sum of num1 and num2 as a string.
 * 
 * You must solve the problem without using any built-in library for handling
 * large integers (such as BigInteger). You must also not convert the inputs to
 * integers directly.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "11", num2 = "123"
 * Output: "134"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "456", num2 = "77"
 * Output: "533"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num1 = "0", num2 = "0"
 * Output: "0"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= num1.length, num2.length <= 10^4
 * num1 and num2 consist of only digits.
 * num1 and num2 don't have any leading zeros except for the zero itself.
 * 
 * 
 */

// @lc code=start

char *addStrings(char *num1, char *num2)
{
	int num1_length = strlen(num1);
	int num2_length = strlen(num2);
	int result_length =
	    num1_length > num2_length ? num1_length + 2 : num2_length + 2;
	char *result = (char *)malloc(sizeof(int) * result_length);
	result[result_length - 1] = '\0';
	result_length--;

	int carry = 0;
	// Be careful of the boundary
	for (int i = 0; i < result_length; i++) {
		// i = 0 ~ (num1/2_length - 1)
		char digit1 =
		    (i < num1_length) ? num1[num1_length - i - 1] : '0';
		char digit2 =
		    (i < num2_length) ? num2[num2_length - i - 1] : '0';
		char result_digit = digit1 + digit2 + carry - '0';
		carry = (result_digit - '0') / 10;
		result_digit = (result_digit - '0') % 10 + '0';
		result[result_length - i - 1] = result_digit;
	}

	if (result[0] == '0')
		return result + 1;
	else
		return result;
}

// @lc code=end

// Accepted
// 317/317 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 59.09 % of c submissions (5.9 MB)
