/*
 * @lc app=leetcode id=1018 lang=cpp
 *
 * [1018] Binary Prefix Divisible By 5
 *
 * https://leetcode.com/problems/binary-prefix-divisible-by-5/description/
 *
 * algorithms
 * Easy (47.16%)
 * Likes:    798
 * Dislikes: 200
 * Total Accepted:    79.8K
 * Total Submissions: 163.5K
 * Testcase Example:  '[0,1,1]'
 *
 * You are given a binary array nums (0-indexed).
 * 
 * We define xi as the number whose binary representation is the subarray
 * nums[0..i] (from most-significant-bit to least-significant-bit).
 * 
 * 
 * For example, if nums = [1,0,1], then x0 = 1, x1 = 2, and x2 = 5.
 * 
 * 
 * Return an array of booleans answer where answer[i] is true if xi is
 * divisible by 5.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [0,1,1]
 * Output: [true,false,false]
 * Explanation: The input numbers in binary are 0, 01, 011; which are 0, 1, and
 * 3 in base-10.
 * Only the first number is divisible by 5, so answer[0] is true.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,1,1]
 * Output: [false,false,false]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        const int n = (int)nums.size();
        vector<bool> res(n, false);
        int curr = 0;
        for(int i = 0; i < n; ++i) {
            curr = ((curr << 1) + nums[i]) % 5;
            res[i] = (curr == 0);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char const *argv[])
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {0, 1, 1};
    vector<bool> res_1 = sol.prefixesDivBy5(nums_1);
    cout << "Test_1: ";
    for (auto res : res_1)
        cout << (res ? "true " : "false ");
    cout << endl;
    assert(res_1 == vector<bool>({true, false, false}));

    // Test_2
    vector<int> nums_2 = {1, 1, 1};
    vector<bool> res_2 = sol.prefixesDivBy5(nums_2);
    cout << "Test_2: ";
    for (auto res : res_2)
        cout << (res ? "true " : "false ");
    cout << endl;
    assert(res_2 == vector<bool>({false, false, false}));

    return 0;
}
// Accepted
// 24/24 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 8.21 % of cpp submissions (18.6 MB)