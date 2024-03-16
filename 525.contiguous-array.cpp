// Given a binary array nums, return the maximum length of a contiguous subarray with an equal
// number of 0 and 1.


// Example 1:

// Input: nums = [0,1]
// Output: 2
// Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
// Example 2:

// Input: nums = [0,1,0]
// Output: 2
// Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


// Constraints:

// 1 <= nums.length <= 10^5
// nums[i] is either 0 or 1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time: O(N)
    // Space: O(N) (worst case: hash table size = nums.size())
    int findMaxLength(vector<int>& nums)
    {
        int zero_count = 0;
        int one_count  = 0;
        // Diff of #zeros and #ones -> first index
        unordered_map<int, int> um;
        // Initailize the diff zero, if we find a diff 0 on index i, the subarray num[0 : i] is with
        // equal #zeros and #ones.
        um[0] = -1;

        // Initialize result as 0 since the minimum subarray is length 0.
        int ret = 0;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            int num = nums[i];
            // Accumulate the count of zeros and ones
            if (num == 1)
                one_count++;
            else if (num == 0)
                zero_count++;


            int diff = zero_count - one_count;

            if (um.find(diff) == um.end())
            {
                um[diff] = i;
            }
            else
            {
                // Find a same diff before.
                // There is a contiguous subarray nums[um[diff] : i] with equal number of 0 and 1.
                int length = i - um[diff];
                if (length > ret)
                    ret = length;
            }
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    cin.tie(0);
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 0, 1 };
    cout << sol.findMaxLength(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { 0, 1, 0 };
    cout << sol.findMaxLength(nums_2) << endl;

    return 0;
}
// Success
// Details
// Runtime: 88 ms, faster than 53.55% of C++ online submissions
// Memory Usage: 87.6 MB, less than 74.78% of C++ online submissions