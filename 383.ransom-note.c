/*
 * @lc app=leetcode id=383 lang=c
 *
 * [383] Ransom Note
 *
 * https://leetcode.com/problems/ransom-note/description/
 *
 * algorithms
 * Easy (55.75%)
 * Likes:    2128
 * Dislikes: 336
 * Total Accepted:    466.6K
 * Total Submissions: 829.4K
 * Testcase Example:  '"a"\n"b"'
 *
 * Given two strings ransomNote and magazine, return true if ransomNote can be
 * constructed by using the letters from magazine and false otherwise.
 * 
 * Each letter in magazine can only be used once in ransomNote.
 * 
 * 
 * Example 1:
 * Input: ransomNote = "a", magazine = "b"
 * Output: false
 * Example 2:
 * Input: ransomNote = "aa", magazine = "ab"
 * Output: false
 * Example 3:
 * Input: ransomNote = "aa", magazine = "aab"
 * Output: true
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= ransomNote.length, magazine.length <= 10^5
 * ransomNote and magazine consist of lowercase English letters.
 * 
 * 
 */
// #include <bits/stdc++.h>
// @lc code=start

bool canConstruct(char *ransomNote, char *magazine)
{
	if (strlen(ransomNote) > strlen(magazine))
		return false;
	int alphabet_table[26];
	memset(alphabet_table, 0, sizeof(int) * 26);
	// Using a variable for strlen is faster!
	int magazine_length = strlen(magazine);
	int ransom_length = strlen(ransomNote);

	for (int i = 0; i < magazine_length; i++)
		alphabet_table[magazine[i] - 'a']++;

	for (int i = 0; i < ransom_length; i++)
		if (alphabet_table[ransomNote[i] - 'a'] == 0)
			return false;
		else
			alphabet_table[ransomNote[i] - 'a']--;

	return true;
}

// @lc code=end
// int main()
// {
//     char *ransome = "a";
//     char *magazine = "b";
//     printf("%d\n", canConstruct(ransome, magazine));

//     return 0;
// }

// Accepted
// 127/127 cases passed (6 ms)
// Your runtime beats 82.55 % of c submissions
// Your memory usage beats 39.34 % of c submissions (6.6 MB)
