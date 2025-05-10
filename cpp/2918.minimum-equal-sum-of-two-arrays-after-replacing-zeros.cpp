/*
 * @lc app=leetcode id=2918 lang=cpp
 *
 * [2918] Minimum Equal Sum of Two Arrays After Replacing Zeros
 *
 * https://leetcode.com/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/description/
 *
 * algorithms
 * Medium (36.52%)
 * Likes:    515
 * Dislikes: 47
 * Total Accepted:    113.3K
 * Total Submissions: 227.1K
 * Testcase Example:  '[3,2,0,1,0]\n[6,5,0]'
 *
 * You are given two arrays nums1 and nums2 consisting of positive integers.
 *
 * You have to replace all the 0's in both arrays with strictly positive
 * integers such that the sum of elements of both arrays becomes equal.
 *
 * Return the minimum equal sum you can obtain, or -1 if it is impossible.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [3,2,0,1,0], nums2 = [6,5,0]
 * Output: 12
 * Explanation: We can replace 0's in the following way:
 * - Replace the two 0's in nums1 with the values 2 and 4. The resulting array
 * is nums1 = [3,2,2,1,4].
 * - Replace the 0 in nums2 with the value 1. The resulting array is nums2 =
 * [6,5,1].
 * Both arrays have an equal sum of 12. It can be shown that it is the minimum
 * sum we can obtain.
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [2,0,2,0], nums2 = [1,4]
 * Output: -1
 * Explanation: It is impossible to make the sum of both arrays equal.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 10^5
 * 0 <= nums1[i], nums2[i] <= 10^6
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        const int n1 = (int) nums1.size();
        const int n2 = (int) nums2.size();
        long long sum1 = 0, sum2 = 0;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n1; ++i)
        {
            if (nums1[i] == 0)
            {
                ++cnt1;
            }
            else
            {
                sum1 += nums1[i];
            }
        }
        for (int i = 0; i < n2; ++i)
        {
            if (nums2[i] == 0)
            {
                ++cnt2;
            }
            else
            {
                sum2 += nums2[i];
            }
        }
        if (cnt1 == 0 && cnt2 == 0)
        {
            return sum1 == sum2 ? sum1 : -1;
        }
        if (cnt1 == 0 && sum2 + cnt2 > sum1)
        {
            return -1;
        }
        if (cnt2 == 0 && sum1 + cnt1 > sum2)
        {
            return -1;
        }
        return max(sum1 + cnt1, sum2 + cnt2);
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    vector<int> nums1 = { 3, 2, 0, 1, 0 };
    vector<int> nums2 = { 6, 5, 0 };
    int res = sol.minSum(nums1, nums2);
    cout << res << endl;  // Output: 12
    assert(res == 12);

    // Test_2
    nums1 = { 2, 0, 2, 0 };
    nums2 = { 1, 4 };
    res = sol.minSum(nums1, nums2);
    cout << res << endl;  // Output: -1
    assert(res == -1);
    return 0;
}
// Accepted
// 636/636 cases passed (128 ms)
// Your runtime beats 65.19 % of cpp submissions
// Your memory usage beats 93.86 % of cpp submissions (135.3 MB)