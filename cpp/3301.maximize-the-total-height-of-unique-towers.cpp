/*
 * @lc app=leetcode id=3301 lang=cpp
 *
 * [3301] Maximize the Total Height of Unique Towers
 *
 * https://leetcode.com/problems/maximize-the-total-height-of-unique-towers/description/
 *
 * algorithms
 * Medium (34.94%)
 * Likes:    82
 * Dislikes: 6
 * Total Accepted:    26.3K
 * Total Submissions: 75.4K
 * Testcase Example:  '[2,3,4,3]'
 *
 * You are given an array maximumHeight, where maximumHeight[i] denotes the
 * maximum height the i^th tower can be assigned.
 *
 * Your task is to assign a height to each tower so that:
 *
 *
 * The height of the i^th tower is a positive integer and does not exceed
 * maximumHeight[i].
 * No two towers have the same height.
 *
 *
 * Return the maximum possible total sum of the tower heights. If it's not
 * possible to assign heights, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: maximumHeight = [2,3,4,3]
 *
 * Output: 10
 *
 * Explanation:
 *
 * We can assign heights in the following way: [1, 2, 4, 3].
 *
 *
 * Example 2:
 *
 *
 * Input: maximumHeight = [15,10]
 *
 * Output: 25
 *
 * Explanation:
 *
 * We can assign heights in the following way: [15, 10].
 *
 *
 * Example 3:
 *
 *
 * Input: maximumHeight = [2,2,1]
 *
 * Output: -1
 *
 * Explanation:
 *
 * It's impossible to assign positive heights to each index so that no two
 * towers have the same height.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= maximumHeight.length <= 10^5
 * 1 <= maximumHeight[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long maximumTotalSum(vector<int> &maximumHeight)
    {
        int n = (int)maximumHeight.size();
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());

        long long sum = 0;
        int prev = INT_MAX;
        for (auto &height : maximumHeight)
        {
            if (height < n)
                return -1;
            // cout << height << " ";
            if (height >= prev)
            {
                // cout << prev - 1 << endl;
                sum += (prev - 1);
                prev = prev - 1;
            }
            else
            {
                // cout << height << endl;
                sum += height;
                prev = height;
            }
            n--;
        }
        return sum;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {2, 3, 4, 3};
    long long res_1 = sol.maximumTotalSum(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 10);

    // Test_1
    vector<int> nums_1 = {15, 10};
    long long res_1 = sol.maximumTotalSum(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 25);

    // Test_1
    vector<int> nums_1 = {2, 2, 1};
    long long res_1 = sol.maximumTotalSum(nums_1);
    cout << res_1 << endl;
    assert(res_1 == -1);
    return 0;
}
// Accepted
// 583/583 cases passed (207 ms)
// Your runtime beats 98.07 % of cpp submissions
// Your memory usage beats 35.55 % of cpp submissions (120 MB)