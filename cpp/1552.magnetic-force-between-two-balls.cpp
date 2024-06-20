/*
 * @lc app=leetcode id=1552 lang=cpp
 *
 * [1552] Magnetic Force Between Two Balls
 *
 * https://leetcode.com/problems/magnetic-force-between-two-balls/description/
 *
 * algorithms
 * Medium (61.30%)
 * Likes:    2590
 * Dislikes: 199
 * Total Accepted:    116.9K
 * Total Submissions: 170.4K
 * Testcase Example:  '[1,2,3,4,7]\n3'
 *
 * In the universe Earth C-137, Rick discovered a special form of magnetic
 * force between two balls if they are put in his new invented basket. Rick has
 * n empty baskets, the i^th basket is at position[i], Morty has m balls and
 * needs to distribute the balls into the baskets such that the minimum
 * magnetic force between any two balls is maximum.
 *
 * Rick stated that magnetic force between two different balls at positions x
 * and y is |x - y|.
 *
 * Given the integer array position and the integer m. Return the required
 * force.
 *
 *
 * Example 1:
 *
 *
 * Input: position = [1,2,3,4,7], m = 3
 * Output: 3
 * Explanation: Distributing the 3 balls into baskets 1, 4 and 7 will make the
 * magnetic force between ball pairs [3, 3, 6]. The minimum magnetic force is
 * 3. We cannot achieve a larger minimum magnetic force than 3.
 *
 *
 * Example 2:
 *
 *
 * Input: position = [5,4,3,2,1,1000000000], m = 2
 * Output: 999999999
 * Explanation: We can use baskets 1 and 1000000000.
 *
 *
 *
 * Constraints:
 *
 *
 * n == position.length
 * 2 <= n <= 10^5
 * 1 <= position[i] <= 10^9
 * All integers in position are distinct.
 * 2 <= m <= position.length
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    // Check if we can place 'm' balls at 'position'
    // with each ball having at least 'x' gap.
    bool canPlaceBalls(int x, vector<int> &position, int m)
    {
        // Place the first ball at the first position.
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        // Iterate on each 'position' and place a ball there if we can place it.
        for (int i = 1; i < (int)position.size() && ballsPlaced < m; i++)
        {
            int currPos = position[i];
            // Check if we can place the ball at the current position.
            if (currPos - prevBallPos >= x)
            {
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }
        // If all 'm' balls are placed, return 'true'.
        return ballsPlaced == m;
    }

    int maxDistance(vector<int> &position, int m)
    {
        int answer = 0;
        int n = (int)position.size();
        sort(position.begin(), position.end());

        // Initial search space.
        int low = 1;
        int high = ceil(position[n - 1] / (m - 1.0));
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            // If we can place all balls having a gap at least 'mid',
            if (canPlaceBalls(mid, position, m))
            {
                // then 'mid' can be our answer,
                answer = mid;
                // and discard the left half search space.
                low = mid + 1;
            }
            else
            {
                // Discard the right half search space.
                high = mid - 1;
            }
        }
        return answer;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> pos_1 = {1, 2, 3, 4, 7};
    int m_1 = 3;
    int result_1 = sol.maxDistance(pos_1, m_1);
    cout << result_1 << endl;
    assert(result_1 == 3);

    // Test_2
    vector<int> pos_2 = {5, 4, 3, 2, 1, 1000000000};
    int m_2 = 2;
    int result_2 = sol.maxDistance(pos_2, m_2);
    cout << result_2 << endl;
    assert(result_2 == 999999999);

    return 0;
}
// Accepted
// 98/98 cases passed (93 ms)
// Your runtime beats 97.44 % of cpp submissions
// Your memory usage beats 11.25 % of cpp submissions (61.6 MB)