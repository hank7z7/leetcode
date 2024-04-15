/*
 * @lc app=leetcode id=392 lang=c
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Easy (50.96%)
 * Likes:    5462
 * Dislikes: 316
 * Total Accepted:    552.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * Given two strings s and t, return true if s is a subsequence of t, or false
 * otherwise.
 * 
 * A subsequence of a string is a new string that is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (i.e., "ace" is a
 * subsequence of "abcde" while "aec" is not).
 * 
 * 
 * Example 1:
 * Input: s = "abc", t = "ahbgdc"
 * Output: true
 * Example 2:
 * Input: s = "axc", t = "ahbgdc"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 100
 * 0 <= t.length <= 10^4
 * s and t consist only of lowercase English letters.
 * 
 * 
 * 
 * Follow up: Suppose there are lots of incoming s, say s1, s2, ..., sk where k
 * >= 10^9, and you want to check one by one to see if t has its subsequence.
 * In this scenario, how would you change your code?
 */

// @lc code=start

bool isSubsequence(char *s, char *t)
{
	int s_length = strlen(s);
	int t_length = strlen(t);
	if (s_length > t_length)
		return false;

	int t_index = 0;
	for (int i = 0; i < s_length; i++) {
		if (s[i] != t[t_index]) {
			while (t_index < t_length) {
				if (s[i] == t[t_index])
					break;
				else
					t_index++;
			}
			if (t_index == t_length)
				return false;
		}
		t_index++;
	}

	return true;
}

// @lc code=end

// Accepted
// 18/18 cases passed (3 ms)
// Your runtime beats 52.31 % of c submissions
// Your memory usage beats 26.16 % of c submissions (5.8 MB)
