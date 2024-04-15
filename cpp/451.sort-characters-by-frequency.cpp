/*
 * @lc app=leetcode id=451 lang=cpp
 *
 * [451] Sort Characters By Frequency
 */
#include <bits/stdc++.h>
// @lc code=start
using namespace std;

class Solution
{
public:
    static int cmp(pair<char, int>& a, pair<char, int>& b) { return a.second > b.second; }

    static string frequencySort(string s)
    {
        unordered_map<char, int> hashmap;
        for (auto it : s)
        {
            auto c = hashmap.find(it);
            // Not found
            if (c == hashmap.end())
            {
                hashmap.insert(pair<char, int>(it, 1));
            }
            else
            {
                hashmap[it]++;
            }
        }

        vector<pair<char, int>> v;
        for (auto it : hashmap)
            v.push_back(pair<char, int>(it.first, it.second));

        sort(v.begin(), v.end(), cmp);

        string result;
        for (auto it : v)
        {
            for (int i = 0; i < it.second; i++)
                result.push_back(it.first);
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    string s_1 = "tree";
    cout << Solution::frequencySort(s_1) << endl;

    // Test_2
    string s_2 = "cccaaa";
    cout << Solution::frequencySort(s_2) << endl;

    // Test_3
    string s_3 = "Aabb";
    cout << Solution::frequencySort(s_3) << endl;

    // Test_4
    string s_4 = "raaeaedere";
    cout << Solution::frequencySort(s_4) << endl;
    return 0;
}
// Accepted
// 33/33 cases passed (11 ms)
// Your runtime beats 59.47 % of cpp submissions
// Your memory usage beats 31.5 % of cpp submissions (10.7 MB)