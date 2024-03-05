/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (44.65%)
 * Likes:    7615
 * Dislikes: 971
 * Total Accepted:    465.4K
 * Total Submissions: 1M
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a
 * row.
 *
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 *
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 *
 *
 * Example 1:
 *
 *
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 *
 *
 * Example 2:
 *
 *
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 *
 *
 * Example 3:
 *
 *
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    bool is_collision(int x, int y)
    {
        if (x > 0 && y < 0)
            return true;
        else
            return false;
    }

public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> st;
        for (auto asteroid : asteroids)
        {
            int asteroid_size = abs(asteroid);
            if (st.empty() || !is_collision(st.top(), asteroid))
                st.push(asteroid);
            else
            {
                if (st.top() > asteroid_size) {}
                else
                {
                    bool explode = false;
                    while (!st.empty() && is_collision(st.top(), asteroid)
                           && st.top() <= asteroid_size)
                    {
                        if (st.top() == asteroid_size)
                        {
                            explode = true;
                            st.pop();
                            break;
                        }
                        st.pop();
                    }
                    if (!st.empty() && st.top() > asteroid_size)
                        explode = true;
                    if (!explode)
                        st.push(asteroid);
                }
            }
        }
        vector<int> ret(st.size());
        for (int i = (int) st.size() - 1; i >= 0; i--)
        {
            ret[i] = st.top();
            st.pop();
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> asteroids_1 = { 5, 10, -5 };
    for (auto it : sol.asteroidCollision(asteroids_1))
        cout << it << " ";
    cout << endl;

    // Test_2
    vector<int> asteroids_2 = { 8, -8 };
    for (auto it : sol.asteroidCollision(asteroids_2))
        cout << it << " ";
    cout << endl;

    // Test_3
    vector<int> asteroids_3 = { 10, 2, -5 };
    for (auto it : sol.asteroidCollision(asteroids_3))
        cout << it << " ";
    cout << endl;

    // Test_4
    vector<int> asteroids_4 = { -2, -1, 1, 2 };
    for (auto it : sol.asteroidCollision(asteroids_4))
        cout << it << " ";
    cout << endl;

    // Test_5
    vector<int> asteroids_5 = { -2, -2, 1, -2 };
    for (auto it : sol.asteroidCollision(asteroids_5))
        cout << it << " ";
    cout << endl;

    // Test_6
    vector<int> asteroids_6 = { 10, 2, -5 };
    for (auto it : sol.asteroidCollision(asteroids_6))
        cout << it << " ";
    cout << endl;

    // Test_7
    vector<int> asteroids_7 = { -2, 2, 1, -2 };
    for (auto it : sol.asteroidCollision(asteroids_7))
        cout << it << " ";
    cout << endl;


    // Test_8
    vector<int> asteroids_8 = { 1, -2, -2, -2 };
    for (auto it : sol.asteroidCollision(asteroids_8))
        cout << it << " ";
    cout << endl;

    return 0;
}
// Accepted
// 275/275 cases passed (8 ms)
// Your runtime beats 75.89 % of cpp submissions
// Your memory usage beats 12.44 % of cpp submissions (20.8 MB)