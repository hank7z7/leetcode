/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0;
        int right = sqrt_int_max;
        while ((right - left) > 1)
        {
            int mid = (left + right) >> 1;
            int mid_pow_2 = mid * mid;
            if (mid_pow_2 > x)
                right = mid;
            else if (mid_pow_2 < x)
                left = mid;
            else
                return mid;
        }
        return left;
    }

private:
    int sqrt_int_max = 46341;
};
// @lc code=end

/*
    Accepted
    1017/1017 cases passed (3 ms)
    Your runtime beats 67.84 % of cpp submissions
    Your memory usage beats 74.97 % of cpp submissions (5.9 MB)
*/
