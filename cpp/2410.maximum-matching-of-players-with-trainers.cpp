/*
 * @lc app=leetcode id=2410 lang=cpp
 *
 * [2410] Maximum Matching of Players With Trainers
 *
 * https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/
 *
 * algorithms
 * Medium (66.48%)
 * Likes:    705
 * Dislikes: 29
 * Total Accepted:    95.8K
 * Total Submissions: 131.6K
 * Testcase Example:  '[4,7,9]\n[8,2,5,8]'
 *
 * You are given a 0-indexed integer array players, where players[i] represents
 * the ability of the i^th player. You are also given a 0-indexed integer array
 * trainers, where trainers[j] represents the training capacity of the j^th
 * trainer.
 * 
 * The i^th player can match with the j^th trainer if the player's ability is
 * less than or equal to the trainer's training capacity. Additionally, the
 * i^th player can be matched with at most one trainer, and the j^th trainer
 * can be matched with at most one player.
 * 
 * Return the maximum number of matchings between players and trainers that
 * satisfy these conditions.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: players = [4,7,9], trainers = [8,2,5,8]
 * Output: 2
 * Explanation:
 * One of the ways we can form two matchings is as follows:
 * - players[0] can be matched with trainers[0] since 4 <= 8.
 * - players[1] can be matched with trainers[3] since 7 <= 8.
 * It can be proven that 2 is the maximum number of matchings that can be
 * formed.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: players = [1,1,1], trainers = [10]
 * Output: 1
 * Explanation:
 * The trainer can be matched with any of the 3 players.
 * Each player can only be matched with one trainer, so the maximum answer is
 * 1.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= players.length, trainers.length <= 10^5
 * 1 <= players[i], trainers[j] <= 10^9
 * 
 * 
 * 
 * Note: This question is the same as  445: Assign Cookies.
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, matches = 0;
        while (i < (int)players.size() && j < (int)trainers.size()) {
            if (players[i] <= trainers[j]) {
                matches++;
                i++;
                j++;
            } else {
                j++;
            }
        }
        return matches;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> players = {4, 7, 9};
    vector<int> trainers = {8, 2, 5, 8};
    int res = sol.matchPlayersAndTrainers(players, trainers);
    cout << res << endl;  // Output: 2
    assert(res == 2);

    // Test_2
    players = {1, 1, 1};
    trainers = {10};
    res = sol.matchPlayersAndTrainers(players, trainers);
    cout << res << endl;  // Output: 1
    assert(res == 1);

    return 0;
}
// Accepted
// 35/35 cases passed (30 ms)
// Your runtime beats 48.66 % of cpp submissions
// Your memory usage beats 85.54 % of cpp submissions (80.1 MB)