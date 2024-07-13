/*
 * @lc app=leetcode id=2751 lang=cpp
 *
 * [2751] Robot Collisions
 *
 * https://leetcode.com/problems/robot-collisions/description/
 *
 * algorithms
 * Hard (40.76%)
 * Likes:    546
 * Dislikes: 38
 * Total Accepted:    23K
 * Total Submissions: 46.1K
 * Testcase Example:  '[5,4,3,2,1]\n[2,17,9,15,10]\n"RRRRR"'
 *
 * There are n 1-indexed robots, each having a position on a line, health, and
 * movement direction.
 *
 * You are given 0-indexed integer arrays positions, healths, and a string
 * directions (directions[i] is either 'L' for left or 'R' for right). All
 * integers in positions are unique.
 *
 * All robots start moving on the line simultaneously at the same speed in
 * their given directions. If two robots ever share the same position while
 * moving, they will collide.
 *
 * If two robots collide, the robot with lower health is removed from the line,
 * and the health of the other robot decreases by one. The surviving robot
 * continues in the same direction it was going. If both robots have the same
 * health, they are both removed from the line.
 *
 * Your task is to determine the health of the robots that survive the
 * collisions, in the same order that the robots were given, i.e. final heath
 * of robot 1 (if survived), final health of robot 2 (if survived), and so on.
 * If there are no survivors, return an empty array.
 *
 * Return an array containing the health of the remaining robots (in the order
 * they were given in the input), after no further collisions can occur.
 *
 * Note: The positions may be unsorted.
 *
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions =
 * "RRRRR"
 * Output: [2,17,9,15,10]
 * Explanation: No collision occurs in this example, since all robots are
 * moving in the same direction. So, the health of the robots in order from the
 * first robot is returned, [2, 17, 9, 15, 10].
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
 * Output: [14]
 * Explanation: There are 2 collisions in this example. Firstly, robot 1 and
 * robot 2 will collide, and since both have the same health, they will be
 * removed from the line. Next, robot 3 and robot 4 will collide and since
 * robot 4's health is smaller, it gets removed, and robot 3's health becomes
 * 15 - 1 = 14. Only robot 3 remains, so we return [14].
 *
 *
 * Example 3:
 *
 *
 *
 *
 * Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
 * Output: []
 * Explanation: Robot 1 and robot 2 will collide and since both have the same
 * health, they are both removed. Robot 3 and 4 will collide and since both
 * have the same health, they are both removed. So, we return an empty array,
 * [].
 *
 *
 * Constraints:
 *
 *
 * 1 <= positions.length == healths.length == directions.length == n <=
 * 10^5
 * 1 <= positions[i], healths[i] <= 10^9
 * directions[i] == 'L' or directions[i] == 'R'
 * All values in positions are distinct
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        int n = (int)positions.size();
        vector<vector<int>> robots;

        for (int i = 0; i < n; i++)
        {
            int direction = (directions[i] == 'L' ? 0 : 1);
            // pos, helth remain, dir, index
            robots.push_back({positions[i], healths[i], direction, i});
        }

        sort(robots.begin(), robots.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        stack<vector<int>> st;

        for (auto robot : robots)
        {
            if (st.empty())
                st.push(robot);
            else
            {
                bool curr_out = false;
                while ((!st.empty() && st.top()[2] == 1 && robot[2] == 0))
                {
                    if (st.top()[1] == robot[1])
                    {
                        curr_out = true;
                        st.pop();
                        break;
                    }
                    else if (st.top()[1] < robot[1])
                    {
                        st.pop();
                        robot[1]--;
                    }
                    else if (st.top()[1] > robot[1])
                    {
                        curr_out = true;
                        st.top()[1]--;
                        break;
                    }
                }
                if (!curr_out)
                    st.push(robot);
            }
        }

        vector<vector<int>> remains;
        vector<int> res;
        while (!st.empty())
        {
            // Store the remain health and origin index
            remains.push_back({st.top()[1], st.top()[3]});
            st.pop();
        }
        sort(remains.begin(), remains.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });
        for (auto remain : remains)
        {
            res.push_back(remain[0]);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> pos_1 = {5, 4, 3, 2, 1};
    vector<int> health_1 = {2, 17, 9, 15, 10};
    string dir_1 = "RRRRR";
    vector<int> res_1 = sol.survivedRobotsHealths(pos_1, health_1, dir_1);
    for (auto res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{2, 17, 9, 15, 10}));

    // Test_2
    vector<int> pos_2 = {3, 5, 2, 6};
    vector<int> health_2 = {10, 10, 15, 12};
    string dir_2 = "RLRL";
    vector<int> res_2 = sol.survivedRobotsHealths(pos_2, health_2, dir_2);
    for (auto res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{14}));

    // Test_3
    vector<int> pos_3 = {1, 2, 5, 6};
    vector<int> health_3 = {10, 10, 11, 11};
    string dir_3 = "RLRL";
    vector<int> res_3 = sol.survivedRobotsHealths(pos_3, health_3, dir_3);
    for (auto res : res_3)
        cout << res << " ";
    cout << endl;
    assert((res_3 == vector<int>{}));

    return 0;
}
// Accepted
// 2433/2433 cases passed (557 ms)
// Your runtime beats 9.63 % of cpp submissions
// Your memory usage beats 6.29 % of cpp submissions (316.7 MB)