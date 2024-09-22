/*
 * @lc app=leetcode id=440 lang=cpp
 *
 * [440] K-th Smallest in Lexicographical Order
 *
 * https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (32.61%)
 * Likes:    876
 * Dislikes: 98
 * Total Accepted:    34.5K
 * Total Submissions: 100.6K
 * Testcase Example:  '13\n2'
 *
 * Given two integers n and k, return the k^th lexicographically smallest
 * integer in the range [1, n].
 *
 *
 * Example 1:
 *
 *
 * Input: n = 13, k = 2
 * Output: 10
 * Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6,
 * 7, 8, 9], so the second smallest number is 10.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= n <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
private:
    // Find steps from a to a + 1
    int find_gap(const long long n, long long a, long long b)
    {
        int steps = 0;
        while (a <= n)
        {
            // cout << "between " << a << " and " << b << " have " << min(n + 1, b) - a << " steps" << endl;
            // If a < n < b, gap is n - a + 1 steps (a, a + 1, ... n)
            // Else if a < b < n, gap is b - a steps (a, a + 1, ... b - 1)
            steps += min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return steps;
    }

public:
    int findKthNumber(int n, int k)
    {
        int steps = 1;
        k--;

        while (k)
        {
            int gap = find_gap((long long)n, (long long)steps, (long long)steps + 1);
            if (gap <= k)
            {
                k -= gap;
                steps++;
            }
            else
            {
                k--;
                steps *= 10;
            }
        }

        return steps;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int n_1 = 13, k_1 = 2;
    int res_1 = sol.findKthNumber(n_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 10);

    // Test_2
    int n_2 = 1, k_2 = 1;
    int res_2 = sol.findKthNumber(n_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    // Test_3
    int n_3 = 681692778, k_3 = 351251360;
    int res_3 = sol.findKthNumber(n_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == 416126219);

    return 0;
}
