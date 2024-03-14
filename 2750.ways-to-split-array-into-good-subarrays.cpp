#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfGoodSubarraySplits(vector<int>& nums)
    {
        int       last_one_index = -1;
        long long ret            = 0;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                if (last_one_index == -1)
                {
                    ret            = 1;
                    last_one_index = i;
                    continue;
                }
                ret *= (i - last_one_index);
                ret %= 1000000007;
                last_one_index = i;
            }
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 0, 1, 0, 0, 1 };
    cout << sol.numberOfGoodSubarraySplits(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { 0, 1, 0 };
    cout << sol.numberOfGoodSubarraySplits(nums_2) << endl;

    // Test_3
    vector<int> nums_3 = { 0, 0 };
    cout << sol.numberOfGoodSubarraySplits(nums_3) << endl;
    return 0;
}
// Success
// Details
// Runtime: 207 ms, faster than 37.67% of C++ online submissions for Ways to Split Array Into Good
// Subarrays. Memory Usage: 238 MB, less than 61.99% of C++ online submissions for Ways to Split
// Array Into Good Subarrays.