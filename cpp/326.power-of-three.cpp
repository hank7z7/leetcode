/*
 * @lc app=leetcode id=326 lang=cpp
 *
 * [326] Power of Three
 *
 * https://leetcode.com/problems/power-of-three/description/
 *
 * algorithms
 * Easy (47.74%)
 * Likes:    3456
 * Dislikes: 299
 * Total Accepted:    1.1M
 * Total Submissions: 2.3M
 * Testcase Example:  '27'
 *
 * Given an integer n, return true if it is a power of three. Otherwise, return
 * false.
 * 
 * An integer n is a power of three, if there exists an integer x such that n
 * == 3^x.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 27
 * Output: true
 * Explanation: 27 = 3^3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 0
 * Output: false
 * Explanation: There is no x where 3^x = 0.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = -1
 * Output: false
 * Explanation: There is no x where 3^x = (-1).
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * -2^31 <= n <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false; // Power of three must be positive
        // Check if n is a power of three by using modulo
        while (n % 3 == 0) {
            n /= 3;
        }
        return n == 1; // If we reduce n to 1, it is a power of three
    }
};
// @lc code=end
int main() {
    Solution sol;
    cout << sol.isPowerOfThree(27) << endl;  // Output: true
    cout << sol.isPowerOfThree(0) << endl;   // Output: false
    cout << sol.isPowerOfThree(-1) << endl;  // Output: false
    return 0;
}
// Accepted
// 21040/21040 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 46.41 % of cpp submissions (8.9 MB)