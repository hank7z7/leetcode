/*
 * @lc app=leetcode id=2092 lang=cpp
 *
 * [2092] Find All People With Secret
 *
 * https://leetcode.com/problems/find-all-people-with-secret/description/
 *
 * algorithms
 * Hard (34.24%)
 * Likes:    1491
 * Dislikes: 74
 * Total Accepted:    89.9K
 * Total Submissions: 194.5K
 * Testcase Example:  '6\n[[1,2,5],[2,3,8],[1,5,10]]\n1'
 *
 * You are given an integer n indicating there are n people numbered from 0 to
 * n - 1. You are also given a 0-indexed 2D integer array meetings where
 * meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a
 * meeting at timei. A person may attend multiple meetings at the same time.
 * Finally, you are given an integer firstPerson.
 *
 * Person 0 has a secret and initially shares the secret with a person
 * firstPerson at time 0. This secret is then shared every time a meeting takes
 * place with a person that has the secret. More formally, for every meeting,
 * if a person xi has the secret at timei, then they will share the secret with
 * person yi, and vice versa.
 *
 * The secrets are shared instantaneously. That is, a person may receive the
 * secret and share it with people in other meetings within the same time
 * frame.
 *
 * Return a list of all the people that have the secret after all the meetings
 * have taken place. You may return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
 * Output: [0,1,2,3,5]
 * Explanation:
 * At time 0, person 0 shares the secret with person 1.
 * At time 5, person 1 shares the secret with person 2.
 * At time 8, person 2 shares the secret with person 3.
 * At time 10, person 1 shares the secret with person 5.​​​​
 * Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
 * Output: [0,1,3]
 * Explanation:
 * At time 0, person 0 shares the secret with person 3.
 * At time 2, neither person 1 nor person 2 know the secret.
 * At time 3, person 3 shares the secret with person 0 and person 1.
 * Thus, people 0, 1, and 3 know the secret after all the meetings.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
 * Output: [0,1,2,3,4]
 * Explanation:
 * At time 0, person 0 shares the secret with person 1.
 * At time 1, person 1 shares the secret with person 2, and person 2 shares the
 * secret with person 3.
 * Note that person 2 can share the secret at the same time as receiving it.
 * At time 2, person 3 shares the secret with person 4.
 * Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 10^5
 * 1 <= meetings.length <= 10^5
 * meetings[i].length == 3
 * 0 <= xi, yi <= n - 1
 * xi != yi
 * 1 <= timei <= 10^5
 * 1 <= firstPerson <= n - 1
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define PERSON_1 (0)
#define PERSON_2 (1)
#define TIME (2)
#pragma GCC optimize("O3", "unroll-loops")
class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson)
    {
        // Hash from "Time" to an "Connection List"
        map<int, vector<pair<int, int>>> mp;
        vector<bool>                     know_secret(n, false);
        know_secret[0]           = true;
        know_secret[firstPerson] = true;
        for (auto meet : meetings)
        {
            mp[meet[TIME]].push_back(pair<int, int>(meet[PERSON_1], meet[PERSON_2]));
        }
        for (auto it_mp : mp)
        {
            // Build graph
            unordered_map<int, vector<int>> graph;  // Adjancency list
            unordered_set<int>              st;     // Know secret set
            for (auto connect : it_mp.second)
            {
                graph[connect.first].push_back(connect.second);
                graph[connect.second].push_back(connect.first);
                if (know_secret[connect.first])
                    st.insert(connect.first);
                if (know_secret[connect.second])
                    st.insert(connect.second);
            }

            // BFS
            queue<int> q;

            // Initialize the queue with people already know the secret
            for (auto& known : st)
                q.push(known);

            // Search all connection till the queue is empty
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();

                for (auto& be_shared : graph[curr])
                {
                    if (!know_secret[be_shared])
                    {
                        know_secret[be_shared] = true;
                        q.push(be_shared);
                    }
                }
            }
        }

        vector<int> ret;
        for (size_t i = 0; i < know_secret.size(); i++)
            if (know_secret[i])
                ret.push_back(i);
        return ret;
    }
};

// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      n, firstPerson;
    // Test_1
    n                              = 6;
    firstPerson                    = 1;
    vector<vector<int>> meetings_1 = { { 1, 2, 5 }, { 2, 3, 8 }, { 1, 5, 10 } };
    for (auto it : sol.findAllPeople(n, meetings_1, firstPerson))
        cout << it << " ";
    cout << endl;

    // Test_2
    n                              = 4;
    firstPerson                    = 3;
    vector<vector<int>> meetings_2 = { { 3, 1, 3 }, { 1, 2, 2 }, { 0, 3, 3 } };
    for (auto it : sol.findAllPeople(n, meetings_2, firstPerson))
        cout << it << " ";
    cout << endl;

    // Test_3
    n                              = 5;
    firstPerson                    = 1;
    vector<vector<int>> meetings_3 = { { 3, 4, 2 }, { 1, 2, 1 }, { 2, 3, 1 } };
    for (auto it : sol.findAllPeople(n, meetings_3, firstPerson))
        cout << it << " ";
    cout << endl;

    // Test_3
    n                              = 11;
    firstPerson                    = 1;
    vector<vector<int>> meetings_4 = { { 5, 1, 4 }, { 0, 4, 18 } };
    for (auto it : sol.findAllPeople(n, meetings_4, firstPerson))
        cout << it << " ";
    cout << endl;

    return 0;
}
// Accepted
// 55/55 cases passed (791 ms)
// Your runtime beats 21.12 % of cpp submissions
// Your memory usage beats 9.95 % of cpp submissions (392.2 MB)