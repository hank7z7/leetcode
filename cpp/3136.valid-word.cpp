/*
 * @lc app=leetcode id=3136 lang=cpp
 *
 * [3136] Valid WordAccepted
 *
 * https://leetcode.com/problems/valid-word/description/
 *
 * algorithms
 * Easy (38.45%)
 * Likes:    343
 * Dislikes: 152
 * Total Accepted:    132K
 * Total Submissions: 274.2K
 * Testcase Example:  '"234Adas"'
 *
 * A word is considered valid if:
 * 
 * 
 * It contains a minimum of 3 characters.
 * It contains only digits (0-9), and English letters (uppercase and
 * lowercase).
 * It includes at least one vowel.
 * It includes at least one consonant.
 * 
 * 
 * You are given a string word.
 * 
 * Return true if word is valid, otherwise, return false.
 * 
 * Notes:
 * 
 * 
 * 'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
 * A consonant is an English letter that is not a vowel.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word = "234Adas"
 * 
 * Output: true
 * 
 * Explanation:
 * 
 * This word satisfies the conditions.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word = "b3"
 * 
 * Output: false
 * 
 * Explanation:
 * 
 * The length of this word is fewer than 3, and does not have a vowel.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: word = "a3$e"
 * 
 * Output: false
 * 
 * Explanation:
 * 
 * This word contains a '$' character and does not have a consonant.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= word.length <= 20
 * word consists of English uppercase and lowercase letters, digits, '@', '#',
 * and '$'.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
               c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
public:
    bool isValid(string word) {
        if((int)word.length() < 3) {
            return false;  // Length check
        }
        bool hasVowel = false;
        bool hasConsonant = false;
        for(char c : word) {
            if(!isdigit(c) && !isalpha(c)) {
                return false;  // Invalid character check
            }
            if(isalpha(c)){
                if(isVowel(c)) hasVowel = true;
                else hasConsonant = true;
            }
        }
        return hasVowel && hasConsonant;  // Must have both a vowel and a consonant
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string word1 = "234Adas";
    bool res1 = sol.isValid(word1);
    cout << res1 << endl;  // Output: true
    assert(res1 == true);

    // Test_2
    string word2 = "b3";
    bool res2 = sol.isValid(word2);
    cout << res2 << endl;  // Output: false
    assert(res2 == false);

    // Test_3
    string word3 = "a3$e";
    bool res3 = sol.isValid(word3);
    cout << res3 << endl;  // Output: false
    assert(res3 == false);

    // Test_4
    string word4 = "UuE6";
    bool res4 = sol.isValid(word4);
    cout << res4 << endl;  // Output: false
    assert(res4 == false);

    return 0;
}
