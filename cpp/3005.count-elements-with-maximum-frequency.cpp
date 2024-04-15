#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        int                     count_max     = 0;
        int                     maxfreq_count = 0;
        unordered_map<int, int> um;
        for (auto num : nums)
        {
            um[num]++;
            if (um[num] == count_max)
            {
                maxfreq_count++;
            }
            if (um[num] > count_max)
            {
                count_max     = um[num];
                maxfreq_count = 1;
            }
        }
        return count_max * maxfreq_count;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 2, 2, 3, 1, 4 };
    cout << sol.maxFrequencyElements(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { 1, 2, 3, 4, 5 };
    cout << sol.maxFrequencyElements(nums_2) << endl;

    return 0;
}