/*
 * @lc app=leetcode id=3309 lang=cpp
 *
 * [3309] Maximum Possible Number by Binary Concatenation
 *
 * https://leetcode.com/problems/maximum-possible-number-by-binary-concatenation/description/
 *
 * algorithms
 * Medium (62.69%)
 * Likes:    10
 * Dislikes: 1
 * Total Accepted:    20.2K
 * Total Submissions: 32.2K
 * Testcase Example:  '[1,2,3]'
 *
 * You are given an array of integers nums of size 3.
 *
 * Return the maximum possible number whose binary representation can be formed
 * by concatenating the binary representation of all elements in nums in some
 * order.
 *
 * Note that the binary representation of any number does not contain leading
 * zeros.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3]
 *
 * Output: 30
 *
 * Explanation:
 *
 * Concatenate the numbers in the order [3, 1, 2] to get the result "11110",
 * which is the binary representation of 30.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,8,16]
 *
 * Output: 1296
 *
 * Explanation:
 *
 * Concatenate the numbers in the order [2, 8, 16] to get the result
 * "10100010000", which is the binary representation of 1296.
 *
 *
 *
 * Constraints:
 *
 *
 * nums.length == 3
 * 1 <= nums[i] <= 127
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxGoodNumber(vector<int> &nums)
    {
        string str1, str2, str3;
        while(nums[0])
        {
            if(nums[0] & 1)
                str1 = "1" + str1;
            else
                str1 = "0" + str1;
            nums[0] = nums[0] >> 1;
        }
        while(nums[1])
        {
            if(nums[1] & 1)
                str2 = "1" + str2;
            else
                str2 = "0" + str2;
            nums[1] = nums[1] >> 1;
        }
        while(nums[2])
        {
            if(nums[2] & 1)
                str3 = "1" + str3;
            else
                str3 = "0" + str3;
            nums[2] = nums[2] >> 1;
        }
        string str[6];
        str[0] = str1 + str2 + str3;
        str[1] = str1 + str3 + str2;
        str[2] = str2 + str1 + str3;
        str[3] = str2 + str3 + str1;
        str[4] = str3 + str1 + str2;
        str[5] = str3 + str2 + str1;
        int res = 0;
        for(int i = 0; i < 6; i++)
        {
            // cout << str[i] << " ";
            int curr = 0;
            for(int j = 0; j < (int)str[i].length(); j++)
            {
                curr *= 2;
                if(str[i][j] == '1')
                    curr += 1;
            }
            res = max(res, curr);
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 2, 3};
    int res_1 = sol.maxGoodNumber(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 30);

    // Test_2
    vector<int> nums_2 = {2, 8, 16};
    int res_2 = sol.maxGoodNumber(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 1296);

    return 0;
}
// Accepted
// 752/752 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 11.11 % of cpp submissions (26.5 MB)