/*
 * @lc app=leetcode id=409 lang=c
 *
 * [409] Longest Palindrome
 *
 * https://leetcode.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (53.45%)
 * Likes:    3281
 * Dislikes: 183
 * Total Accepted:    339.2K
 * Total Submissions: 624.4K
 * Testcase Example:  '"abccccdd"'
 *
 * Given a string s which consists of lowercase or uppercase letters, return
 * the length of the longest palindrome that can be built with those letters.
 * 
 * Letters are case sensitive, for example, "Aa" is not considered a palindrome
 * here.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abccccdd"
 * Output: 7
 * Explanation: One longest palindrome that can be built is "dccaccd", whose
 * length is 7.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "a"
 * Output: 1
 * Explanation: The longest palindrome that can be built is "a", whose length
 * is 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2000
 * s consists of lowercase and/or uppercase English letters only.
 * 
 * 
 */

// @lc code=start

int longestPalindrome(char *s)
{
	int alphabet_table[52];
	memset(alphabet_table, 0, sizeof(int) * 52);

	int result = 0, odd_num = 0;
	int s_length = strlen(s);
	for (int i = 0; i < s_length; i++) {
		// a = 97, A = 65
		int index = s[i] - 'A';
		if (index >= 26)	// Is lower case
			index -= 6;

		if (alphabet_table[index] == 1) {
			result += 2;
			alphabet_table[index] = 0;
			odd_num--;
		} else {
			alphabet_table[index]++;
			odd_num++;
		}
	}

	if (odd_num > 0)
		result++;

	return result;
}

// @lc code=end

// Accepted
// 95/95 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 10.34 % of c submissions (6 MB)
