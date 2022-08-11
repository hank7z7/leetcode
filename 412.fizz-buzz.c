/*
 * @lc app=leetcode id=412 lang=c
 *
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (66.41%)
 * Likes:    754
 * Dislikes: 125
 * Total Accepted:    703.1K
 * Total Submissions: 1M
 * Testcase Example:  '3'
 *
 * Given an integer n, return a string array answer (1-indexed) where:
 * 
 * 
 * answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
 * answer[i] == "Fizz" if i is divisible by 3.
 * answer[i] == "Buzz" if i is divisible by 5.
 * answer[i] == i (as a string) if none of the above conditions are true.
 * 
 * 
 * 
 * Example 1:
 * Input: n = 3
 * Output: ["1","2","Fizz"]
 * Example 2:
 * Input: n = 5
 * Output: ["1","2","Fizz","4","Buzz"]
 * Example 3:
 * Input: n = 15
 * Output:
 * ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 10^4
 * 
 * 
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **fizzBuzz(int n, int *returnSize)
{
	char fizz[5] = "Fizz";
	char buzz[5] = "Buzz";
	char fizzbuzz[9] = "FizzBuzz";
	char **result = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++) {
		result[i] = malloc(sizeof(char) * 9);	// Max length of FizzBuzz
		int divide_3 = (i + 1) % 3;
		int divide_5 = (i + 1) % 5;
		if ((divide_5 == 0) && (divide_3 == 0))
			strcpy(result[i], fizzbuzz);
		else if (divide_3 == 0)
			strcpy(result[i], fizz);
		else if (divide_5 == 0)
			strcpy(result[i], buzz);
		else {
			char str[20];
			sprintf(str, "%d", (i + 1));
			strcpy(result[i], str);
		}
	}

	*returnSize = n;
	return result;
}

// @lc code=end

// Accepted
// 8/8 cases passed (13 ms)
// Your runtime beats 35.09 % of c submissions
// Your memory usage beats 88.16 % of c submissions (6.9 MB)
