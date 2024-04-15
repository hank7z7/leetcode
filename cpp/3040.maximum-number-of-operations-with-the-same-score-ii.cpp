/*
 * @lc app=leetcode id=3040 lang=cpp
 *
 * [3040] Maximum Number of Operations With the Same Score II
 *
 * https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-ii/description/
 *
 * algorithms
 * Medium (23.38%)
 * Likes:    14
 * Dislikes: 1
 * Total Accepted:    7.1K
 * Total Submissions: 29.4K
 * Testcase Example:  '[3,2,1,2,3,4]'
 *
 * Given an array of integers called nums, you can perform any of the following
 * operation while nums contains at least 2 elements:
 *
 *
 * Choose the first two elements of nums and delete them.
 * Choose the last two elements of nums and delete them.
 * Choose the first and the last elements of nums and delete them.
 *
 *
 * The score of the operation is the sum of the deleted elements.
 *
 * Your task is to find the maximum number of operations that can be performed,
 * such that all operations have the same score.
 *
 * Return the maximum number of operations possible that satisfy the condition
 * mentioned above.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,2,1,2,3,4]
 * Output: 3
 * Explanation: We perform the following operations:
 * - Delete the first two elements, with score 3 + 2 = 5, nums = [1,2,3,4].
 * - Delete the first and the last elements, with score 1 + 4 = 5, nums =
 * [2,3].
 * - Delete the first and the last elements, with score 2 + 3 = 5, nums = [].
 * We are unable to perform any more operations as nums is empty.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,6,1,4]
 * Output: 2
 * Explanation: We perform the following operations:
 * - Delete the first two elements, with score 3 + 2 = 5, nums = [6,1,4].
 * - Delete the last two elements, with score 1 + 4 = 5, nums = [6].
 * It can be proven that we can perform at most 2 operations.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 2000
 * 1 <= nums[i] <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int max_ops_of_subarray(vector<int>& nums, int l, int r, int score, vector<vector<int>>& dp)
    {
        // Becareful r and l input
        if (l >= r)
            return 0;
        if (dp[l][r] != 0)
            return dp[l][r];
        int max_ops = 0;
        if ((nums[l] + nums[l + 1]) == score)
            max_ops = max(max_ops, max_ops_of_subarray(nums, l + 2, r, score, dp) + 1);
        if ((nums[l] + nums[r]) == score)
            max_ops = max(max_ops, max_ops_of_subarray(nums, l + 1, r - 1, score, dp) + 1);
        if ((nums[r - 1] + nums[r]) == score)
            max_ops = max(max_ops, max_ops_of_subarray(nums, l, r - 2, score, dp) + 1);
        dp[l][r] = max_ops;
        return max_ops;
    }
    int maxOperations(vector<int>& nums)
    {
        int                 size = (int) nums.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        int                 start = 0;
        int                 end   = size - 1;

        int ret = 0;
        ret     = max(ret,
                  max_ops_of_subarray(nums, start + 2, end, nums[start] + nums[start + 1], dp) + 1);
        ret     = max(ret,
                  max_ops_of_subarray(nums, start + 1, end - 1, nums[start] + nums[end], dp) + 1);
        ret     = max(ret,
                  max_ops_of_subarray(nums, start, end - 2, nums[end - 1] + nums[end], dp) + 1);

        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution Sol;
    // Test_1
    vector<int> nums_1 = { 3, 2, 1, 4, 5 };
    cout << Sol.maxOperations(nums_1) << endl;  // 2

    // Test_2
    vector<int> nums_2 = { 3, 2, 6, 1, 4 };
    cout << Sol.maxOperations(nums_2) << endl;  // 2

    // Test_3
    vector<int> nums_3 = { max_ops };  // 6
    cout << Sol.maxOperations(nums_3) << endl;
    return 0;
}
// Accepted
// 549/549 cases passed (85 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 50 % of cpp submissions (147.3 MB)