/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 *
 * https://leetcode.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (66.78%)
 * Likes:    16761
 * Dislikes: 846
 * Total Accepted:    2.2M
 * Total Submissions: 3.4M
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * Given an integer array nums and an integer k, return the k^th largest
 * element in the array.
 *
 * Note that it is the k^th largest element in the sorted order, not the k^th
 * distinct element.
 *
 * Can you solve it without sorting?
 *
 *
 * Example 1:
 * Input: nums = [3,2,1,5,6,4], k = 2
 * Output: 5
 * Example 2:
 * Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
 * Output: 4
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        priority_queue<int> pq;
        for (auto num : nums)
            pq.push(num);
        int result;
        for (int i = 0; i < k; i++)
        {
            result = pq.top();
            pq.pop();
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 3, 2, 1, 5, 6, 4 };
    int         k_1    = 2;
    cout << sol.findKthLargest(nums_1, k_1) << endl;

    // Test_2
    vector<int> nums_2 = { 3, 2, 3, 1, 2, 4, 5, 5, 6 };
    int         k_2    = 4;
    cout << sol.findKthLargest(nums_2, k_2) << endl;

    return 0;
}
// Accepted
// 41/41 cases passed (106 ms)
// Your runtime beats 31.23 % of cpp submissions
// Your memory usage beats 19.18 % of cpp submissions (64.2 MB)