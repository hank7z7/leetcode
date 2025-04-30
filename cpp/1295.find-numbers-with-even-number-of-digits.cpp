/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 *
 * https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/
 *
 * algorithms
 * Easy (77.77%)
 * Likes:    2661
 * Dislikes: 134
 * Total Accepted:    861.7K
 * Total Submissions: 1.1M
 * Testcase Example:  '[12,345,2,6,7896]'
 *
 * Given an array nums of integers, return how many of them contain an even
 * number of digits.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [12,345,2,6,7896]
 * Output: 2
 * Explanation:
 * 12 contains 2 digits (even number of digits). 
 * 345 contains 3 digits (odd number of digits). 
 * 2 contains 1 digit (odd number of digits). 
 * 6 contains 1 digit (odd number of digits). 
 * 7896 contains 4 digits (even number of digits). 
 * Therefore only 12 and 7896 contain an even number of digits.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [555,901,482,1771]
 * Output: 1
 * Explanation:
 * Only 1771 contains an even number of digits.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 500
 * 1 <= nums[i] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    int findNumbers(vector<int>& nums)
    {
        int res = 0;
        for (int num : nums)
        {
            int digits = 0;
            while (num > 0)
            {
                num /= 10;
                digits++;
            }
            if (!(digits & 1))
            {
                res++;
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = { 12, 345, 2, 6, 7896 };
    int res = sol.findNumbers(nums);
    cout << "Test_1: " << res << endl;  // Expected output: 2
    assert(res == 2);

    // Test_2
    nums = { 555, 901, 482, 1771 };
    res = sol.findNumbers(nums);
    cout << "Test_2: " << res << endl;  // Expected output: 1
    assert(res == 1);

    return 0;
}
// Accepted
// 105/105 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 99.22 % of cpp submissions (13.2 MB)