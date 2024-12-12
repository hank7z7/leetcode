/*
 * @lc app=leetcode id=2558 lang=cpp
 *
 * [2558] Take Gifts From the Richest Pile
 *
 * https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/
 *
 * algorithms
 * Easy (67.05%)
 * Likes:    555
 * Dislikes: 55
 * Total Accepted:    97.2K
 * Total Submissions: 133.2K
 * Testcase Example:  '[25,64,9,4,100]\n4'
 *
 * You are given an integer array gifts denoting the number of gifts in various
 * piles. Every second, you do the following:
 *
 *
 * Choose the pile with the maximum number of gifts.
 * If there is more than one pile with the maximum number of gifts, choose
 * any.
 * Leave behind the floor of the square root of the number of gifts in the
 * pile. Take the rest of the gifts.
 *
 *
 * Return the number of gifts remaining after k seconds.
 *
 *
 * Example 1:
 *
 *
 * Input: gifts = [25,64,9,4,100], k = 4
 * Output: 29
 * Explanation:
 * The gifts are taken in the following way:
 * - In the first second, the last pile is chosen and 10 gifts are left behind.
 * - Then the second pile is chosen and 8 gifts are left behind.
 * - After that the first pile is chosen and 5 gifts are left behind.
 * - Finally, the last pile is chosen again and 3 gifts are left behind.
 * The final remaining gifts are [5,8,9,4,3], so the total number of gifts
 * remaining is 29.
 *
 *
 * Example 2:
 *
 *
 * Input: gifts = [1,1,1,1], k = 4
 * Output: 4
 * Explanation:
 * In this case, regardless which pile you choose, you have to leave behind 1
 * gift in each pile.
 * That is, you can't take any pile with you.
 * So, the total gifts remaining are 4.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= gifts.length <= 10^3
 * 1 <= gifts[i] <= 10^9
 * 1 <= k <= 10^3
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        priority_queue<int> pq;
        for (auto gift : gifts)
            pq.push(gift);

        for (int i = 0; i < k; i++)
        {
            int top = pq.top();
            pq.pop();
            pq.push((int) floor(sqrt(top)));
        }

        long long res = 0;
        while (!pq.empty())
        {
            res += (long long) pq.top();
            pq.pop();
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> gifts_1 = { 25, 64, 9, 4, 100 };
    int k_1 = 4;
    long long res_1 = sol.pickGifts(gifts_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 29);

    // Test_2
    vector<int> gifts_2 = { 1, 1, 1, 1 };
    int k_2 = 4;
    long long res_2 = sol.pickGifts(gifts_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 4);

    return 0;
}
// Accepted
// 102/102 cases passed (3 ms)
// Your runtime beats 54.53 % of cpp submissions
// Your memory usage beats 62.09 % of cpp submissions (13.1 MB)