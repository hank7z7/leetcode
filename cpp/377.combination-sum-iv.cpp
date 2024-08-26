/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 *
 * https://leetcode.com/problems/combination-sum-iv/description/
 *
 * algorithms
 * Medium (54.26%)
 * Likes:    7414
 * Dislikes: 664
 * Total Accepted:    501.2K
 * Total Submissions: 923.7K
 * Testcase Example:  '[1,2,3]\n4'
 *
 * Given an array of distinct integers nums and a target integer target, return
 * the number of possible combinations that add up to target.
 *
 * The test cases are generated so that the answer can fit in a 32-bit
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3], target = 4
 * Output: 7
 * Explanation:
 * The possible combination ways are:
 * (1, 1, 1, 1)
 * (1, 1, 2)
 * (1, 2, 1)
 * (1, 3)
 * (2, 1, 1)
 * (2, 2)
 * (3, 1)
 * Note that different sequences are counted as different combinations.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [9], target = 3
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 200
 * 1 <= nums[i] <= 1000
 * All the elements of nums are unique.
 * 1 <= target <= 1000
 *
 *
 *
 * Follow up: What if negative numbers are allowed in the given array? How does
 * it change the problem? What limitation we need to add to the question to
 * allow negative numbers?
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        int n = (int) nums.size();
        sort(nums.begin(), nums.end());

        vector<unsigned long long> dp(target + 1, 0);
        for (int i = 1; i <= target; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int prev = i - nums[j];
                if (prev < 0)
                    break;
                // cout << "prev = " << prev << endl;
                // Create a new combination
                if (prev == 0)
                {
                    dp[i]++;
                }
                dp[i] += dp[prev];
            }
            // cout << "dp[" << i << "]" << endl;
            // for(auto vec : dp[i])
            // {
            //     for(auto it : vec)
            //         cout << it << " ";
            //     cout << endl;
            // }
            // cout << endl;
        }

        return (int) dp[target];
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1   = { 1, 2, 3 };
    int         target_1 = 4;
    int         res_1    = sol.combinationSum4(nums_1, target_1);
    cout << res_1 << endl;
    assert(res_1 == 7);

    // Test_2
    vector<int> nums_2   = { 9 };
    int         target_2 = 3;
    int         res_2    = sol.combinationSum4(nums_2, target_2);
    cout << res_2 << endl;
    assert(res_2 == 0);

    // Test_3 (WA)
    vector<int> nums_3
        = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25 };
    int target_3 = 10;
    int res_3    = sol.combinationSum4(nums_3, target_3);
    cout << res_3 << endl;
    assert(res_3 == 9);

    // Test_4 (MLE)
    vector<int> nums_4   = { 4, 2, 1 };
    int         target_4 = 32;
    int         res_4    = sol.combinationSum4(nums_4, target_4);
    cout << res_4 << endl;
    assert(res_4 == 39882198);

    // Test_5 (UB)
    vector<int> nums_5
        = { 10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130, 140, 150, 160, 170,
            180, 190, 200, 210, 220, 230, 240, 250, 260, 270, 280, 290, 300, 310, 320, 330, 340,
            350, 360, 370, 380, 390, 400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510,
            520, 530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650, 660, 670, 680,
            690, 700, 710, 720, 730, 740, 750, 760, 770, 780, 790, 800, 810, 820, 830, 840, 850,
            860, 870, 880, 890, 900, 910, 920, 930, 940, 950, 960, 970, 980, 990, 111 };
    int target_5 = 999;
    int res_5    = sol.combinationSum4(nums_5, target_5);
    cout << res_5 << endl;
    assert(res_5 == 1);

    return 0;
}
// Accepted
// 16/16 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 20.45 % of cpp submissions (8.4 MB)