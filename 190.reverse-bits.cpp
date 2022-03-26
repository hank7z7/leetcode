/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

// @lc code=start
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};
// @lc code=end

/*
    Accepted
    600/600 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 10.7 % of cpp submissions (6 MB)
*/