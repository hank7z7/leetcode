/*
 * @lc app=leetcode id=2942 lang=cpp
 *
 * [2942] Find Words Containing Character
 *
 * https://leetcode.com/problems/find-words-containing-character/description/
 *
 * algorithms
 * Easy (88.37%)
 * Likes:    503
 * Dislikes: 40
 * Total Accepted:    246.3K
 * Total Submissions: 274.3K
 * Testcase Example:  '["leet","code"]\n"e"'
 *
 * You are given a 0-indexed array of strings words and a character x.
 * 
 * Return an array of indices representing the words that contain the character
 * x.
 * 
 * Note that the returned array may be in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["leet","code"], x = "e"
 * Output: [0,1]
 * Explanation: "e" occurs in both words: "leet", and "code". Hence, we return
 * indices 0 and 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["abc","bcd","aaaa","cbc"], x = "a"
 * Output: [0,2]
 * Explanation: "a" occurs in "abc", and "aaaa". Hence, we return indices 0 and
 * 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["abc","bcd","aaaa","cbc"], x = "z"
 * Output: []
 * Explanation: "z" does not occur in any of the words. Hence, we return an
 * empty array.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 50
 * 1 <= words[i].length <= 50
 * x is a lowercase English letter.
 * words[i] consists only of lowercase English letters.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(auto &word : words) {
            if(word.find(x) != string::npos) {
                res.push_back(&word - &words[0]); // Get index of the word
            }
        }
        return res;
    }
};
// @lc code=end
int main() {
    Solution sol;
    vector<string> words = {"leet", "code", "abc", "bcd"};
    char x = 'e';
    vector<int> result = sol.findWordsContaining(words, x);
    
    cout << "Indices of words containing '" << x << "': ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}
// Accepted
// 912/912 cases passed (3 ms)
// Your runtime beats 26.74 % of cpp submissions
// Your memory usage beats 56.49 % of cpp submissions (33 MB)