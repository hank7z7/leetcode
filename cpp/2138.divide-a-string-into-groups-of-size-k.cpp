/*
 * @lc app=leetcode id=2138 lang=cpp
 *
 * [2138] Divide a String Into Groups of Size k
 *
 * https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/
 *
 * algorithms
 * Easy (67.32%)
 * Likes:    635
 * Dislikes: 24
 * Total Accepted:    105.3K
 * Total Submissions: 141.8K
 * Testcase Example:  '"abcdefghi"\n3\n"x"'
 *
 * A string s can be partitioned into groups of size k using the following
 * procedure:
 * 
 * 
 * The first group consists of the first k characters of the string, the second
 * group consists of the next k characters of the string, and so on. Each
 * element can be a part of exactly one group.
 * For the last group, if the string does not have k characters remaining, a
 * character fill is used to complete the group.
 * 
 * 
 * Note that the partition is done so that after removing the fill character
 * from the last group (if it exists) and concatenating all the groups in
 * order, the resultant string should be s.
 * 
 * Given the string s, the size of each group k and the character fill, return
 * a string array denoting the composition of every group s has been divided
 * into, using the above procedure.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcdefghi", k = 3, fill = "x"
 * Output: ["abc","def","ghi"]
 * Explanation:
 * The first 3 characters "abc" form the first group.
 * The next 3 characters "def" form the second group.
 * The last 3 characters "ghi" form the third group.
 * Since all groups can be completely filled by characters from the string, we
 * do not need to use fill.
 * Thus, the groups formed are "abc", "def", and "ghi".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abcdefghij", k = 3, fill = "x"
 * Output: ["abc","def","ghi","jxx"]
 * Explanation:
 * Similar to the previous example, we are forming the first three groups
 * "abc", "def", and "ghi".
 * For the last group, we can only use the character 'j' from the string. To
 * complete this group, we add 'x' twice.
 * Thus, the 4 groups formed are "abc", "def", "ghi", and "jxx".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s consists of lowercase English letters only.
 * 1 <= k <= 100
 * fill is a lowercase English letter.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.length();
        for (int i = 0; i < n; i += k) {
            string group = s.substr(i, k);
            if ((int)group.length() < k) {
                group.append(k - group.length(), fill);
            }
            result.push_back(group);
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution sol;
    // Test_1
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    vector<string> result = sol.divideString(s, k, fill);
    for (const auto& str : result) {
        cout << str << " ";
    }
    cout << endl;
    assert((result == vector<string>{"abc", "def", "ghi", "jxx"}));

    // Test_2
    s = "abcdefghi";
    k = 3;
    fill = 'x';
    result = sol.divideString(s, k, fill);
    for (const auto& str : result) {
        cout << str << " ";
    }
    cout << endl;
    assert((result == vector<string>{"abc", "def", "ghi"}));

    return 0;
}
// Accepted
// 157/157 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 43.69 % of cpp submissions (9.8 MB)
