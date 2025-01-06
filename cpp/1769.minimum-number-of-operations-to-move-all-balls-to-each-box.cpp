/*
 * @lc app=leetcode id=1769 lang=cpp
 *
 * [1769] Minimum Number of Operations to Move All Balls to Each Box
 *
 * https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/
 *
 * algorithms
 * Medium (85.92%)
 * Likes:    2478
 * Dislikes: 100
 * Total Accepted:    173.6K
 * Total Submissions: 197.6K
 * Testcase Example:  '"110"'
 *
 * You have n boxes. You are given a binary string boxes of length n, where
 * boxes[i] is '0' if the i^th box is empty, and '1' if it contains one ball.
 *
 * In one operation, you can move one ball from a box to an adjacent box. Box i
 * is adjacent to box j if abs(i - j) == 1. Note that after doing so, there may
 * be more than one ball in some boxes.
 *
 * Return an array answer of size n, where answer[i] is the minimum number of
 * operations needed to move all the balls to the i^th box.
 *
 * Each answer[i] is calculated considering the initial state of the boxes.
 *
 *
 * Example 1:
 *
 *
 * Input: boxes = "110"
 * Output: [1,1,3]
 * Explanation: The answer for each box is as follows:
 * 1) First box: you will have to move one ball from the second box to the
 * first box in one operation.
 * 2) Second box: you will have to move one ball from the first box to the
 * second box in one operation.
 * 3) Third box: you will have to move one ball from the first box to the third
 * box in two operations, and move one ball from the second box to the third
 * box in one operation.
 *
 *
 * Example 2:
 *
 *
 * Input: boxes = "001011"
 * Output: [11,8,5,4,3,4]
 *
 *
 * Constraints:
 *
 *
 * n == boxes.length
 * 1 <= n <= 2000
 * boxes[i] is either '0' or '1'.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> minOperations(string s)
    {
        const int n = (int) s.length();
        vector<int> res(n, 0);
        int one_count = 0;
        int prev = 0;
        // Forward
        for (int i = 0; i < n; i++)
        {
            res[i] += prev + one_count;
            prev += one_count;
            if (s[i] == '1')
                one_count++;
        }

        // Backward
        one_count = 0;
        prev = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            res[i] += prev + one_count;
            prev += one_count;
            if (s[i] == '1')
                one_count++;
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string boxes_1 = "110";
    vector<int> res_1 = sol.minOperations(boxes_1);
    for (auto it : res_1)
        cout << it << " ";
    cout << endl;
    assert((res_1 == vector<int>{ 1, 1, 3 }));

    // Test_2
    string boxes_2 = "001011";
    vector<int> res_2 = sol.minOperations(boxes_2);
    for (auto it : res_2)
        cout << it << " ";
    cout << endl;
    assert((res_2 == vector<int>{ 11, 8, 5, 4, 3, 4 }));

    return 0;
}
// Accepted
// 95/95 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 76.52 % of cpp submissions (11.9 MB)