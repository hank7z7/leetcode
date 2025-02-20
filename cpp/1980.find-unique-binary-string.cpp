/*
 * @lc app=leetcode id=1980 lang=cpp
 *
 * [1980] Find Unique Binary String
 *
 * https://leetcode.com/problems/find-unique-binary-string/description/
 *
 * algorithms
 * Medium (74.69%)
 * Likes:    2199
 * Dislikes: 81
 * Total Accepted:    198.8K
 * Total Submissions: 257.9K
 * Testcase Example:  '["01","10"]'
 *
 * Given an array of strings nums containing n unique binary strings each of
 * length n, return a binary string of length n that does not appear in nums.
 * If there are multiple answers, you may return any of them.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = ["01","10"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "00" would also be correct.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = ["00","01"]
 * Output: "11"
 * Explanation: "11" does not appear in nums. "10" would also be correct.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = ["111","011","001"]
 * Output: "101"
 * Explanation: "101" does not appear in nums. "000", "010", "100", and "110"
 * would also be correct.
 *
 *
 *
 * Constraints:
 *
 *
 * n == nums.length
 * 1 <= n <= 16
 * nums[i].length == n
 * nums[i] is either '0' or '1'.
 * All the strings of nums are unique.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string findDifferentBinaryString(vector<string>& nums)
    {
        unordered_set<string> us(nums.begin(), nums.end());
        const int n = (int) nums.size();
        for (int i = 0; i <= (1 << n) - 1; i++)
        {
            // Convert integer i to a binary string in lenght of n
            string s = bitset<16>(i).to_string().substr(16 - n);
            if (us.find(s) == us.end())
                return s;
        }
        // Should not reach here
        return "";
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<string> nums_1 = { "01", "10" };
    string res_1 = sol.findDifferentBinaryString(nums_1);
    cout << res_1 << endl;
    assert((res_1 == "00"));

    // Test_2
    vector<string> nums_2 = { "00", "01" };
    string res_2 = sol.findDifferentBinaryString(nums_2);
    cout << res_2 << endl;
    assert((res_2 == "10"));

    // Test_3
    vector<string> nums_3 = { "111", "011", "001" };
    string res_3 = sol.findDifferentBinaryString(nums_3);
    cout << res_3 << endl;
    assert((res_3 == "000"));

    return 0;
}
// Accepted
// 184/184 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 55.88 % of cpp submissions (12.9 MB)