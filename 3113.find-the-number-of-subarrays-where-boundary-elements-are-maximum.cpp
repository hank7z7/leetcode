/*
 * @lc app=leetcode id=3113 lang=cpp
 *
 * [3113] Find the Number of Subarrays Where Boundary Elements Are Maximum
 *
 * https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/description/
 *
 * algorithms
 * Hard (12.42%)
 * Likes:    8
 * Dislikes: 0
 * Total Accepted:    2K
 * Total Submissions: 15.7K
 * Testcase Example:  '[1,4,3,3,2]'
 *
 * You are given an array of positive integers nums.
 *
 * Return the number of subarrays of nums, where the first and the last
 * elements of the subarray are equal to the largest element in the
 * subarray.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,4,3,3,2]
 *
 * Output: 6
 *
 * Explanation:
 *
 * There are 6 subarrays which have the first and the last elements equal to
 * the largest element of the subarray:
 *
 *
 * subarray [1,4,3,3,2], with its largest element 1. The first element is 1 and
 * the last element is also 1.
 * subarray [1,4,3,3,2], with its largest element 4. The first element is 4 and
 * the last element is also 4.
 * subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and
 * the last element is also 3.
 * subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and
 * the last element is also 3.
 * subarray [1,4,3,3,2], with its largest element 2. The first element is 2 and
 * the last element is also 2.
 * subarray [1,4,3,3,2], with its largest element 3. The first element is 3 and
 * the last element is also 3.
 *
 *
 * Hence, we return 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,3,3]
 *
 * Output: 6
 *
 * Explanation:
 *
 * There are 6 subarrays which have the first and the last elements equal to
 * the largest element of the subarray:
 *
 *
 * subarray [3,3,3], with its largest element 3. The first element is 3 and the
 * last element is also 3.
 * subarray [3,3,3], with its largest element 3. The first element is 3 and the
 * last element is also 3.
 * subarray [3,3,3], with its largest element 3. The first element is 3 and the
 * last element is also 3.
 * subarray [3,3,3], with its largest element 3. The first element is 3 and the
 * last element is also 3.
 * subarray [3,3,3], with its largest element 3. The first element is 3 and the
 * last element is also 3.
 * subarray [3,3,3], with its largest element 3. The first element is 3 and the
 * last element is also 3.
 *
 *
 * Hence, we return 6.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1]
 *
 * Output: 1
 *
 * Explanation:
 *
 * There is a single subarray of nums which is [1], with its largest element 1.
 * The first element is 1 and the last element is also 1.
 *
 * Hence, we return 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long numberOfSubarrays(vector<int> &nums)
    {
        long long res = 0;
        int n = (int)nums.size();
        // Monotonic Stack: (index, count)
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++)
        {
            // Push monotonic stack in decreasing order
            if (st.empty() || nums[i] < nums[st.top().first])
            {
                st.push({i, 1});
            }
            else
            {
                bool find_same = false;
                int same_count = 1;
                // Pop until it is a monotonic stack
                while (!st.empty() && nums[i] >= nums[st.top().first])
                {
                    pair<int, int> st_top = st.top();
                    st.pop();
                    // Find a same start index and update the count
                    if (nums[i] == nums[st_top.first])
                    {
                        find_same = true;
                        same_count += st_top.second;
                        res += st_top.second;
                    }
                }
                // Push new index into stack
                st.push({i, same_count});
            }
        }

        res += (long long)n;
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {1, 4, 3, 3, 2};
    cout << sol.numberOfSubarrays(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = {3, 3, 3};
    cout << sol.numberOfSubarrays(nums_2) << endl;

    // Test_3
    vector<int> nums_3 = {1};
    cout << sol.numberOfSubarrays(nums_3) << endl;
    return 0;
}
// Accepted
// 889/889 cases passed (160 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (110.6 MB)