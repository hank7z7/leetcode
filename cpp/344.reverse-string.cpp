/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
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

    void reverseString(vector<char> &s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            // cout << "i = " << s[i] << ", j = " << s[j] << endl;
            swap(&s[i], &s[j]);
        }
    }
};
// @lc code=end

// Accepted
// 477/477 cases passed (24 ms)
// Your runtime beats 76.51 % of cpp submissions
// Your memory usage beats 76.65 % of cpp submissions (23.2 MB)