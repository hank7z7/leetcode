/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 *
 * https://leetcode.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (54.77%)
 * Likes:    10671
 * Dislikes: 307
 * Total Accepted:    1.1M
 * Total Submissions: 1.9M
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * Given a collection of candidate numbers (candidates) and a target number
 * (target), find all unique combinations in candidates where the candidate
 * numbers sum to target.
 *
 * Each number in candidates may only be used once in the combination.
 *
 * Note: The solution set must not contain duplicate combinations.
 *
 *
 * Example 1:
 *
 *
 * Input: candidates = [10,1,2,7,6,1,5], target = 8
 * Output:
 * [
 * [1,1,6],
 * [1,2,5],
 * [1,7],
 * [2,6]
 * ]
 *
 *
 * Example 2:
 *
 *
 * Input: candidates = [2,5,2,1,2], target = 5
 * Output:
 * [
 * [1,2,2],
 * [5]
 * ]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    void combination2(vector<vector<int>>& res,
                      vector<int>&         combination,
                      vector<int>&         candidates,
                      int                  target,
                      int                  index)
    {
        if (target == 0)
        {
            res.push_back(combination);
            return;
        }
        for (int i = index; i < candidates.size() && target >= candidates[i]; ++i)
        {
            if (i == index || candidates[i] != candidates[i - 1])
            {
                combination.push_back(candidates[i]);
                combination2(res, combination, candidates, target - candidates[i], i + 1);
                combination.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int>         combination;
        combination2(result, combination, candidates, target, 0);
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int>         candidates_1 = { 10, 1, 2, 7, 6, 1, 5 };
    int                 target_1     = 8;
    vector<vector<int>> res_1        = sol.combinationSum2(candidates_1, target_1);
    cout << "[";
    for (auto& row : res_1)
    {
        cout << "[";
        for (int i = 0; i < (int) row.size(); i++)
            cout << row[i] << (i < ((int) row.size() - 1) ? " " : "");
        cout << "]";
    }
    cout << "]" << endl;
    assert((res_1 == vector<vector<int>>{ { 1, 1, 6 }, { 1, 2, 5 }, { 1, 7 }, { 2, 6 } }));

    // Test_2
    vector<int>         candidates_2 = { 2, 5, 2, 1, 2 };
    int                 target_2     = 5;
    vector<vector<int>> res_2        = sol.combinationSum2(candidates_2, target_2);
    cout << "[";
    for (auto& row : res_2)
    {
        cout << "[";
        for (int i = 0; i < (int) row.size(); i++)
            cout << row[i] << (i < ((int) row.size() - 1) ? " " : "");
        cout << "]";
    }
    cout << "]" << endl;
    assert((res_2 == vector<vector<int>>{ { 1, 2, 2 }, { 5 } }));

    return 0;
}
