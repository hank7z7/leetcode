/*
 * @lc app=leetcode id=387 lang=c
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (56.91%)
 * Likes:    5512
 * Dislikes: 213
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '"leetcode"'
 *
 * Given a string s, find the first non-repeating character in it and return
 * its index. If it does not exist, return -1.
 * 
 * 
 * Example 1:
 * Input: s = "leetcode"
 * Output: 0
 * Example 2:
 * Input: s = "loveleetcode"
 * Output: 2
 * Example 3:
 * Input: s = "aabb"
 * Output: -1
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of only lowercase English letters.
 * 
 * 
 */

// @lc code=start
// z ascii in dec is 122
#define LOWER_Z_ASCII (122 + 1)
int firstUniqChar(char *s)
{
	int alphabet_table[LOWER_Z_ASCII];
	memset(alphabet_table, 0, sizeof(int) * LOWER_Z_ASCII);
	int s_length = strlen(s);

	for (int i = 0; i < s_length; i++)
		alphabet_table[s[i]]++;

	for (int i = 0; i < s_length; i++)
		if (alphabet_table[s[i]] == 1)
			return i;
	return -1;
}

// @lc code=end

// Accepted
// 105/105 cases passed (4 ms)
// Your runtime beats 89.69 % of c submissions
// Your memory usage beats 77.86 % of c submissions (7.1 MB)
