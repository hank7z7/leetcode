/*
 * @lc app=leetcode id=2134 lang=cpp
 *
 * [2134] Minimum Swaps to Group All 1's Together II
 *
 * https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/
 *
 * algorithms
 * Medium (65.50%)
 * Likes:    1966
 * Dislikes: 40
 * Total Accepted:    157.7K
 * Total Submissions: 240.6K
 * Testcase Example:  '[0,1,0,1,1,0,0]'
 *
 * A swap is defined as taking two distinct positions in an array and swapping
 * the values in them.
 *
 * A circular array is defined as an array where we consider the first element
 * and the last element to be adjacent.
 *
 * Given a binary circular array nums, return the minimum number of swaps
 * required to group all 1's present in the array together at any location.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [0,1,0,1,1,0,0]
 * Output: 1
 * Explanation: Here are a few of the ways to group all the 1's together:
 * [0,0,1,1,1,0,0] using 1 swap.
 * [0,1,1,1,0,0,0] using 1 swap.
 * [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
 * There is no way to group all 1's together with 0 swaps.
 * Thus, the minimum number of swaps required is 1.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,1,1,1,0,0,1,1,0]
 * Output: 2
 * Explanation: Here are a few of the ways to group all the 1's together:
 * [1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the
 * array).
 * [1,1,1,1,1,0,0,0,0] using 2 swaps.
 * There is no way to group all 1's together with 0 or 1 swaps.
 * Thus, the minimum number of swaps required is 2.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,0,0,1]
 * Output: 0
 * Explanation: All the 1's are already grouped together due to the circular
 * property of the array.
 * Thus, the minimum number of swaps required is 0.
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
class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        const int n = (int)nums.size();
        int one_count = 0;
        for (auto &num : nums)
            if (num == 1)
                one_count++;

        // WA (initialize to one_count instead of INT_MAX)
        int res = one_count;
        int curr_ones = 0;
        for (int i = 0; i < (n + one_count - 1); i++)
        {
            if (nums[i % n] == 1)
                curr_ones++;
            if (i >= one_count && nums[i - one_count] == 1)
                curr_ones--;
            if (i >= (one_count - 1))
            {
                res = min(res, (one_count - curr_ones));
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {0, 1, 0, 1, 1, 0, 0};
    int res_1 = sol.minSwaps(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    vector<int> nums_2 = {0, 1, 1, 1, 0, 0, 1, 1, 0};
    int res_2 = sol.minSwaps(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    // Test_3
    vector<int> nums_3 = {1, 1, 0, 0, 1};
    int res_3 = sol.minSwaps(nums_3);
    cout << res_3 << endl;
    assert(res_3 == 0);

    // Test_4
    vector<int> nums_4 = {0};
    int res_4 = sol.minSwaps(nums_4);
    cout << res_4 << endl;
    assert(res_4 == 0);

    return 0;
}
// Accepted
// 63/63 cases passed (56 ms)
// Your runtime beats 91.98 % of cpp submissions
// Your memory usage beats 41.86 % of cpp submissions (83.2 MB)