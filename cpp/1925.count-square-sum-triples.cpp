/*
 * @lc app=leetcode id=1925 lang=cpp
 *
 * [1925] Count Square Sum Triples
 *
 * https://leetcode.com/problems/count-square-sum-triples/description/
 *
 * algorithms
 * Easy (69.33%)
 * Likes:    547
 * Dislikes: 51
 * Total Accepted:    92.9K
 * Total Submissions: 126.5K
 * Testcase Example:  '5'
 *
 * A square triple (a,b,c) is a triple where a, b, and c are integers and a^2 +
 * b^2 = c^2.
 *
 * Given an integer n, return the number of square triples such that 1 <= a, b,
 * c <= n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 5
 * Output: 2
 * Explanation: The square triples are (3,4,5) and (4,3,5).
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: 4
 * Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and
 * (8,6,10).
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 250
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countTriples(int n)
    {
        set<int> squares;
        for (int i = 1; i <= n; i++)
        {
            squares.insert(i * i);
        }
        int count = 0;
        for (int a = 1; a <= n; a++)
        {
            for (int b = a; b <= n; b++)
            {
                int c_square = a * a + b * b;
                if (c_square > n * n)
                {
                    continue;
                }
                if (squares.find(c_square) != squares.end())
                {
                    if(a == b)
                        count += 1;
                    else
                        count += 2;
                }
            }
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n = 5;
    int res = sol.countTriples(n);
    cout << res << endl;
    assert(res == 2);

    // Test_2
    n = 10;
    res = sol.countTriples(n);
    cout << res << endl;
    assert(res == 4);

    return 0;
}
// Accepted
// 91/91 cases passed (14 ms)
// Your runtime beats 40.85 % of cpp submissions
// Your memory usage beats 8.51 % of cpp submissions (8.9 MB)