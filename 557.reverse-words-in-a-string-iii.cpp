/*
 * @lc app=leetcode id=557 lang=cpp
 *
 * [557] Reverse Words in a String III
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

    string reverseWords(string s)
    {
        string output = s;
        int size = output.size();

        int l = 0;
        int r = 0;
        int i = 0;
        while (i++ < size)
        {
            if (output[i] == ' ')
            {
                r = i - 1;
                for (int i = l, j = r; i < j; i++, j--)
                    swap(&output[i], &output[j]);
                l = i + 1;
            }
            if (i == size)
            {
                r = i - 1;
                for (int i = l, j = r; i < j; i++, j--)
                    swap(&output[i], &output[j]);
                l = i + 1;
            }
        }

        return output;
    }
};

// @lc code=end

// Accepted
// 29/29 cases passed (12 ms)
// Your runtime beats 92.46 % of cpp submissions
// Your memory usage beats 39.62 % of cpp submissions (10.2 MB)
