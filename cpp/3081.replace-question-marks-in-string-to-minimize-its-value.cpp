/*
You are given a string s. s[i] is either a lowercase English letter or '?'.

For a string t having length m containing only lowercase English letters, we define the function
cost(i) for an index i as the number of characters equal to t[i] that appeared before it, i.e. in
the range [0, i - 1].

The value of t is the sum of cost(i) for all indices i.

For example, for the string t = "aab":

cost(0) = 0
cost(1) = 1
cost(2) = 0
Hence, the value of "aab" is 0 + 1 + 0 = 1.
Your task is to replace all occurrences of '?' in s with any lowercase English letter so that the
value of s is minimized.

Return a string denoting the modified string with replaced occurrences of '?'. If there are multiple
strings resulting in the minimum value, return the lexicographically smallest one.



Example 1:

Input:  s = "???"

Output:  "abc"

Explanation: In this example, we can replace the occurrences of '?' to make s equal to "abc".

For "abc", cost(0) = 0, cost(1) = 0, and cost(2) = 0.

The value of "abc" is 0.

Some other modifications of s that have a value of 0 are "cba", "abz", and, "hey".

Among all of them, we choose the lexicographically smallest.

Example 2:

Input: s = "a?a?"

Output: "abac"

Explanation: In this example, the occurrences of '?' can be replaced to make s equal to "abac".

For "abac", cost(0) = 0, cost(1) = 0, cost(2) = 1, and cost(3) = 0.

The value of "abac" is 1.



Constraints:

1 <= s.length <= 105
s[i] is either a lowercase English letter or '?'.
*/
#include <bits/stdc++.h>
using namespace std;

#define LOWER_SIZE (26)
class Solution
{
public:
    string minimizeStringValue(string s)
    {
        vector<int> count(LOWER_SIZE, 0);
        string      questions;
        for (auto c : s)
        {
            if (c != '?')
                count[c - 'a']++;
        }
        for (int i = 0; i < (int) s.size(); i++)
        {
            char c = s[i];
            if (c == '?')
            {
                int min_time  = INT_MAX;
                int min_index = -1;
                for (int i = 0; i < (int) count.size(); i++)
                {
                    if (count[i] < min_time)
                    {
                        min_time  = count[i];
                        min_index = i;
                    }
                }
                count[min_index]++;
                questions.push_back('a' + min_index);
            }
        }
        sort(questions.begin(), questions.end());
        int questions_top = 0;
        for (int i = 0; i < (int) s.size(); i++)
            if (s[i] == '?')
                s[i] = questions[questions_top++];


        return s;
    }
};


int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s_1 = "???";
    cout << sol.minimizeStringValue(s_1) << endl;

    // Test_2
    string s_2 = "a?b?";
    cout << sol.minimizeStringValue(s_2) << endl;

    // Test_3
    string s_3 = "eq?umjlasi";
    cout << sol.minimizeStringValue(s_3) << endl;

    // Test_4
    string s_4 = "abcdefghijklmnopqrstuvwxy??";
    cout << sol.minimizeStringValue(s_4) << endl;

    return 0;
}
// Status: Accepted
// 548 / 548 test cases passed.
// Runtime: 89 ms, faster than 66.67% of C++ online submissions
// Memory Usage: 20.2 MB, less than 83.33% of C++ online submissions