/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

// @lc code=start

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize)
{
    int carry = 1;
    int *result = (int *)malloc((digitsSize + 1) * sizeof(int));
    int i;
    for (i = digitsSize - 1; i >= 0; i--)
    {
        if (carry == 1 && (digits[i] + carry) == 10)
        {
            result[i + 1] = 0;
            carry = 1;
        }
        else
        {
            result[i + 1] = digits[i] + carry;
            carry = 0;
        }
    }

    if (carry == 0)
    {
        *returnSize = digitsSize;
        return ++result;
    }
    else
    {
        *returnSize = digitsSize + 1;
        result[0] = 1;
        return result;
    }
}
// @lc code=end

// Accepted
// 111/111 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 29.67 % of c submissions (6.1 MB)