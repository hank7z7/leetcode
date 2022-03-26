/*
 * @lc app=leetcode id=821 lang=cpp
 *
 * [821] Shortest Distance to a Character
 */

// @lc code=start
class Solution
{
public:
    vector<int> shortestToChar(string s, char c)
    {
        vector<int> output;

        int i = 0;
        int left = -1;
        int size = s.size();
        while (i < size)
        {
            if (s[i] == c)
            {
                // first meet c
                if (left == -1)
                {
                    for (int j = 0; j < i; j++) // left~i
                        output.push_back(i - j);
                    left = i;
                }
                else // meet c again
                {

                    for (int j = 0; j <= (i - left) / 2; j++)
                        output.push_back(j);
                    for (int j = (i - left) % 2 ? (i - left) / 2 : (i - left - 1) / 2; j > 0; j--)
                        output.push_back(j);

                    left = i;
                }
            }
            i++;
        }
        for (int j = 0; j < size - left; j++)
            output.push_back(j);

        return output;
    }
};
// @lc code=end

// Accepted
// 76/76 cases passed (7 ms)
// Your runtime beats 26.77 % of cpp submissions
// Your memory usage beats 57.37 % of cpp submissions (6.8 MB)