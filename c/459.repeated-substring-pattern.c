/*
 * @lc app=leetcode id=459 lang=c
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (43.55%)
 * Likes:    3645
 * Dislikes: 338
 * Total Accepted:    257.9K
 * Total Submissions: 590.2K
 * Testcase Example:  '"abab"'
 *
 * Given a string s, check if it can be constructed by taking a substring of it
 * and appending multiple copies of the substring together.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abab"
 * Output: true
 * Explanation: It is the substring "ab" twice.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aba"
 * Output: false
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "abcabcabcabc"
 * Output: true
 * Explanation: It is the substring "abc" four times or the substring "abcabc"
 * twice.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s consists of lowercase English letters.
 * 
 * 
 */

// @lc code=start

bool repeatedSubstringPattern(char *s)
{
	bool result = false;
	int l = strlen(s);
	int sub_l = 0;
	int max_sub_l = l / 2;

	for (sub_l = 1; sub_l <= max_sub_l; sub_l++) {
		bool sub_l_is_result = true;
		if ((l % sub_l) == 0) {
			// In each place of substring
			for (int i = sub_l; i < l; i += sub_l) {
				if (strncmp(s, s + i, sub_l) != 0) {
					sub_l_is_result = false;
				}
			}
		    if (sub_l_is_result == true)
			    return true;
		}
	}
	return false;
}

// @lc code=end

// Accepted
// 129/129 cases passed (28 ms)
// Your runtime beats 32.12 % of c submissions
// Your memory usage beats 91.24 % of c submissions (6.4 MB)
