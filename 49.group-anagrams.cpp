/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    static vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string>>             result;
        unordered_map<string, vector<int>> um;
        int                                result_top = 0;
        for (int i = 0; i < strs.size(); ++i)
        {
            string c = strs[i];
            sort(begin(c), end(c));
            um[c].push_back(i);
        }

        for (const auto& it : um)
        {
            result.push_back({});
            for (int i : it.second)
                result.back().push_back(strs[i]);
        }

        return result;
    }
};
// @lc code=end

int main(int argc, char** argv)
{
    // Test_1
    vector<string> strs_1;
    strs_1.push_back("eat");
    strs_1.push_back("tea");
    strs_1.push_back("tan");
    strs_1.push_back("ate");
    strs_1.push_back("nat");
    strs_1.push_back("bat");
    vector<vector<string>> result_1 = Solution::groupAnagrams(strs_1);
    cout << "[";
    for (int i = 0; i < result_1.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result_1[i].size(); j++)
        {
            cout << result_1[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    // Test_2
    vector<string>         strs_2;
    vector<vector<string>> result_2 = Solution::groupAnagrams(strs_2);
    cout << "[";
    for (int i = 0; i < result_2.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result_2[i].size(); j++)
        {
            cout << result_2[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;

    // Test_3
    vector<string> strs_3;
    strs_3.push_back("a");
    vector<vector<string>> result_3 = Solution::groupAnagrams(strs_3);
    cout << "[";
    for (int i = 0; i < result_3.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < result_3[i].size(); j++)
        {
            cout << result_3[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}