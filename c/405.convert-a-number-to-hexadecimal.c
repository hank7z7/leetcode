/*
 * @lc app=leetcode id=405 lang=c
 *
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (45.72%)
 * Likes:    946
 * Dislikes: 181
 * Total Accepted:    103.8K
 * Total Submissions: 225.9K
 * Testcase Example:  '26'
 *
 * Given an integer num, return a string representing its hexadecimal
 * representation. For negative integers, two’s complement method is used.
 * 
 * All the letters in the answer string should be lowercase characters, and
 * there should not be any leading zeros in the answer except for the zero
 * itself.
 * 
 * Note: You are not allowed to use any built-in library method to directly
 * solve this problem.
 * 
 * 
 * Example 1:
 * Input: num = 26
 * Output: "1a"
 * Example 2:
 * Input: num = -1
 * Output: "ffffffff"
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= num <= 2^31 - 1
 * 
 * 
 */
// #include <bits/stdc++.h>
// @lc code=start

char *toHex(int num)
{
	char hex[20];
	sprintf(hex, "%x", num);
	char *result = (char *)malloc(sizeof(char) * (strlen(hex) + 1));
	strcpy(result, hex);
	return result;
}

// @lc code=end

// int main()
// {
//     printf("%s\n", toHex(16));
//     return 0;
// }

// Accepted
// 100/100 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 75 % of c submissions (5.4 MB)
