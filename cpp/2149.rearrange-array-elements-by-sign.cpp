/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 *
 * https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
 *
 * algorithms
 * Medium (82.23%)
 * Likes:    2872
 * Dislikes: 150
 * Total Accepted:    251.9K
 * Total Submissions: 300.9K
 * Testcase Example:  '[3,1,-2,-5,2,-4]'
 *
 * You are given a 0-indexed integer array nums of even length consisting of an
 * equal number of positive and negative integers.
 *
 * You should rearrange the elements of nums such that the modified array
 * follows the given conditions:
 *
 *
 * Every consecutive pair of integers have opposite signs.
 * For all integers with the same sign, the order in which they were present in
 * nums is preserved.
 * The rearranged array begins with a positive integer.
 *
 *
 * Return the modified array after rearranging the elements to satisfy the
 * aforementioned conditions.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [3,1,-2,-5,2,-4]
 * Output: [3,-2,1,-5,2,-4]
 * Explanation:
 * The positive integers in nums are [3,1,2]. The negative integers are
 * [-2,-5,-4].
 * The only possible way to rearrange them such that they satisfy all
 * conditions is [3,-2,1,-5,2,-4].
 * Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are
 * incorrect because they do not satisfy one or more conditions.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-1,1]
 * Output: [1,-1]
 * Explanation:
 * 1 is the only positive integer and -1 the only negative integer in nums.
 * So nums is rearranged to [1,-1].
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 2 * 10^5
 * nums.length is even
 * 1 <= |nums[i]| <= 10^5
 * nums consists of equal number of positive and negative integers.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    static vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int> ret;
        size_t      l            = nums.size();
        size_t      positive_ptr = 0;
        size_t      negative_ptr = 0;
        while (positive_ptr < l && negative_ptr < l)
        {
            while (!(nums[positive_ptr] >= 0))
            {
                positive_ptr++;
            }
            ret.push_back(nums[positive_ptr]);
            positive_ptr++;
            while (!(nums[negative_ptr] < 0))
            {
                negative_ptr++;
            }
            ret.push_back(nums[negative_ptr]);
            negative_ptr++;
        }
        return ret;
    }
};
// @lc code=end

int main(int argc, char** argvc)
{
    // Test_1
    vector<int> nums_1   = { 3, 1, -2, -5, 2, -4 };
    vector<int> result_1 = Solution::rearrangeArray(nums_1);
    for (auto it : result_1)
        std::cout << it << " ";
    std::cout << std::endl;

    // Test_2
    vector<int> nums_2   = { -1, 1 };
    vector<int> result_2 = Solution::rearrangeArray(nums_2);
    for (auto it : result_2)
        std::cout << it << " ";
    std::cout << std::endl;
    return 0;
}
// Accepted
// 133/133 cases passed (124 ms)
// Your runtime beats 97.61 % of cpp submissions
// Your memory usage beats 35.46 % of cpp submissions (132.4 MB)