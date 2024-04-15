/*
 * @lc app=leetcode id=371 lang=c
 *
 * [371] Sum of Two Integers
 *
 * https://leetcode.com/problems/sum-of-two-integers/description/
 *
 * algorithms
 * Medium (50.85%)
 * Likes:    3924
 * Dislikes: 5322
 * Total Accepted:    433.4K
 * Total Submissions: 845.8K
 * Testcase Example:  '1\n2'
 *
 * Given two integers a and b, return the sum of the two integers without using
 * the operators + and -.
 * 
 * 
 * Example 1:
 * Input: a = 1, b = 2
 * Output: 3
 * Example 2:
 * Input: a = 2, b = 3
 * Output: 5
 * 
 * 
 * Constraints:
 * 
 * 
 * -1000 <= a, b <= 1000
 * 
 * 
 */
#include <bits/stdc++.h>

// @lc code=start
int getSum(int a, int b)
{
    while(b != 0)
    {
        unsigned int carry = (unsigned int)(a & b) << 1;
        a ^= b;
        b = (int)carry;
    }
    return a;
}

// @lc code=end

int main(int argc, char **argv)
{
	int a = 1;
	int b = 2;
	int result = getSum(a, b);
	printf("result = %d\n", result);

	return 0;
}
