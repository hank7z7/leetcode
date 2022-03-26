/*
 * @lc app=leetcode id=263 lang=cpp
 *
 * [263] Ugly Number
 */

// @lc code=start
class Solution
{
public:
    bool isUgly(int n)
    {
        if (n == 0)
            return false;
        if (n == INT_MIN)
            return false;
        while (n % 2 == 0)
            n /= 2;
        while (n % 3 == 0)
            n /= 3;
        while (n % 5 == 0)
            n /= 5;

        // cout << "n = " << n << endl;
        if (n == 1)
            return true;
        else
            return false;
    }
};
// @lc code=end

/*
    Accepted
    1013/1013 cases passed (10 ms)
    Your runtime beats 6.26 % of cpp submissions
    Your memory usage beats 69.61 % of cpp submissions (5.8 MB)
*/