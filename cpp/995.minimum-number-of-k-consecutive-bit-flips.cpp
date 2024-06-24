/*
 * @lc app=leetcode id=995 lang=cpp
 *
 * [995] Minimum Number of K Consecutive Bit Flips
 *
 * https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
 *
 * algorithms
 * Hard (51.50%)
 * Likes:    1365
 * Dislikes: 69
 * Total Accepted:    52.3K
 * Total Submissions: 94.7K
 * Testcase Example:  '[0,1,0]\n1'
 *
 * You are given a binary array nums and an integer k.
 *
 * A k-bit flip is choosing a subarray of length k from nums and simultaneously
 * changing every 0 in the subarray to 1, and every 1 in the subarray to 0.
 *
 * Return the minimum number of k-bit flips required so that there is no 0 in
 * the array. If it is not possible, return -1.
 *
 * A subarray is a contiguous part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1,0], k = 1
 * Output: 2
 * Explanation: Flip nums[0], then flip nums[2].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,1,0], k = 2
 * Output: -1
 * Explanation: No matter how we flip subarrays of size 2, we cannot make the
 * array become [1,1,1].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [0,0,0,1,0,1,1,0], k = 3
 * Output: 3
 * Explanation:
 * Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
 * Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
 * Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= k <= nums.length
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minKBitFlips(vector<int>& nums, int k)
    {
        int  n         = (int) nums.size();
        int  count     = 0;  // Result
        bool flip_this = false;
        // flip[i] means we change flip_this when k - i before i current element
        queue<bool> flip;

        for (int i = 0; i < k; i++)
            flip.push(false);

        for (auto i = 0; i < n; i++)
        {
            int num = nums[i];
            // Check if the last change to flip_this is k before current element
            if (flip.front())
                flip_this = !flip_this;
            flip.pop();

            if (((num == 1) && !flip_this) || ((num == 0) && flip_this))
            {
                flip.push(false);
            }
            else
            {
                // If the the flip region is out of nums' bound, it's invalid
                if ((i + k) > n)
                {
                    count = -1;
                    return count;
                }
                count++;
                flip.push(true);
                flip_this = !flip_this;
            }
        }

        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 0, 1, 0 };
    int         k_1    = 1;
    int         res_1  = sol.minKBitFlips(nums_1, k_1);
    cout << res_1 << endl;
    // assert(res_1 == 2);

    // Test_2
    vector<int> nums_2 = { 1, 1, 0 };
    int         k_2    = 2;
    int         res_2  = sol.minKBitFlips(nums_2, k_2);
    cout << res_2 << endl;
    // assert(res_2 == -1);

    // Test_3
    vector<int> nums_3 = { 0, 0, 0, 1, 0, 1, 1, 0 };
    int         k_3    = 3;
    int         res_3  = sol.minKBitFlips(nums_3, k_3);
    cout << res_3 << endl;
    // assert(res_3 == 3);
    /*
    { 0, 0, 0, 1, 0, 1, 1, 0 }
    id  |queue of flip   |   flip_this
    Init|0 0 0           |   0
    0   |0 0 1           |   1
    1   |0 1 0           |   1
    2   |1 0 0           |   1
    3   |0 0 0           |   0
    4   |0 0 1           |   1
    5   |0 1 1           |   1
    6   |1 1 0           |   0
    7   |1 0             |   1
    */
    return 0;
}
// Accepted
// 113/113 cases passed (66 ms)
// Your runtime beats 99.18 % of cpp submissions
// Your memory usage beats 63.52 % of cpp submissions (110.4 MB)