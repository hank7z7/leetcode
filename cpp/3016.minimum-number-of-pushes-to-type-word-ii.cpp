/*
 * @lc app=leetcode id=3016 lang=cpp
 *
 * [3016] Minimum Number of Pushes to Type Word II
 *
 * https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/description/
 *
 * algorithms
 * Medium (70.56%)
 * Likes:    215
 * Dislikes: 13
 * Total Accepted:    39.7K
 * Total Submissions: 52.4K
 * Testcase Example:  '"abcde"'
 *
 * You are given a string word containing lowercase English letters.
 *
 * Telephone keypads have keys mapped with distinct collections of lowercase
 * English letters, which can be used to form words by pushing them. For
 * example, the key 2 is mapped with ["a","b","c"], we need to push the key one
 * time to type "a", two times to type "b", and three times to type "c" .
 *
 * It is allowed to remap the keys numbered 2 to 9 to distinct collections of
 * letters. The keys can be remapped to any amount of letters, but each letter
 * must be mapped to exactly one key. You need to find the minimum number of
 * times the keys will be pushed to type the string word.
 *
 * Return the minimum number of pushes needed to type word after remapping the
 * keys.
 *
 * An example mapping of letters to keys on a telephone keypad is given below.
 * Note that 1, *, #, and 0 do not map to any letters.
 *
 *
 * Example 1:
 *
 *
 * Input: word = "abcde"
 * Output: 5
 * Explanation: The remapped keypad given in the image provides the minimum
 * cost.
 * "a" -> one push on key 2
 * "b" -> one push on key 3
 * "c" -> one push on key 4
 * "d" -> one push on key 5
 * "e" -> one push on key 6
 * Total cost is 1 + 1 + 1 + 1 + 1 = 5.
 * It can be shown that no other mapping can provide a lower cost.
 *
 *
 * Example 2:
 *
 *
 * Input: word = "xyzxyzxyzxyz"
 * Output: 12
 * Explanation: The remapped keypad given in the image provides the minimum
 * cost.
 * "x" -> one push on key 2
 * "y" -> one push on key 3
 * "z" -> one push on key 4
 * Total cost is 1 * 4 + 1 * 4 + 1 * 4 = 12
 * It can be shown that no other mapping can provide a lower cost.
 * Note that the key 9 is not mapped to any letter: it is not necessary to map
 * letters to every key, but to map all the letters.
 *
 *
 * Example 3:
 *
 *
 * Input: word = "aabbccddeeffgghhiiiiii"
 * Output: 24
 * Explanation: The remapped keypad given in the image provides the minimum
 * cost.
 * "a" -> one push on key 2
 * "b" -> one push on key 3
 * "c" -> one push on key 4
 * "d" -> one push on key 5
 * "e" -> one push on key 6
 * "f" -> one push on key 7
 * "g" -> one push on key 8
 * "h" -> two pushes on key 9
 * "i" -> one push on key 9
 * Total cost is 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 1 * 2 + 2 * 2
 * + 6 * 1 = 24.
 * It can be shown that no other mapping can provide a lower cost.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 10^5
 * word consists of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumPushes(string& word)
    {
        vector<int> count(26, 0);
        for (auto& c : word)
            count[c - 'a']++;
        sort(count.begin(), count.end(), greater());

        int res   = 0;
        int keys  = 8;
        int times = 1;
        for (auto& c : count)
        {
            if (c == 0)
                break;
            res += times * c;
            keys--;
            if (keys == 0)
            {
                keys = 8;
                times++;
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string word_1 = "abcde";
    int    res_1  = sol.minimumPushes(word_1);
    cout << res_1 << endl;
    assert(res_1 == 5);

    // Test_2
    string word_2 = "xyzxyzxyzxyz";
    int    res_2  = sol.minimumPushes(word_2);
    cout << res_2 << endl;
    assert(res_2 == 12);

    // Test_3
    string word_3 = "aabbccddeeffgghhiiiiii";
    int    res_3  = sol.minimumPushes(word_3);
    cout << res_3 << endl;
    assert(res_3 == 24);

    // Test_4
    string word_4 = "hiknogatpyjzcdbe";
    int    res_4  = sol.minimumPushes(word_4);
    cout << res_4 << endl;
    assert(res_4 == 24);

    return 0;
}
// Accepted
// 877/877 cases passed (71 ms)
// Your runtime beats 66.7 % of cpp submissions
// Your memory usage beats 98.11 % of cpp submissions (21 MB)