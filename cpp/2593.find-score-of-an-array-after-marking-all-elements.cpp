/*
 * @lc app=leetcode id=2593 lang=cpp
 *
 * [2593] Find Score of an Array After Marking All Elements
 *
 * https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/
 *
 * algorithms
 * Medium (52.66%)
 * Likes:    778
 * Dislikes: 17
 * Total Accepted:    97.6K
 * Total Submissions: 151.3K
 * Testcase Example:  '[2,1,3,4,5,2]'
 *
 * You are given an array nums consisting of positive integers.
 *
 * Starting with score = 0, apply the following algorithm:
 *
 *
 * Choose the smallest integer of the array that is not marked. If there is a
 * tie, choose the one with the smallest index.
 * Add the value of the chosen integer to score.
 * Mark the chosen element and its two adjacent elements if they exist.
 * Repeat until all the array elements are marked.
 *
 *
 * Return the score you get after applying the above algorithm.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,1,3,4,5,2]
 * Output: 7
 * Explanation: We mark the elements as follows:
 * - 1 is the smallest unmarked element, so we mark it and its two adjacent
 * elements: [2,1,3,4,5,2].
 * - 2 is the smallest unmarked element, so we mark it and its left adjacent
 * element: [2,1,3,4,5,2].
 * - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
 * Our score is 1 + 2 + 4 = 7.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [2,3,5,1,3,2]
 * Output: 5
 * Explanation: We mark the elements as follows:
 * - 1 is the smallest unmarked element, so we mark it and its two adjacent
 * elements: [2,3,5,1,3,2].
 * - 2 is the smallest unmarked element, since there are two of them, we choose
 * the left-most one, so we mark the one at index 0 and its right adjacent
 * element: [2,3,5,1,3,2].
 * - 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
 * Our score is 1 + 2 + 2 = 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^6
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long findScore(const vector<int> &nums)
    {
        const int n = (int)nums.size();
        vector<int> index(n);
        for (int i = 0; i < n; i++)
            index[i] = i;

        sort(index.begin(), index.end(), [&nums](const int &a, const int &b)
             { 
                if(nums[a] < nums[b])
                    return true;
                else if(nums[a] == nums[b])
                    if(a < b)
                        return true;
                return false; });

        long long score = 0;
        vector<bool> mark(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!mark[index[i]])
            {
                score += (long long)nums[index[i]];
                mark[index[i]] = true;
                if (index[i] - 1 >= 0)
                    mark[index[i] - 1] = true;

                if (index[i] + 1 < n)
                    mark[index[i] + 1] = true;
            }
        }
        return score;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {2, 1, 3, 4, 5, 2};
    long long res_1 = sol.findScore(nums_1);
    cout << res_1 << endl;
    assert(res_1 == 7);

    // Test_2
    vector<int> nums_2 = {2, 3, 5, 1, 3, 2};
    long long res_2 = sol.findScore(nums_2);
    cout << res_2 << endl;
    assert(res_2 == 5);

    // Test_3 (WA)
    vector<int> nums_3 = {10, 44, 10, 8, 48, 30, 17, 38, 41, 27, 16, 33, 45, 45, 34, 30, 22, 3, 42, 42};
    long long res_3 = sol.findScore(nums_3);
    cout << res_3 << endl;
    assert(res_3 == 212);

    return 0;
}
// Accepted
// 1044/1044 cases passed (103 ms)
// Your runtime beats 76.17 % of cpp submissions
// Your memory usage beats 98.04 % of cpp submissions (95.9 MB)