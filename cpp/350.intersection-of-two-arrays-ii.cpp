/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 *
 * https://leetcode.com/problems/intersection-of-two-arrays-ii/description/
 *
 * algorithms
 * Easy (56.58%)
 * Likes:    7368
 * Dislikes: 950
 * Total Accepted:    1.3M
 * Total Submissions: 2.2M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must appear as many times as it
 * shows in both arrays and you may return the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2,2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [4,9]
 * Explanation: [9,4] is also accepted.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length, nums2.length <= 1000
 * 0 <= nums1[i], nums2[i] <= 1000
 *
 *
 *
 * Follow up:
 *
 *
 * What if the given array is already sorted? How would you optimize your
 * algorithm?
 * What if nums1's size is small compared to nums2's size? Which algorithm is
 * better?
 * What if elements of nums2 are stored on disk, and the memory is limited such
 * that you cannot load all elements into the memory at once?
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> um;
        for (auto num1 : nums1)
            um[num1]++;

        vector<int> res;
        for (auto num2 : nums2)
        {
            if (um.find(num2) != um.end())
            {
                res.push_back(num2);
                um[num2]--;
                if (um[num2] == 0)
                    um.erase(num2);
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums1_1 = { 1, 2, 2, 1 };
    vector<int> nums2_1 = { 2, 2 };
    vector<int> res_1   = sol.intersect(nums1_1, nums2_1);
    for (auto i = 0; i < (int) res_1.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << res_1[i];
    }
    cout << endl;
    assert((res_1 == vector<int>{ 2, 2 }));

    // Test_2
    vector<int> nums1_2 = { 4, 9, 5 };
    vector<int> nums2_2 = { 9, 4, 9, 8, 4 };
    vector<int> res_2   = sol.intersect(nums1_2, nums2_2);
    for (auto i = 0; i < (int) res_2.size(); i++)
    {
        if (i != 0)
            cout << " ";
        cout << res_2[i];
    }
    cout << endl;
    assert((res_2 == vector<int>{ 9, 4 }));

    return 0;
}
// Accepted
// 57/57 cases passed (4 ms)
// Your runtime beats 59.42 % of cpp submissions
// Your memory usage beats 34.02 % of cpp submissions (13.5 MB)