/*
 * @lc app=leetcode id=1942 lang=cpp
 *
 * [1942] The Number of the Smallest Unoccupied Chair
 *
 * https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/
 *
 * algorithms
 * Medium (42.42%)
 * Likes:    759
 * Dislikes: 36
 * Total Accepted:    32.7K
 * Total Submissions: 65.1K
 * Testcase Example:  '[[1,4],[2,3],[4,6]]\n1'
 *
 * There is a party where n friends numbered from 0 to n - 1 are attending.
 * There is an infinite number of chairs in this party that are numbered from 0
 * to infinity. When a friend arrives at the party, they sit on the unoccupied
 * chair with the smallest number.
 *
 *
 * For example, if chairs 0, 1, and 5 are occupied when a friend comes, they
 * will sit on chair number 2.
 *
 *
 * When a friend leaves the party, their chair becomes unoccupied at the moment
 * they leave. If another friend arrives at that same moment, they can sit in
 * that chair.
 *
 * You are given a 0-indexed 2D integer array times where times[i] = [arrivali,
 * leavingi], indicating the arrival and leaving times of the i^th friend
 * respectively, and an integer targetFriend. All arrival times are distinct.
 *
 * Return the chair number that the friend numbered targetFriend will sit
 * on.
 *
 *
 * Example 1:
 *
 *
 * Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
 * Output: 1
 * Explanation:
 * - Friend 0 arrives at time 1 and sits on chair 0.
 * - Friend 1 arrives at time 2 and sits on chair 1.
 * - Friend 1 leaves at time 3 and chair 1 becomes empty.
 * - Friend 0 leaves at time 4 and chair 0 becomes empty.
 * - Friend 2 arrives at time 4 and sits on chair 0.
 * Since friend 1 sat on chair 1, we return 1.
 *
 *
 * Example 2:
 *
 *
 * Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
 * Output: 2
 * Explanation:
 * - Friend 1 arrives at time 1 and sits on chair 0.
 * - Friend 2 arrives at time 2 and sits on chair 1.
 * - Friend 0 arrives at time 3 and sits on chair 2.
 * - Friend 1 leaves at time 5 and chair 0 becomes empty.
 * - Friend 2 leaves at time 6 and chair 1 becomes empty.
 * - Friend 0 leaves at time 10 and chair 2 becomes empty.
 * Since friend 0 sat on chair 2, we return 2.
 *
 *
 *
 * Constraints:
 *
 *
 * n == times.length
 * 2 <= n <= 10^4
 * times[i].length == 2
 * 1 <= arrivali < leavingi <= 10^5
 * 0 <= targetFriend <= n - 1
 * Each arrivali time is distinct.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
};

class Solution
{
public:
    int smallestChair(const vector<vector<int>> &times, const int &targetFriend)
    {
        const int n = (int)times.size();

        vector<int> index(n);
        iota(index.begin(), index.end(), 0);

        sort(index.begin(),
             index.end(),
             [&times](const int &a, const int &b)
             { return times[a][0] < times[b][0]; });

        priority_queue<int, vector<int>, greater<>> chair; // Empty charis
        chair.push(0);                                     // Chair 0 is empty when start
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> release;

        for (auto &i : index)
        {
            // cout << endl
            //  << "arrival: " << times[i][0] << ", leave: " << times[i][1] << endl;
            // Release chairs and push into empty chairs
            // if(!release.empty())
            //     cout << "release top: " << release.top().first << endl;
            while (!release.empty() && release.top().first <= times[i][0])
            {
                // cout << "pop out release chair: " << release.top().second << endl;
                chair.push(release.top().second);
                release.pop();
            }

            // Find the occupy num
            int occupy = chair.top();
            chair.pop();

            if (i == targetFriend)
                return occupy;

            if (chair.empty())
                chair.push(occupy + 1);
            // cout << "occupy " << occupy << endl;
            // Push {leave time, chair num}
            release.push({times[i][1], occupy});
        }

        // Should not reach here
        return -1;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<int>> times_1 = {{1, 4}, {2, 3}, {4, 6}};
    int target_1 = 1;
    int res_1 = sol.smallestChair(times_1, target_1);
    cout << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    vector<vector<int>> times_2 = {{3, 10}, {1, 5}, {2, 6}};
    int target_2 = 0;
    int res_2 = sol.smallestChair(times_2, target_2);
    cout << res_2 << endl;
    assert(res_2 == 2);

    // Test_3
    vector<vector<int>> times_3 = {{33889, 98676}, {80071, 89737}, {44118, 52565}, {52992, 84310}, {78492, 88209}, {21695, 67063}, {84622, 95452}, {98048, 98856}, {98411, 99433}, {55333, 56548}, {65375, 88566}, {55011, 62821}, {48548, 48656}, {87396, 94825}, {55273, 81868}, {75629, 91467}};
    int target_3 = 6;
    int res_3 = sol.smallestChair(times_3, target_3);
    cout << res_3 << endl;
    assert(res_3 == 2);

    return 0;
}
// Accepted
// 65/65 cases passed (141 ms)
// Your runtime beats 71.48 % of cpp submissions
// Your memory usage beats 92.44 % of cpp submissions (56 MB)