/*
 * @lc app=leetcode id=948 lang=cpp
 *
 * [948] Bag of Tokens
 *
 * https://leetcode.com/problems/bag-of-tokens/description/
 *
 * algorithms
 * Medium (52.26%)
 * Likes:    2798
 * Dislikes: 484
 * Total Accepted:    161.1K
 * Total Submissions: 286.5K
 * Testcase Example:  '[100]\n50'
 *
 * You start with an initial power of power, an initial score of 0, and a bag
 * of tokens given as an integer array tokens, where each tokens[i] donates the
 * value of tokeni.
 *
 * Your goal is to maximize the total score by strategically playing these
 * tokens. In one move, you can play an unplayed token in one of the two ways
 * (but not both for the same token):
 *
 *
 * Face-up: If your current power is at least tokens[i], you may play tokeni,
 * losing tokens[i] power and gaining 1 score.
 * Face-down: If your current score is at least 1, you may play tokeni, gaining
 * tokens[i] power and losing 1 score.
 *
 *
 * Return the maximum possible score you can achieve after playing any number
 * of tokens.
 *
 *
 * Example 1:
 *
 *
 * Input: tokens = [100], power = 50
 *
 * Output: 0
 *
 * Explanation: Since your score is 0 initially, you cannot play the token
 * face-down. You also cannot play it face-up since your power (50) is less
 * than tokens[0] (100).
 *
 *
 * Example 2:
 *
 *
 * Input: tokens = [200,100], power = 150
 *
 * Output: 1
 *
 * Explanation: Play token1 (100) face-up, reducing your power to 50 and
 * increasing your score to 1.
 *
 * There is no need to play token0, since you cannot play it face-up to add to
 * your score. The maximum score achievable is 1.
 *
 *
 * Example 3:
 *
 *
 * Input: tokens = [100,200,300,400], power = 200
 *
 * Output: 2
 *
 * Explanation: Play the tokens in this order to get a score of 2:
 *
 *
 * Play token0 (100) face-up, reducing power to 100 and increasing score to
 * 1.
 * Play token3 (400) face-down, increasing power to 500 and reducing score to
 * 0.
 * Play token1 (200) face-up, reducing power to 300 and increasing score to
 * 1.
 * Play token2 (300) face-up, reducing power to 0 and increasing score to 2.
 *
 *
 * The maximum score achievable is 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= tokens.length <= 1000
 * 0 <= tokens[i], power < 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int l     = 0;
        int r     = tokens.size() - 1;
        // Becareful the NULL tokens
        if (r < 0)
            return 0;
        while (power >= tokens[l] && l <= r)
        {
            // First step, buy score from the cheapest power
            // cout << "buy " << l << endl;
            power -= tokens[l];
            l++;
            score++;
            if (l > r)
                break;
            // Second step, sale most power for buying next cheapest power
            if (power < tokens[l] && (power + tokens[r]) > tokens[l] && r >= (l + 1))
            {
                // cout << "sale " << r << endl;
                power += tokens[r];
                r--;
                score--;
            }
        }
        return score;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    int      power;
    // Test_1
    vector<int> tokens_1 = { 100 };
    power                = 50;
    cout << sol.bagOfTokensScore(tokens_1, power) << endl;

    // Test_2
    vector<int> tokens_2 = { 200, 100 };
    power                = 150;
    cout << sol.bagOfTokensScore(tokens_2, power) << endl;

    // Test_3
    vector<int> tokens_3 = { 100, 200, 300, 400 };
    power                = 200;
    cout << sol.bagOfTokensScore(tokens_3, power) << endl;

    // Test_4
    vector<int> tokens_4 = { 100 };
    power                = 150;
    cout << sol.bagOfTokensScore(tokens_4, power) << endl;

    // Test_5
    vector<int> tokens_5 = {};
    power                = 50;
    cout << sol.bagOfTokensScore(tokens_5, power) << endl;

    return 0;
}
// Accepted
// 147/147 cases passed (3 ms)
// Your runtime beats 86.63 % of cpp submissions
// Your memory usage beats 70.94 % of cpp submissions (12.9 MB)