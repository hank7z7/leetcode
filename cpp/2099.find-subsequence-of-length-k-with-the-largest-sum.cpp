/*
 * @lc app=leetcode id=2099 lang=cpp
 *
 * [2099] Find Subsequence of Length K With the Largest Sum
 *
 * https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/description/
 *
 * algorithms
 * Easy (45.12%)
 * Likes:    1401
 * Dislikes: 151
 * Total Accepted:    81.7K
 * Total Submissions: 168.1K
 * Testcase Example:  '[2,1,3,3]\n2'
 *
 * You are given an integer array nums and an integer k. You want to find a
 * subsequence of nums of length k that has the largest sum.
 * 
 * Return any such subsequence as an integer array of length k.
 * 
 * A subsequence is an array that can be derived from another array by deleting
 * some or no elements without changing the order of the remaining elements.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,1,3,3], k = 2
 * Output: [3,3]
 * Explanation:
 * The subsequence has the largest sum of 3 + 3 = 6.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [-1,-2,3,4], k = 3
 * Output: [-1,3,4]
 * Explanation: 
 * The subsequence has the largest sum of -1 + 3 + 4 = 6.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,4,3,3], k = 2
 * Output: [3,4]
 * Explanation:
 * The subsequence has the largest sum of 3 + 4 = 7. 
 * Another possible subsequence is [4, 3].
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 1000
 * -10^5 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // max-heap to store pairs of (value, index)
        const int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
            if((int)pq.size() > k) {
                pq.pop(); // remove the smallest element if size exceeds k
            }
        }
        vector<pair<int, int>> pairs;
        while (!pq.empty()) {
            pairs.push_back(pq.top()); // extract all elements from the heap
            pq.pop();
        }
        sort(pairs.begin(), pairs.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second; // sort original indices in ascending order
        });
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(pairs[i].first); // extract the values in sorted order
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv) {
    Solution sol;
    // Test_1
    vector<int> nums = {2, 1, 3, 3};
    int k = 2;
    vector<int> res = sol.maxSubsequence(nums, k);
    cout << "Result: ";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    assert((res == vector<int>{3, 3}));

    // Test_2
    nums = {-1, -2, 3, 4};
    k = 3;
    res = sol.maxSubsequence(nums, k);
    cout << "Result: ";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;
    assert((res == vector<int>{-1, 3, 4}));

    return 0;
}
// Accepted
// 49/49 cases passed (2 ms)
// Your runtime beats 50.49 % of cpp submissions
// Your memory usage beats 43.6 % of cpp submissions (13.9 MB)