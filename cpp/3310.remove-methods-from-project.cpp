/*
 * @lc app=leetcode id=3310 lang=cpp
 *
 * [3310] Remove Methods From Project
 *
 * https://leetcode.com/problems/remove-methods-from-project/description/
 *
 * algorithms
 * Medium (42.96%)
 * Likes:    15
 * Dislikes: 9
 * Total Accepted:    10.4K
 * Total Submissions: 24.3K
 * Testcase Example:  '4\n1\n[[1,2],[0,1],[3,2]]'
 *
 * You are maintaining a project that has n methods numbered from 0 to n - 1.
 *
 * You are given two integers n and k, and a 2D integer array invocations,
 * where invocations[i] = [ai, bi] indicates that method ai invokes method bi.
 *
 * There is a known bug in method k. Method k, along with any method invoked by
 * it, either directly or indirectly, are considered suspicious and we aim to
 * remove them.
 *
 * A group of methods can only be removed if no method outside the group
 * invokes any methods within it.
 *
 * Return an array containing all the remaining methods after removing all the
 * suspicious methods. You may return the answer in any order. If it is not
 * possible to remove all the suspicious methods, none should be removed.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
 *
 * Output: [0,1,2,3]
 *
 * Explanation:
 *
 *
 *
 * Method 2 and method 1 are suspicious, but they are directly invoked by
 * methods 3 and 0, which are not suspicious. We return all elements without
 * removing anything.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]
 *
 * Output: [3,4]
 *
 * Explanation:
 *
 *
 *
 * Methods 0, 1, and 2 are suspicious and they are not directly invoked by any
 * other method. We can remove them.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]
 *
 * Output: []
 *
 * Explanation:
 *
 *
 *
 * All methods are suspicious. We can remove them.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^5
 * 0 <= k <= n - 1
 * 0 <= invocations.length <= 2 * 10^5
 * invocations[i] == [ai, bi]
 * 0 <= ai, bi <= n - 1
 * ai != bi
 * invocations[i] != invocations[j]
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        set<int> suspicious;
        unordered_map<int, vector<int>> invoke;
        for (auto invocation : invocations)
            invoke[invocation[0]].push_back(invocation[1]);

        // DFS
        unordered_set<int> visited;
        stack<int> st;
        st.push(k);
        while (!st.empty())
        {
            int curr = st.top();
            // cout << "visit " << curr << endl;
            visited.insert(curr);
            st.pop();
            for (auto it : invoke[curr])
                if (visited.find(it) == visited.end())
                    st.push(it);
        }

        bool is_invoked = false;
        for (auto invocation : invocations)
        {
            if ((visited.find(invocation[0]) == visited.end()) && (visited.find(invocation[1]) != visited.end()))
            {
                is_invoked = true;
                break;
            }
        }
        // cout << "is invoked: " << is_invoked << endl;
        vector<int> res;
        for (int i = 0; i < n; i++)
            if (is_invoked)
                res.push_back(i);
            else if (visited.find(i) == visited.end())
                res.push_back(i);
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int n_1 = 4, k_1 = 1;
    vector<vector<int>> invocations_1 = {{1, 2}, {0, 1}, {3, 2}};
    vector<int> res_1 = sol.remainingMethods(n_1, k_1, invocations_1);
    for (auto res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{0, 1, 2, 3}));

    // Test_2
    int n_2 = 5, k_2 = 0;
    vector<vector<int>> invocations_2 = {{1, 2}, {0, 2}, {0, 1}, {3, 4}};
    vector<int> res_2 = sol.remainingMethods(n_2, k_2, invocations_2);
    for (auto res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{3, 4}));

    // Test_3
    int n_3 = 3, k_3 = 2;
    vector<vector<int>> invocations_3 = {{1, 2}, {0, 1}, {2, 0}};
    vector<int> res_3 = sol.remainingMethods(n_3, k_3, invocations_3);
    for (auto res : res_3)
        cout << res << " ";
    cout << endl;
    assert((res_3 == vector<int>{}));

    return 0;
}
// Accepted
// 774/774 cases passed (1072 ms)
// Your runtime beats 8.33 % of cpp submissions
// Your memory usage beats 8.33 % of cpp submissions (382.1 MB)