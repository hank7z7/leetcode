/*
 * @lc app=leetcode id=1544 lang=cpp
 *
 * [1544] Make The String Great
 *
 * https://leetcode.com/problems/make-the-string-great/description/
 *
 * algorithms
 * Easy (63.16%)
 * Likes:    2695
 * Dislikes: 139
 * Total Accepted:    220.3K
 * Total Submissions: 334.5K
 * Testcase Example:  '"leEeetcode"'
 *
 * Given a string s of lower and upper case English letters.
 * 
 * A good string is a string which doesn't have two adjacent characters s[i]
 * and s[i + 1] where:
 * 
 * 
 * 0 <= i <= s.length - 2
 * s[i] is a lower-case letter and s[i + 1] is the same letter but in
 * upper-case or vice-versa.
 * 
 * 
 * To make the string good, you can choose two adjacent characters that make
 * the string bad and remove them. You can keep doing this until the string
 * becomes good.
 * 
 * Return the string after making it good. The answer is guaranteed to be
 * unique under the given constraints.
 * 
 * Notice that an empty string is also good.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leEeetcode"
 * Output: "leetcode"
 * Explanation: In the first step, either you choose i = 1 or i = 2, both will
 * result "leEeetcode" to be reduced to "leetcode".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abBAcC"
 * Output: ""
 * Explanation: We have many possible scenarios, and all lead to the same
 * answer. For example:
 * "abBAcC" --> "aAcC" --> "cC" --> ""
 * "abBAcC" --> "abBA" --> "aA" --> ""
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "s"
 * Output: "s"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 100
 * s contains only lower and upper case English letters.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
private:
    bool is_bad(char top, char c)
    {
        if((isupper(top) && islower(c) && (top - 'A') == (c - 'a'))
        || (islower(top) && isupper(c) && (top - 'a') == (c - 'A')))
            return true;
        return false;
    }
public:
    string makeGood(string s) {
        deque<char> dq;
        for(auto c : s)
        {
            if(!dq.empty() && is_bad(dq.back(), c))
                dq.pop_back();         
            else
                dq.push_back(c);
        }
        string result;
        while(!dq.empty())
        {
            result.push_back(dq.front());
            dq.pop_front();
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "leEeetcode";
    cout << sol.makeGood(s_1) << endl;

    // Test_2
    string s_2 = "abBAcC";
    cout << sol.makeGood(s_2) << endl;

    // Test_3
    string s_3 = "s";
    cout << sol.makeGood(s_3) << endl;

    return 0;
}
// Accepted
// 334/334 cases passed (5 ms)
// Your runtime beats 30.95 % of cpp submissions
// Your memory usage beats 49.2 % of cpp submissions (7.4 MB)