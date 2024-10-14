/*
 * @lc app=leetcode id=2530 lang=cpp
 *
 * [2530] Maximal Score After Applying K Operations
 *
 * https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/
 *
 * algorithms
 * Medium (46.17%)
 * Likes:    447
 * Dislikes: 20
 * Total Accepted:    44.5K
 * Total Submissions: 83.6K
 * Testcase Example:  '[10,10,10,10,10]\n5'
 *
 * You are given a 0-indexed integer array nums and an integer k. You have a
 * starting score of 0.
 *
 * In one operation:
 *
 *
 * choose an index i such that 0 <= i < nums.length,
 * increase your score by nums[i], and
 * replace nums[i] with ceil(nums[i] / 3).
 *
 *
 * Return the maximum possible score you can attain after applying exactly k
 * operations.
 *
 * The ceiling function ceil(val) is the least integer greater than or equal to
 * val.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [10,10,10,10,10], k = 5
 * Output: 50
 * Explanation: Apply the operation to each array element exactly once. The
 * final score is 10 + 10 + 10 + 10 + 10 = 50.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,10,3,3,3], k = 3
 * Output: 17
 * Explanation: You can do the following operations:
 * Operation 1: Select i = 1, so nums becomes [1,4,3,3,3]. Your score increases
 * by 10.
 * Operation 2: Select i = 1, so nums becomes [1,2,3,3,3]. Your score increases
 * by 4.
 * Operation 3: Select i = 2, so nums becomes [1,1,1,3,3]. Your score increases
 * by 3.
 * The final score is 10 + 4 + 3 = 17.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length, k <= 10^5
 * 1 <= nums[i] <= 10^9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        priority_queue<int> pq;
        for (auto& num : nums)
            pq.push(num);

        long long res = 0;
        for (int i = 0; i < k; i++)
        {
            int top = pq.top();
            res += (long long) top;
            pq.pop();
            pq.push(ceil(top / 3.0));
        }

        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 10, 10, 10, 10, 10 };
    int k_1 = 5;
    long long res_1 = sol.maxKelements(nums_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == 50);

    // Test_2
    vector<int> nums_2 = { 1, 10, 3, 3, 3 };
    int k_2 = 3;
    long long res_2 = sol.maxKelements(nums_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == 17);

    // Test_3
    vector<int> nums_3 = { 672579538, 806947365, 854095676, 815137524 };
    int k_3 = 3;
    long long res_3 = sol.maxKelements(nums_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == 2476180565);

    // Test_4
    vector<int> nums_4
        = { 881784984, 829998714, 730002802, 56524562,  120336848,
            548306998, 801116106, 828640251, 519131180, 819176153,
            476262254, 15904939,  540793851, 53572296,  259044378,
            491129827, 561147559, 205793082, 967833729 };
    int k_4 = 16;
    long long res_4 = sol.maxKelements(nums_4, k_4);
    cout << res_4 << endl;
    assert(res_4 == 9888530217);
    return 0;
}
// Accepted
// 39/39 cases passed (195 ms)
// Your runtime beats 57.86 % of cpp submissions
// Your memory usage beats 64.84 % of cpp submissions (79.6 MB)