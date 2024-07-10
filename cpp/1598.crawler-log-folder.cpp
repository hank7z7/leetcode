/*
 * @lc app=leetcode id=1598 lang=cpp
 *
 * [1598] Crawler Log Folder
 *
 * https://leetcode.com/problems/crawler-log-folder/description/
 *
 * algorithms
 * Easy (65.31%)
 * Likes:    1354
 * Dislikes: 90
 * Total Accepted:    209.9K
 * Total Submissions: 295.4K
 * Testcase Example:  '["d1/","d2/","../","d21/","./"]'
 *
 * The Leetcode file system keeps a log each time some user performs a change
 * folder operation.
 *
 * The operations are described below:
 *
 *
 * "../" : Move to the parent folder of the current folder. (If you are already
 * in the main folder, remain in the same folder).
 * "./" : Remain in the same folder.
 * "x/" : Move to the child folder named x (This folder is guaranteed to always
 * exist).
 *
 *
 * You are given a list of strings logs where logs[i] is the operation
 * performed by the user at the i^th step.
 *
 * The file system starts in the main folder, then the operations in logs are
 * performed.
 *
 * Return the minimum number of operations needed to go back to the main folder
 * after the change folder operations.
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: logs = ["d1/","d2/","../","d21/","./"]
 * Output: 2
 * Explanation: Use this change folder operation "../" 2 times and go back to
 * the main folder.
 *
 *
 * Example 2:
 *
 *
 *
 *
 * Input: logs = ["d1/","d2/","./","d3/","../","d31/"]
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: logs = ["d1/","../","../","../"]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= logs.length <= 10^3
 * 2 <= logs[i].length <= 10
 * logs[i] contains lowercase English letters, digits, '.', and '/'.
 * logs[i] follows the format described in the statement.
 * Folder names consist of lowercase English letters and digits.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int res = 0;
        for (const string &currentOperation : logs)
        {
            if (currentOperation == "../")
            {
                // Move up to parent directory if not already at main folder
                if (res > 0)
                {
                    res--;
                }
            }
            else if (currentOperation != "./")
            {
                // Enter a new folder
                res++;
            }
            // Ignore "./" operations as they don't change the current folder
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<string> logs_1 = {"d1/", "d2/", "../", "d21/", "./"};
    int res_1 = sol.minOperations(logs_1);
    cout << res_1 << endl;
    assert(res_1 == 2);

    // Test_2
    vector<string> logs_2 = {"d1/", "d2/", "./", "d3/", "../", "d31/"};
    int res_2 = sol.minOperations(logs_2);
    cout << res_2 << endl;
    assert(res_2 == 3);

    // Test_3
    vector<string> logs_3 = {"d1/", "../", "../", "../"};
    int res_3 = sol.minOperations(logs_3);
    cout << res_3 << endl;
    assert(res_3 == 0);

    return 0;
}
// Accepted
// 99/99 cases passed (3 ms)
// Your runtime beats 86.11 % of cpp submissions
// Your memory usage beats 84.88 % of cpp submissions (13.8 MB)