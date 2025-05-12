/*
 * @lc app=leetcode id=2094 lang=cpp
 *
 * [2094] Finding 3-Digit Even Numbers
 *
 * https://leetcode.com/problems/finding-3-digit-even-numbers/description/
 *
 * algorithms
 * Easy (63.40%)
 * Likes:    1057
 * Dislikes: 297
 * Total Accepted:    74.9K
 * Total Submissions: 103.3K
 * Testcase Example:  '[2,1,3,0]'
 *
 * You are given an integer array digits, where each element is a digit. The
 * array may contain duplicates.
 *
 * You need to find all the unique integers that follow the given
 * requirements:
 *
 *
 * The integer consists of the concatenation of three elements from digits in
 * any arbitrary order.
 * The integer does not have leading zeros.
 * The integer is even.
 *
 *
 * For example, if the given digits were [1, 2, 3], integers 132 and 312 follow
 * the requirements.
 *
 * Return a sorted array of the unique integers.
 *
 *
 * Example 1:
 *
 *
 * Input: digits = [2,1,3,0]
 * Output: [102,120,130,132,210,230,302,310,312,320]
 * Explanation: All the possible integers that follow the requirements are in
 * the output array.
 * Notice that there are no odd integers or integers with leading zeros.
 *
 *
 * Example 2:
 *
 *
 * Input: digits = [2,2,8,8,2]
 * Output: [222,228,282,288,822,828,882]
 * Explanation: The same digit can be used as many times as it appears in
 * digits.
 * In this example, the digit 8 is used twice each time in 288, 828, and
 * 882.
 *
 *
 * Example 3:
 *
 *
 * Input: digits = [3,7,5]
 * Output: []
 * Explanation: No even integers can be formed using the given digits.
 *
 *
 *
 * Constraints:
 *
 *
 * 3 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> findEvenNumbers(vector<int>& digits)
    {
        int third = 0;
        int second = 0;
        int first = 0;
        vector<int> cnt(10, 0);
        for (auto digit : digits)
            cnt[digit]++;

        vector<int> res;
        vector<int> cnt_curr(10, 0);
        for (int i = 100; i <= 999; i += 2)
        {
            third = i % 10;
            second = (i / 10) % 10;
            first = i / 100;
            for(int j = 0; j < 10; j++)
                cnt_curr[j] = 0;
            cnt_curr[third]++;
            cnt_curr[second]++;
            cnt_curr[first]++;
            if (cnt_curr[first] <= cnt[first] && cnt_curr[second] <= cnt[second]
                && cnt_curr[third] <= cnt[third])
                res.push_back(i);
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> digits = { 2, 1, 3, 0 };
    vector<int> res = sol.findEvenNumbers(digits);
    for (auto num : res)
        cout << num << " ";
    cout << endl;
    assert(res == vector<int>({ 102, 120, 130, 132, 210, 230, 302, 310, 312, 320 }));

    // Test_2
    digits = { 2, 2, 8, 8, 2 };
    res = sol.findEvenNumbers(digits);
    for (auto num : res)
        cout << num << " ";
    cout << endl;
    assert(res == vector<int>({ 222, 228, 282, 288, 822, 828, 882 }));

    // Test_3
    digits = { 3, 7, 5 };
    res = sol.findEvenNumbers(digits);
    for (auto num : res)
        cout << num << " ";
    cout << endl;
    assert(res == vector<int>({}));

    return 0;
}
// Accepted
// 79/79 cases passed (3 ms)
// Your runtime beats 81.83 % of cpp submissions
// Your memory usage beats 99.4 % of cpp submissions (12.3 MB)