/*
 * @lc app=leetcode id=3066 lang=cpp
 *
 * [3066] Minimum Operations to Exceed Threshold Value II
 *
 * https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/
 *
 * algorithms
 * Medium (22.94%)
 * Likes:    10
 * Dislikes: 1
 * Total Accepted:    16.9K
 * Total Submissions: 73.8K
 * Testcase Example:  '[2,11,10,1,3]\n10'
 *
 * You are given a 0-indexed integer array nums, and an integer k.
 *
 * In one operation, you will:
 *
 *
 * Take the two smallest integers x and y in nums.
 * Remove x and y from nums.
 * Add min(x, y) * 2 + max(x, y) anywhere in the array.
 *
 *
 * Note that you can only apply the described operation if nums contains at
 * least two elements.
 *
 * Return the minimum number of operations needed so that all elements of the
 * array are greater than or equal to k.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,11,10,1,3], k = 10
 * Output: 2
 * Explanation: In the first operation, we remove elements 1 and 2, then add 1
 * * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
 * In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to
 * nums. nums becomes equal to [10, 11, 10].
 * At this stage, all the elements of nums are greater than or equal to 10 so
 * we can stop.
 * It can be shown that 2 is the minimum number of operations needed so that
 * all elements of the array are greater than or equal to 10.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,1,2,4,9], k = 20
 * Output: 4
 * Explanation: After one operation, nums becomes equal to [2, 4, 9, 3].
 * After two operations, nums becomes equal to [7, 4, 9].
 * After three operations, nums becomes equal to [15, 9].
 * After four operations, nums becomes equal to [33].
 * At this stage, all the elements of nums are greater than 20 so we can stop.
 * It can be shown that 4 is the minimum number of operations needed so that
 * all elements of the array are greater than or equal to 20.
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 2 * 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= k <= 10^9
 * The input is generated such that an answer always exists. That is, there
 * exists some sequence of operations after which all elements of the array are
 * greater than or equal to k.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        // Min_heap
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        int count = 0;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            pq.push((long long) nums[i]);
        }
        while (pq.top() < (long long) k)
        {
            long long min_1 = pq.top();
            pq.pop();
            long long min_2 = pq.top();
            pq.pop();
            pq.push(min(min_1, min_2) * 2 + max(min_1, min_2));
            count++;
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      k;
    // Test_1
    k                  = 10;
    vector<int> nums_1 = { 2, 11, 10, 1, 3 };
    cout << sol.minOperations(nums_1, k) << endl;

    // Test_2
    k                  = 1;
    vector<int> nums_2 = { 1, 1, 2, 4, 9 };
    cout << sol.minOperations(nums_2, k) << endl;

    // Test_3
    k                  = 9;
    vector<int> nums_3 = { 1, 1, 2, 4, 9 };
    cout << sol.minOperations(nums_3, k) << endl;

    return 0;
}
// Accepted
// 675/675 cases passed (221 ms)
// Your runtime beats 71.43 % of cpp submissions
// Your memory usage beats 42.86 % of cpp submissions (98.6 MB)