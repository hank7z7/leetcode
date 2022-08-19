/*
 * @lc app=leetcode id=521 lang=c
 *
 * [521] Longest Uncommon Subsequence I
 *
 * https://leetcode.com/problems/longest-uncommon-subsequence-i/description/
 *
 * algorithms
 * Easy (60.07%)
 * Likes:    620
 * Dislikes: 5781
 * Total Accepted:    87.6K
 * Total Submissions: 145.4K
 * Testcase Example:  '"aba"\n"cdc"'
 *
 * Given two strings a and b, return the length of the longest uncommon
 * subsequence between a and b. If the longest uncommon subsequence does not
 * exist, return -1.
 * 
 * An uncommon subsequence between two strings is a string that is a
 * subsequence of one but not the other.
 * 
 * A subsequence of a string s is a string that can be obtained after deleting
 * any number of characters from s.
 * 
 * 
 * For example, "abc" is a subsequence of "aebdc" because you can delete the
 * underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc"
 * include "aebdc", "aeb", and "" (empty string).
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: a = "aba", b = "cdc"
 * Output: 3
 * Explanation: One longest uncommon subsequence is "aba" because "aba" is a
 * subsequence of "aba" but not "cdc".
 * Note that "cdc" is also a longest uncommon subsequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: a = "aaa", b = "bbb"
 * Output: 3
 * Explanation: The longest uncommon subsequences are "aaa" and "bbb".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: a = "aaa", b = "aaa"
 * Output: -1
 * Explanation: Every subsequence of string a is also a subsequence of string
 * b. Similarly, every subsequence of string b is also a subsequence of string
 * a.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= a.length, b.length <= 100
 * a and b consist of lower-case English letters.
 * 
 * 
 */

// @lc code=start

int findLUSlength(char *a, char *b)
{
	int a_l = strlen(a);
	int b_l = strlen(b);
	if ((a_l == b_l) && (strcmp(a, b) == 0))
		return -1;

	return a_l > b_l ? a_l : b_l;
}

// @lc code=end

// Accepted
// 40/40 cases passed (4 ms)
// Your runtime beats 27.27 % of c submissions
// Your memory usage beats 63.64 % of c submissions (5.4 MB)
