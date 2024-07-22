/*
 * @lc app=leetcode id=2418 lang=cpp
 *
 * [2418] Sort the People
 *
 * https://leetcode.com/problems/sort-the-people/description/
 *
 * algorithms
 * Easy (80.11%)
 * Likes:    1434
 * Dislikes: 25
 * Total Accepted:    186K
 * Total Submissions: 225.1K
 * Testcase Example:  '["Mary","John","Emma"]\n[180,165,170]'
 *
 * You are given an array of strings names, and an array heights that consists
 * of distinct positive integers. Both arrays are of length n.
 *
 * For each index i, names[i] and heights[i] denote the name and height of the
 * i^th person.
 *
 * Return names sorted in descending order by the people's heights.
 *
 *
 * Example 1:
 *
 *
 * Input: names = ["Mary","John","Emma"], heights = [180,165,170]
 * Output: ["Mary","Emma","John"]
 * Explanation: Mary is the tallest, followed by Emma and John.
 *
 *
 * Example 2:
 *
 *
 * Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
 * Output: ["Bob","Alice","Bob"]
 * Explanation: The first Bob is the tallest, followed by Alice and the second
 * Bob.
 *
 *
 *
 * Constraints:
 *
 *
 * n == names.length == heights.length
 * 1 <= n <= 10^3
 * 1 <= names[i].length <= 20
 * 1 <= heights[i] <= 10^5
 * names[i] consists of lower and upper case English letters.
 * All the values of heights are distinct.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights)
    {
        vector<int> idx(names.size());
        for (int i = 0; i < (int) names.size(); ++i)
        {
            idx[i] = i;
        }
        sort(idx.begin(),
             idx.end(),
             [&heights](const int& i, const int& j) { return heights[i] > heights[j]; });
        vector<string> res(names.size());
        for (int i = 0; i < (int) names.size(); ++i)
        {
            res[i] = names[idx[i]];
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<string> names_1   = { "Mary", "John", "Emma" };
    vector<int>    heights_1 = { 180, 165, 170 };
    vector<string> res_1     = sol.sortPeople(names_1, heights_1);
    for (auto name : names_1)
        cout << name << " ";
    cout << endl;
    assert((res_1 == vector<string>{ "Mary", "Emma", "John" }));

    // Test_2
    vector<string> names_2   = { "Alice", "Bob", "Bob" };
    vector<int>    heights_2 = { 155, 185, 150 };
    vector<string> res_2     = sol.sortPeople(names_2, heights_2);
    for (auto name : names_2)
        cout << name << " ";
    cout << endl;
    assert((res_2 == vector<string>{ "Bob", "Alice", "Bob" }));

    return 0;
}
// Accepted
// 68/68 cases passed (30 ms)
// Your runtime beats 55.87 % of cpp submissions
// Your memory usage beats 84.98 % of cpp submissions (22.7 MB)