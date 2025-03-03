/*
 * @lc app=leetcode id=2161 lang=cpp
 *
 * [2161] Partition Array According to Given Pivot
 *
 * https://leetcode.com/problems/partition-array-according-to-given-pivot/description/
 *
 * algorithms
 * Medium (85.39%)
 * Likes:    1454
 * Dislikes: 105
 * Total Accepted:    182.8K
 * Total Submissions: 205K
 * Testcase Example:  '[9,12,5,10,14,3,10]\n10'
 *
 * You are given a 0-indexed integer array nums and an integer pivot. Rearrange
 * nums such that the following conditions are satisfied:
 *
 *
 * Every element less than pivot appears before every element greater than
 * pivot.
 * Every element equal to pivot appears in between the elements less than and
 * greater than pivot.
 * The relative order of the elements less than pivot and the elements greater
 * than pivot is maintained.
 *
 * More formally, consider every pi, pj where pi is the new position of the
 * i^th element and pj is the new position of the j^th element. If i < j and
 * both elements are smaller (or larger) than pivot, then pi < pj.
 *
 *
 *
 *
 * Return nums after the rearrangement.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [9,12,5,10,14,3,10], pivot = 10
 * Output: [9,5,3,10,10,12,14]
 * Explanation:
 * The elements 9, 5, and 3 are less than the pivot so they are on the left
 * side of the array.
 * The elements 12 and 14 are greater than the pivot so they are on the right
 * side of the array.
 * The relative ordering of the elements less than and greater than pivot is
 * also maintained. [9, 5, 3] and [12, 14] are the respective orderings.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-3,4,3,2], pivot = 2
 * Output: [-3,2,4,3]
 * Explanation:
 * The element -3 is less than the pivot so it is on the left side of the
 * array.
 * The elements 4 and 3 are greater than the pivot so they are on the right
 * side of the array.
 * The relative ordering of the elements less than and greater than pivot is
 * also maintained. [-3] and [4, 3] are the respective orderings.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^6 <= nums[i] <= 10^6
 * pivot equals to an element of nums.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> ans(nums.size());
        int lessI = 0;
        int greaterI = nums.size() - 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i++, j--)
        {
            if (nums[i] < pivot)
            {
                ans[lessI] = nums[i];
                lessI++;
            }
            if (nums[j] > pivot)
            {
                ans[greaterI] = nums[j];
                greaterI--;
            }
        }
        while (lessI <= greaterI)
        {
            ans[lessI] = pivot;
            lessI++;
        }
        return ans;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {9, 12, 5, 10, 14, 3, 10};
    int pivot_1 = 10;
    vector<int> res_1 = sol.pivotArray(nums_1, pivot_1);
    for (auto &it : res_1)
        cout << it << " ";
    cout << endl;
    assert((res_1 == vector<int>{9, 5, 3, 10, 10, 12, 14}));

    // Test_2
    vector<int> nums_2 = {-3, 4, 3, 2};
    int pivot_2 = 2;
    vector<int> res_2 = sol.pivotArray(nums_2, pivot_2);
    for (auto &it : res_2)
        cout << it << " ";
    cout << endl;
    assert((res_2 == vector<int>{-3, 2, 4, 3}));

    return 0;
}
