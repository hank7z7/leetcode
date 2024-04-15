/*
 * @lc app=leetcode id=500 lang=c
 *
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (67.87%)
 * Likes:    1010
 * Dislikes: 974
 * Total Accepted:    160.5K
 * Total Submissions: 233.9K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given an array of strings words, return the words that can be typed using
 * letters of the alphabet on only one row of American keyboard like the image
 * below.
 * 
 * In the American keyboard:
 * 
 * 
 * the first row consists of the characters "qwertyuiop",
 * the second row consists of the characters "asdfghjkl", and
 * the third row consists of the characters "zxcvbnm".
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["Hello","Alaska","Dad","Peace"]
 * Output: ["Alaska","Dad"]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["omk"]
 * Output: []
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["adsdf","sfd"]
 * Output: ["adsdf","sfd"]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 20
 * 1 <= words[i].length <= 100
 * words[i] consists of English letters (both lowercase and uppercase). 
 * 
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int find_row(char c)
{
	switch (c) {
	case 'Q':
		return 1;
		break;
	case 'W':
		return 1;
		break;
	case 'E':
		return 1;
		break;
	case 'R':
		return 1;
		break;
	case 'T':
		return 1;
		break;
	case 'Y':
		return 1;
		break;
	case 'U':
		return 1;
		break;
	case 'I':
		return 1;
		break;
	case 'O':
		return 1;
		break;
	case 'P':
		return 1;
		break;
	case 'A':
		return 2;
		break;
	case 'S':
		return 2;
		break;
	case 'D':
		return 2;
		break;
	case 'F':
		return 2;
		break;
	case 'G':
		return 2;
		break;
	case 'H':
		return 2;
		break;
	case 'J':
		return 2;
		break;
	case 'K':
		return 2;
		break;
	case 'L':
		return 2;
		break;
	case 'Z':
		return 3;
		break;
	case 'X':
		return 3;
		break;
	case 'C':
		return 3;
		break;
	case 'V':
		return 3;
		break;
	case 'B':
		return 3;
		break;
	case 'N':
		return 3;
		break;
	case 'M':
		return 3;
		break;
	default:
		return 0;
		break;
	}
}

char **findWords(char **words, int wordsSize, int *returnSize)
{
	char **result = (char **)malloc(sizeof(char *) * wordsSize);
	(*returnSize) = 0;

	for (int i = 0; i < wordsSize; i++) {
		int l = strlen(words[i]);
		int first = find_row(words[i][0] & (~32));
		bool same_row = true;
		for (int j = 0; j < l; j++)
			if (find_row(words[i][j] & (~32)) != first) {
				same_row = false;
				break;
			}

		if (same_row) {
			result[(*returnSize)] =
			    (char *)malloc(sizeof(char) * (l + 1));
			strcpy(result[(*returnSize)], words[i]);
			(*returnSize)++;
		}
	}

	return result;
}

// @lc code=end

// Accepted
// 22/22 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 25.81 % of c submissions (5.8 MB)
