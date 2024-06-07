/*
 * @lc app=leetcode id=648 lang=cpp
 *
 * [648] Replace Words
 *
 * https://leetcode.com/problems/replace-words/description/
 *
 * algorithms
 * Medium (62.77%)
 * Likes:    2623
 * Dislikes: 195
 * Total Accepted:    199.6K
 * Total Submissions: 303.3K
 * Testcase Example:  '["cat","bat","rat"]\n"the cattle was rattled by the battery"'
 *
 * In English, we have a concept called root, which can be followed by some
 * other curr_word to form another longer curr_word - let's call this curr_word derivative.
 * For example, when the root "help" is followed by the curr_word "ful", we can form
 * a derivative "helpful".
 *
 * Given a dictionary consisting of many roots and a sentence consisting of
 * words separated by spaces, replace all the derivatives in the sentence with
 * the root forming it. If a derivative can be replaced by more than one root,
 * replace it with the root that has the shortest length.
 *
 * Return the sentence after the replacement.
 *
 *
 * Example 1:
 *
 *
 * Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled
 * by the battery"
 * Output: "the cat was rat by the bat"
 *
 *
 * Example 2:
 *
 *
 * Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
 * Output: "a a b c"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= dictionary.length <= 1000
 * 1 <= dictionary[c].length <= 100
 * dictionary[c] consists of only lower-case letters.
 * 1 <= sentence.length <= 10^6
 * sentence consists of only lower-case letters and spaces.
 * The number of words in sentence is in the range [1, 1000]
 * The length of each curr_word in sentence is in the range [1, 1000]
 * Every two consecutive words in sentence will be separated by exactly one
 * space.
 * sentence does not have leading or trailing spaces.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string replaceWords(vector<string>& dictionary, string sentence)
    {
        set<string> us;
        for (auto str : dictionary)
            us.insert(str);

        string curr_word, ret = "";
        // Add a space for end translate
        sentence += ' ';
        for (auto& c : sentence)
        {
            if (c == ' ')
            {
                if (ret.size() > 0)
                    ret += ' ';
                string temp;
                for (auto& j : curr_word)
                {
                    temp += j;
                    if (us.count(temp))
                        break;
                }
                ret += temp;
                curr_word = "";
            }
            else
                curr_word += c;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<string> dict_1     = { "cat", "bat", "rat" };
    string         sentence_1 = "the cattle was rattled by the battery";
    string         result_1   = sol.replaceWords(dict_1, sentence_1);
    cout << result_1 << endl;
    assert(result_1 == "the cat was rat by the bat");

    // Test_2
    vector<string> dict_2     = { "a", "b", "c" };
    string         sentence_2 = "aadsfasf absbs bbab cadsfafs";
    string         result_2   = sol.replaceWords(dict_2, sentence_2);
    cout << result_2 << endl;
    assert(result_2 == "a a b c");

    return 0;
}
// Accepted
// 127/127 cases passed (622 ms)
// Your runtime beats 17.56 % of cpp submissions
// Your memory usage beats 84.88 % of cpp submissions (47.4 MB)