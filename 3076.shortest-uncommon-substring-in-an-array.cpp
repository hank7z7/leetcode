#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> shortestSubstrings(vector<string>& arr)
    {
        unordered_map<string, set<int>> um;
        for (int j = 0; j < (int) arr.size(); j++)
        {
            int l = arr[j].size();
            for (int len = 1; len <= l; len++)
            {
                for (int i = 0; i + len <= l; i++)
                {
                    um[arr[j].substr(i, len)].insert(j);
                }
            }
        }
        vector<string> ret;
        for (int j = 0; j < (int) arr.size(); j++)
        {
            int            l = arr[j].size();
            vector<string> pq;
            for (int len = 1; len <= l; len++)
            {
                for (int i = 0; i + len <= l; i++)
                {
                    if (um[arr[j].substr(i, len)].size() == 1)
                        pq.push_back(arr[j].substr(i, len));
                }
            }
            sort(pq.begin(),
                 pq.end(),
                 [](const string& first, const string& second)
                 {
                     if (first.size() != second.size())
                         return first.size() < second.size();
                     else
                         return (first < second);
                 });
            if (pq.size() > 0)
                ret.push_back(pq[0]);
            else
                ret.push_back("");
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<string> arr_1 = { "cab", "ad", "bad", "c" };
    for (auto str : sol.shortestSubstrings(arr_1))
        cout << str << ", ";
    cout << endl;

    // Test_2
    vector<string> arr_2 = { "abc", "bcd", "abcd" };
    for (auto str : sol.shortestSubstrings(arr_2))
        cout << str << ", ";
    cout << endl;
}
// 631 / 631 test cases passed.
// Status: Accepted
// Runtime: 274 ms
// Memory Usage: 145.6 MB