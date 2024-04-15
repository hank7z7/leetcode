/*
 * @lc app=leetcode id=482 lang=c
 *
 * [482] License Key Formatting
 *
 * https://leetcode.com/problems/license-key-formatting/description/
 *
 * algorithms
 * Easy (43.12%)
 * Likes:    813
 * Dislikes: 1143
 * Total Accepted:    225.8K
 * Total Submissions: 524.3K
 * Testcase Example:  '"5F3Z-2e-9-w"\n4'
 *
 * You are given a license key represented as a string s that consists of only
 * alphanumeric characters and dashes. The string is separated into n + 1
 * groups by n dashes. You are also given an integer k.
 * 
 * We want to reformat the string s such that each group contains exactly k
 * characters, except for the first group, which could be shorter than k but
 * still must contain at least one character. Furthermore, there must be a dash
 * inserted between two groups, and you should convert all lowercase letters to
 * uppercase.
 * 
 * Return the reformatted license key.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "5F3Z-2e-9-w", k = 4
 * Output: "5F3Z-2E9W"
 * Explanation: The string s has been split into two parts, each part has 4
 * characters.
 * Note that the two extra dashes are not needed and can be removed.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "2-5g-3-J", k = 2
 * Output: "2-5G-3J"
 * Explanation: The string s has been split into three parts, each part has 2
 * characters except the first part as it could be shorter as mentioned
 * above.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of English letters, digits, and dashes '-'.
 * 1 <= k <= 10^4
 * 
 * 
 */
// #include <bits/stdc++.h>
// @lc code=start

char *licenseKeyFormatting(char *s, int k)
{
	int l = strlen(s);
	// Be careful of the malloc size!
	char *remove_dash = (char *)malloc(sizeof(char) * l + 1);

	int index = 0, remove_index = 0;
	// Fill remove_dash from the tail
	while (index < l) {
		char c = s[index];
		if (c != '-') {
			remove_dash[remove_index++] =
			    isalpha(c) ? c & (~32) : c;
		}
		index++;
	}

	remove_dash[remove_index] = '\0';
	// Be careful of the malloc size!
	char *result =
	    (char *)malloc(sizeof(char) *
			   (remove_index + (remove_index / k) + 1));
	int result_index = 0;
	for (int i = 0; i < remove_index; i++) {
		if (i > 0 && (remove_index - i) % k == 0)
			result[result_index++] = '-';
		result[result_index++] = remove_dash[i];
	}
	result[result_index] = '\0';
	return result;
}

// @lc code=end

// int main()
// {
//     char str[] = "r";
//     char *ret = licenseKeyFormatting(str, 1);

//     printf("%s\n", ret);

//     return 0;
// }

// Accepted
// 38/38 cases passed (10 ms)
// Your runtime beats 44.78 % of c submissions
// Your memory usage beats 20.9 % of c submissions (6.9 MB)
