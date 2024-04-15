/*
 * @lc app=leetcode id=762 lang=cpp
 *
 * [762] Prime Number of Set Bits in Binary Representation
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

    int countPrimeSetBits(int left, int right)
    {
        int countPrime = 0;
        int index = left;
        int countBits[32] = {0};
        int BitsTableSize = 1;
        int BitsTableIndex = 0;

        while (index <= right)
        {
            if (Solution().Prime[hammingWeight((uint32_t)index)] == 1)
                countPrime++;
            index++;
        }
        return countPrime;
    }

private:
    int Prime[32] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1};
};
// @lc code=end

// Accepted
// 202/202 cases passed (56 ms)
// Your runtime beats 14.7 % of cpp submissions
// Your memory usage beats 49.83 % of cpp submissions (6 MB)