/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 *
 * https://leetcode.com/problems/height-checker/description/
 *
 * algorithms
 * Easy (76.52%)
 * Likes:    1467
 * Dislikes: 103
 * Total Accepted:    445.3K
 * Total Submissions: 558.5K
 * Testcase Example:  '[1,1,4,2,1,3]'
 *
 * A school is trying to take an annual photo of all the students. The students
 * are asked to stand in a single file line in non-decreasing order by height.
 * Let this ordering be represented by the integer array expected where
 * expected[i] is the expected height of the i^th student in line.
 *
 * You are given an integer array heights representing the current order that
 * the students are standing in. Each heights[i] is the height of the i^th
 * student in line (0-indexed).
 *
 * Return the number of indices where heights[i] != expected[i].
 *
 *
 * Example 1:
 *
 *
 * Input: heights = [1,1,4,2,1,3]
 * Output: 3
 * Explanation:
 * heights:  [1,1,4,2,1,3]
 * expected: [1,1,1,2,3,4]
 * Indices 2, 4, and 5 do not match.
 *
 *
 * Example 2:
 *
 *
 * Input: heights = [5,1,2,3,4]
 * Output: 5
 * Explanation:
 * heights:  [5,1,2,3,4]
 * expected: [1,2,3,4,5]
 * All indices do not match.
 *
 *
 * Example 3:
 *
 *
 * Input: heights = [1,2,3,4,5]
 * Output: 0
 * Explanation:
 * heights:  [1,2,3,4,5]
 * expected: [1,2,3,4,5]
 * All indices match.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= heights.length <= 100
 * 1 <= heights[i] <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int count = 0;
        for (int i = 0; i < (int)heights.size(); i++)
        {
            if (heights[i] != sorted[i])
            {
                count++;
            }
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> heights_1 = {1, 1, 4, 2, 1, 3};
    int result_1 = sol.heightChecker(heights_1);
    cout << result_1 << endl;
    assert(result_1 == 3);

    // Test_2
    vector<int> heights_2 = {5, 1, 2, 3, 4};
    int result_2 = sol.heightChecker(heights_2);
    cout << result_2 << endl;
    assert(result_2 == 5);

    // Test_3
    vector<int> heights_3 = {1, 2, 3, 4, 5};
    int result_3 = sol.heightChecker(heights_3);
    cout << result_3 << endl;
    assert(result_3 == 0);

    return 0;
}
// Accepted
// 81/81 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 78.64 % of cpp submissions (10 MB)