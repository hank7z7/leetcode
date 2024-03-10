/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (68.78%)
 * Likes:    3367
 * Dislikes: 1970
 * Total Accepted:    714.5K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,2,1]\n[2,2]'
 *
 * Given two integer arrays nums1 and nums2, return an array of their
 * intersection. Each element in the result must be unique and you may return
 * the result in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums1 = [1,2,2,1], nums2 = [2,2]
 * Output: [2]
 *
 *
 * Example 2:
 *
 *
 * Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
 * Output: [9,4]
 * Explanation: [4,9] is also accepted.
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
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start

class Solution
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> nums1_set;
        for (auto num : nums1)
            nums1_set.insert(num);
        set<int>    intersection;
        vector<int> ret;
        for (auto num : nums2)
        {
            if (intersection.find(num) == intersection.end()
                && nums1_set.find(num) != nums1_set.end())
            {
                intersection.insert(num);
                ret.push_back(num);
            }
        }
        return ret;
    }
};

// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> test_1_nums_1 = { 1, 2, 2, 1 };
    vector<int> test_1_nums_2 = { 2, 2 };
    for (auto it : sol.intersection(test_1_nums_1, test_1_nums_2))
        cout << it << " ";
    cout << endl;

    // Test_2
    vector<int> test_2_nums_1 = { 4, 9, 5 };
    vector<int> test_2_nums_2 = { 9, 4, 9, 8, 4 };
    for (auto it : sol.intersection(test_2_nums_1, test_2_nums_2))
        cout << it << " ";
    cout << endl;

    return 0;
}
// Success
// Details
// Runtime: 3 ms, faster than 83.79% of C++ online submissions
// Memory Usage: 13.1 MB, less than 32.08% of C++ online submissions