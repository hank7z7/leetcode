/*
 * @lc app=leetcode id=520 lang=c
 *
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (55.70%)
 * Likes:    1703
 * Dislikes: 370
 * Total Accepted:    272.1K
 * Total Submissions: 488.7K
 * Testcase Example:  '"USA"'
 *
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital, like "Google".
 * 
 * 
 * Given a string word, return true if the usage of capitals in it is right.
 * 
 * 
 * Example 1:
 * Input: word = "USA"
 * Output: true
 * Example 2:
 * Input: word = "FlaG"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 100
 * word consists of lowercase and uppercase English letters.
 * 
 * 
 */

// @lc code=start

bool detectCapitalUse(char *word)
{
	bool all_upper = true;
	bool all_lower = true;
	bool first_upper = true;
	int l = strlen(word);

	for (int i = 0; i < l; i++) {
		// Is upper
		if ((word[i] & 32) == 0) {
			all_lower = false;
			if (i != 0)
				first_upper = false;
		} else {
			all_upper = false;
			if (i == 0)
				first_upper = false;
		}
	}
	return (all_upper || all_lower || first_upper);
}

// @lc code=end

// Accepted
// 550/550 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 83.04 % of c submissions (5.5 MB)
