/*
 * @lc app=leetcode id=992 lang=cpp
 *
 * [992] Subarrays with K Different Integers
 *
 * https://leetcode.com/problems/subarrays-with-k-different-integers/description/
 *
 * algorithms
 * Hard (56.63%)
 * Likes:    5228
 * Dislikes: 75
 * Total Accepted:    132.1K
 * Total Submissions: 227.5K
 * Testcase Example:  '[1,2,1,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the number of good
 * subarrays of nums.
 *
 * A good array is an array where the number of different integers in that
 * array is exactly k.
 *
 *
 * For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
 *
 *
 * A subarray is a contiguous part of an array.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,1,2,3], k = 2
 * Output: 7
 * Explanation: Subarrays formed with exactly 2 different integers: [1,2],
 * [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,1,3,4], k = 3
 * Output: 3
 * Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3],
 * [2,1,3], [1,3,4].
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * 1 <= nums[i], k <= nums.length
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    int subarrays_with_at_most_k_distinct(vector<int> &nums, int k)
    {
        unordered_map<int, int> um;
        int ret = 0;
        for (int i = 0, j = 0; j < (int)nums.size(); j++)
        {
            um[nums[j]]++;
            while (i <= j && (int)um.size() > k)
            {
                um[nums[i]]--;
                if (um[nums[i]] == 0)
                    um.erase(nums[i]);
                i++;
            }
            ret += (j - i + 1);
        }
        return ret;
    }

public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int at_most_k = subarrays_with_at_most_k_distinct(nums, k);
        int at_most_k_minus_1 = subarrays_with_at_most_k_distinct(nums, k - 1);
        return at_most_k - at_most_k_minus_1;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 2, 1, 2, 3};
    int k_1 = 2;
    cout << sol.subarraysWithKDistinct(nums_1, k_1) << endl;

    // Test_2
    vector<int> nums_2 = {1, 2, 1, 3, 4};
    int k_2 = 3;
    cout << sol.subarraysWithKDistinct(nums_2, k_2) << endl;

    return 0;
}
// Accepted
// 55/55 cases passed (111 ms)
// Your runtime beats 54.24 % of cpp submissions
// Your memory usage beats 34.2 % of cpp submissions (49.8 MB)