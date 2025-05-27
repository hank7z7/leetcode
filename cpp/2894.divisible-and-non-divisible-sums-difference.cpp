/*
 * @lc app=leetcode id=2894 lang=cpp
 *
 * [2894] Divisible and Non-divisible Sums Difference
 *
 * https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/
 *
 * algorithms
 * Easy (88.29%)
 * Likes:    516
 * Dislikes: 30
 * Total Accepted:    223.2K
 * Total Submissions: 244.9K
 * Testcase Example:  '10\n3'
 *
 * You are given positive integers n and m.
 * 
 * Define two integers as follows:
 * 
 * 
 * num1: The sum of all integers in the range [1, n] (both inclusive) that are
 * not divisible by m.
 * num2: The sum of all integers in the range [1, n] (both inclusive) that are
 * divisible by m.
 * 
 * 
 * Return the integer num1 - num2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 10, m = 3
 * Output: 19
 * Explanation: In the given example:
 * - Integers in the range [1, 10] that are not divisible by 3 are
 * [1,2,4,5,7,8,10], num1 is the sum of those integers = 37.
 * - Integers in the range [1, 10] that are divisible by 3 are [3,6,9], num2 is
 * the sum of those integers = 18.
 * We return 37 - 18 = 19 as the answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 5, m = 6
 * Output: 15
 * Explanation: In the given example:
 * - Integers in the range [1, 5] that are not divisible by 6 are [1,2,3,4,5],
 * num1 is the sum of those integers = 15.
 * - Integers in the range [1, 5] that are divisible by 6 are [], num2 is the
 * sum of those integers = 0.
 * We return 15 - 0 = 15 as the answer.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: n = 5, m = 1
 * Output: -15
 * Explanation: In the given example:
 * - Integers in the range [1, 5] that are not divisible by 1 are [], num1 is
 * the sum of those integers = 0.
 * - Integers in the range [1, 5] that are divisible by 1 are [1,2,3,4,5], num2
 * is the sum of those integers = 15.
 * We return 0 - 15 = -15 as the answer.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n, m <= 1000
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0, num2 = 0;
        for(int i = 1; i <= n; ++i) {
            if (i % m == 0) {
                num2 += i; // Sum of numbers divisible by m
            } else {
                num1 += i; // Sum of numbers not divisible by m
            }
        }
        return num1 - num2; // Return the difference
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution sol;
    // Test case 1
    int n1 = 10, m1 = 3;
    int res1 = sol.differenceOfSums(n1, m1);
    cout << "Test case 1 result: " << res1 << endl; // Expected: 19
    assert(res1 == 19);

    // Test case 2
    int n2 = 5, m2 = 6;
    int res2 = sol.differenceOfSums(n2, m2);
    cout << "Test case 2 result: " << res2 << endl; // Expected: 15
    assert(res2 == 15);

    // Test case 3
    int n3 = 5, m3 = 1;
    int res3 = sol.differenceOfSums(n3, m3);
    cout << "Test case 3 result: " << res3 << endl; // Expected: -15
    assert(res3 == -15);

    return 0;
}
// Accepted
// 737/737 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 70.35 % of cpp submissions (8.3 MB)