/*
 * @lc app=leetcode id=1404 lang=cpp
 *
 * [1404] Number of Steps to Reduce a Number in Binary Representation to One
 *
 * https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/
 *
 * algorithms
 * Medium (52.85%)
 * Likes:    963
 * Dislikes: 71
 * Total Accepted:    64.3K
 * Total Submissions: 112.8K
 * Testcase Example:  '"1101"'
 *
 * Given the binary representation of an integer as a string s, return the
 * number of steps to reduce it to 1 under the following rules:
 *
 *
 *
 * If the current number is even, you have to divide it by 2.
 *
 *
 * If the current number is odd, you have to add 1 to it.
 *
 *
 *
 * It is guaranteed that you can always reach one for all test cases.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "1101"
 * Output: 6
 * Explanation: "1101" corressponds to number 13 in their decimal
 * representation.
 * Step 1) 13 is odd, add 1 and obtain 14. 
 * Step 2) 14 is even, divide by 2 and obtain 7.
 * Step 3) 7 is odd, add 1 and obtain 8.
 * Step 4) 8 is even, divide by 2 and obtain 4. 
 * Step 5) 4 is even, divide by 2 and obtain 2. 
 * Step 6) 2 is even, divide by 2 and obtain 1. 
 *
 *
 * Example 2:
 *
 *
 * Input: s = "10"
 * Output: 1
 * Explanation: "10" corressponds to number 2 in their decimal representation.
 * Step 1) 2 is even, divide by 2 and obtain 1. 
 *
 *
 * Example 3:
 *
 *
 * Input: s = "1"
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 500
 * s consists of characters '0' or '1'
 * s[0] == '1'
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numSteps(string s)
    {
        int n           = (int) s.size();
        int leading_one = 0;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
            {
                leading_one = i;
                break;
            }
        int count = 0;
        int carry = 0;
        for (int i = n - 1; i > leading_one; i--)
        {
            if (s[i] == '1')
            {
                if (carry == 0)
                {
                    count += 2;
                    carry = 1;
                }
                else
                {
                    count += 1;
                }
            }
            else if (s[i] == '0')
            {
                if (carry == 0)
                {
                    count += 1;
                }
                else
                {
                    count += 2;
                }
            }
        }
        count += carry;
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1      = "1101";
    int    result_1 = sol.numSteps(s_1);
    cout << result_1 << endl;
    assert(result_1 == 6);

    // Test_2
    string s_2      = "10";
    int    result_2 = sol.numSteps(s_2);
    cout << result_2 << endl;
    assert(result_2 == 1);

    // Test_3
    string s_3      = "1";
    int    result_3 = sol.numSteps(s_3);
    cout << result_3 << endl;
    assert(result_3 == 0);

    return 0;
}
// Accepted
// 73/73 cases passed (3 ms)
// Your runtime beats 51.92 % of cpp submissions
// Your memory usage beats 25.06 % of cpp submissions (7.7 MB)