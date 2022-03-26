/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int size = nums.size();
        int ColorCount[3] = {0, 0, 0};
        for (int i = 0; i < size; i++)
            ColorCount[nums[i]]++;
        nums.clear();
        for (int i = 0; i < 3; i++)
        {
            while (ColorCount[i] > 0)
            {
                nums.push_back(i);
                ColorCount[i]--;
            }
        }
    }
};
// @lc code=end

/*
    Accepted
    87/87 cases passed (0 ms)
    Your runtime beats 100 % of cpp submissions
    Your memory usage beats 24.53 % of cpp submissions (8.3 MB)
*/