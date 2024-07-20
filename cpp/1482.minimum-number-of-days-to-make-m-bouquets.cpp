/*
 * @lc app=leetcode id=1482 lang=cpp
 *
 * [1482] Minimum Number of Days to Make m Bouquets
 *
 * https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
 *
 * algorithms
 * Medium (56.08%)
 * Likes:    4604
 * Dislikes: 217
 * Total Accepted:    257.2K
 * Total Submissions: 458.5K
 * Testcase Example:  '[1,10,3,10,2]\n3\n1'
 *
 * You are given an integer array bloomDay, an integer m and an integer k.
 *
 * You want to make m bouquets. To make a bouquet, you need to use k adjacent
 * flowers from the garden.
 *
 * The garden consists of n flowers, the i^th flower will bloom in the
 * bloomDay[i] and then can be used in exactly one bouquet.
 *
 * Return the minimum number of days you need to wait to be able to make m
 * bouquets from the garden. If it is impossible to make m bouquets return
 * -1.
 *
 *
 * Example 1:
 *
 *
 * Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
 * Output: 3
 * Explanation: Let us see what happened in the first three days. x means
 * flower bloomed and _ means flower did not bloom in the garden.
 * We need 3 bouquets each should contain 1 flower.
 * After day 1: [x, _, _, _, _]   // we can only make one bouquet.
 * After day 2: [x, _, _, _, x]   // we can only make two bouquets.
 * After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.
 *
 *
 * Example 2:
 *
 *
 * Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
 * Output: -1
 * Explanation: We need 3 bouquets each has 2 flowers, that means we need 6
 * flowers. We only have 5 flowers so it is impossible to get the needed
 * bouquets and we return -1.
 *
 *
 * Example 3:
 *
 *
 * Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
 * Output: 12
 * Explanation: We need 2 bouquets each should have 3 flowers.
 * Here is the garden after the 7 and 12 days:
 * After day 7: [x, x, x, x, _, x, x]
 * We can make one bouquet of the first three flowers that bloomed. We cannot
 * make another bouquet from the last three flowers that bloomed because they
 * are not adjacent.
 * After day 12: [x, x, x, x, x, x, x]
 * It is obvious that we can make two bouquets in different ways.
 *
 *
 *
 * Constraints:
 *
 *
 * bloomDay.length == n
 * 1 <= n <= 10^5
 * 1 <= bloomDay[i] <= 10^9
 * 1 <= m <= 10^6
 * 1 <= k <= n
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        // Impossible to make m bouquets
        if ((long long)m * k > bloomDay.size())
        {
            return -1;
        }

        // Binary search range 1 <= bloomDay[i] <= 10^9
        int low = 1, high = 1e9;
        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool canMakeBouquets(vector<int> &bloomDay, int m, int k, int day)
    {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day)
            {
                count++;
                i++;
            }

            if (count == k)
            {
                total++;
                i--;
            }

            if (total >= m)
            {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> bloomDay_1 = {1, 10, 3, 10, 2};
    int m_1 = 3;
    int k_1 = 1;
    int res_1 = sol.minDays(bloomDay_1, m_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 3);

    // Test_2
    vector<int> bloomDay_2 = {1, 10, 3, 10, 2};
    int m_2 = 3;
    int k_2 = 2;
    int res_2 = sol.minDays(bloomDay_2, m_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == -1);

    // Test_3
    vector<int> bloomDay_3 = {7, 7, 7, 7, 12, 7, 7};
    int m_3 = 2;
    int k_3 = 3;
    int res_3 = sol.minDays(bloomDay_3, m_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == 12);

    return 0;
}
