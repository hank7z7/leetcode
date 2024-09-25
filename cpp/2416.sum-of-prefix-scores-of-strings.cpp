/*
 * @lc app=leetcode id=2416 lang=cpp
 *
 * [2416] Sum of Prefix Scores of Strings
 *
 * https://leetcode.com/problems/sum-of-prefix-scores-of-strings/description/
 *
 * algorithms
 * Hard (46.40%)
 * Likes:    870
 * Dislikes: 73
 * Total Accepted:    53.5K
 * Total Submissions: 99K
 * Testcase Example:  '["abc","ab","bc","b"]'
 *
 * You are given an array words of size n consisting of non-empty strings.
 *
 * We define the score of a string word as the number of strings words[i] such
 * that word is a prefix of words[i].
 *
 *
 * For example, if words = ["a", "ab", "abc", "cab"], then the score of "ab" is
 * 2, since "ab" is a prefix of both "ab" and "abc".
 *
 *
 * Return an array answer of size n where answer[i] is the sum of scores of
 * every non-empty prefix of words[i].
 *
 * Note that a string is considered as a prefix of itself.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["abc","ab","bc","b"]
 * Output: [5,4,3,2]
 * Explanation: The answer for each string is the following:
 * - "abc" has 3 prefixes: "a", "ab", and "abc".
 * - There are 2 strings with the prefix "a", 2 strings with the prefix "ab",
 * and 1 string with the prefix "abc".
 * The total is answer[0] = 2 + 2 + 1 = 5.
 * - "ab" has 2 prefixes: "a" and "ab".
 * - There are 2 strings with the prefix "a", and 2 strings with the prefix
 * "ab".
 * The total is answer[1] = 2 + 2 = 4.
 * - "bc" has 2 prefixes: "b" and "bc".
 * - There are 2 strings with the prefix "b", and 1 string with the prefix
 * "bc".
 * The total is answer[2] = 2 + 1 = 3.
 * - "b" has 1 prefix: "b".
 * - There are 2 strings with the prefix "b".
 * The total is answer[3] = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["abcd"]
 * Output: [4]
 * Explanation:
 * "abcd" has 4 prefixes: "a", "ab", "abc", and "abcd".
 * Each prefix has a score of one, so the total is answer[0] = 1 + 1 + 1 + 1 =
 * 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 1000
 * 1 <= words[i].length <= 1000
 * words[i] consists of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
struct TrieNode
{
    struct TrieNode* next[26] = {}; // lower case letter
    int count = 0;
};

class Solution
{
private:
    TrieNode trie;
public:
    vector<int> sumPrefixScores(const vector<string>& words)
    {
        const int n = (int) words.size();
        // prefix -> count
        unordered_map<string_view, int> um;
        for (const auto& word : words)
        {
            // For every word, insert prefix to trie
            struct TrieNode* curr = &trie;
            for(const auto& c : word)
            {
                if(!curr->next[c - 'a'])
                    curr->next[c - 'a'] = new TrieNode();
                curr = curr->next[c - 'a'];
                curr->count++;
            }
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            string_view word = words[i];
            // For every word, search prefix in trie
            struct TrieNode* curr = &trie;
            for(const auto& c : word)
            {
                curr = curr->next[c - 'a'];
                res[i] += curr->count;
            }
        }

        return res;
    }
};

/* Hash Map
class Solution
{
public:
    vector<int> sumPrefixScores(const vector<string>& words)
    {
        const int n = (int) words.size();
        // prefix -> count
        unordered_map<string_view, int> um;
        for (const auto& word : words)
            for (size_t len = 1, sz = word.size(); len <= sz; len++)
            {
                string_view prefix = string_view(word.data(), len);
                um[prefix]++;
            }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (size_t len = 1, sz = words[i].size(); len <= sz; len++)
            {
                string_view prefix = string_view(words[i].data(), len);
                res[i] += um[prefix];
            }
        }
        return res;
    }
};
*/
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<string> words_1 = { "abc", "ab", "bc", "b" };
    vector<int> res_1 = sol.sumPrefixScores(words_1);
    for (auto res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{ 5, 4, 3, 2 }));

    // Test_2
    vector<string> words_2 = { "abcd" };
    vector<int> res_2 = sol.sumPrefixScores(words_2);
    for (auto res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{ 4 }));

    // Test_3
    vector<string> words_3 = { "bfiaaaaifb", "aaaaooaaaa" };
    vector<int> res_3 = sol.sumPrefixScores(words_3);
    for (auto res : res_3)
        cout << res << " ";
    cout << endl;
    assert((res_3 == vector<int>{ 10, 10 }));

    return 0;
}
// Hash Map
// Accepted
// 38/38 cases passed (2723 ms)
// Your runtime beats 5.23 % of cpp submissions
// Your memory usage beats 87.28 % of cpp submissions (236 MB)

// Accepted
// 38/38 cases passed (626 ms)
// Your runtime beats 37.4 % of cpp submissions
// Your memory usage beats 63.84 % of cpp submissions (704.2 MB)