/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution
{
public:
    int countPrimes(int n)
    {
        bool *PrimeTable;
        PrimeTable = new bool[n + 1];
        for (int i = 0; i < n + 1; i++)
            PrimeTable[i] = true;

        for (int i = 2; i < (int)ceil(sqrt(n)); i++)
        {
            if (PrimeTable[i] == true)
            {
                for (int j = i * i; j < n; j += i)
                    if (j != i)
                        PrimeTable[j] = false;
            }
        }

        int countPrime = 0;
        for (int i = 2; i < n; i++)
            if (PrimeTable[i] == true)
                countPrime++;

        delete[] PrimeTable;
        return countPrime;
    }
};
// @lc code=end

/*
    Accepted
    66/66 cases passed (231 ms)
    Your runtime beats 70.88 % of cpp submissions
    Your memory usage beats 15.42 % of cpp submissions (37.6 MB)
*/