/*
 * @lc app=leetcode id=3191 lang=cpp
 *
 * [3191] Minimum Operations to Make Binary Array Elements Equal to One I
 *
 * https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-i/description/
 *
 * algorithms
 * Medium (66.08%)
 * Likes:    3
 * Dislikes: 0
 * Total Accepted:    24.3K
 * Total Submissions: 36.7K
 * Testcase Example:  '[0,1,1,1,0,0]'
 *
 * You are given a binary array nums.
 *
 * You can do the following operation on the array any number of times
 * (possibly zero):
 *
 *
 * Choose any 3 consecutive elements from the array and flip all of them.
 *
 *
 * Flipping an element means changing its value from 0 to 1, and from 1 to 0.
 *
 * Return the minimum number of operations required to make all elements in
 * nums equal to 1. If it is impossible, return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1,1,1,0,0]
 *
 * Output: 3
 *
 * Explanation:
 * We can do the following operations:
 *
 *
 * Choose the elements at indices 0, 1 and 2. The resulting array is nums =
 * [1,0,0,1,0,0].
 * Choose the elements at indices 1, 2 and 3. The resulting array is nums =
 * [1,1,1,0,0,0].
 * Choose the elements at indices 3, 4 and 5. The resulting array is nums =
 * [1,1,1,1,1,1].
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1,1]
 *
 * Output: -1
 *
 * Explanation:
 * It is impossible to make all elements equal to 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= nums.length <= 10^5
 * 0 <= nums[i] <= 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = (int)nums.size();
        int flips = 0;

        // Iterate over the array up to the third last element
        for (int i = 0; i <= n - 3; ++i)
        {
            if (nums[i] == 0)
            {
                // Flip the current element and the next two elements
                for (int j = i; j < i + 3; ++j)
                {
                    nums[j] = 1 - nums[j]; // Flip the element
                }
                flips++;
            }
        }

        // Check the last two elements
        for (int i = n - 2; i < n; ++i)
        {
            if (nums[i] == 0)
            {
                return -1; // It's impossible to make all elements 1
            }
        }

        return flips;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {0, 1, 1, 1, 0, 0};
    int res_1 = sol.minOperations(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<int> nums_2 = {0, 1, 1, 1};
    int res_2 = sol.minOperations(nums_2);
    cout << res_2 << endl;
    assert(res_2 == -1);

    return 0;
}
// Accepted
// 689/689 cases passed (112 ms)
// Your runtime beats 60 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (138.2 MB)