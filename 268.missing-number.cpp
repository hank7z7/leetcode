/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int l = (int)nums.size();
        long long target = (long long)((l + 1) * l / 2);
        long long sum = 0;
        for(int i = 0; i < l; i++)
            sum += (long long)nums[i];
        return (int)(target - sum);
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 3, 0, 1 };
    cout << sol.missingNumber(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { 0,1 };
    cout << sol.missingNumber(nums_2) << endl;

    // Test_3
    vector<int> nums_3 = { 9,6,4,2,3,5,7,0,1 };
    cout << sol.missingNumber(nums_3) << endl;
    return 0;
}
// Accepted
// 122/122 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 54.51 % of cpp submissions (20.2 MB)