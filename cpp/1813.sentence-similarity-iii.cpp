/*
 * @lc app=leetcode id=1813 lang=cpp
 *
 * [1813] Sentence Similarity III
 *
 * https://leetcode.com/problems/sentence-similarity-iii/description/
 *
 * algorithms
 * Medium (40.30%)
 * Likes:    530
 * Dislikes: 94
 * Total Accepted:    32.8K
 * Total Submissions: 81.7K
 * Testcase Example:  '"My name is Haley"\n"My Haley"'
 *
 * You are given two strings sentence1 and sentence2, each representing a
 * sentence composed of words. A sentence is a list of words that are separated
 * by a single space with no leading or trailing spaces. Each word consists of
 * only uppercase and lowercase English characters.
 *
 * Two sentences s1 and s2 are considered similar if it is possible to insert
 * an arbitrary sentence (possibly empty) inside one of these sentences such
 * that the two sentences become equal. Note that the inserted sentence must be
 * separated from existing words by spaces.
 *
 * For example,
 *
 *
 * s1 = "Hello Jane" and s2 = "Hello my name is Jane" can be made equal by
 * inserting "my name is" between "Hello" and "Jane" in s1.
 * s1 = "Frog cool" and s2 = "Frogs are cool" are not similar, since although
 * there is a sentence "s are" inserted into s1, it is not separated from
 * "Frog" by a space.
 *
 *
 * Given two sentences sentence1 and sentence2, return true if sentence1 and
 * sentence2 are similar. Otherwise, return false.
 *
 *
 * Example 1:
 *
 *
 * Input: sentence1 = "My name is Haley", sentence2 = "My Haley"
 *
 * Output: true
 *
 * Explanation:
 *
 * sentence2 can be turned to sentence1 by inserting "name is" between "My" and
 * "Haley".
 *
 *
 * Example 2:
 *
 *
 * Input: sentence1 = "of", sentence2 = "A lot of words"
 *
 * Output: false
 *
 * Explanation:
 *
 * No single sentence can be inserted inside one of the sentences to make it
 * equal to the other.
 *
 *
 * Example 3:
 *
 *
 * Input: sentence1 = "Eating right now", sentence2 = "Eating"
 *
 * Output: true
 *
 * Explanation:
 *
 * sentence2 can be turned to sentence1 by inserting "right now" at the end of
 * the sentence.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= sentence1.length, sentence2.length <= 100
 * sentence1 and sentence2 consist of lowercase and uppercase English letters
 * and spaces.
 * The words in sentence1 and sentence2 are separated by a single space.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool areSentencesSimilar(string &s1, string &s2)
    {
        string str;
        vector<string> arr_1, arr_2;
        istringstream iss1(s1);
        while (iss1 >> str)
            arr_1.push_back(str);

        istringstream iss2(s2);
        while (iss2 >> str)
            arr_2.push_back(str);

        const int n1 = arr_1.size();
        const int n2 = arr_2.size();

        int same_prefix = 0;
        for (int i = 0; i < min(n1, n2); i++)
            if (arr_1[i] == arr_2[i])
                same_prefix++;
            else
                break;

        int same_suffix = 0;
        for (int i = 0; i < min(n1, n2); i++)
            if (arr_1[n1 - 1 - i] == arr_2[n2 - 1 - i])
                same_suffix++;
            else
                break;

        if ((same_prefix + same_suffix) >= min(n1, n2))
            return true;
        return false;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string test_1_s1 = "Hello Jane";
    string test_1_s2 = "Hello my name is Jane";
    bool res_1 = sol.areSentencesSimilar(test_1_s1, test_1_s2);
    cout << res_1 << endl;
    assert(res_1 == true);

    // Test_2
    string test_2_s1 = "of";
    string test_2_s2 = "A lot of words";
    bool res_2 = sol.areSentencesSimilar(test_2_s1, test_2_s2);
    cout << res_2 << endl;
    assert(res_2 == false);

    // Test_3
    string test_3_s1 = "My name is Haley";
    string test_3_s2 = "My Haley";
    bool res_3 = sol.areSentencesSimilar(test_3_s1, test_3_s2);
    cout << res_3 << endl;
    assert(res_3 == true);

    // Test_4
    string test_4_s1 = "Eating right now";
    string test_4_s2 = "Eating";
    bool res_4 = sol.areSentencesSimilar(test_4_s1, test_4_s2);
    cout << res_4 << endl;
    assert(res_4 == true);

    // Test_5
    string test_5_s1 = "Ogn WtWj HneS";
    string test_5_s2 = "Ogn WtWj HneS";
    bool res_5 = sol.areSentencesSimilar(test_5_s1, test_5_s2);
    cout << res_5 << endl;
    assert(res_5 == true);

    return 0;
}
// Accepted
// 138/138 cases passed (4 ms)
// Your runtime beats 40.09 % of cpp submissions
// Your memory usage beats 76.5 % of cpp submissions (8.4 MB)