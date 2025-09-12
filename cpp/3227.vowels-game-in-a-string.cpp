/*
 * @lc app=leetcode id=3227 lang=cpp
 *
 * [3227] Vowels Game in a String
 *
 * https://leetcode.com/problems/vowels-game-in-a-string/description/
 *
 * algorithms
 * Medium (62.66%)
 * Likes:    311
 * Dislikes: 68
 * Total Accepted:    97.4K
 * Total Submissions: 134.9K
 * Testcase Example:  '"leetcoder"'
 *
 * Alice and Bob are playing a game on a string.
 *
 * You are given a string s, Alice and Bob will take turns playing the
 * following game where Alice starts first:
 *
 *
 * On Alice's turn, she has to remove any non-empty substring from s that
 * contains an odd number of vowels.
 * On Bob's turn, he has to remove any non-empty substring from s that contains
 * an even number of vowels.
 *
 *
 * The first player who cannot make a move on their turn loses the game. We
 * assume that both Alice and Bob play optimally.
 *
 * Return true if Alice wins the game, and false otherwise.
 *
 * The English vowels are: a, e, i, o, and u.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "leetcoder"
 *
 * Output: true
 *
 * Explanation:
 * Alice can win the game as follows:
 *
 *
 * Alice plays first, she can delete the underlined substring in s =
 * "leetcoder" which contains 3 vowels. The resulting string is s = "der".
 * Bob plays second, he can delete the underlined substring in s = "der" which
 * contains 0 vowels. The resulting string is s = "er".
 * Alice plays third, she can delete the whole string s = "er" which contains 1
 * vowel.
 * Bob plays fourth, since the string is empty, there is no valid play for Bob.
 * So Alice wins the game.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: s = "bbcd"
 *
 * Output: false
 *
 * Explanation:
 * There is no valid play for Alice in her first turn, so Alice loses the
 * game.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists only of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isVowel(char c) { return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; }
    bool doesAliceWin(string s)
    {
        int vowel_count = 0;
        for (char c : s)
        {
            if (isVowel(c))
            {
                vowel_count++;
            }
        }
        return vowel_count > 0;
    }
};
// @lc code=end
int main(int argc, char const* argv[])
{
    Solution sol;
    // Test_1
    string s_1 = "leetcoder";
    bool res_1 = sol.doesAliceWin(s_1);
    cout << res_1 << endl;  // true
    assert(res_1 == true);

    // Test_2
    string s_2 = "bbcd";
    bool res_2 = sol.doesAliceWin(s_2);
    cout << res_2 << endl;  // false
    assert(res_2 == false);

    return 0;
}
// Accepted
// 697/697 cases passed (4 ms)
// Your runtime beats 78.54 % of cpp submissions
// Your memory usage beats 79.48 % of cpp submissions (18.9 MB)