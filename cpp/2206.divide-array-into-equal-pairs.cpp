/*
 * @lc app=leetcode id=2206 lang=cpp
 *
 * [2206] Divide Array Into Equal Pairs
 *
 * https://leetcode.com/problems/divide-array-into-equal-pairs/description/
 *
 * algorithms
 * Easy (74.14%)
 * Likes:    861
 * Dislikes: 40
 * Total Accepted:    135.9K
 * Total Submissions: 177.5K
 * Testcase Example:  '[3,2,3,2,2,2]'
 *
 * You are given an integer array nums consisting of 2 * n integers.
 *
 * You need to divide nums into n pairs such that:
 *
 *
 * Each element belongs to exactly one pair.
 * The elements present in a pair are equal.
 *
 *
 * Return true if nums can be divided into n pairs, otherwise return false.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,2,3,2,2,2]
 * Output: true
 * Explanation:
 * There are 6 elements in nums, so they should be divided into 6 / 2 = 3
 * pairs.
 * If nums is divided into the pairs (2, 2), (3, 3), and (2, 2), it will
 * satisfy all the conditions.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4]
 * Output: false
 * Explanation:
 * There is no way to divide nums into 4 / 2 = 2 pairs such that the pairs
 * satisfy every condition.
 *
 *
 *
 * Constraints:
 *
 *
 * nums.length == 2 * n
 * 1 <= n <= 500
 * 1 <= nums[i] <= 500
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool divideArray(vector<int>& nums)
    {
        const int n = (int) nums.size();
        unordered_map<int, int> freq;
        for (int i = 0; i < n; i++)
            freq[nums[i]]++;
        for (auto& [key, value] : freq)
            if (value % 2)
                return false;
        return true;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    vector<int> nums = { 3, 2, 3, 2, 2, 2 };
    bool res = sol.divideArray(nums);
    cout << res << endl;
    assert(res == true);

    // Test_2
    nums = { 1, 2, 3, 4 };
    res = sol.divideArray(nums);
    cout << res << endl;
    assert(res == false);

    return 0;
}
// Accepted
// 134/134 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 31.79 % of cpp submissions (18.2 MB)