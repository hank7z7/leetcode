/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 *
 * https://leetcode.com/problems/count-and-say/description/
 *
 * algorithms
 * Medium (57.95%)
 * Likes:    4479
 * Dislikes: 8686
 * Total Accepted:    1.1M
 * Total Submissions: 1.9M
 * Testcase Example:  '1'
 *
 * The count-and-say sequence is a sequence of digit strings defined by the
 * recursive formula:
 *
 *
 * countAndSay(1) = "1"
 * countAndSay(n) is the run-length encoding of countAndSay(n - 1).
 *
 *
 * Run-length encoding (RLE) is a string compression method that works by
 * replacing consecutive identical characters (repeated 2 or more times) with
 * the concatenation of the character and the number marking the count of the
 * characters (length of the run). For example, to compress the string
 * "3322251" we replace "33" with "23", replace "222" with "32", replace "5"
 * with "15" and replace "1" with "11". Thus the compressed string becomes
 * "23321511".
 *
 * Given a positive integer n, return the n^th element of the count-and-say
 * sequence.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 4
 *
 * Output: "1211"
 *
 * Explanation:
 *
 *
 * countAndSay(1) = "1"
 * countAndSay(2) = RLE of "1" = "11"
 * countAndSay(3) = RLE of "11" = "21"
 * countAndSay(4) = RLE of "21" = "1211"
 *
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 *
 * Output: "1"
 *
 * Explanation:
 *
 * This is the base case.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 30
 *
 *
 *
 * Follow up: Could you solve it iteratively?
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string countAndSay(int n)
    {
        string res = "1";
        helper(1, n, res);
        return res;
    }

    void helper(int ind, int n, string& res)
    {
        if (ind >= n)
            return;
        string prev_val = res;
        res = "";
        int left = 0, count = 0;
        for (int right = 0; right < (int) prev_val.size(); right++)
        {
            if (prev_val[left] != prev_val[right])
            {
                res += to_string(count) + prev_val[left];
                left = right;
                count = 1;
            }
            else
            {
                count++;
            }
        }
        res += to_string(count) + prev_val[left];
        return helper(ind + 1, n, res);
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    int n = 4;
    string res = sol.countAndSay(n);
    cout << res << endl;
    assert(res == "1211");

    // Test_2
    n = 1;
    res = sol.countAndSay(n);
    cout << res << endl;
    assert(res == "1");

    return 0;
}
