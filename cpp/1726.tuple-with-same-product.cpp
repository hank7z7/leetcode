/*
 * @lc app=leetcode id=1726 lang=cpp
 *
 * [1726] Tuple with Same Product
 *
 * https://leetcode.com/problems/tuple-with-same-product/description/
 *
 * algorithms
 * Medium (61.23%)
 * Likes:    1043
 * Dislikes: 49
 * Total Accepted:    109.1K
 * Total Submissions: 160.3K
 * Testcase Example:  '[2,3,4,6]'
 *
 * Given an array nums of distinct positive integers, return the number of
 * tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are
 * elements of nums, and a != b != c != d.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,4,6]
 * Output: 8
 * Explanation: There are 8 valid tuples:
 * (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
 * (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,4,5,10]
 * Output: 16
 * Explanation: There are 16 valid tuples:
 * (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
 * (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
 * (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
 * (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 1000
 * 1 <= nums[i] <= 10^4
 * All elements in nums are distinct.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int tupleSameProduct(const vector<int>& nums)
    {
        // product -> count
        unordered_map<int, int> um;
        const int n = (int) nums.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int product = nums[i] * nums[j];
                um[product]++;
            }
        }
        for (auto& [product, count] : um)
            if (count >= 2)
                res += (count - 1) * count * 4;

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 2, 3, 4, 6 };
    int res_1 = sol.tupleSameProduct(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 8);

    // Test_2
    vector<int> nums_2 = { 1, 2, 4, 5, 10 };
    int res_2 = sol.tupleSameProduct(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 16);

    return 0;
}
// Accepted
// 37/37 cases passed (344 ms)
// Your runtime beats 30.72 % of cpp submissions
// Your memory usage beats 67.71 % of cpp submissions (84.9 MB)