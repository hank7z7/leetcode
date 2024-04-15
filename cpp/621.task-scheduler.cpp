/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 *
 * https://leetcode.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (58.31%)
 * Likes:    9733
 * Dislikes: 1994
 * Total Accepted:    545.3K
 * Total Submissions: 928.1K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * You are given an array of CPU tasks, each represented by letters A to Z, and
 * a cooling time, n. Each cycle or interval allows the completion of one task.
 * Tasks can be completed in any order, but there's a constraint: identical
 * tasks must be separated by at least n intervals due to cooling time.
 *
 * ​Return the minimum number of intervals required to complete all tasks.
 *
 *
 * Example 1:
 *
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 *
 * Output: 8
 *
 * Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A
 * -> B.
 *
 * After completing task A, you must wait two cycles before doing A again. The
 * same applies to task B. In the 3^rd interval, neither A nor B can be done,
 * so you idle. By the 4^th cycle, you can do A again as 2 intervals have
 * passed.
 *
 *
 * Example 2:
 *
 *
 * Input: tasks = ["A","C","A","B","D","B"], n = 1
 *
 * Output: 6
 *
 * Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.
 *
 * With a cooling interval of 1, you can repeat a task after just one other
 * task.
 *
 *
 * Example 3:
 *
 *
 * Input: tasks = ["A","A","A", "B","B","B"], n = 3
 *
 * Output: 10
 *
 * Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B ->
 * idle -> idle -> A -> B.
 *
 * There are only two types of tasks, A and B, which need to be separated by 3
 * intervals. This leads to idling twice between repetitions of these
 * tasks.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= tasks.length <= 10^4
 * tasks[i] is an uppercase English letter.
 * 0 <= n <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int leastInterval(vector<char>& tasks, int n)
    {
        // Hash Map of task name to number of task
        unordered_map<char, int> um;
        for (auto task : tasks)
        {
            um[task]++;
        }

        int count = 0;
        priority_queue<int> pq;
        for (auto count : um)
        {
            pq.push(count.second);
        }

        while (!pq.empty())
        {
            vector<int> window;
            int pop_out = min((int) pq.size(), (n + 1));
            for (int i = 1; i <= pop_out; i++)
            {
                if ((pq.top() - 1) > 0)
                {
                    window.push_back(pq.top() - 1);
                }
                // cout << "pop out: " << pq.top() << endl;
                pq.pop();
            }
            for (int i = 0; i < (int) window.size(); i++)
            {
                pq.push(window[i]);
            }
            if (pq.empty())
                count += pop_out;
            else
                count += (n + 1);
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      n = 0;
    // Test_1
    vector<char> tasks_1 = { 'A', 'A', 'A', 'B', 'B', 'B' };
    n                    = 2;
    cout << sol.leastInterval(tasks_1, n) << endl;

    // Test_2
    vector<char> tasks_2 = { 'A', 'C', 'A', 'B', 'D', 'B' };
    n                    = 1;
    cout << sol.leastInterval(tasks_2, n) << endl;

    // Test_3
    vector<char> tasks_3 = { 'A', 'A', 'A', 'B', 'B', 'B' };
    n                    = 3;
    cout << sol.leastInterval(tasks_3, n) << endl;
    return 0;
}
// Accepted
// 71/71 cases passed (87 ms)
// Your runtime beats 37.59 % of cpp submissions
// Your memory usage beats 19.11 % of cpp submissions (47.5 MB)