/*
 * @lc app=leetcode id=2515 lang=cpp
 *
 * [2515] Shortest Distance to Target String in a Circular Array
 *
 * https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/
 *
 * algorithms
 * Easy (50.55%)
 * Likes:    478
 * Dislikes: 29
 * Total Accepted:    70.6K
 * Total Submissions: 120.5K
 * Testcase Example:  '["hello","i","am","leetcode","hello"]\n"hello"\n1'
 *
 * You are given a 0-indexed circular string array words and a string target. A
 * circular array means that the array's end connects to the array's
 * beginning.
 * 
 * 
 * Formally, the next element of words[i] is words[(i + 1) % n] and the
 * previous element of words[i] is words[(i - 1 + n) % n], where n is the
 * length of words.
 * 
 * 
 * Starting from startIndex, you can move to either the next word or the
 * previous word with 1 step at a time.
 * 
 * Return the shortest distance needed to reach the string target. If the
 * string target does not exist in words, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: words = ["hello","i","am","leetcode","hello"], target = "hello",
 * startIndex = 1
 * Output: 1
 * Explanation: We start from index 1 and can reach "hello" by
 * - moving 3 units to the right to reach index 4.
 * - moving 2 units to the left to reach index 4.
 * - moving 4 units to the right to reach index 0.
 * - moving 1 unit to the left to reach index 0.
 * The shortest distance to reach "hello" is 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: words = ["a","b","leetcode"], target = "leetcode", startIndex = 0
 * Output: 1
 * Explanation: We start from index 0 and can reach "leetcode" by
 * - moving 2 units to the right to reach index 2.
 * - moving 1 unit to the left to reach index 2.
 * The shortest distance to reach "leetcode" is 1.
 * 
 * Example 3:
 * 
 * 
 * Input: words = ["i","eat","leetcode"], target = "ate", startIndex = 0
 * Output: -1
 * Explanation: Since "ate" does not exist in words, we return -1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 100
 * words[i] and target consist of only lowercase English letters.
 * 0 <= startIndex < words.length
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        const int n = (int)words.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (words[i] == target) {
                res = min(res, min(abs(i - startIndex), n - abs(i - startIndex)));
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
// @lc code=end
int main() {
    Solution s;
    // Test_1
    vector<string> words = {"hello","i","am","leetcode","hello"};
    string target = "hello";
    int startIndex = 1;
    cout << s.closestTarget(words, target, startIndex) << endl;
    return 0;
}
// Accepted
// 164/164 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 96.67 % of cpp submissions (18.2 MB)