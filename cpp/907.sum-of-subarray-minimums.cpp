/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (37.42%)
 * Likes:    7909
 * Dislikes: 601
 * Total Accepted:    249.4K
 * Total Submissions: 666.6K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers arr, find the sum of min(b), where b ranges over
 * every (contiguous) subarray of arr. Since the answer may be large, return
 * the answer modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [3,1,2,4]
 * Output: 17
 * Explanation:
 * Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4],
 * [3,1,2,4].
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
 * Sum is 17.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [11,81,94,43,3]
 * Output: 444
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 3 * 10^4
 * 1 <= arr[i] <= 3 * 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
#define MOD 1000000007
class Solution
{
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        long long result = 0;
        // Monotonic stack for index of increasing subarray
        stack<int> st;
        int        n = (int) arr.size();
        // Index of previous element less than current element
        vector<int> prev(n, 0);
        // Index of next element less than current element
        vector<int> next(n, 0);
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[i] < arr[st.top()])
            {
                int pop_idx = st.top();
                st.pop();
                next[pop_idx] = i;
            }
            if (!st.empty())
                prev[i] = st.top();
            else
                prev[i] = -1;
            st.push(i);
        }
        while (!st.empty())
        {
            int pop_idx = st.top();
            st.pop();
            next[pop_idx] = n;
        }

        for (int i = 0; i < n; i++)
        {
            long long left  = i - prev[i];
            long long right = next[i] - i;
            result += left * right * arr[i] % MOD;
            result = result % MOD;
        }
        return (int) result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> arr_1 = { 3, 1, 2, 4 };
    cout << sol.sumSubarrayMins(arr_1) << endl;

    // Test_2
    vector<int> arr_2 = { 11, 81, 94, 43, 3 };
    cout << sol.sumSubarrayMins(arr_2) << endl;

    return 0;
}
// Accepted
// 88/88 cases passed (59 ms)
// Your runtime beats 76.55 % of cpp submissions
// Your memory usage beats 73.55 % of cpp submissions (44.8 MB)