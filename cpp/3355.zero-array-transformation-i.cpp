/*
 * @lc app=leetcode id=3355 lang=cpp
 *
 * [3355] Zero Array Transformation I
 *
 * https://leetcode.com/problems/zero-array-transformation-i/description/
 *
 * algorithms
 * Medium (42.93%)
 * Likes:    225
 * Dislikes: 28
 * Total Accepted:    32.9K
 * Total Submissions: 75.4K
 * Testcase Example:  '[1,0,1]\n[[0,2]]'
 *
 * You are given an integer array nums of length n and a 2D array queries,
 * where queries[i] = [li, ri].
 *
 * For each queries[i]:
 *
 *
 * Select a subset of indices within the range [li, ri] in nums.
 * Decrement the values at the selected indices by 1.
 *
 *
 * A Zero Array is an array where all elements are equal to 0.
 *
 * Return true if it is possible to transform nums into a Zero Array after
 * processing all the queries sequentially, otherwise return false.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,0,1], queries = [[0,2]]
 *
 * Output: true
 *
 * Explanation:
 *
 *
 * For i = 0:
 *
 *
 * Select the subset of indices as [0, 2] and decrement the values at these
 * indices by 1.
 * The array will become [0, 0, 0], which is a Zero Array.
 *
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,3,2,1], queries = [[1,3],[0,2]]
 *
 * Output: false
 *
 * Explanation:
 *
 *
 * For i = 0:
 *
 *
 * Select the subset of indices as [1, 2, 3] and decrement the values at these
 * indices by 1.
 * The array will become [4, 2, 1, 0].
 *
 *
 * For i = 1:
 *
 * Select the subset of indices as [0, 1, 2] and decrement the values at these
 * indices by 1.
 * The array will become [3, 1, 0, 0], which is not a Zero
 * Array.
 *
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= li <= ri < nums.length
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        const int n = (int) nums.size();
        vector<int> sweep(n + 1, 0);

        for (auto& query : queries)
        {
            int l = query[0];
            int r = query[1];
            sweep[l] += 1;
            sweep[r + 1] -= 1;
        }

        for (int i = 1; i <= n; i++)
        {
            sweep[i] += sweep[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            if (sweep[i] < nums[i])
                return false;
        }
        return true;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    vector<int> nums = { 1, 0, 1 };
    vector<vector<int>> queries = { { 0, 2 } };
    bool res = sol.isZeroArray(nums, queries);
    cout << res << endl;
    assert(res == true);

    // Test_2
    nums = { 4, 3, 2, 1 };
    queries = { { 1, 3 }, { 0, 2 } };
    res = sol.isZeroArray(nums, queries);
    cout << res << endl;
    assert(res == false);

    return 0;
}
