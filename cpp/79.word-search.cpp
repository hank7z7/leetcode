/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (41.53%)
 * Likes:    15404
 * Dislikes: 641
 * Total Accepted:    1.6M
 * Total Submissions: 3.8M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given an m x n grid of characters board and a string word, return true if
 * word exists in the grid.
 *
 * The word can be constructed from letters of sequentially adjacent cells,
 * where adjacent cells are horizontally or vertically neighboring. The same
 * letter cell may not be used more than once.
 *
 *
 * Example 1:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCCED"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "SEE"
 * Output: true
 *
 *
 * Example 3:
 *
 *
 * Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word
 * = "ABCB"
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board and word consists of only lowercase and uppercase English letters.
 *
 *
 *
 * Follow up: Could you use search pruning to make your solution faster with a
 * larger board?
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define MAX_WIDTH 6
class Solution
{
private:
    const int dir_size = 4;
    const vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool valid_next(pair<int, int> next, int w, int h)
    {
        return next.first >= 0 && next.first < h && next.second >= 0 && next.second < w;
    }

public:
    bool exist(vector<vector<char>> &board, const string word)
    {
        const int h = (int)board.size();
        const int w = (int)board[0].size();
        bool find = false;
        // Iterate all element as a root
        for (int i = 0; i < h && !find; i++)
        {
            for (int j = 0; j < w && !find; j++)
            {
                // index (i, j), index of a traced string
                stack<pair<pair<int, int>, int>> st;
                // For backtracing
                vector<pair<int, int>> bt;
                vector<bitset<MAX_WIDTH>> visited(h);

                // Push first element
                if (board[i][j] == word[0])
                    st.push({{i, j}, 0});

                // DFS
                while (!st.empty())
                {
                    pair<int, int> top = st.top().first;
                    int curr = st.top().second;
                    st.pop();

                    // Find a correct word
                    if (curr == (int)(word.size() - 1))
                    {
                        find = true;
                        break;
                    }

                    // Clear previos tracing visited
                    while ((int)bt.size() > curr)
                    {
                        visited[bt.back().first][bt.back().second] = false;
                        bt.pop_back();
                    }

                    // Record this element
                    visited[top.first][top.second] = true;
                    bt.push_back({top.first, top.second});

                    for (auto dir : dirs)
                    {
                        pair<int, int> next = {top.first + dir.first,
                                            top.second + dir.second};
                        if (valid_next(next, w, h)
                        && !visited[next.first][next.second]
                        && board[next.first][next.second] == word[curr + 1])
                        {
                            st.push({next, curr + 1});
                        }
                    }
                }
            }
        }
        return find;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<vector<char>> board_1 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word_1 = "ABCCED";
    cout << sol.exist(board_1, word_1) << endl;

    // Test_2
    vector<vector<char>> board_2 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word_2 = "SEE";
    cout << sol.exist(board_2, word_2) << endl;

    // Test_3
    vector<vector<char>> board_3 = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word_3 = "ABCB";
    cout << sol.exist(board_3, word_3) << endl;

    // Test_4
    vector<vector<char>> board_4 = {{'a', 'a'}};
    string word_4 = "aaa";
    cout << sol.exist(board_4, word_4) << endl;

    return 0;
}
// Accepted
// 87/87 cases passed (459 ms)
// Your runtime beats 63.89 % of cpp submissions
// Your memory usage beats 61.03 % of cpp submissions (11.4 MB)