/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (41.28%)
 * Likes:    4297
 * Dislikes: 5642
 * Total Accepted:    1.4M
 * Total Submissions: 3.3M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * A phrase is a palindrome if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads the
 * same forward and backward. Alphanumeric characters include letters and
 * numbers.
 * 
 * Given a string s, return true if it is a palindrome, or false otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "race a car"
 * Output: false
 * Explanation: "raceacar" is not a palindrome.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = " "
 * Output: true
 * Explanation: s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 2 * 10^5
 * s consists only of printable ASCII characters.
 * 
 * 
 */
// #include <bits/stdc++.h>
// @lc code=start

bool isPalindrome(char *s)
{
	int i = 0;
	int j = strlen(s) - 1;
	bool result = true;

	while (j > i) {
		// Alphabet or digit is ok
		bool l = isalpha(s[i]) | isdigit(s[i]);
		bool r = isalpha(s[j]) | isdigit(s[j]);

		if (l && r) {
			// Or 32 is a trick to transform to lower
			if ((s[i] | 32) == (s[j] | 32)) {
				i++;
				j--;
			} else {
				result = false;
				break;
			}
		} else {
			i = l ? i : i + 1;
			j = r ? j : j - 1;
		}
	}

	return result;
}

// @lc code=end

// int main()
// {
//      char s[] = "A man, a plan, a canal: Panama";
//      printf("%d\n", result ? 1 : 0);

//      return 0;
// }

// Accepted
// 480/480 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 53.67 % of c submissions (6.3 MB)