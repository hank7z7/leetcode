/*
 * @lc app=leetcode id=3447 lang=cpp
 *
 * [3447] Assign Elements to Groups with Constraints
 *
 * https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/
 *
 * algorithms
 * Medium (22.62%)
 * Likes:    55
 * Dislikes: 6
 * Total Accepted:    11.9K
 * Total Submissions: 52.6K
 * Testcase Example:  '[8,4,3,2,4]\n[4,2]'
 *
 * You are given an integer array groups, where groups[i] represents the size
 * of the i^th group. You are also given an integer array elements.
 *
 * Your task is to assign one element to each group based on the following
 * rules:
 *
 *
 * An element j can be assigned to a group i if groups[i] is divisible by
 * elements[j].
 * If there are multiple elements that can be assigned, assign the element with
 * the smallest index j.
 * If no element satisfies the condition for a group, assign -1 to that
 * group.
 *
 *
 * Return an integer array assigned, where assigned[i] is the index of the
 * element chosen for group i, or -1 if no suitable element exists.
 *
 * Note: An element may be assigned to more than one group.
 *
 *
 * Example 1:
 *
 *
 * Input: groups = [8,4,3,2,4], elements = [4,2]
 *
 * Output: [0,0,-1,1,0]
 *
 * Explanation:
 *
 *
 * elements[0] = 4 is assigned to groups 0, 1, and 4.
 * elements[1] = 2 is assigned to group 3.
 * Group 2 cannot be assigned any element.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: groups = [2,3,5,7], elements = [5,3,3]
 *
 * Output: [-1,1,0,-1]
 *
 * Explanation:
 *
 *
 * elements[1] = 3 is assigned to group 1.
 * elements[0] = 5 is assigned to group 2.
 * Groups 0 and 3 cannot be assigned any element.
 *
 *
 *
 * Example 3:
 *
 *
 * Input: groups = [10,21,30,41], elements = [2,1]
 *
 * Output: [0,1,0,1]
 *
 * Explanation:
 *
 * elements[0] = 2 is assigned to the groups with even values, and elements[1]
 * = 1 is assigned to the groups with odd values.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= groups.length <= 10^5
 * 1 <= elements.length <= 10^5
 * 1 <= groups[i] <= 10^5
 * 1 <= elements[i] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> assignElements(vector<int> &groups, vector<int> &elements)
    {
        // element -> first index
        unordered_map<int, int> um;
        const int elem_n = (int)elements.size();
        for (int i = 0; i < elem_n; i++)
            if (um.find(elements[i]) == um.end())
                um[elements[i]] = i;

        const int group_n = (int)groups.size();
        vector<int> res(group_n, INT_MAX);
        // group -> its assigned value
        unordered_map<int, int> um2;
        for (int i = 0; i < group_n; i++)
        {
            if (um2.find(groups[i]) != um2.end())
            {
                res[i] = um2[groups[i]];
                continue;
            }
            // cout << groups[i] << endl;
            for (int j = 1; j * j <= groups[i]; j++)
            {
                if (groups[i] % j != 0)
                    continue;
                if (um.find(j) != um.end())
                    res[i] = min(res[i], um[j]);
                if (um.find(groups[i] / j) != um.end())
                    res[i] = min(res[i], um[groups[i] / j]);
            }
            // cout << endl;
            if (res[i] == INT_MAX)
                res[i] = -1;
            else
                um2[groups[i]] = res[i];
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> groups_1 = {8, 4, 3, 2, 4};
    vector<int> elements_1 = {4, 2};
    vector<int> res_1 = sol.assignElements(groups_1, elements_1);
    res_1 = sol.assignElements(groups_1, elements_1);
    for (auto &elem : res_1)
        cout << elem << " ";
    cout << endl;
    assert((res_1 == vector<int>{0, 0, -1, 1, 0}));

    // Test_2
    vector<int> groups_2 = {2, 3, 5, 7};
    vector<int> elements_2 = {5, 3, 3};
    vector<int> res_2 = sol.assignElements(groups_2, elements_2);
    res_2 = sol.assignElements(groups_2, elements_2);
    for (auto &elem : res_2)
        cout << elem << " ";
    cout << endl;
    assert((res_2 == vector<int>{-1, 1, 0, -1}));

    // Test_3
    vector<int> groups_3 = {10, 21, 30, 41};
    vector<int> elements_3 = {2, 1};
    vector<int> res_3 = sol.assignElements(groups_3, elements_3);
    res_3 = sol.assignElements(groups_3, elements_3);
    for (auto &elem : res_3)
        cout << elem << " ";
    cout << endl;
    assert((res_3 == vector<int>{0, 1, 0, 1}));

    return 0;
}
// Accepted
// 572/572 cases passed (899 ms)
// Your runtime beats 42.1 % of cpp submissions
// Your memory usage beats 26.32 % of cpp submissions (302 MB)