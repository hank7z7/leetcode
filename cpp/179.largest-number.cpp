/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 *
 * https://leetcode.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (36.76%)
 * Likes:    8488
 * Dislikes: 712
 * Total Accepted:    561.9K
 * Total Submissions: 1.5M
 * Testcase Example:  '[10,2]'
 *
 * Given a list of non-negative integers nums, arrange them such that they form
 * the largest number and return it.
 *
 * Since the result may be very large, so you need to return a string instead
 * of an integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,2]
 * Output: "210"
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,30,34,5,9]
 * Output: "9534330"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string largestNumber(vector<int>& nums)
    {
        vector<string> num_str;
        for (auto num : nums)
            num_str.push_back(to_string(num));
        sort(num_str.begin(),
             num_str.end(),
             [](const string& a, const string& b)
             { return (a + b) > (b + a); });
        string res;
        bool leading_zero = true;
        for (size_t i = 0; i < num_str.size(); i++)
        {
            string str = num_str[i];
            if (str != "0")
                leading_zero = false;
            if (!leading_zero || i == num_str.size() - 1)
                res += str;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 10, 2 };
    string res_1 = sol.largestNumber(nums_1);
    cout << res_1 << endl;
    assert(res_1 == "210");

    // Test_2
    vector<int> nums_2 = { 3, 30, 34, 5, 9 };
    string res_2 = sol.largestNumber(nums_2);
    cout << res_2 << endl;
    assert(res_2 == "9534330");

    // Test_3
    vector<int> nums_3 = { 999999991, 9 };
    string res_3 = sol.largestNumber(nums_3);
    cout << res_3 << endl;
    assert(res_3 == "9999999991");

    // Test_4
    vector<int> nums_4 = { 0, 0 };
    string res_4 = sol.largestNumber(nums_4);
    cout << res_4 << endl;
    assert(res_4 == "0");
}
// Accepted
// 233/233 cases passed (7 ms)
// Your runtime beats 61.31 % of cpp submissions
// Your memory usage beats 55.19 % of cpp submissions (17.2 MB)