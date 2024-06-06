/*
 * @lc app=leetcode id=846 lang=cpp
 *
 * [846] Hand of Straights
 *
 * https://leetcode.com/problems/hand-of-straights/description/
 *
 * algorithms
 * Medium (55.84%)
 * Likes:    2954
 * Dislikes: 224
 * Total Accepted:    237.1K
 * Total Submissions: 424.5K
 * Testcase Example:  '[1,2,3,6,2,3,4,7,8]\n3'
 *
 * Alice has some number of cards and she wants to rearrange the cards into
 * groups so that each group is of size groupSize, and consists of groupSize
 * consecutive cards.
 *
 * Given an integer array hand where hand[i] is the value written on the i^th
 * card and an integer groupSize, return true if she can rearrange the cards,
 * or false otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
 * Output: true
 * Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
 *
 *
 * Example 2:
 *
 *
 * Input: hand = [1,2,3,4,5], groupSize = 4
 * Output: false
 * Explanation: Alice's hand can not be rearranged into groups of 4.
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= hand.length <= 10^4
 * 0 <= hand[i] <= 10^9
 * 1 <= groupSize <= hand.length
 *
 *
 *
 * Note: This question is the same as 1296:
 * https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        sort(hand.begin(), hand.end());
        // value -> count
        map<int, int> mp;
        for (auto value : hand)
            mp[value]++;
        for (auto it : mp)
        {
            if (mp[it.first] > 0)
            {
                for (int i = groupSize - 1; i >= 0; i--)
                {
                    mp[it.first + i] -= mp[it.first];
                    if (mp[it.first + i] < 0)
                        return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> hand_1      = { 1, 2, 3, 6, 2, 3, 4, 7, 8 };
    int         groupSize_1 = 3;
    bool        result_1    = sol.isNStraightHand(hand_1, groupSize_1);
    cout << result_1 << endl;
    assert(result_1 == true);

    // Test_2
    vector<int> hand_2      = { 1, 2, 3, 4, 5 };
    int         groupSize_2 = 4;
    bool        result_2    = sol.isNStraightHand(hand_2, groupSize_2);
    cout << result_2 << endl;
    assert(result_2 == false);

    return 0;
}
// Accepted
// 84/84 cases passed (69 ms)
// Your runtime beats 29.97 % of cpp submissions
// Your memory usage beats 33.43 % of cpp submissions (31.6 MB)