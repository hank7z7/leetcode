/*
 * @lc app=leetcode id=401 lang=c
 *
 * [401] Binary Watch
 *
 * https://leetcode.com/problems/binary-watch/description/
 *
 * algorithms
 * Easy (50.36%)
 * Likes:    1022
 * Dislikes: 1911
 * Total Accepted:    114K
 * Total Submissions: 223.1K
 * Testcase Example:  '1'
 *
 * A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6
 * LEDs on the bottom to represent the minutes (0-59). Each LED represents a
 * zero or one, with the least significant bit on the right.
 *
 *
 * For example, the below binary watch reads "4:51".
 *
 *
 *
 *
 * Given an integer turnedOn which represents the number of LEDs that are
 * currently on (ignoring the PM), return all possible times the watch could
 * represent. You may return the answer in any order.
 *
 * The hour must not contain a leading zero.
 *
 *
 * For example, "01:00" is not valid. It should be "1:00".
 *
 *
 * The minute must be consist of two digits and may contain a leading
 * zero.
 *
 *
 * For example, "10:2" is not valid. It should be "10:02".
 *
 *
 *
 * Example 1:
 * Input: turnedOn = 1
 * Output:
 * ["0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"]
 * Example 2:
 * Input: turnedOn = 9
 * Output: []
 *
 *
 * Constraints:
 *
 *
 * 0 <= turnedOn <= 10
 *
 *
 */
// #include <bits/stdc++.h>
// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **readBinaryWatch(int turnedOn, int *returnSize)
{
	// Max possible = C(10, turnedOn)
	switch (turnedOn) {
	case 0:
		*returnSize = 1;
		break;
	case 1:
		*returnSize = 10;
		break;
	case 2:
		*returnSize = 45;
		break;
	case 3:
		*returnSize = 120;
		break;
	case 4:
		*returnSize = 210;
		break;
	case 5:
		*returnSize = 252;
		break;
	case 6:
		*returnSize = 210;
		break;
	case 7:
		*returnSize = 120;
		break;
	case 8:
		*returnSize = 45;
		break;
	case 9:
		*returnSize = 10;
		break;
	case 10:
		*returnSize = 1;
		break;
	default:
		*returnSize = 0;
		break;
	}

	char **result = (char **)malloc(sizeof(char *) * (*returnSize));
	int result_index = 0;
	for (int i = 0; i < 1024; i++) {
		int bits_count = ((i & 1) > 0) + ((i & 2) > 0) + ((i & 4) > 0) +
		    ((i & 8) > 0) + ((i & 16) > 0) + ((i & 32) > 0) +
		    ((i & 64) > 0) + ((i & 128) > 0) + ((i & 256) > 0) +
		    ((i & 512) > 0);
		if (bits_count == turnedOn) {
			int hour = i >> 6;
			int minute = i & 0x3f;	// 0x0...011_1111
			if ((hour >= 12) || (minute >= 60))
				(*returnSize)--;
			else {
				char time[6];
				sprintf(time, "%d:%02d", hour, minute);
				result[result_index] =
				    (char *)malloc(sizeof(char) *
						   (strlen(time) + 1));
				strcpy(result[result_index++], time);
			}
		}
	}
	return result;
}

// @lc code=end
// int main()
// {
//     int num = 0;
//     char ** result = readBinaryWatch(4, &num);
//     return 0;
// }

// Accepted
// 11/11 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 76.19 % of c submissions (5.7 MB)
