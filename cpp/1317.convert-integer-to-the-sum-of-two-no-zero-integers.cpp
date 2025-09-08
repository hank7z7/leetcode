/*
 * @lc app=leetcode id=1317 lang=cpp
 *
 * [1317] Convert Integer to the Sum of Two No-Zero Integers
 *
 * https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/
 *
 * algorithms
 * Easy (54.31%)
 * Likes:    562
 * Dislikes: 332
 * Total Accepted:    90.7K
 * Total Submissions: 160.8K
 * Testcase Example:  '2'
 *
 * No-Zero integer is a positive integer that does not contain any 0 in its
 * decimal representation.
 *
 * Given an integer n, return a list of two integers [a, b] where:
 *
 *
 * a and b are No-Zero integers.
 * a + b = n
 *
 *
 * The test cases are generated so that there is at least one valid solution.
 * If there are many valid solutions, you can return any of them.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: [1,1]
 * Explanation: Let a = 1 and b = 1.
 * Both a and b are no-zero integers, and a + b = 2 = n.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 11
 * Output: [2,9]
 * Explanation: Let a = 2 and b = 9.
 * Both a and b are no-zero integers, and a + b = 11 = n.
 * Note that there are other valid answers as [8, 3] that can be accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> getNoZeroIntegers(int n)
    {
        vector<int> res(2);
        for (int i = 1; i < n; ++i)
        {
            int a = i, b = n - i;
            bool flag = true;
            while (a)
            {
                if (a % 10 == 0)
                {
                    flag = false;
                    break;
                }
                a /= 10;
            }
            while (b)
            {
                if (b % 10 == 0)
                {
                    flag = false;
                    break;
                }
                b /= 10;
            }
            if (flag)
            {
                res[0] = i;
                res[1] = n - i;
                break;
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n_1 = 2;
    vector<int> res_1 = sol.getNoZeroIntegers(n_1);
    for (auto& elem : res_1)
        cout << elem << " ";
    cout << endl;
    assert((res_1 == vector<int>{ 1, 1 }));

    // Test_2
    int n_2 = 11;
    vector<int> res_2 = sol.getNoZeroIntegers(n_2);
    for (auto& elem : res_2)
        cout << elem << " ";
    cout << endl;
    assert((res_2 == vector<int>{ 2, 9 } || res_2 == vector<int>{ 9, 2 }
            || res_2 == vector<int>{ 8, 3 } || res_2 == vector<int>{ 3, 8 }
            || res_2 == vector<int>{ 7, 4 } || res_2 == vector<int>{ 4, 7 }
            || res_2 == vector<int>{ 6, 5 } || res_2 == vector<int>{ 5, 6 }));

    // Test_3
    int n_3 = 10000;
    vector<int> res_3 = sol.getNoZeroIntegers(n_3);
    for (auto& elem : res_3)
        cout << elem << " ";
    cout << endl;
    assert((res_3 == vector<int>{ 1, 9999 } || res_3 == vector<int>{ 9999, 1 }
            || res_3 == vector<int>{ 2, 9998 } || res_3 == vector<int>{ 9998, 2 }));  // and so on

    return 0;
}
// Accepted
// 207/207 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 59.59 % of cpp submissions (8.3 MB)