/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define LOWERCASE_LETTER_SIZE (26)
#define FIRST_LOWERCASE ('a')
struct VectorHasher
{
    int operator()(const vector<int>& V) const
    {
        int hash = V.size();
        for (auto& i : V)
        {
            hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
        }
        cout << "hash = " << hash << endl;
        return hash;
    }
};
class Solution
{
public:
    static vector<vector<string>> groupAnagrams(const vector<string>& strs)
    {
        vector<int>                count(LOWERCASE_LETTER_SIZE);
        vector<vector<string>>     result;
        unordered_map<string, int> um;
        int                        result_top = 0;
        for (size_t i = 0; i < strs.size(); ++i)
        {
            // Use string as count table since unordered_map doesn't support vector<int> as key
            string count_table;
            for (size_t j = 0; j < LOWERCASE_LETTER_SIZE; j++)
                count_table.push_back(0);
            for (size_t j = 0; j < strs[i].size(); j++)
                count_table[strs[i][j] - FIRST_LOWERCASE]++;
            auto it = um.find(count_table);
            // HashMap not found
            if (it == um.end())
            {
                // Push current string into result
                result.push_back({});
                result[result_top].push_back(strs[i]);
                // Add count table as key
                um[count_table] = result_top;
                result_top++;
            }
            // HashMap found
            else
            {
                result[it->second].push_back(strs[i]);
            }
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
    for (size_t i = 0; i < result_1.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < result_1[i].size(); j++)
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
    for (size_t i = 0; i < result_2.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < result_2[i].size(); j++)
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
    for (size_t i = 0; i < result_3.size(); i++)
    {
        cout << "[";
        for (size_t j = 0; j < result_3[i].size(); j++)
        {
            cout << result_3[i][j] << " ";
        }
        cout << "]";
    }
    cout << "]" << endl;
}
// Accepted
// 120/120 cases passed (21 ms)
// Your runtime beats 93.86 % of cpp submissions
// Your memory usage beats 29.02 % of cpp submissions (24.1 MB)