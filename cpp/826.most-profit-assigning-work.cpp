/*
 * @lc app=leetcode id=826 lang=cpp
 *
 * [826] Most Profit Assigning Work
 *
 * https://leetcode.com/problems/most-profit-assigning-work/description/
 *
 * algorithms
 * Medium (46.43%)
 * Likes:    2024
 * Dislikes: 160
 * Total Accepted:    140.6K
 * Total Submissions: 265.1K
 * Testcase Example:  '[2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]'
 *
 * You have n jobs and m workers. You are given three arrays: difficulty,
 * profit, and worker where:
 *
 *
 * difficulty[i] and profit[i] are the difficulty and the profit of the i^th
 * job, and
 * worker[j] is the ability of j^th worker (i.e., the j^th worker can only
 * complete a job with difficulty at most worker[j]).
 *
 *
 * Every worker can be assigned at most one job, but one job can be completed
 * multiple times.
 *
 *
 * For example, if three workers atjobst the same job that pays $1, then the
 * total profit will be $3. If a worker cannot complete any job, their profit
 * is $0.
 *
 *
 * Return the maximum profit we can achieve after assigning the workers to the
 * jobs.
 *
 *
 * Example 1:
 *
 *
 * Input: difficulty = [2,4,6,8,10], profit = [10,20,30,40,50], worker =
 * [4,5,6,7]
 * Output: 100
 * Explanation: Workers are assigned jobs of difficulty [4,4,6,6] and they get
 * a profit of [20,20,30,30] separately.
 *
 *
 * Example 2:
 *
 *
 * Input: difficulty = [85,47,57], profit = [24,66,99], worker = [40,25,25]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * n == difficulty.length
 * n == profit.length
 * m == worker.length
 * 1 <= n, m <= 10^4
 * 1 <= difficulty[i], profit[i], worker[i] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int res = 0, j = 0, best = 0;
        vector<pair<int, int>> jobs;
        for (int i = 0; i < worker.size(); ++i)
        {
            jobs.push_back({difficulty[i], profit[i]});
        }

        sort(begin(jobs), end(jobs));
        sort(begin(worker), end(worker));
        for (int work : worker)
        {
            while (work >= jobs[j].first && j < worker.size())
            {
                best = max(best, jobs[j++].second);
            }

            res += best;
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> difficulty_1 = {2, 4, 6, 8, 10};
    vector<int> profit_1 = {10, 20, 30, 40, 50};
    vector<int> worker_1 = {4, 5, 6, 7};
    int result_1 = sol.maxProfitAssignment(difficulty_1, profit_1, worker_1);
    cout << result_1 << endl;
    assert(result_1 == 100);

    // Test_2
    vector<int> difficulty_2 = {85, 47, 57};
    vector<int> profit_2 = {24, 66, 99};
    vector<int> worker_2 = {40, 25, 25};
    int result_2 = sol.maxProfitAssignment(difficulty_2, profit_2, worker_2);
    cout << result_2 << endl;
    assert(result_2 == 0);

    return 0;
}
