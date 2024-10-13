/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range Covering Elements from K Lists
 *
 * https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
 *
 * algorithms
 * Hard (63.41%)
 * Likes:    3843
 * Dislikes: 86
 * Total Accepted:    159.9K
 * Total Submissions: 236.6K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in non-decreasing order. Find the
 * smallest range that includes at least one number from each of the k lists.
 *
 * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or
 * a < c if b - a == d - c.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
 * Output: [20,24]
 * Explanation:
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
 * Output: [1,1]
 *
 *
 *
 * Constraints:
 *
 *
 * nums.length == k
 * 1 <= k <= 3500
 * 1 <= nums[i].length <= 50
 * -10^5 <= nums[i][j] <= 10^5
 * nums[i] is sorted in non-decreasing order.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        const int nums_n = (int)nums.size();
        // {num, index of origin array in nums}
        vector<pair<int, int>> arr;
        for(int i = 0; i < nums_n; i++)
        {
            const int num_i_size = (int)nums[i].size();
            for(int j = 0; j < num_i_size; j++)
                arr.push_back({nums[i][j], i});
        }

        // Sort new array
        sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            return a.first < b.first;
        });

        int target_l = 0, target_r = 0;
        int l = 0, r = 0;
        vector<int> from(nums_n, 0);
        int total_from = 0;
        int min_range = INT_MAX;
        // Sliding window
        const int arr_size = (int)arr.size();
        for(r = 0; r < arr_size; r++)
        {
            if(from[arr[r].second] == 0)
                total_from++;
            from[arr[r].second]++;
            // cout << "num " << arr[r].first << endl;
            // cout << "add count " << arr[r].second << endl;
            // cout << "totoal count " << total_from << endl;
            // This range is valid
            while(total_from == nums_n)
            {
                // Update if it is a smaller range
                if((arr[r].first - arr[l].first) < min_range)
                {
                    min_range = arr[r].first - arr[l].first;
                    target_l = arr[l].first;
                    target_r = arr[r].first;
                    // cout << "update l: " << target_l << ", r: " << target_r << endl;
                }

                // Move left
                from[arr[l].second]--;
                if(from[arr[l].second] == 0)
                    total_from--;
                // cout << "remove " << arr[l].second << " become " << from[arr[l].second] << endl;
                l++;
            }
        }
        vector<int> res(2);
        res[0] = target_l;
        res[1] = target_r;
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> nums_1 = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    vector<int> res_1 = sol.smallestRange(nums_1);
    cout << res_1[0] << ", " << res_1[1] << endl;
    assert((res_1 == vector<int>{20, 24}));

    // Test_2
    vector<vector<int>> nums_2 = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    vector<int> res_2 = sol.smallestRange(nums_2);
    cout << res_2[0] << ", " << res_2[1] << endl;
    assert((res_2 == vector<int>{1, 1}));

    return 0;
}
// Accepted
// 99/99 cases passed (28 ms)
// Your runtime beats 99.25 % of cpp submissions
// Your memory usage beats 60.18 % of cpp submissions (21.7 MB)