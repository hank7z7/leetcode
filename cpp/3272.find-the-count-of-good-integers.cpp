/*
 * @lc app=leetcode id=3272 lang=cpp
 *
 * [3272] Find the Count of Good Integers
 *
 * https://leetcode.com/problems/find-the-count-of-good-integers/description/
 *
 * algorithms
 * Hard (69.59%)
 * Likes:    398
 * Dislikes: 98
 * Total Accepted:    65.1K
 * Total Submissions: 93.6K
 * Testcase Example:  '3\n5'
 *
 * You are given two positive integers n and k.
 *
 * An integer x is called k-palindromic if:
 *
 *
 * x is a palindrome.
 * x is divisible by k.
 *
 *
 * An integer is called good if its digits can be rearranged to form a
 * k-palindromic integer. For example, for k = 2, 2020 can be rearranged to
 * form the k-palindromic integer 2002, whereas 1010 cannot be rearranged to
 * form a k-palindromic integer.
 *
 * Return the count of good integers containing n digits.
 *
 * Note that any integer must not have leading zeros, neither before nor after
 * rearrangement. For example, 1010 cannot be rearranged to form 101.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3, k = 5
 *
 * Output: 27
 *
 * Explanation:
 *
 * Some of the good integers are:
 *
 *
 * 551 because it can be rearranged to form 515.
 * 525 because it is already k-palindromic.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 4
 *
 * Output: 2
 *
 * Explanation:
 *
 * The two good integers are 4 and 8.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 5, k = 6
 *
 * Output: 2468
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10
 * 1 <= k <= 9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    long long countGoodIntegers(int n, int k)
    {
        unordered_set<string> dict;
        int base = pow(10, (n - 1) / 2);
        int skip = n & 1;
        /* Enumerate the number of palindrome numbers of n digits */
        for (int i = base; i < base * 10; i++)
        {
            string s = to_string(i);
            s += string(s.rbegin() + skip, s.rend());
            long long palindromicInteger = stoll(s);
            /* If the current palindrome number is a k-palindromic integer */
            if (palindromicInteger % k == 0)
            {
                sort(s.begin(), s.end());
                dict.emplace(s);
            }
        }

        vector<long long> factorial(n + 1, 1);
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            factorial[i] = factorial[i - 1] * i;
        }
        for (const string& s : dict)
        {
            vector<int> cnt(10);
            for (char c : s)
            {
                cnt[c - '0']++;
            }
            /* Calculate permutations and combinations */
            long long tot = (n - cnt[0]) * factorial[n - 1];
            for (int x : cnt)
            {
                tot /= factorial[x];
            }
            ans += tot;
        }

        return ans;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n = 3;
    int k = 5;
    long long result = sol.countGoodIntegers(n, k);
    cout << result << endl;
    assert(result == 27);

    // Test_2
    n = 1;
    k = 4;
    result = sol.countGoodIntegers(n, k);
    cout << result << endl;
    assert(result == 2);

    // Test_3
    n = 5;
    k = 6;
    result = sol.countGoodIntegers(n, k);
    cout << result << endl;
    assert(result == 2468);

    return 0;
}
// Accepted
// 90/90 cases passed (507 ms)
// Your runtime beats 49.27 % of cpp submissions
// Your memory usage beats 46.38 % of cpp submissions (60.2 MB)