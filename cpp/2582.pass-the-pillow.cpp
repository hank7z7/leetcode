/*
 * @lc app=leetcode id=2582 lang=cpp
 *
 * [2582] Pass the Pillow
 *
 * https://leetcode.com/problems/pass-the-pillow/description/
 *
 * algorithms
 * Easy (45.92%)
 * Likes:    573
 * Dislikes: 22
 * Total Accepted:    73.3K
 * Total Submissions: 138.8K
 * Testcase Example:  '4\n5'
 *
 * There are n people standing in a line labeled from 1 to n. The first person
 * in the line is holding a pillow initially. Every second, the person holding
 * the pillow passes it to the next person standing in the line. Once the
 * pillow reaches the end of the line, the direction changes, and people
 * continue passing the pillow in the opposite direction.
 * 
 * 
 * For example, once the pillow reaches the n^th person they pass it to the n -
 * 1^th person, then to the n - 2^th person and so on.
 * 
 * 
 * Given the two positive integers n and time, return the index of the person
 * holding the pillow after time seconds.
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4, time = 5
 * Output: 2
 * Explanation: People pass the pillow in the following way: 1 -> 2 -> 3 -> 4
 * -> 3 -> 2.
 * After five seconds, the 2^nd person is holding the pillow.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 3, time = 2
 * Output: 3
 * Explanation: People pass the pillow in the following way: 1 -> 2 -> 3.
 * After two seconds, the 3^r^d person is holding the pillow.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= n <= 1000
 * 1 <= time <= 1000
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int passThePillow(int n, int time) {
        // Calculate the number of complete rounds of pillow passing
        int fullRounds = time / (n - 1);

        // Calculate the remaining time after complete rounds
        int extraTime = time % (n - 1);

        // Determine the position of the person holding the pillow
        // If fullRounds is even, the pillow is moving forward.
        // If fullRounds is odd, the pillow is moving backward.
        if (fullRounds % 2 == 0) {
            return extraTime + 1;  // Position when moving forward
        } else {
            return n - extraTime;  // Position when moving backward
        }
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n_1 = 4;
    int time_1 = 5;
    int res_1 = sol.passThePillow(n_1, time_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    int n_2 = 3;
    int time_2 = 2;
    int res_2 = sol.passThePillow(n_2, time_2);
    cout << res_2 << endl;
    assert(res_2 == 3);

    return 0;
}
// Accepted
// 68/68 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 71.18 % of cpp submissions (7.1 MB)