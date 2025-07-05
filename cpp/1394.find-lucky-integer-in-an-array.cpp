/*
 * @lc app=leetcode id=1394 lang=cpp
 *
 * [1394] Find Lucky Integer in an Array
 *
 * https://leetcode.com/problems/find-lucky-integer-in-an-array/description/
 *
 * algorithms
 * Easy (68.97%)
 * Likes:    1364
 * Dislikes: 36
 * Total Accepted:    211.7K
 * Total Submissions: 290.9K
 * Testcase Example:  '[2,2,3,4]'
 *
 * Given an array of integers arr, a lucky integer is an integer that has a
 * frequency in the array equal to its value.
 *
 * Return the largest lucky integer in the array. If there is no lucky integer
 * return -1.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = [2,2,3,4]
 * Output: 2
 * Explanation: The only lucky number in the array is 2 because frequency[2] ==
 * 2.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2,2,3,3,3]
 * Output: 3
 * Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.
 *
 *
 * Example 3:
 *
 *
 * Input: arr = [2,2,2,3,3]
 * Output: -1
 * Explanation: There are no lucky numbers in the array.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 500
 * 1 <= arr[i] <= 500
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int findLucky(vector<int>& arr)
    {
        unordered_map<int, int> freq;
        for (int num : arr)
        {
            freq[num]++;
        }

        int lucky = -1;
        for (const auto& [num, count] : freq)
        {
            if (num == count)
            {
                lucky = max(lucky, num);
            }
        }

        return lucky;
    }
};
// @lc code=end
int main()
{
    Solution solution;
    // Test_1
    vector<int> arr = { 2, 2, 3, 4 };
    int res = solution.findLucky(arr);
    cout << res << endl;
    assert(res == 2);  // Expected output: 2

    // Test_2
    arr = { 1, 2, 2, 3, 3, 3 };
    res = solution.findLucky(arr);
    cout << res << endl;
    assert(res == 3);  // Expected output: 3

    // Test_3
    arr = { 2, 2, 2, 3, 3 };
    res = solution.findLucky(arr);
    cout << res << endl;
    assert(res == -1);  // Expected output: -1

    return 0;
}
// Accepted
// 101/101 cases passed (3 ms)
// Your runtime beats 21.69 % of cpp submissions
// Your memory usage beats 11.89 % of cpp submissions (14.1 MB)