/*
 * @lc app=leetcode id=2211 lang=cpp
 *
 * [2211] Count Collisions on a Road
 *
 * https://leetcode.com/problems/count-collisions-on-a-road/description/
 *
 * algorithms
 * Medium (44.64%)
 * Likes:    866
 * Dislikes: 255
 * Total Accepted:    64K
 * Total Submissions: 123K
 * Testcase Example:  '"RLRSLL"'
 *
 * There are n cars on an infinitely long road. The cars are numbered from 0 to
 * n - 1 from left to right and each car is present at a unique point.
 *
 * You are given a 0-indexed string directions of length n. directions[i] can
 * be either 'L', 'R', or 'S' denoting whether the i^th car is moving towards
 * the left, towards the right, or staying at its current point respectively.
 * Each moving car has the same speed.
 *
 * The number of collisions can be calculated as follows:
 *
 *
 * When two cars moving in opposite directions collide with each other, the
 * number of collisions increases by 2.
 * When a moving car collides with a stationary car, the number of collisions
 * increases by 1.
 *
 *
 * After a collision, the cars involved can no longer move and will stay at the
 * point where they collided. Other than that, cars cannot change their state
 * or direction of motion.
 *
 * Return the total number of collisions that will happen on the road.
 *
 *
 * Example 1:
 *
 *
 * Input: directions = "RLRSLL"
 * Output: 5
 * Explanation:
 * The collisions that will happen on the road are:
 * - Cars 0 and 1 will collide with each other. Since they are moving in
 * opposite directions, the number of collisions becomes 0 + 2 = 2.
 * - Cars 2 and 3 will collide with each other. Since car 3 is stationary, the
 * number of collisions becomes 2 + 1 = 3.
 * - Cars 3 and 4 will collide with each other. Since car 3 is stationary, the
 * number of collisions becomes 3 + 1 = 4.
 * - Cars 4 and 5 will collide with each other. After car 4 collides with car
 * 3, it will stay at the point of collision and get hit by car 5. The number
 * of collisions becomes 4 + 1 = 5.
 * Thus, the total number of collisions that will happen on the road is 5.
 *
 *
 * Example 2:
 *
 *
 * Input: directions = "LLRR"
 * Output: 0
 * Explanation:
 * No cars will collide with each other. Thus, the total number of collisions
 * that will happen on the road is 0.
 *
 *
 * Constraints:
 *
 *
 * 1 <= directions.length <= 10^5
 * directions[i] is either 'L', 'R', or 'S'.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countCollisions(string directions)
    {
        stack<char> st;
        int collisions = 0;
        for (char dir : directions)
        {
            if (dir == 'L')
            {
                if (st.empty())
                {
                    st.push(dir);
                }
                else if (!st.empty() && st.top() == 'L')
                {
                    st.push(dir);
                }
                else if (!st.empty() && st.top() == 'S')
                {
                    collisions++;
                }
                else if (!st.empty() && st.top() == 'R')
                {
                    collisions += 2;
                    st.pop();
                    while (!st.empty() && st.top() == 'R')
                    {
                        collisions++;
                        st.pop();
                    }
                    st.push('S');
                }
            }
            else if (dir == 'S')
            {
                if (!st.empty() && st.top() == 'R')
                {
                    while (!st.empty() && st.top() == 'R')
                    {
                        collisions++;
                        st.pop();
                    }
                    st.push('S');
                }
                else
                {
                    st.push('S');
                }
            }
            else if (dir == 'R')
            {
                st.push(dir);
            }
            else
            {
                // should not reach here
            }
        }
        return collisions;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string directions = "RLRSLL";
    int res = sol.countCollisions(directions);
    cout << res << endl;
    assert(res == 5);

    // Test_2
    directions = "LLRR";
    res = sol.countCollisions(directions);
    cout << res << endl;
    assert(res == 0);

    // Test_3
    directions = "SSRSSRLLRSLLRSRSSRLRRRRLLRRLSSRR";
    res = sol.countCollisions(directions);
    cout << res << endl;
    assert(res == 20);

    // Test_4
    directions = "SRRLRLRSRLRSSRRLSLRLLRSLSLLSSRRLSRSLSLRRS";
    res = sol.countCollisions(directions);
    cout << res << endl;
    assert(res == 28);

    return 0;
}
// Accepted
// 119/119 cases passed (26 ms)
// Your runtime beats 43.77 % of cpp submissions
// Your memory usage beats 18.26 % of cpp submissions (23.2 MB)