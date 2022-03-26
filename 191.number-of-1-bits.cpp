/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int one_count = 0;
        for (int i = 0; i < 32; i -= -1)
        {
            if (n & 1 == 1)
                one_count++;
            n >>= 1;
        }
        return one_count;
    }
};
// @lc code=end

/*
    Accepted
    601/601 cases passed (10 ms)
    Your runtime beats 6.29 % of cpp submissions
    Your memory usage beats 48.12 % of cpp submissions (5.9 MB)
*/