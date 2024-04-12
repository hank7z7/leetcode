/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (60.88%)
 * Likes:    31030
 * Dislikes: 478
 * Total Accepted:    2M
 * Total Submissions: 3.2M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it can trap after raining.
 *
 *
 * Example 1:
 *
 *
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by array
 * [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 *
 * Example 2:
 *
 *
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * n == height.length
 * 1 <= n <= 2 * 10^4
 * 0 <= height[i] <= 10^5
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int trap(const vector<int>& height)
    {
        int result = 0;
        // Record the last left index
        stack<int> st;
        for (int i = 0; i < (int) height.size(); i++)
        {
            // Decreasing monotonic stack (No water trap here)
            if (st.empty() || height[i] <= height[st.top()])
            {
                st.push(i);
            }
            // Increase step will become a trap
            else
            {
                // Find a left most highest boundary
                while (!st.empty() && height[st.top()] <= height[i])
                {
                    int buttom = st.top();
                    st.pop();
                    // Cannot be a trap if no left boundary
                    if (!st.empty() && height[st.top()] > height[buttom])
                    {
                        int l_height    = height[st.top()];
                        int r_height    = height[i];
                        int trap_height = min(l_height, r_height) - height[buttom];
                        int trap_width  = i - st.top() - 1;
                        result += trap_height * trap_width;
                    }
                }
                // Push the current index
                st.push(i);
            }
        }
        return result;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> height_1 = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout << sol.trap(height_1) << endl;

    // Test_2
    vector<int> height_2 = { 4, 2, 0, 3, 2, 5 };
    cout << sol.trap(height_2) << endl;

    return 0;
}
// Accepted
// 322/322 cases passed (12 ms)
// Your runtime beats 40.97 % of cpp submissions
// Your memory usage beats 7.88 % of cpp submissions (23.3 MB)