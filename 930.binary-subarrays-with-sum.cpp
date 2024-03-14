#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        unordered_map<int, int> um;
        int                     prefix_sum = 0;
        int                     ret        = 0;
        um[0]++;
        for (auto num : nums)
        {
            prefix_sum += num;
            // nums[j : i] sum with goal and nums[0 : j - 1] sum with prefix_sum - goal
            ret += um[prefix_sum - goal];
            um[prefix_sum]++;
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    int      goal;
    // Test_1
    goal               = 2;
    vector<int> nums_1 = { 1, 0, 1, 0, 1 };
    cout << sol.numSubarraysWithSum(nums_1, goal) << endl;

    // Test_2
    goal               = 0;
    vector<int> nums_2 = { 0, 0, 0, 0, 0 };
    cout << sol.numSubarraysWithSum(nums_2, goal) << endl;

    return 0;
}
// Success
// Details
// Runtime: 51 ms, faster than 28.85% of C++ online submissions for Binary Subarrays With Sum.
// Memory Usage: 40 MB, less than 10.17% of C++ online submissions for Binary Subarrays With Sum.