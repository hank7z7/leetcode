/*
 * @lc app=leetcode id=874 lang=cpp
 *
 * [874] Walking Robot Simulation
 *
 * https://leetcode.com/problems/walking-robot-simulation/description/
 *
 * algorithms
 * Medium (40.57%)
 * Likes:    504
 * Dislikes: 127
 * Total Accepted:    82.6K
 * Total Submissions: 163.7K
 * Testcase Example:  '[4,-1,3]\n[]'
 *
 * A robot on an infinite XY-plane starts at point (0, 0) facing north. The
 * robot can receive a sequence of these three possible types of
 * commands:
 *
 *
 * -2: Turn left 90 degrees.
 * -1: Turn right 90 degrees.
 * 1 <= k <= 9: Move forward k units, one unit at a time.
 *
 *
 * Some of the grid squares are obstacles. The i^th obstacle is at grid point
 * obstacles[i] = (xi, yi). If the robot runs into an obstacle, then it will
 * instead stay in its current location and move on to the next command.
 *
 * Return the maximum Euclidean distance that the robot ever gets from the
 * origin squared (i.e. if the distance is 5, return 25).
 *
 * Note:
 *
 *
 * North means +Y direction.
 * East means +X direction.
 * South means -Y direction.
 * West means -X direction.
 * There can be obstacle in [0,0].
 *
 *
 *
 * Example 1:
 *
 *
 * Input: commands = [4,-1,3], obstacles = []
 * Output: 25
 * Explanation: The robot starts at (0, 0):
 * 1. Move north 4 units to (0, 4).
 * 2. Turn right.
 * 3. Move east 3 units to (3, 4).
 * The furthest point the robot ever gets from the origin is (3, 4), which
 * squared is 3^2 + 4^2 = 25 units away.
 *
 *
 * Example 2:
 *
 *
 * Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
 * Output: 65
 * Explanation: The robot starts at (0, 0):
 * 1. Move north 4 units to (0, 4).
 * 2. Turn right.
 * 3. Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at
 * (1, 4).
 * 4. Turn left.
 * 5. Move north 4 units to (1, 8).
 * The furthest point the robot ever gets from the origin is (1, 8), which
 * squared is 1^2 + 8^2 = 65 units away.
 *
 *
 * Example 3:
 *
 *
 * Input: commands = [6,-1,-1,6], obstacles = []
 * Output: 36
 * Explanation: The robot starts at (0, 0):
 * 1. Move north 6 units to (0, 6).
 * 2. Turn right.
 * 3. Turn right.
 * 4. Move south 6 units to (0, 0).
 * The furthest point the robot ever gets from the origin is (0, 6), which
 * squared is 6^2 = 36 units away.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= commands.length <= 10^4
 * commands[i] is either -2, -1, or an integer in the range [1, 9].
 * 0 <= obstacles.length <= 10^4
 * -3 * 10^4 <= xi, yi <= 3 * 10^4
 * The answer is guaranteed to be less than 2^31.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct pair_hash {
    template <class T1, class T2>
    size_t operator () (const pair<T1, T2>& p) const {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);
        return h1 ^ (h2 << 1); // or use boost::hash_combine
    }
};

class Solution
{
private:
    // {x, y}
    // North, East, South, West
    const vector<vector<int>> direction = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };

public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles)
    {
        unordered_set<pair<int, int>, pair_hash> obstacle_set;
        for (auto obstacle : obstacles)
        {
            obstacle_set.insert({ obstacle[0], obstacle[1] });
        }

        int max_d  = 0;
        int curr_x = 0, curr_y = 0;
        int curr_dir = 0;  // Initialize to North
        for (auto cmd : commands)
        {
            // Turn left
            if (cmd == -2)
            {
                curr_dir = (curr_dir + 3) % 4;
                continue;
            }

            // Turn right
            if (cmd == -1)
            {
                curr_dir = (curr_dir + 1) % 4;
                continue;
            }

            // Go forward
            for (int i = 0; i < cmd; i++)
            {
                int next_x = curr_x + direction[curr_dir][0];
                int next_y = curr_y + direction[curr_dir][1];
                // If next grid is an obstacle, stop
                if (obstacle_set.find({ next_x, next_y }) != obstacle_set.end())
                    break;

                // Update current position
                curr_y = next_y;
                curr_x = next_x;

                // Calculate Euclidean distance
                max_d = max(max_d, curr_x * curr_x + curr_y * curr_y);
            }
        }
        return max_d;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int>         cmd_1      = { 4, -1, 3 };
    vector<vector<int>> obstacle_1 = {};
    int                 res_1      = sol.robotSim(cmd_1, obstacle_1);
    cout << res_1 << endl;
    assert(res_1 == 25);

    // Test_2
    vector<int>         cmd_2      = { 4, -1, 4, -2, 4 };
    vector<vector<int>> obstacle_2 = { { 2, 4 } };
    int                 res_2      = sol.robotSim(cmd_2, obstacle_2);
    cout << res_2 << endl;
    assert(res_2 == 65);

    // Test_3
    vector<int>         cmd_3      = { 6, -1, -1, 6 };
    vector<vector<int>> obstacle_3 = {};
    int                 res_3      = sol.robotSim(cmd_3, obstacle_3);
    cout << res_3 << endl;
    assert(res_3 == 36);

    return 0;
}
// Accepted
// 49/49 cases passed (79 ms)
// Your runtime beats 56.63 % of cpp submissions
// Your memory usage beats 43.65 % of cpp submissions (40 MB)