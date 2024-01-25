/*
 * @lc app=leetcode id=1143 lang=c
 *
 * [1143] Longest Common Subsequence
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// @lc code=start
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

#define INPUT_STR_NUM 2

// The e* is the last element of each string
// str1 = sub1 + e1
// str2 = sub2 + e2
// LCS(str1, str2) = 
//  max(
//      When e1 != e2
//      max(max( LCS(sub1, str2), LCS (str1, sub2), LCS(sub1, sub2))                        
//      When e1 == e2
//      LCS(sub1, sub2) + e1
//  )

int longestCommonSubsequence(char *text1, char *text2)
{
	int length[INPUT_STR_NUM] = { 0 };
	length[0] = strlen(text1);
	length[1] = strlen(text2);
	int small_str = length[0] < length[1] ? 0 : 1;
	int big_str = length[0] < length[1] ? 1 : 0;

	// First element for smaller text pointer
	char *text_arr[2];
	text_arr[0] = small_str == 0 ? text1 : text2;
	text_arr[1] = small_str == 0 ? text2 : text1;
	// For recording the LCS(sub1, sub2)
	int up_left = 0;
	int *dp = (int *)malloc(sizeof(int) * (length[small_str] + 1));
	memset(dp, 0, sizeof(int) * (length[small_str] + 1));

	// Traversal the bigger str
	for (int i = 1; i <= length[big_str]; i++) {
		// Traversal the smaller str
		for (int j = 1; j <= length[small_str]; j++) {
			if (j == 1)
				up_left = dp[j - 1];
			int up = dp[j];
			// The last elements are different
			if (text_arr[0][j - 1] != text_arr[1][i - 1]) {
				int left = dp[j - 1];
				int new_max = max(up, left);
				up_left = up;
				dp[j] = new_max;
			}
			// The last elements are the same
			else {
				int new_max = up_left + 1;
				up_left = up;
				dp[j] = new_max;

			}
		}
	}

	int result = dp[length[small_str]];
	free(dp);
	return result;
}

// @lc code=end
int main(int argc, char **argv)
{
	// Test 1
	char *test1_1 = "abcde";
	char *test1_2 = "ace";
	printf("%d\n", longestCommonSubsequence(test1_1, test1_2));

	// // Test 2
	char *test2_1 = "abc";
	char *test2_2 = "abc";
	printf("%d\n", longestCommonSubsequence(test2_1, test2_2));

	// // Test 3
	char *test3_1 = "abc";
	char *test3_2 = "def";
	printf("%d\n", longestCommonSubsequence(test3_1, test3_2));

	// Test 4
	char *test4_1 = "bsbininm";
	char *test4_2 = "jmjkbkjkv";
	printf("%d\n", longestCommonSubsequence(test4_1, test4_2));
	return 0;
}
