/*
 * @lc app=leetcode id=3072 lang=cpp
 *
 * [3072] Distribute Elements Into Two Arrays II
 *
 * https://leetcode.com/problems/distribute-elements-into-two-arrays-ii/description/
 *
 * algorithms
 * Hard (12.58%)
 * Likes:    8
 * Dislikes: 2
 * Total Accepted:    2.6K
 * Total Submissions: 18.7K
 * Testcase Example:  '[2,1,3,3]'
 *
 * You are given a 1-indexed array of integers nums of length n.
 *
 * We define a function greaterCount such that greaterCount(arr, val) returns
 * the number of elements in arr that are strictly greater than val.
 *
 * You need to distribute all the elements of nums between two arrays arr1 and
 * arr2 using n operations. In the first operation, append nums[1] to arr1. In
 * the second operation, append nums[2] to arr2. Afterwards, in the i^th
 * operation:
 *
 *
 * If greaterCount(arr1, nums[i]) > greaterCount(arr2, nums[i]), append nums[i]
 * to arr1.
 * If greaterCount(arr1, nums[i]) < greaterCount(arr2, nums[i]), append nums[i]
 * to arr2.
 * If greaterCount(arr1, nums[i]) == greaterCount(arr2, nums[i]), append
 * nums[i] to the array with a lesser number of elements.
 * If there is still a tie, append nums[i] to arr1.
 *
 *
 * The array result is formed by concatenating the arrays arr1 and arr2. For
 * example, if arr1 == [1,2,3] and arr2 == [4,5,6], then result =
 * [1,2,3,4,5,6].
 *
 * Return the integer array result.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,1,3,3]
 * Output: [2,3,1,3]
 * Explanation: After the first 2 operations, arr1 = [2] and arr2 = [1].
 * In the 3^rd operation, the number of elements greater than 3 is zero in both
 * arrays. Also, the lengths are equal, hence, append nums[3] to arr1.
 * In the 4^th operation, the number of elements greater than 3 is zero in both
 * arrays. As the length of arr2 is lesser, hence, append nums[4] to arr2.
 * After 4 operations, arr1 = [2,3] and arr2 = [1,3].
 * Hence, the array result formed by concatenation is [2,3,1,3].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,14,3,1,2]
 * Output: [5,3,1,2,14]
 * Explanation: After the first 2 operations, arr1 = [5] and arr2 = [14].
 * In the 3^rd operation, the number of elements greater than 3 is one in both
 * arrays. Also, the lengths are equal, hence, append nums[3] to arr1.
 * In the 4^th operation, the number of elements greater than 1 is greater in
 * arr1 than arr2 (2 > 1). Hence, append nums[4] to arr1.
 * In the 5^th operation, the number of elements greater than 2 is greater in
 * arr1 than arr2 (2 > 1). Hence, append nums[5] to arr1.
 * After 5 operations, arr1 = [5,3,1,2] and arr2 = [14].
 * Hence, the array result formed by concatenation is [5,3,1,2,14].
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3,3,3]
 * Output: [3,3,3,3]
 * Explanation: At the end of 4 operations, arr1 = [3,3] and arr2 = [3,3].
 * Hence, the array result formed by concatenation is [3,3,3,3].
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= n <= 10^5
 * 1 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    int greaterCount(vector<int>& arr, int val)
    {
        return arr.end() - upper_bound(arr.begin(), arr.end(), val);
    }

public:
    vector<int> resultArray(vector<int>& nums)
    {
        vector<int> ret_1;
        vector<int> ret_2;
        ret_1.push_back(nums[0]);
        ret_2.push_back(nums[1]);
        vector<int> sorted_1;
        vector<int> sorted_2;
        sorted_1.push_back(nums[0]);
        sorted_2.push_back(nums[1]);
        for (size_t i = 2; i < nums.size(); i++)
        {
            int count_1 = greaterCount(sorted_1, nums[i]);
            int count_2 = greaterCount(sorted_2, nums[i]);
            if (count_1 > count_2)
            {
                ret_1.push_back(nums[i]);
                sorted_1.insert(sorted_1.end() - count_1, nums[i]);
            }
            else if (count_1 < count_2)
            {
                ret_2.push_back(nums[i]);
                sorted_2.insert(sorted_2.end() - count_2, nums[i]);
            }
            else
            {
                if (ret_1.size() <= ret_2.size())
                {
                    ret_1.push_back(nums[i]);
                    sorted_1.insert(sorted_1.end() - count_1, nums[i]);
                }
                else
                {
                    ret_2.push_back(nums[i]);
                    sorted_2.insert(sorted_2.end() - count_2, nums[i]);
                }
            }
        }

        for (auto it : ret_2)
            ret_1.push_back(it);
        return ret_1;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 2, 1, 3, 3 };
    for (auto it : sol.resultArray(nums_1))
        cout << it << " ";
    cout << endl;

    // Test_2
    vector<int> nums_2 = { 5, 14, 3, 1, 2 };
    for (auto it : sol.resultArray(nums_2))
        cout << it << " ";
    cout << endl;

    // Test_3
    vector<int> nums_3 = { 3, 3, 3, 3 };
    for (auto it : sol.resultArray(nums_3))
        cout << it << " ";
    cout << endl;
    return 0;
}
// Accepted
// 784/784 cases passed (1009 ms)
// Your runtime beats 12.5 % of cpp submissions
// Your memory usage beats 62.5 % of cpp submissions (123.2 MB)