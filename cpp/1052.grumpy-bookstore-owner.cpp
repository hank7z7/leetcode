/*
 * @lc app=leetcode id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 *
 * https://leetcode.com/problems/grumpy-bookstore-owner/description/
 *
 * algorithms
 * Medium (57.05%)
 * Likes:    1798
 * Dislikes: 152
 * Total Accepted:    83.8K
 * Total Submissions: 144K
 * Testcase Example:  '[1,0,1,2,1,1,7,5]\n[0,1,0,1,0,1,0,1]\n3'
 *
 * There is a bookstore owner that has a store open for n minutes. Every
 * minute, some number of customers enter the store. You are given an integer
 * array customers of length n where customers[i] is the number of the customer
 * that enters the store at the start of the i^th minute and all those
 * customers leave after the end of that minute.
 *
 * On some minutes, the bookstore owner is grumpy. You are given a binary array
 * grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the i^th
 * minute, and is 0 otherwise.
 *
 * When the bookstore owner is grumpy, the customers of that minute are not
 * satisfied, otherwise, they are satisfied.
 *
 * The bookstore owner knows a secret technique to keep themselves not grumpy
 * for minutes consecutive minutes, but can only use it once.
 *
 * Return the maximum number of customers that can be satisfied throughout the
 * day.
 *
 *
 * Example 1:
 *
 *
 * Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes =
 * 3
 * Output: 16
 * Explanation: The bookstore owner keeps themselves not grumpy for the last 3
 * minutes.
 * The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 +
 * 5 = 16.
 *
 *
 * Example 2:
 *
 *
 * Input: customers = [1], grumpy = [0], minutes = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * n == customers.length == grumpy.length
 * 1 <= minutes <= n <= 2 * 10^4
 * 0 <= customers[i] <= 1000
 * grumpy[i] is either 0 or 1.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int n                   = customers.size();
        int unrealizedCustomers = 0;

        // Calculate initial number of unrealized customers in first 'minutes'
        // window
        for (int i = 0; i < minutes; i++)
        {
            unrealizedCustomers += customers[i] * grumpy[i];
        }

        int maxUnrealizedCustomers = unrealizedCustomers;

        // Slide the 'minutes' window across the rest of the customers array
        for (int i = minutes; i < n; i++)
        {
            // Add the current minute's unsatisfied customers if the owner is
            // grumpy and remove the customers that are out of the current
            // window
            unrealizedCustomers += customers[i] * grumpy[i];
            unrealizedCustomers -= customers[i - minutes] * grumpy[i - minutes];

            // Update the maximum unrealized customers
            maxUnrealizedCustomers = max(maxUnrealizedCustomers, unrealizedCustomers);
        }

        // Start with maximum possible satisfied customers due to secret
        // technique
        int totalCustomers = maxUnrealizedCustomers;

        // Add the satisfied customers during non-grumpy minutes
        for (int i = 0; i < n; i++)
        {
            totalCustomers += customers[i] * (1 - grumpy[i]);
        }

        // Return the maximum number of satisfied customers
        return totalCustomers;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> customers_1 = { 1, 0, 1, 2, 1, 1, 7, 5 };
    vector<int> grumpy_1    = { 0, 1, 0, 1, 0, 1, 0, 1 };
    int         minutes_1   = 3;
    int         result_1    = sol.maxSatisfied(customers_1, grumpy_1, minutes_1);
    cout << result_1 << endl;
    assert(result_1 == 16);

    // Test_2
    vector<int> customers_2 = { 1 };
    vector<int> grumpy_2    = { 0 };
    int         minutes_2   = 1;
    int         result_2    = sol.maxSatisfied(customers_2, grumpy_2, minutes_2);
    cout << result_2 << endl;
    assert(result_2 == 1);

    return 0;
}
// Accepted
// 78/78 cases passed (20 ms)
// Your runtime beats 80.7 % of cpp submissions
// Your memory usage beats 11.51 % of cpp submissions (34.5 MB)