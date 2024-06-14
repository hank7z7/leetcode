/*
 * @lc app=leetcode id=945 lang=cpp
 *
 * [945] Minimum Increment to Make Array Unique
 *
 * https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/
 *
 * algorithms
 * Medium (52.33%)
 * Likes:    2051
 * Dislikes: 66
 * Total Accepted:    125.6K
 * Total Submissions: 225.9K
 * Testcase Example:  '[1,2,2]'
 *
 * You are given an integer array nums. In one move, you can pick an index i
 * where 0 <= i < nums.length and increment nums[i] by 1.
 *
 * Return the minimum number of moves to make every value in nums unique.
 *
 * The test cases are generated so that the answer fits in a 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,2]
 * Output: 1
 * Explanation: After 1 move, the array could be [1, 2, 3].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,1,2,1,7]
 * Output: 6
 * Explanation: After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
 * It can be shown with 5 or less moves that it is impossible for the array to
 * have all unique values.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 0 <= nums[i] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minIncrementForUnique(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int        prev = -1;
        int        curr = 0;
        queue<int> duplicate;
        int        result = 0;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            curr = nums[i];
            if (curr == prev)
            {
                // Find a dulplicated num to be increased
                duplicate.push(curr);
            }
            else
            {
                // Find slot for increment
                for (int j = prev + 1; j < curr; j++)
                {
                    if (!duplicate.empty())
                    {
                        result += (j - duplicate.front());
                        duplicate.pop();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            prev = nums[i];
        }

        // Increase the remain duplicate elements
        int slot = nums[nums.size() - 1] + 1;
        while (!duplicate.empty())
        {
            result += (slot - duplicate.front());
            duplicate.pop();
            slot++;
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1   = { 1, 2, 2 };
    int         result_1 = sol.minIncrementForUnique(nums_1);
    cout << result_1 << endl;
    assert(result_1 == 1);

    // Test_2
    vector<int> nums_2   = { 1, 2, 2 };
    int         result_2 = sol.minIncrementForUnique(nums_2);
    cout << result_2 << endl;
    assert(result_2 == 1);

    // Test_3
    vector<int> nums_3   = { 1, 1, 2, 0 };
    int         result_3 = sol.minIncrementForUnique(nums_3);
    cout << result_3 << endl;
    assert(result_3 == 2);

    return 0;
}
// Accepted
// 63/63 cases passed (113 ms)
// Your runtime beats 78.54 % of cpp submissions
// Your memory usage beats 20.67 % of cpp submissions (70.3 MB)