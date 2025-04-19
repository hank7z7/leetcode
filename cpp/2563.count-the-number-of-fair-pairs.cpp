/*
 * @lc app=leetcode id=2563 lang=cpp
 *
 * [2563] Count the Number of Fair Pairs
 *
 * https://leetcode.com/problems/count-the-number-of-fair-pairs/description/
 *
 * algorithms
 * Medium (48.76%)
 * Likes:    1873
 * Dislikes: 138
 * Total Accepted:    204.7K
 * Total Submissions: 391.2K
 * Testcase Example:  '[0,1,7,4,4,5]\n3\n6'
 *
 * Given a 0-indexed integer array nums of size n and two integers lower and
 * upper, return the number of fair pairs.
 * 
 * A pair (i, j) is fair if:
 * 
 * 
 * 0 <= i < j < n, and
 * lower <= nums[i] + nums[j] <= upper
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
 * Output: 6
 * Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and
 * (1,5).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,7,9,2,5], lower = 11, upper = 11
 * Output: 1
 * Explanation: There is a single fair pair: (2,3).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums.length == n
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= lower <= upper <= 10^9
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        const int n = (int)nums.size();

        // Sort the array
        sort(nums.begin(), nums.end());
        for(auto num : nums)
            cout << num << " ";
        cout << endl;

        long long ans = 0;
        // Two pointers
        for (int i = 0; i < n; ++i) {
            // Find the first index where nums[i] + nums[j] > upper
            // in the right of i
            int r = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            // Find the first index where nums[i] + nums[j] >= lower
            // in the right of i
            int l = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            // cout << l << " " << r << endl;

            // Count the number of valid pairs
            ans += r - l;

        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums = {0, 1, 7, 4, 4, 5};
    int lower = 3;
    int upper = 6;
    long long res = sol.countFairPairs(nums, lower, upper);
    cout << "Test_1: " << res << endl; // Expected output: 6
    assert(res == 6);

    // Test_2
    nums = {1, 7, 9, 2, 5};
    lower = 11;
    upper = 11;
    res = sol.countFairPairs(nums, lower, upper);
    cout << "Test_2: " << res << endl; // Expected output: 1
    assert(res == 1);

    // Test_3
    nums = {0, 0, 0, 0, 0, 0};
    lower = 0;
    upper = 0;
    res = sol.countFairPairs(nums, lower, upper);
    cout << "Test_3: " << res << endl; // Expected output: 15
    assert(res == 15);

    // Test_4
    nums = {-2,-6,4,0,-1000000000,-1000000000,-1000000000,-1000000000};
    lower = -15;
    upper = 15;
    res = sol.countFairPairs(nums, lower, upper);
    cout << "Test_4: " << res << endl; // Expected output: 6
    assert(res == 6);

    return 0;
}
