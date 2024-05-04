/*
 * @lc app=leetcode id=881 lang=cpp
 *
 * [881] Boats to Save People
 *
 * https://leetcode.com/problems/boats-to-save-people/description/
 *
 * algorithms
 * Medium (56.63%)
 * Likes:    6204
 * Dislikes: 152
 * Total Accepted:    367.3K
 * Total Submissions: 626.2K
 * Testcase Example:  '[1,2]\n3'
 *
 * You are given an array people where people[i] is the weight of the i^th
 * person, and an infinite number of boats where each boat can carry a maximum
 * weight of limit. Each boat carries at most two people at the same time,
 * provided the sum of the weight of those people is at most limit.
 *
 * Return the minimum number of boats to carry every given person.
 *
 *
 * Example 1:
 *
 *
 * Input: people = [1,2], limit = 3
 * Output: 1
 * Explanation: 1 boat (1, 2)
 *
 *
 * Example 2:
 *
 *
 * Input: people = [3,2,2,1], limit = 3
 * Output: 3
 * Explanation: 3 boats (1, 2), (2) and (3)
 *
 *
 * Example 3:
 *
 *
 * Input: people = [3,5,3,4], limit = 5
 * Output: 4
 * Explanation: 4 boats (3), (3), (4), (5)
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= people.length <= 5 * 10^4
 * 1 <= people[i] <= limit <= 3 * 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int count = 0;
        sort(people.begin(), people.end());
        int l = 0;
        int r = (int)people.size() - 1;
        while (l <= r)
        {
            // Two people on boat
            if ((people[l] + people[r]) <= limit)
            {
                count++;
                l++;
                r--;
            }
            // The heavier one on boat
            else if (people[r] <= limit)
            {
                count++;
                r--;
            }
        }
        return count;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> people_1 = {1, 2};
    int limit_1 = 3;
    cout << sol.numRescueBoats(people_1, limit_1) << endl;

    // Test_2
    vector<int> people_2 = {3, 2, 2, 1};
    int limit_2 = 3;
    cout << sol.numRescueBoats(people_2, limit_2) << endl;

    // Test_3
    vector<int> people_3 = {3, 5, 3, 4};
    int limit_3 = 5;
    cout << sol.numRescueBoats(people_3, limit_3) << endl;

    return 0;
}
// Accepted
// 78/78 cases passed (55 ms)
// Your runtime beats 71.98 % of cpp submissions
// Your memory usage beats 97.56 % of cpp submissions (45.2 MB)