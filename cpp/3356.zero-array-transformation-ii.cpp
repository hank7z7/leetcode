/*
 * @lc app=leetcode id=3356 lang=cpp
 *
 * [3356] Zero Array Transformation II
 *
 * https://leetcode.com/problems/zero-array-transformation-ii/description/
 *
 * algorithms
 * Medium (39.21%)
 * Likes:    534
 * Dislikes: 49
 * Total Accepted:    59.3K
 * Total Submissions: 149.2K
 * Testcase Example:  '[2,0,2]\n[[0,2,1],[0,2,1],[1,1,3]]'
 *
 * You are given an integer array nums of length n and a 2D array queries where
 * queries[i] = [li, ri, vali].
 *
 * Each queries[i] represents the following action on nums:
 *
 *
 * Decrement the value at each index in the range [li, ri] in nums by at most
 * vali.
 * The amount by which each value is decremented can be chosen independently
 * for each index.
 *
 *
 * A Zero Array is an array with all its elements equal to 0.
 *
 * Return the minimum possible non-negative value of k, such that after
 * processing the first k queries in sequence, nums becomes a Zero Array. If no
 * such k exists, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
 *
 * Output: 2
 *
 * Explanation:
 *
 *
 * For i = 0 (l = 0, r = 2, val = 1):
 *
 *
 * Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
 * The array will become [1, 0, 1].
 *
 *
 * For i = 1 (l = 0, r = 2, val = 1):
 *
 * Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
 * The array will become [0, 0, 0], which is a Zero Array. Therefore, the
 * minimum value of k is 2.
 *
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
 *
 * Output: -1
 *
 * Explanation:
 *
 *
 * For i = 0 (l = 1, r = 3, val = 2):
 *
 *
 * Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
 * The array will become [4, 1, 0, 0].
 *
 *
 * For i = 1 (l = 0, r = 2, val = 1):
 *
 * Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
 * The array will become [3, 0, 0, 0], which is not a Zero
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
 * 0 <= nums[i] <= 5 * 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 3
 * 0 <= li <= ri < nums.length
 * 1 <= vali <= 5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        const int n = (int) nums.size();
        int sum = 0, k = 0;
        vector<int> differenceArray(n + 1);

        // Iterate through nums
        for (int index = 0; index < n; index++)
        {
            // Iterate through queries while current index of nums cannot equal
            // zero
            while (sum + differenceArray[index] < nums[index])
            {
                k++;

                // Zero array isn't formed after all queries are processed
                if (k > (int)queries.size())
                {
                    return -1;
                }
                int left = queries[k - 1][0], right = queries[k - 1][1], val = queries[k - 1][2];

                // Process start and end of range
                if (right >= index)
                {
                    differenceArray[max(left, index)] += val;
                    differenceArray[right + 1] -= val;
                }
            }
            // Update prefix sum at current index
            sum += differenceArray[index];
        }
        return k;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    vector<int> nums;
    vector<vector<int>> queries;
    nums = { 2, 0, 2 };
    queries = { { 0, 2, 1 }, { 0, 2, 1 }, { 1, 1, 3 } };
    int res = sol.minZeroArray(nums, queries);
    cout << res << endl;
    assert(res == 2);

    // Test_2
    nums = { 4, 3, 2, 1 };
    queries = { { 1, 3, 2 }, { 0, 2, 1 } };
    res = sol.minZeroArray(nums, queries);
    cout << res << endl;
    assert(res == -1);

    return 0;
}
