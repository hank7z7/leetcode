/*
 * @lc app=leetcode id=1415 lang=cpp
 *
 * [1415] The k-th Lexicographical String of All Happy Strings of Length n
 *
 * https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/
 *
 * algorithms
 * Medium (75.01%)
 * Likes:    1296
 * Dislikes: 36
 * Total Accepted:    113.3K
 * Total Submissions: 135.6K
 * Testcase Example:  '1\n3'
 *
 * A happy string is a string that:
 *
 *
 * consists only of letters of the set ['a', 'b', 'c'].
 * s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is
 * 1-indexed).
 *
 *
 * For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings
 * and strings "aa", "baa" and "ababbc" are not happy strings.
 *
 * Given two integers n and k, consider a list of all happy strings of length n
 * sorted in lexicographical order.
 *
 * Return the kth string of this list or return an empty string if there are
 * less than k happy strings of length n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 1, k = 3
 * Output: "c"
 * Explanation: The list ["a", "b", "c"] contains all happy strings of length
 * 1. The third string is "c".
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1, k = 4
 * Output: ""
 * Explanation: There are only 3 happy strings of length 1.
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3, k = 9
 * Output: "cab"
 * Explanation: There are 12 different happy string of length 3 ["aba", "abc",
 * "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You
 * will find the 9^th string = "cab"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10
 * 1 <= k <= 100
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    const int set_size = 3;
    const vector<char> char_set{'a', 'b', 'c'};
    int idx;
    int const_n;
    int const_k;

public:
    bool dfs(string &prev)
    {
        char back = prev.length() == 0 ? '#' : prev.back();
        for (int i = 0; i < set_size; i++)
        {
            if (back == char_set[i])
                continue;
            prev.push_back(char_set[i]);
            if ((int)prev.length() == const_n)
            {
                idx++;
                if (idx == const_k)
                    return true;
            }
            else
            {
                bool dfs_res = dfs(prev);
                if (dfs_res)
                    return dfs_res;
            }
            prev.pop_back();
        }
        return false;
    }
    string getHappyString(int n, int k)
    {
        string init;
        idx = 0;
        const_n = n;
        const_k = k;
        bool res = dfs(init);
        if (res)
            return init;
        return "";
    }
};
// @lc code=end

int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int n_1 = 1, k_1 = 3;
    string res_1 = sol.getHappyString(n_1, k_1);
    cout << res_1 << endl;
    assert((res_1 == "c"));

    // Test_2
    int n_2 = 1, k_2 = 4;
    string res_2 = sol.getHappyString(n_2, k_2);
    cout << res_2 << endl;
    assert((res_2 == ""));

    // Test_3
    int n_3 = 3, k_3 = 9;
    string res_3 = sol.getHappyString(n_3, k_3);
    cout << res_3 << endl;
    assert((res_3 == "cab"));

    return 0;
}
// Accepted
// 345/345 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 77.25 % of cpp submissions (9.1 MB)