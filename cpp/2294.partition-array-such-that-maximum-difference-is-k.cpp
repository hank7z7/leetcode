/*
 * @lc app=leetcode id=2294 lang=cpp
 *
 * [2294] Partition Array Such That Maximum Difference Is K
 *
 * https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/description/
 *
 * algorithms
 * Medium (74.33%)
 * Likes:    1005
 * Dislikes: 39
 * Total Accepted:    107.3K
 * Total Submissions: 133.8K
 * Testcase Example:  '[3,6,1,2,5]\n2'
 *
 * You are given an integer array nums and an integer k. You may partition nums
 * into one or more subsequences such that each element in nums appears in
 * exactly one of the subsequences.
 *
 * Return the minimum number of subsequences needed such that the difference
 * between the maximum and minimum values in each subsequence is at most k.
 *
 * A subsequence is a sequence that can be derived from another sequence by
 * deleting some or no elements without changing the order of the remaining
 * elements.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,6,1,2,5], k = 2
 * Output: 2
 * Explanation:
 * We can partition nums into the two subsequences [3,1,2] and [6,5].
 * The difference between the maximum and minimum value in the first
 * subsequence is 3 - 1 = 2.
 * The difference between the maximum and minimum value in the second
 * subsequence is 6 - 5 = 1.
 * Since two subsequences were created, we return 2. It can be shown that 2 is
 * the minimum number of subsequences needed.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3], k = 1
 * Output: 2
 * Explanation:
 * We can partition nums into the two subsequences [1,2] and [3].
 * The difference between the maximum and minimum value in the first
 * subsequence is 2 - 1 = 1.
 * The difference between the maximum and minimum value in the second
 * subsequence is 3 - 3 = 0.
 * Since two subsequences were created, we return 2. Note that another optimal
 * solution is to partition nums into the two subsequences [1] and [2,3].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [2,2,4,5], k = 0
 * Output: 3
 * Explanation:
 * We can partition nums into the three subsequences [2,2], [4], and [5].
 * The difference between the maximum and minimum value in the first
 * subsequences is 2 - 2 = 0.
 * The difference between the maximum and minimum value in the second
 * subsequences is 4 - 4 = 0.
 * The difference between the maximum and minimum value in the third
 * subsequences is 5 - 5 = 0.
 * Since three subsequences were created, we return 3. It can be shown that 3
 * is the minimum number of subsequences needed.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 * 0 <= k <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int partitionArray(vector<int>& nums, int k)
    {
        const int n = (int) nums.size();
        sort(nums.begin(), nums.end());
        int count = 0;
        int min = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (min + k >= nums[i])
            {
                // still in the same subsequence
                continue;
            }
            else
            {
                // new subsequence
                count++;
                min = nums[i];
            }
        }
        return count + 1;  // +1 for the last subsequence
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = { 3, 6, 1, 2, 5 };
    int k = 2;
    int res = sol.partitionArray(nums, k);
    cout << res << endl;  // Expected output: 2
    assert(res == 2);

    // Test_2
    nums = { 1, 2, 3 };
    k = 1;
    res = sol.partitionArray(nums, k);
    cout << res << endl;  // Expected output: 2
    assert(res == 2);

    // Test_3
    nums = { 2, 2, 4, 5 };
    k = 0;
    res = sol.partitionArray(nums, k);
    cout << res << endl;  // Expected output: 3
    assert(res == 3);

    return 0;
}
// Accepted
// 92/92 cases passed (31 ms)
// Your runtime beats 81.44 % of cpp submissions
// Your memory usage beats 96.08 % of cpp submissions (86.8 MB)