/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (63.21%)
 * Likes:    10992
 * Dislikes: 344
 * Total Accepted:    2.8M
 * Total Submissions: 4.4M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 * 
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 * 
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 * 
 * 
 * 
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 * 
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// @lc code=start
#define ALPHABET_COUNT 26
bool isAnagram(char *s, char *t)
{
	bool result = true;
	int alphabet[ALPHABET_COUNT] = { 0 };

	int s_l = strlen(s);
	int t_l = strlen(t);
	for (int i = 0; i < s_l; i++)
		alphabet[s[i] - 'a']++;
	for (int i = 0; i < t_l; i++) {
		if (alphabet[t[i] - 'a'] == 0) {
			result = false;
			break;
		} else {
			alphabet[t[i] - 'a']--;
		}
	}

	for (int i = 0; i < ALPHABET_COUNT; i++) {
		if (alphabet[i] != 0) {
			result = false;
			break;
		}
	}

	return result;
}

// @lc code=end

int main(int argc, char **argv)
{
	// test 1
	char *test1_s = "anagram";
	char *test1_t = "nagaram";
	printf("%d\n", isAnagram(test1_s, test1_t));

	// test 2
	char *test2_s = "rat";
	char *test2_t = "car";
	printf("%d\n", isAnagram(test2_s, test2_t));

	return 0;
}

// Accepted
// 42/42 cases passed (5 ms)
// Your runtime beats 35.08 % of c submissions
// Your memory usage beats 86.95 % of c submissions (6.5 MB)
