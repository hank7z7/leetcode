/*
 * @lc app=leetcode id=502 lang=cpp
 *
 * [502] IPO
 *
 * https://leetcode.com/problems/ipo/description/
 *
 * algorithms
 * Hard (49.52%)
 * Likes:    3410
 * Dislikes: 218
 * Total Accepted:    165.6K
 * Total Submissions: 325.3K
 * Testcase Example:  '2\n0\n[1,2,3]\n[0,1,1]'
 *
 * Suppose LeetCode will start its IPO soon. In order to sell a good price of
 * its shares to Venture Capital, LeetCode would like to work on some projects
 * to increase its capital before the IPO. Since it has limited resources, it
 * can only finish at most k distinct projects before the IPO. Help LeetCode
 * design the best way to maximize its total capital after finishing at most k
 * distinct projects.
 *
 * You are given n projects where the i^th project has a pure profit profits[i]
 * and a minimum capital of capital[i] is needed to start it.
 *
 * Initially, you have w capital. When you finish a project, you will obtain
 * its pure profit and the profit will be added to your total capital.
 *
 * Pick a list of at most k distinct projects from given projects to maximize
 * your final capital, and return the final maximized capital.
 *
 * The answer is guaranteed to fit in a 32-bit signed integer.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
 * Output: 4
 * Explanation: Since your initial capital is 0, you can only start the project
 * indexed 0.
 * After finishing it you will obtain profit 1 and your capital becomes 1.
 * With capital 1, you can either start the project indexed 1 or the project
 * indexed 2.
 * Since you can choose at most 2 projects, you need to finish the project
 * indexed 2 to get the maximum capital.
 * Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
 * Output: 6
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= 10^5
 * 0 <= w <= 10^9
 * n == profits.length
 * n == capital.length
 * 1 <= n <= 10^5
 * 0 <= profits[i] <= 10^4
 * 0 <= capital[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<vector<int>> projects;
        for (int i = 0; i < (int)profits.size(); i++)
        {
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());
        priority_queue<int> maxHeap;
        for (int i = 0; i < (int)projects.size(); i++)
        {
            if (w >= projects[i][0])
            {
                maxHeap.push(projects[i][1]);
            }
            else if (k > 0 && (int)maxHeap.size() > 0)
            {
                k--;
                i--;
                w += maxHeap.top();
                maxHeap.pop();
            }
        }

        while ((int)maxHeap.size() > 0 && k > 0)
        {
            w += maxHeap.top();
            maxHeap.pop();
            k--;
        }
        return w;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int k_1 = 2, w_1 = 0;
    vector<int> profits_1 = {1, 2, 3};
    vector<int> capital_1 = {0, 1, 1};
    int result_1 = sol.findMaximizedCapital(k_1, w_1, profits_1, capital_1);
    cout << result_1 << endl;
    assert(result_1 == 4);

    // Test_2
    int k_2 = 3, w_2 = 0;
    vector<int> profits_2 = {1, 2, 3};
    vector<int> capital_2 = {0, 1, 2};
    int result_2 = sol.findMaximizedCapital(k_2, w_2, profits_2, capital_2);
    cout << result_2 << endl;
    assert(result_2 == 6);

    return 0;
}
