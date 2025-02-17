/*
 * @lc app=leetcode id=1079 lang=cpp
 *
 * [1079] Letter Tile Possibilities
 *
 * https://leetcode.com/problems/letter-tile-possibilities/description/
 *
 * algorithms
 * Medium (76.44%)
 * Likes:    2668
 * Dislikes: 76
 * Total Accepted:    135.8K
 * Total Submissions: 172.1K
 * Testcase Example:  '"AAB"'
 *
 * You have n  tiles, where each tile has one letter tiles[i] printed on it.
 *
 * Return the number of possible non-empty sequences of letters you can make
 * using the letters printed on those tiles.
 *
 *
 * Example 1:
 *
 *
 * Input: tiles = "AAB"
 * Output: 8
 * Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB",
 * "ABA", "BAA".
 *
 *
 * Example 2:
 *
 *
 * Input: tiles = "AAABBC"
 * Output: 188
 *
 *
 * Example 3:
 *
 *
 * Input: tiles = "V"
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= tiles.length <= 7
 * tiles consists of uppercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int dfs(vector<int>& count)
    {
        int sum = 0;
        for (int i = 0; i < 26; i++)
        {
            if (count[i] == 0)
            {
                continue;
            }
            sum++;
            count[i]--;
            sum += dfs(count);
            count[i]++;
        }
        return sum;
    }

    int numTilePossibilities(string tiles)
    {
        const int n = tiles.size();
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++)
        {
            count[tiles[i] - 'A']++;
        }
        return dfs(count);
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test case 1.
    string tiles_1 = "AAB";
    int res_1 = sol.numTilePossibilities(tiles_1);
    cout << "Test case 1: " << res_1 << endl;
    assert(res_1 == 8);

    // Test case 2.
    string tiles_2 = "AAABBC";
    int res_2 = sol.numTilePossibilities(tiles_2);
    cout << "Test case 2: " << res_2 << endl;
    assert(res_2 == 188);

    // Test case 3.
    string tiles_3 = "V";
    int res_3 = sol.numTilePossibilities(tiles_3);
    cout << "Test case 3: " << res_3 << endl;
    assert(res_3 == 1);

    return 0;
}
// Accepted
// 86/86 cases passed (3 ms)
// Your runtime beats 78.62 % of cpp submissions
// Your memory usage beats 92.23 % of cpp submissions (7.8 MB)