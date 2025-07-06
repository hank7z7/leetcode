/*
 * @lc app=leetcode id=1865 lang=cpp
 *
 * [1865] Finding Pairs With a Certain Sum
 *
 * https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/
 *
 * algorithms
 * Medium (51.76%)
 * Likes:    878
 * Dislikes: 130
 * Total Accepted:    85.1K
 * Total Submissions: 145.1K
 * Testcase Example:  '["FindSumPairs","count","add","count","count","add","add","count"]\n' +
  '[[[1,1,2,2,2,3],[1,4,5,2,5,4]],[7],[3,2],[8],[4],[0,1],[1,1],[7]]'
 *
 * You are given two integer arrays nums1 and nums2. You are tasked to
 * implement a data structure that supports queries of two types:
 *
 *
 * Add a positive integer to an element of a given index in the array
 * nums2.
 * Count the number of pairs (i, j) such that nums1[i] + nums2[j] equals a
 * given value (0 <= i < nums1.length and 0 <= j < nums2.length).
 *
 *
 * Implement the FindSumPairs class:
 *
 *
 * FindSumPairs(int[] nums1, int[] nums2) Initializes the FindSumPairs object
 * with two integer arrays nums1 and nums2.
 * void add(int index, int val) Adds val to nums2[index], i.e., apply
 * nums2[index] += val.
 * int count(int tot) Returns the number of pairs (i, j) such that nums1[i] +
 * nums2[j] == tot.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["FindSumPairs", "count", "add", "count", "count", "add", "add", "count"]
 * [[[1, 1, 2, 2, 2, 3], [1, 4, 5, 2, 5, 4]], [7], [3, 2], [8], [4], [0, 1],
 * [1, 1], [7]]
 * Output
 * [null, 8, null, 2, 1, null, null, 11]
 *
 * Explanation
 * FindSumPairs findSumPairs = new FindSumPairs([1, 1, 2, 2, 2, 3], [1, 4, 5,
 * 2, 5, 4]);
 * findSumPairs.count(7);  // return 8; pairs (2,2), (3,2), (4,2), (2,4),
 * (3,4), (4,4) make 2 + 5 and pairs (5,1), (5,5) make 3 + 4
 * findSumPairs.add(3, 2); // now nums2 = [1,4,5,4,5,4]
 * findSumPairs.count(8);  // return 2; pairs (5,2), (5,4) make 3 + 5
 * findSumPairs.count(4);  // return 1; pair (5,0) makes 3 + 1
 * findSumPairs.add(0, 1); // now nums2 = [2,4,5,4,5,4]
 * findSumPairs.add(1, 1); // now nums2 = [2,5,5,4,5,4]
 * findSumPairs.count(7);  // return 11; pairs (2,1), (2,2), (2,4), (3,1),
 * (3,2), (3,4), (4,1), (4,2), (4,4) make 2 + 5 and pairs (5,3), (5,5) make 3 +
 * 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums1.length <= 1000
 * 1 <= nums2.length <= 10^5
 * 1 <= nums1[i] <= 10^9
 * 1 <= nums2[i] <= 10^5
 * 0 <= index < nums2.length
 * 1 <= val <= 10^5
 * 1 <= tot <= 10^9
 * At most 1000 calls are made to add and count each.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class FindSumPairs
{
    // hash map
    // map1: num1 value -> count
    // map2: num2 value -> count
    // array for nums2 to keep track of the original values
private:
    map<int, int> map1;  // map for nums1
    map<int, int> map2;  // map for nums2
    vector<int> nums2;   // to keep track of the original values of nums2
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
    {
        // Initialize the data structure
        this->nums2.clear();
        map1.clear();
        map2.clear();

        // Store the counts of each number in nums1 and nums2
        for (int num : nums1)
        {
            map1[num]++;
        }
        for (int num : nums2)
        {
            map2[num]++;
        }

        // Store the original nums2 values
        this->nums2 = nums2;
    }

    void add(int index, int val)
    {
        int old_value = nums2[index];  // Get the old value at index
        nums2[index] += val;           // Update the value at index
        int new_value = nums2[index];  // Get the new value at index
        // Update the map2 counts
        map2[old_value]--;  // Decrease the count of the old value
        map2[new_value]++;  // Increase the count of the new value
    }

    int count(int tot)
    {
        int count = 0;
        for (auto& [num1, cnt1] : map1)
        {
            int complement = tot - num1;
            if (map2.count(complement))
            {
                count += cnt1 * map2[complement];
            }
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    vector<int> nums1 = { 1, 1, 2, 2, 2, 3 };
    vector<int> nums2 = { 1, 4, 5, 2, 5, 4 };
    FindSumPairs findSumPairs(nums1, nums2);

    cout << findSumPairs.count(7) << endl;  // Output: 8
    findSumPairs.add(3, 2);
    cout << findSumPairs.count(8) << endl;  // Output: 2
    cout << findSumPairs.count(4) << endl;  // Output: 1
    findSumPairs.add(0, 1);
    findSumPairs.add(1, 1);
    cout << findSumPairs.count(7) << endl;  // Output: 11


    return 0;
}
// Accepted
// 26/26 cases passed (303 ms)
// Your runtime beats 28.18 % of cpp submissions
// Your memory usage beats 41.54 % of cpp submissions (83.4 MB)