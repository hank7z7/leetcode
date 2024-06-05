/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 *
 * https://leetcode.com/problems/find-common-characters/description/
 *
 * algorithms
 * Easy (68.84%)
 * Likes:    3710
 * Dislikes: 323
 * Total Accepted:    246.1K
 * Total Submissions: 347.7K
 * Testcase Example:  '["bella","label","roller"]'
 *
 * Given a string array words, return an array of all characters that show up
 * in all strings within the words (including duplicates). You may return the
 * answer in any order.
 *
 *
 * Example 1:
 * Input: words = ["bella","label","roller"]
 * Output: ["e","l","l"]
 * Example 2:
 * Input: words = ["cool","lock","cook"]
 * Output: ["c","o"]
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] consists of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define LOWER_CASE_COUNT 26
class Solution
{
public:
    vector<string> commonChars(vector<string>& words)
    {
        vector<int>    common(LOWER_CASE_COUNT, 1000);
        vector<string> result;
        for (auto word : words)
        {
            vector<int> char_count(LOWER_CASE_COUNT, 0);
            for (auto c : word)
                char_count[c - 'a']++;
            for (int i = 0; i < LOWER_CASE_COUNT; i++)
                common[i] = min(common[i], char_count[i]);
        }
        for (int i = 0; i < LOWER_CASE_COUNT; i++)
        {
            for (int j = 0; j < common[i]; j++)
            {
                string str = "";
                str.push_back('a' + i);
                result.push_back(str);
            }
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<string> words_1  = { "bella", "label", "roller" };
    vector<string> result_1 = sol.commonChars(words_1);
    for (auto str : result_1)
        cout << str;
    cout << endl;

    // Test_2
    vector<string> words_2  = { "cool", "lock", "cook" };
    vector<string> result_2 = sol.commonChars(words_2);
    for (auto str : result_2)
        cout << str;
    cout << endl;

    return 0;
}
// Accepted
// 83/83 cases passed (10 ms)
// Your runtime beats 44.21 % of cpp submissions
// Your memory usage beats 36.52 % of cpp submissions (11.9 MB)