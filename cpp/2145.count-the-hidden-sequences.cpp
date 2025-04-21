/*
 * @lc app=leetcode id=2145 lang=cpp
 *
 * [2145] Count the Hidden Sequences
 *
 * https://leetcode.com/problems/count-the-hidden-sequences/description/
 *
 * algorithms
 * Medium (39.29%)
 * Likes:    912
 * Dislikes: 78
 * Total Accepted:    91.6K
 * Total Submissions: 166K
 * Testcase Example:  '[1,-3,4]\n1\n6'
 *
 * You are given a 0-indexed array of n integers differences, which describes
 * the differences between each pair of consecutive integers of a hidden
 * sequence of length (n + 1). More formally, call the hidden sequence hidden,
 * then we have that differences[i] = hidden[i + 1] - hidden[i].
 *
 * You are further given two integers lower and upper that describe the
 * inclusive range of values [lower, upper] that the hidden sequence can
 * contain.
 *
 *
 * For example, given differences = [1, -3, 4], lower = 1, upper = 6, the
 * hidden sequence is a sequence of length 4 whose elements are in between 1
 * and 6 (inclusive).
 *
 *
 * [3, 4, 1, 5] and [4, 5, 2, 6] are possible hidden sequences.
 * [5, 6, 3, 7] is not possible since it contains an element greater than
 * 6.
 * [1, 2, 3, 4] is not possible since the differences are not
 * correct.
 *
 *
 *
 *
 * Return the number of possible hidden sequences there are. If there are no
 * possible sequences, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: differences = [1,-3,4], lower = 1, upper = 6
 * Output: 2
 * Explanation: The possible hidden sequences are:
 * - [3, 4, 1, 5]
 * - [4, 5, 2, 6]
 * Thus, we return 2.
 *
 *
 * Example 2:
 *
 *
 * Input: differences = [3,-4,5,1,-2], lower = -4, upper = 5
 * Output: 4
 * Explanation: The possible hidden sequences are:
 * - [-3, 0, -4, 1, 2, 0]
 * - [-2, 1, -3, 2, 3, 1]
 * - [-1, 2, -2, 3, 4, 2]
 * - [0, 3, -1, 4, 5, 3]
 * Thus, we return 4.
 *
 *
 * Example 3:
 *
 *
 * Input: differences = [4,-7,2], lower = 3, upper = 6
 * Output: 0
 * Explanation: There are no possible hidden sequences. Thus, we return 0.
 *
 *
 *
 * Constraints:
 *
 *
 * n == differences.length
 * 1 <= n <= 10^5
 * -10^5 <= differences[i] <= 10^5
 * -10^5 <= lower <= upper <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper)
    {
        int curr_diff = 0;
        int min_diff = 0;
        int max_diff = 0;
        int gap = upper - lower;
        for (int diff : differences)
        {
            curr_diff += diff;
            min_diff = min(min_diff, curr_diff);
            max_diff = max(max_diff, curr_diff);
            if (abs(curr_diff) > gap)
                return 0;
        }

        if (max_diff == min_diff)
            return max(0, upper - lower - abs(max_diff) + 1);

        return max(0, upper - lower - abs(max_diff - min_diff) + 1);
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> differences = { 1, -3, 4 };
    int lower = 1;
    int upper = 6;
    int res = sol.numberOfArrays(differences, lower, upper);
    cout << res << endl;  // Expected output: 2
    assert(res == 2);

    // Test_2
    differences = { 3, -4, 5, 1, -2 };
    lower = -4;
    upper = 5;
    res = sol.numberOfArrays(differences, lower, upper);
    cout << res << endl;  // Expected output: 4
    assert(res == 4);

    // Test_3
    differences = { 4, -7, 2 };
    lower = 3;
    upper = 6;
    res = sol.numberOfArrays(differences, lower, upper);
    cout << res << endl;  // Expected output: 0
    assert(res == 0);

    // Test_4
    differences = { -40 };
    lower = -46;
    upper = 53;
    res = sol.numberOfArrays(differences, lower, upper);
    cout << res << endl;  // Expected output: 60
    assert(res == 60);

    // Test_5
    differences = { 83702, -5216 };
    lower = -82788;
    upper = 14602;
    res = sol.numberOfArrays(differences, lower, upper);
    cout << res << endl;  // Expected output: 13689
    assert(res == 13689);

    return 0;
}
// Accepted
// 86/86 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 47.58 % of cpp submissions (112.6 MB)