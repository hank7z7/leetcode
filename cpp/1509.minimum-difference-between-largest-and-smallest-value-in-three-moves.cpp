/*
 * @lc app=leetcode id=1509 lang=cpp
 *
 * [1509] Minimum Difference Between Largest and Smallest Value in Three Moves
 *
 * https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/
 *
 * algorithms
 * Medium (55.06%)
 * Likes:    2254
 * Dislikes: 249
 * Total Accepted:    176.6K
 * Total Submissions: 307K
 * Testcase Example:  '[5,3,2,4]'
 *
 * You are given an integer array nums.
 *
 * In one move, you can choose one element of nums and change it to any value.
 *
 * Return the minimum difference between the largest and smallest value of nums
 * after performing at most three moves.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [5,3,2,4]
 * Output: 0
 * Explanation: We can make at most 3 moves.
 * In the first move, change 2 to 3. nums becomes [5,3,3,4].
 * In the second move, change 4 to 3. nums becomes [5,3,3,3].
 * In the third move, change 5 to 3. nums becomes [3,3,3,3].
 * After performing 3 moves, the difference between the minimum and maximum is
 * 3 - 3 = 0.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,5,0,10,14]
 * Output: 1
 * Explanation: We can make at most 3 moves.
 * In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
 * In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
 * In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
 * After performing 3 moves, the difference between the minimum and maximum is
 * 1 - 0 = 1.
 * It can be shown that there is no way to make the difference 0 in 3 moves.
 *
 * Example 3:
 *
 *
 * Input: nums = [3,100,20]
 * Output: 0
 * Explanation: We can make at most 3 moves.
 * In the first move, change 100 to 7. nums becomes [3,7,20].
 * In the second move, change 20 to 7. nums becomes [3,7,7].
 * In the third move, change 3 to 7. nums becomes [7,7,7].
 * After performing 3 moves, the difference between the minimum and maximum is
 * 7 - 7 = 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define TIME (3)
class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        if ((int)nums.size() <= 4)
        {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int k = (int)nums.size() - 3;
        int ans = nums.back() - nums[0];
        for (int i = k - 1; i < (int)nums.size(); i++)
        {
            ans = min(ans, nums[i] - nums[i - k + 1]);
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {5, 3, 2, 4};
    int res_1 = sol.minDifference(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 0);

    // Test_2
    vector<int> nums_2 = {1, 5, 0, 10, 14};
    int res_2 = sol.minDifference(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 1);

    // Test_3
    vector<int> nums_3 = {3, 100, 20};
    int res_3 = sol.minDifference(nums_3);
    cout << res_3 << endl;
    assert(res_3 == 0);

    return 0;
}
