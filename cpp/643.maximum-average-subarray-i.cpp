/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    double findMaxAverage(vector<int>& nums, int k)
    {
        int sum_of_k = 0;
        for (int i = 0; i < k; i++)
        {
            sum_of_k += nums[i];
        }
        int max    = sum_of_k;
        int offset = nums.size() - k;
        for (int i = 0; i < offset; i++)
        {
            sum_of_k -= nums[i];
            sum_of_k += nums[i + k];
            if (sum_of_k > max)
                max = sum_of_k;
        }

        return (double) max / k;
    }
};
// @lc code=end

// Accepted
// 127/127 cases passed (199 ms)
// Your runtime beats 91.82 % of cpp submissions
// Your memory usage beats 89.28 % of cpp submissions (109.5 MB)