/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution
{
public:
    void swap(char *x, char *y)
    {
        *y = *x ^ *y;
        *x = *x ^ *y;
        *y = *x ^ *y;
    }

    string reverseStr(string s, int k)
    {
        string output = s;
        int size = output.size();

        int l = 0;
        while (l < size)
        {
            int r = l + k - 1;
            if (r > size - 1)
                r = size - 1;
            for (int i = l, j = r; i < j; i++, j--)
                swap(&output[i], &output[j]);
            l += 2 * k;
        }

        return output;
    }
};
// @lc code=end

// Accepted
// 60/60 cases passed (12 ms)
// Your runtime beats 9.21 % of cpp submissions
// Your memory usage beats 35.48 % of cpp submissions (7.3 MB)