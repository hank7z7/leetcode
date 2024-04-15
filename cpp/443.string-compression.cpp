/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 *
 * https://leetcode.com/problems/string-compression/description/
 *
 * algorithms
 * Medium (53.93%)
 * Likes:    4768
 * Dislikes: 7562
 * Total Accepted:    523.1K
 * Total Submissions: 969.8K
 * Testcase Example:  '["a","a","b","b","c","c","c"]'
 *
 * Given an array of characters chars, compress it using the following
 * algorithm:
 *
 * Begin with an empty string s. For each group of consecutive repeating
 * characters in chars:
 *
 *
 * If the group's length is 1, append the character to s.
 * Otherwise, append the character followed by the group's length.
 *
 *
 * The compressed string s should not be returned separately, but instead, be
 * stored in the input character array chars. Note that group lengths that are
 * 10 or longer will be split into multiple characters in chars.
 *
 * After you are done modifying the input array, return the new length of the
 * array.
 *
 * You must write an algorithm that uses only constant extra space.
 *
 *
 * Example 1:
 *
 *
 * Input: chars = ["a","a","b","b","c","c","c"]
 * Output: Return 6, and the first 6 characters of the input array should be:
 * ["a","2","b","2","c","3"]
 * Explanation: The groups are "aa", "bb", and "ccc". This compresses to
 * "a2b2c3".
 *
 *
 * Example 2:
 *
 *
 * Input: chars = ["a"]
 * Output: Return 1, and the first character of the input array should be:
 * ["a"]
 * Explanation: The only group is "a", which remains uncompressed since it's a
 * single character.
 *
 *
 * Example 3:
 *
 *
 * Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
 * Output: Return 4, and the first 4 characters of the input array should be:
 * ["a","b","1","2"].
 * Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to
 * "ab12".
 *
 *
 * Constraints:
 *
 *
 * 1 <= chars.length <= 2000
 * chars[i] is a lowercase English letter, uppercase English letter, digit, or
 * symbol.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int compress(vector<char>& chars)
    {
        size_t l     = chars.size();
        int    count = 0;
        int    idx   = 0;
        for (size_t i = 0; i < l; i++)
        {
            count++;
            if (i == (l - 1) || chars[i] != chars[i + 1])
            {
                // For the char
                chars[idx++] = chars[i];
                // For the number
                if (count > 1)
                {
                    string str  = to_string(count);
                    int    size = (int) str.size();
                    for (int j = 0; j < size; j++)
                        chars[idx++] = str[j];
                }
                count = 0;
            }
        }
        return idx;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<char> chars_1 = { 'a', 'a', 'b', 'b', 'c', 'c', 'c' };
    cout << sol.compress(chars_1) << endl;
    for (auto it : chars_1)
        cout << it;
    cout << endl;

    // Test _2
    vector<char> chars_2 = { 'a' };
    cout << sol.compress(chars_2) << endl;
    for (auto it : chars_2)
        cout << it;
    cout << endl;

    // Test _3
    vector<char> chars_3 = { 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b' };
    cout << sol.compress(chars_3) << endl;
    for (auto it : chars_3)
        cout << it;
    cout << endl;
    return 0;
}
// Accepted
// 76/76 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 28.61 % of cpp submissions (12.6 MB)