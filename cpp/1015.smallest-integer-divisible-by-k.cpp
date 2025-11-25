/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 *
 * https://leetcode.com/problems/smallest-integer-divisible-by-k/description/
 *
 * algorithms
 * Medium (46.64%)
 * Likes:    1361
 * Dislikes: 1017
 * Total Accepted:    112.6K
 * Total Submissions: 221.3K
 * Testcase Example:  '1'
 *
 * Given a positive integer k, you need to find the length of the smallest
 * positive integer n such that n is divisible by k, and n only contains the
 * digit 1.
 * 
 * Return the length of n. If there is no such n, return -1.
 * 
 * Note: n may not fit in a 64-bit signed integer.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 1
 * Output: 1
 * Explanation: The smallest answer is n = 1, which has length 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 2
 * Output: -1
 * Explanation: There is no such positive integer n divisible by 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: k = 3
 * Output: 3
 * Explanation: The smallest answer is n = 111, which has length 3.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= k <= 10^5
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int remainder = 0;
        for (int length = 1; length <= k; ++length) {
            remainder = (remainder * 10 + 1) % k;
            if (remainder == 0) {
                return length;
            }
        }
        return -1;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution sol;
    // Test_1
    int k_1 = 1;
    int res_1 = sol.smallestRepunitDivByK(k_1);
    cout << "Test_1: " << res_1 << endl;
    assert(res_1 == 1);

    // Test_2
    int k_2 = 2;
    int res_2 = sol.smallestRepunitDivByK(k_2);
    cout << "Test_2: " << res_2 << endl;
    assert(res_2 == -1);

    // Test_3
    int k_3 = 3;
    int res_3 = sol.smallestRepunitDivByK(k_3);
    cout << "Test_3: " << res_3 << endl;
    assert(res_3 == 3);

    return 0;
}
