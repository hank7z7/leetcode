/*
 * @lc app=leetcode id=434 lang=c
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (37.91%)
 * Likes:    494
 * Dislikes: 1047
 * Total Accepted:    122.7K
 * Total Submissions: 324.6K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Given a string s, return the number of segments in the string.
 * 
 * A segment is defined to be a contiguous sequence of non-space characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "Hello, my name is John"
 * Output: 5
 * Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "Hello"
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 300
 * s consists of lowercase and uppercase English letters, digits, or one of the
 * following characters "!@#$%^&*()_+-=',.:".
 * The only space character in s is ' '.
 * 
 * 
 */

// @lc code=start

int countSegments(char *s)
{
	int length = strlen(s);
	int result = 0;

	bool is_word = false;
	for (int i = 0; i < length; i++) {
		char c = s[i];
		if (c != ' ') {
			if (!is_word) {
				is_word = true;
				result++;
			}
		} else {
			is_word = false;
		}
	}

	return result;
}

// @lc code=end

// Accepted
// 27/27 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 65.06 % of c submissions (5.6 MB)
