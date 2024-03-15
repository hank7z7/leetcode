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
        vector<int> prefix_product(size, 0);
        vector<int> suffix_product(size, 0);
        vector<int> ret(size, 0);
        int         prev_pre_prod = 1;
        int         prev_suf_prod = 1;
        for (int i = 0; i < size; i++)
        {
            prefix_product[i]            = nums[i] * prev_pre_prod;
            prev_pre_prod                = prefix_product[i];
            suffix_product[size - i - 1] = nums[size - i - 1] * prev_suf_prod;
            prev_suf_prod                = suffix_product[size - i - 1];
        }

        for (int i = 0; i < size; i++)
        {
            int pre_product = (i == 0 ? 1 : prefix_product[i - 1]);
            int suf_product = (i == (size - 1) ? 1 : suffix_product[i + 1]);
            ret[i]          = pre_product * suf_product;
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
