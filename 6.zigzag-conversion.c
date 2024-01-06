/*
 * @lc app=leetcode id=6 lang=c
 *
 * [6] Zigzag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (46.80%)
 * Likes:    7124
 * Dislikes: 13936
 * Total Accepted:    1.2M
 * Total Submissions: 2.6M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "A", numRows = 1
 * Output: "A"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s consists of English letters (lower-case and upper-case), ',' and '.'.
 * 1 <= numRows <= 1000
 * 
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// @lc code=start
char *convert(char *s, int numRows)
{
	int l = strlen(s);
	char **stacks = (char **)malloc(sizeof(char *) * numRows);
	int *index = (int *)malloc(sizeof(int) * numRows);
	for (int i = 0; i < numRows; i++) {
		stacks[i] = (char *)malloc(sizeof(char) * l);
		index[i] = 0;
	}

	int zigzag_size = numRows + (numRows > 2 ? numRows - 2 : 0);
	// Zigzag
	int fill_row = 0;
	for (int i = 0; i < l; i++) {
		// fill down direction
		if ((i % zigzag_size) < numRows) {
			fill_row = i % zigzag_size;
		}
		// fill up direction
		else {
			fill_row =
			    (numRows - 1) - (i % zigzag_size) % (numRows - 1);
		}
		stacks[fill_row][index[fill_row]] = s[i];
		index[fill_row]++;
	}

	// Fill back to s
	int fill_index = 0;
	for (int i = 0; i < numRows; i++) {
		for (int j = 0; j < index[i]; j++)
			s[fill_index++] = stacks[i][j];
	}

	for (int i = 0; i < numRows; i++) {
		free(stacks[i]);
	}
	free(stacks);
	free(index);

	return s;
}

// @lc code=end

int main(int argc, char **argv)
{
	char input_1[] = "PAYPALISHIRING\0";
	int rows_1 = 3;
	printf("%s\n", convert(input_1, rows_1));

	char input_2[] = "A\0";
	int rows_2 = 1;
	printf("%s\n", convert(input_2, rows_2));

	return 0;
}

// Accepted
// 1157/1157 cases passed (14 ms)
// Your runtime beats 42.37 % of c submissions
// Your memory usage beats 8.76 % of c submissions (37.8 MB)
