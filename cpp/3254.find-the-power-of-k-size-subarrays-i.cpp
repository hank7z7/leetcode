/*
 * @lc app=leetcode id=3254 lang=cpp
 *
 * [3254] Find the Power of K-Size Subarrays I
 *
 * https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/
 *
 * algorithms
 * Medium (51.30%)
 * Likes:    17
 * Dislikes: 1
 * Total Accepted:    28.7K
 * Total Submissions: 56K
 * Testcase Example:  '[1,2,3,4,3,2,5]\n3'
 *
 * You are given an array of integers nums of length n and a positive integer
 * k.
 *
 * The power of an array is defined as:
 *
 *
 * Its maximum element if all of its elements are consecutive and sorted in
 * ascending order.
 * -1 otherwise.
 *
 *
 * You need to find the power of all subarrays of nums of size k.
 *
 * Return an integer array results of size n - k + 1, where results[i] is the
 * power of nums[i..(i + k - 1)].
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,4,3,2,5], k = 3
 *
 * Output: [3,4,-1,-1,-1]
 *
 * Explanation:
 *
 * There are 5 subarrays of nums of size 3:
 *
 *
 * [1, 2, 3] with the maximum element 3.
 * [2, 3, 4] with the maximum element 4.
 * [3, 4, 3] whose elements are not consecutive.
 * [4, 3, 2] whose elements are not sorted.
 * [3, 2, 5] whose elements are not consecutive.
 *
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,2,2,2,2], k = 4
 *
 * Output: [-1,-1]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,2,3,2,3,2], k = 2
 *
 * Output: [-1,3,-1,3,-1]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n == nums.length <= 500
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= n
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = (int)nums.size();
        int last_valid = 0;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (i != 0 && nums[i] != (nums[i - 1] + 1))
                last_valid = i;
            if (i >= (k - 1))
            {
                if ((i - last_valid + 1) >= k)
                    res.push_back(nums[i]);
                else
                    res.push_back(-1);
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 2, 3, 4, 3, 2, 5};
    int k_1 = 3;
    vector<int> res_1 = sol.resultsArray(nums_1, k_1);
    for (auto res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<int>{3, 4, -1, -1, -1}));

    // Test_2
    vector<int> nums_2 = {2, 2, 2, 2, 2};
    int k_2 = 4;
    vector<int> res_2 = sol.resultsArray(nums_2, k_2);
    for (auto res : res_2)
        cout << res << " ";
    cout << endl;
    assert((res_2 == vector<int>{-1, -1}));

    // Test_3
    vector<int> nums_3 = {3, 2, 3, 2, 3, 2};
    int k_3 = 2;
    vector<int> res_3 = sol.resultsArray(nums_3, k_3);
    for (auto res : res_3)
        cout << res << " ";
    cout << endl;
    assert((res_3 == vector<int>{-1, 3, -1, 3, -1}));

    return 0;
}
// Accepted
// 854/854 cases passed (8 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 35.71 % of cpp submissions (33.2 MB)