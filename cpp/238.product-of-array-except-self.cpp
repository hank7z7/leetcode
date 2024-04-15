/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
// Time: O(N)
// Space: O(N)
class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int         size = (int) nums.size();
        vector<int> ret(size, 1);
        int curr;
        curr = 1;
        // Result store the (prefix_product from 0 : i - 1)
        for (int i = 0; i < size; i++)
        {
            ret[i] *= curr;
            curr *= nums[i];
        }

        // Result store the prefix_product * (suffix_product from i + 1 : size - 1)
        curr = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            ret[i] *= curr;
            curr *= nums[i];
        }

        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 2, 3, 4 };
    for (auto it : sol.productExceptSelf(nums_1))
        cout << it << " ";
    cout << endl;

    // Test_2
    vector<int> nums_2 = { -1, 1, 0, -3, 3 };
    for (auto it : sol.productExceptSelf(nums_2))
        cout << it << " ";
    cout << endl;

    return 0;
}

// Success
// Details 
// Runtime: 7 ms, faster than 98.68% of C++ online submissions for Product of Array Except Self.
// Memory Usage: 27.4 MB, less than 23.95% of C++ online submissions for Product of Array Except Self.
