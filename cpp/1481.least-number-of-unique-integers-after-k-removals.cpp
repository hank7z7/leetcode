/*
 * @lc app=leetcode id=1481 lang=cpp
 *
 * [1481] Least Number of Unique Integers after K Removals
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    static int findLeastNumOfUniqueInts(vector<int>& arr, int k)
    {
        // <arr element -> index of count>
        unordered_map<int, int> um;
        vector<int>             count;
        int                     count_top = 0;
        for (auto it : arr)
        {
            if (um.find(it) == um.end())
            {
                um[it] = count_top;
                // This element appear one time
                count.push_back(1);
                count_top++;
            }
            else
            {
                count[um[it]]++;
            }
        }

        // Sort since we remove from the least appearence frequency
        sort(count.begin(), count.end());

        int result = count.size();
        for (size_t i = 0; i < count.size(); i++)
        {
            k -= count[i];
            if (k < 0)
                break;
            result--;
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    int k;
    // Test_1
    vector<int> arr_1 = { 5, 5, 4 };
    k                 = 1;
    cout << Solution::findLeastNumOfUniqueInts(arr_1, k) << endl;

    // Test_2
    vector<int> arr_2 = { 4, 3, 1, 1, 3, 3, 2 };
    k                 = 3;
    cout << Solution::findLeastNumOfUniqueInts(arr_2, k) << endl;
    return 0;
}
// Accepted
// 43/43 cases passed (107 ms)
// Your runtime beats 91.43 % of cpp submissions
// Your memory usage beats 51.33 % of cpp submissions (66.1 MB)