/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.33%)
 * Likes:    16339
 * Dislikes: 596
 * Total Accepted:    1.8M
 * Total Submissions: 2.9M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
  public:
    static vector<int> topKFrequent(vector<int> &nums, int k) {
        // map = <key, count>
        unordered_map<int, int> map;
        priority_queue<pair<int, int>> queue;
        vector<int> res;

        for (auto i : nums)
            map[i]++;
        for (auto it : map)
            queue.push({it.second, it.first});
        for (int i = 0; i < k; ++i) {
            res.push_back(queue.top().second);
            queue.pop();
        }

        return res;
    }
};

// @lc code=end

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // test 1
    int k = 2;
    vector<int> nums1 = {1, 1, 1, 2, 2, 3};
    vector<int> result1 = Solution::topKFrequent(nums1, k);
    for (int i = 0; i < k; i++) {
        cout << result1[i] << " ";
    }
    cout << endl;

    // test 1
    k = 1;
    vector<int> nums2 = {1};
    vector<int> result2 = Solution::topKFrequent(nums2, k);
    for (int i = 0; i < k; i++) {
        cout << result2[i] << " ";
    }
    cout << endl;

    return 0;
}

// Accepted
// 21/21 cases passed (11 ms)
// Your runtime beats 74.85 % of cpp submissions
// Your memory usage beats 45.26 % of cpp submissions (14.1 MB)
