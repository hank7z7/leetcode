/*
 * @lc app=leetcode id=1255 lang=cpp
 *
 * [1255] Maximum Score Words Formed by Letters
 *
 * https://leetcode.com/problems/maximum-score-words-formed-by-letters/description/
 *
 * algorithms
 * Hard (72.58%)
 * Likes:    1701
 * Dislikes: 108
 * Total Accepted:    111K
 * Total Submissions: 134.8K
 * Testcase Example:  '["dog","cat","dad","good"]\n' +
  '["a","a","c","d","d","d","g","o","o"]\n' +
  '[1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]'
 *
 * Given a list of words, list of  single letters (might be repeating) and
 * score of every character.
 *
 * Return the maximum score of any valid set of words formed by using the given
 * letters (words[i] cannot be used two or more times).
 *
 * It is not necessary to use all characters in letters and each letter can
 * only be used once. Score of letters 'a', 'b', 'c', ... ,'z' is given by
 * score[0], score[1], ... , score[25] respectively.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["dog","cat","dad","good"], letters =
 * ["a","a","c","d","d","d","g","o","o"], score =
 * [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
 * Output: 23
 * Explanation:
 * Score  a=1, c=9, d=5, g=3, o=2
 * Given letters, we can form the words "dad" (5+1+5) and "good" (3+2+2+5) with
 * a score of 23.
 * Words "dad" and "dog" only get a score of 21.
 *
 * Example 2:
 *
 *
 * Input: words = ["xxxz","ax","bx","cx"], letters =
 * ["z","a","b","c","x","x","x"], score =
 * [4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,10]
 * Output: 27
 * Explanation:
 * Score  a=4, b=4, c=4, x=5, z=10
 * Given letters, we can form the words "ax" (4+5), "bx" (4+5) and "cx" (4+5)
 * with a score of 27.
 * Word "xxxz" only get a score of 25.
 *
 * Example 3:
 *
 *
 * Input: words = ["leetcode"], letters = ["l","e","t","c","o","d"], score =
 * [0,0,1,1,1,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0]
 * Output: 0
 * Explanation:
 * Letter "e" can only be used once.
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 14
 * 1 <= words[i].length <= 15
 * 1 <= letters.length <= 100
 * letters[i].length == 1
 * score.length == 26
 * 0 <= score[i] <= 10
 * words[i], letters[i] contains only lower case English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int dfs(vector<string>& ws, vector<int>& cnt, vector<int>& score, int i)
    {
        if (i >= (int)ws.size())
            return 0;
        auto        skipGain = dfs(ws, cnt, score, i + 1), gain = 0, formed = 1;
        vector<int> cnt1(begin(cnt), end(cnt));
        for (auto ch : ws[i])
        {
            if (--cnt1[ch - 'a'] < 0)
                formed = 0;
            gain += score[ch - 'a'];
        }
        return max(skipGain, formed ? gain + dfs(ws, cnt1, score, i + 1) : 0);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score)
    {
        vector<int> cnt(26);
        for (auto ch : letters)
            ++cnt[ch - 'a'];
        return dfs(words, cnt, score, 0);
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<string> words_1   = { "dog", "cat", "dad", "good" };
    vector<char>   letters_1 = { 'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o' };
    vector<int>    score_1
        = { 1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int result_1 = sol.maxScoreWords(words_1, letters_1, score_1);
    cout << result_1 << endl;
    assert(result_1 == 23);

    // Test_2
    vector<string> words_2   = { "xxxz", "ax", "bx", "cx" };
    vector<char>   letters_2 = { 'z', 'a', 'b', 'c', 'x', 'x', 'x' };
    vector<int>    score_2
        = { 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10 };
    int result_2 = sol.maxScoreWords(words_2, letters_2, score_2);
    cout << result_2 << endl;
    assert(result_2 == 27);

    // Test_3
    vector<string> words_3   = { "leetcode" };
    vector<char>   letters_3 = { 'l', 'e', 't', 'c', 'o', 'd' };
    vector<int>    score_3
        = { 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
    int result_3 = sol.maxScoreWords(words_3, letters_3, score_3);
    cout << result_3 << endl;
    assert(result_3 == 0);

    return 0;
}
