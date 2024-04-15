/*
 * @lc app=leetcode id=3092 lang=cpp
 *
 * [3092] Most Frequent IDs
 *
 * https://leetcode.com/problems/most-frequent-ids/description/
 *
 * algorithms
 * Medium (33.59%)
 * Likes:    42
 * Dislikes: 8
 * Total Accepted:    7.9K
 * Total Submissions: 23.6K
 * Testcase Example:  '[2,3,2,1]\n[3,2,-3,1]'
 *
 * The problem involves tracking the frequency of IDs in a collection that
 * changes over time. You have two integer arrays, nums and freq, of equal
 * length n. Each element in nums represents an ID, and the corresponding
 * element in freq indicates how many times that ID should be added to or
 * removed from the collection at each step.
 *
 *
 * Addition of IDs: If freq[i] is positive, it means freq[i] IDs with the value
 * nums[i] are added to the collection at step i.
 * Removal of IDs: If freq[i] is negative, it means -freq[i] IDs with the value
 * nums[i] are removed from the collection at step i.
 *
 *
 * Return an array ans of length n, where ans[i] represents the count of the
 * most frequent ID in the collection after the i^th step. If the collection is
 * empty at any step, ans[i] should be 0 for that step.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,2,1], freq = [3,2,-3,1]
 *
 * Output: [3,3,2,2]
 *
 * Explanation:
 *
 * After step 0, we have 3 IDs with the value of 2. So ans[0] = 3.
 * After step 1, we have 3 IDs with the value of 2 and 2 IDs with the value of
 * 3. So ans[1] = 3.
 * After step 2, we have 2 IDs with the value of 3. So ans[2] = 2.
 * After step 3, we have 2 IDs with the value of 3 and 1 ID with the value of
 * 1. So ans[3] = 2.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [5,5,3], freq = [2,-2,1]
 *
 * Output: [2,0,1]
 *
 * Explanation:
 *
 * After step 0, we have 2 IDs with the value of 5. So ans[0] = 2.
 * After step 1, there are no IDs. So ans[1] = 0.
 * After step 2, we have 1 ID with the value of 3. So ans[2] = 1.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length == freq.length <= 10^5
 * 1 <= nums[i] <= 10^5
 * -10^5 <= freq[i] <= 10^5
 * freq[i] != 0
 * The input is generated such that the occurrences of an ID will not be
 * negative in any step.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
    {
        vector<long long> ret;
        // ID -> count
        unordered_map<int, long long> um;
        int max_num = 0;
        long long curr_max = 0;
        for (int i = 0; i < (int)freq.size(); i++)
        {
            um[nums[i]] += (long long)freq[i];

            if (um[nums[i]] <= 0)
                um.erase(nums[i]);
            if (um[nums[i]] > curr_max)
            {
                curr_max = um[nums[i]];
                max_num = nums[i];
                ret.push_back(curr_max);
            }
            else
            {
                if (nums[i] == max_num)
                {
                    auto max_it = max_element(um.begin(),
                                              um.end(),
                                              [](const auto &a, const auto &b)
                                              { return a.second < b.second; });
                    long long most = (max_it != um.end()) ? max_it->second : 0;
                    max_num = max_it->first;
                    curr_max = most;
                    ret.push_back(most);
                }
                else
                {
                    ret.push_back(curr_max);
                }
            }
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = {2, 3, 2, 1};
    vector<int> freq_1 = {3, 2, -3, 1};
    for (auto it : sol.mostFrequentIDs(nums_1, freq_1))
        cout << it << " ";
    cout << endl;

    // Test_2
    vector<int> nums_2 = {5, 5, 3};
    vector<int> freq_2 = {2, -2, 1};
    for (auto it : sol.mostFrequentIDs(nums_2, freq_2))
        cout << it << " ";
    cout << endl;
    return 0;
}
// Accepted
// 622/622 cases passed (191 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 100 % of cpp submissions (141.1 MB)