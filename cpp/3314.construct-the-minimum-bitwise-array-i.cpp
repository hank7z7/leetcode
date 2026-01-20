/*
 * @lc app=leetcode id=3314 lang=cpp
 *
 * [3314] Construct the Minimum Bitwise Array I
 *
 * https://leetcode.com/problems/construct-the-minimum-bitwise-array-i/description/
 *
 * algorithms
 * Easy (74.22%)
 * Likes:    235
 * Dislikes: 35
 * Total Accepted:    69.1K
 * Total Submissions: 83.8K
 * Testcase Example:  '[2,3,5,7]'
 *
 * You are given an array nums consisting of n prime integers.
 * 
 * You need to construct an array ans of length n, such that, for each index i,
 * the bitwise OR of ans[i] and ans[i] + 1 is equal to nums[i], i.e. ans[i] OR
 * (ans[i] + 1) == nums[i].
 * 
 * Additionally, you must minimize each value of ans[i] in the resulting
 * array.
 * 
 * If it is not possible to find such a value for ans[i] that satisfies the
 * condition, then set ans[i] = -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,5,7]
 * 
 * Output: [-1,1,4,3]
 * 
 * Explanation:
 * 
 * 
 * For i = 0, as there is no value for ans[0] that satisfies ans[0] OR (ans[0]
 * + 1) = 2, so ans[0] = -1.
 * For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 3 is
 * 1, because 1 OR (1 + 1) = 3.
 * For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 5 is
 * 4, because 4 OR (4 + 1) = 5.
 * For i = 3, the smallest ans[3] that satisfies ans[3] OR (ans[3] + 1) = 7 is
 * 3, because 3 OR (3 + 1) = 7.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [11,13,31]
 * 
 * Output: [9,12,15]
 * 
 * Explanation:
 * 
 * 
 * For i = 0, the smallest ans[0] that satisfies ans[0] OR (ans[0] + 1) = 11 is
 * 9, because 9 OR (9 + 1) = 11.
 * For i = 1, the smallest ans[1] that satisfies ans[1] OR (ans[1] + 1) = 13 is
 * 12, because 12 OR (12 + 1) = 13.
 * For i = 2, the smallest ans[2] that satisfies ans[2] OR (ans[2] + 1) = 31 is
 * 15, because 15 OR (15 + 1) = 31.
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 100
 * 2 <= nums[i] <= 1000
 * nums[i] is a prime number.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums) {
            // Find the rightmost 0 bit and clear the bit to its right
            if((num & 1) == 0) {
                // If rightmost bit is 0, it's impossible
                ans.push_back(-1);
                continue;
            }
            
            // Find rightmost 0 bit
            int pos = 1;
            while(pos < 32) {
                if(((num >> pos) & 1) == 0) {
                    // Found rightmost 0 bit at position pos
                    // Answer = num with bit (pos-1) cleared
                    int result = num & ~(1 << (pos - 1));
                    ans.push_back(result);
                    break;
                }
                pos++;
            }
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = {2,3,5,7};
    vector<int> res = sol.minBitwiseArray(nums);
    vector<int> expected1 = {-1,1,4,3};
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    assert(res == expected1);

    // Test_2
    vector<int> nums2 = {11,13,31};
    vector<int> res2 = sol.minBitwiseArray(nums2);
    vector<int> expected2 = {9,12,15};
    for(int i = 0; i < res2.size(); i++) {
        cout << res2[i] << " ";
    }
    cout << endl;
    assert(res2 == expected2);

    return 0;
}
// Accepted
// 658/658 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 26.63 % of cpp submissions (25.3 MB)