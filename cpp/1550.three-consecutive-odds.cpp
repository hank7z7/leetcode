/*
 * @lc app=leetcode id=1550 lang=cpp
 *
 * [1550] Three Consecutive Odds
 *
 * https://leetcode.com/problems/three-consecutive-odds/description/
 *
 * algorithms
 * Easy (63.19%)
 * Likes:    806
 * Dislikes: 71
 * Total Accepted:    135.9K
 * Total Submissions: 204.2K
 * Testcase Example:  '[2,6,4,1]'
 *
 * Given an integer array arr, return true if there are three consecutive odd
 * numbers in the array. Otherwise, return false.
 *
 * Example 1:
 *
 *
 * Input: arr = [2,6,4,1]
 * Output: false
 * Explanation: There are no three consecutive odds.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = [1,2,34,3,4,5,7,23,12]
 * Output: true
 * Explanation: [5,7,23] are three consecutive odds.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= arr.length <= 1000
 * 1 <= arr[i] <= 1000
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool threeConsecutiveOdds(vector<int>& arr)
    {
        bool prev_2 = false;
        bool prev_1 = false;
        bool curr   = false;
        for (auto elem : arr)
        {
            curr = (elem & 1);
            if (prev_2 && prev_1 && curr)
                return true;

            // Update before next element
            prev_2 = prev_1;
            prev_1 = curr;
        }
        return false;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> arr_1 = { 2, 6, 4, 1 };
    bool        res_1 = sol.threeConsecutiveOdds(arr_1);
    cout << res_1 << endl;
    assert(res_1 == false);

    // Test_2
    vector<int> arr_2 = { 1, 2, 34, 3, 4, 5, 7, 23, 12 };
    bool        res_2 = sol.threeConsecutiveOdds(arr_2);
    cout << res_2 << endl;
    assert(res_2 == true);

    return 0;
}
// Accepted
// 32/32 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 45.76 % of cpp submissions (10.6 MB)