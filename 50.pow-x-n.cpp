/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution
{
public:
    double myPow(double x, int n)
    {
        double pow = x;
        long long abs_n = n < 0 ? -(long long)n : (long long)n;
        double result = 1;
        for (long long i = abs_n; i != 0; i = i >> 1)
        {
            if (i & 1)
                result *= pow;
            pow = pow * pow;
        }
        return n < 0 ? 1 / result : result;
    }
};
// @lc code=end

/*
    Accepted
    305/305 cases passed (5 ms)
    Your runtime beats 18.83 % of cpp submissions
    Your memory usage beats 44.98 % of cpp submissions (5.9 MB)
*/