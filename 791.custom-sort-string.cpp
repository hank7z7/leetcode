#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        vector<int> index(26, INT_MAX);
        for (int i = 0; i < (int) order.size(); i++)
            index[order[i] - 'a'] = i;
        sort(s.begin(),
             s.end(),
             [&index](const char& a, const char& b) { return index[a - 'a'] < index[b - 'a']; });
        return s;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string order_1 = "cba";
    string s_1     = "abcd";
    cout << sol.customSortString(order_1, s_1) << endl;

    // Test_2
    string order_2 = "bcafg";
    string s_2     = "abcd";
    cout << sol.customSortString(order_2, s_2) << endl;

    return 0;
}
// Success
// Details
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Custom Sort String.
// Memory Usage: 8.2 MB, less than 30.10% of C++ online submissions for Custom Sort String.