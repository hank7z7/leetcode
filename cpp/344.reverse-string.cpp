/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    void swap(char *x, char *y)
    {
        *y = *x ^ *y;
        *x = *x ^ *y;
        *y = *x ^ *y;
    }

    void reverseString(vector<char> &s)
    {
        for (int i = 0, j = s.size() - 1; i < j; i++, j--)
        {
            // cout << "i = " << s[i] << ", j = " << s[j] << endl;
            swap(&s[i], &s[j]);
        }
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<char> s_1 = {'h', 'e', 'l', 'l', 'o'};
    sol.reverseString(s_1);
    for (auto c : s_1)
        cout << c;
    cout << endl;
    // assert(s_1 == vector<char>(5){'o', 'l', 'l', 'e', 'h'});

    // Test_2
    vector<char> s_2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    sol.reverseString(s_2);
    for (auto c : s_2)
        cout << c;
    cout << endl;
    // assert(s_2 == vector<char>(5){'o', 'l', 'l', 'e', 'h'});
}
// Accepted
// 477/477 cases passed (24 ms)
// Your runtime beats 76.51 % of cpp submissions
// Your memory usage beats 76.65 % of cpp submissions (23.2 MB)