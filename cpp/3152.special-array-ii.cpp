/*
 * @lc app=leetcode id=3152 lang=cpp
 *
 * [3152] Special Array II
 *
 * https://leetcode.com/problems/special-array-ii/description/
 *
 * algorithms
 * Medium (30.04%)
 * Likes:    364
 * Dislikes: 30
 * Total Accepted:    52.7K
 * Total Submissions: 143.5K
 * Testcase Example:  '[3,4,1,2,6]\n[[0,4]]'
 *
 * An array is considered special if every pair of its adjacent elements
 * contains two numbers with different parity.
 * 
 * You are given an array of integer nums and a 2D integer matrix queries,
 * where for queries[i] = [fromi, toi] your task is to check that subarray
 * nums[fromi..toi] is special or not.
 * 
 * Return an array of booleans answer such that answer[i] is true if
 * nums[fromi..toi] is special.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,4,1,2,6], queries = [[0,4]]
 * 
 * Output: [false]
 * 
 * Explanation:
 * 
 * The subarray is [3,4,1,2,6]. 2 and 6 are both even.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
 * 
 * Output: [false,true]
 * 
 * Explanation:
 * 
 * 
 * The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query
 * is false.
 * The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers
 * with different parity. So the answer to this query is true.
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * 1 <= queries.length <= 10^5
 * queries[i].length == 2
 * 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<bool> isArraySpecial(const vector<int>& nums, const vector<vector<int>>& queries) {
        const int m = (int)nums.size();
        vector<int> max_reach(m, 0);
        int last = 0;
        for(int i = 0; i < m; i++)
        {
            if(i == m - 1 || (nums[i] & 1) == (nums[i + 1] & 1)) // Same parity
            {
                for(int j = last; j <= i; j++)
                    max_reach[j] = i;
                last = i + 1;
            }
        }
        
        // for(auto reach : max_reach)
        //     cout << reach << " ";
        // cout << endl;

        vector<bool> res;
        for(auto querie : queries)
            if(max_reach[querie[0]] < querie[1])
                res.push_back(false);
            else
                res.push_back(true);
        
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {4, 3, 1, 6};
    vector<vector<int>> queries_1 = {{0, 2}, {2, 3}};
    vector<bool> res_1 = sol.isArraySpecial(nums_1, queries_1);
    for(auto ans : res_1)
        cout << ans << " ";
    cout << endl;
    assert((res_1 == vector<bool>{false, true}));

    // Test_2
    vector<int> nums_2 = {3, 4, 1, 2, 6};
    vector<vector<int>> queries_2 = {{0, 4}};
    vector<bool> res_2 = sol.isArraySpecial(nums_2, queries_2);
    for(auto ans : res_2)
        cout << ans << " ";
    cout << endl;
    assert((res_2 == vector<bool>{false}));

    return 0;
}
// Accepted
// 536/536 cases passed (41 ms)
// Your runtime beats 40.63 % of cpp submissions
// Your memory usage beats 22.19 % of cpp submissions (136.5 MB)