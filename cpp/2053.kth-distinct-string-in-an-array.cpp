/*
 * @lc app=leetcode id=2053 lang=cpp
 *
 * [2053] Kth Distinct String in an Array
 *
 * https://leetcode.com/problems/kth-distinct-string-in-an-array/description/
 *
 * algorithms
 * Easy (72.92%)
 * Likes:    927
 * Dislikes: 41
 * Total Accepted:    113.7K
 * Total Submissions: 144.6K
 * Testcase Example:  '["d","b","c","b","c","a"]\n2'
 *
 * A distinct string is a string that is present only once in an array.
 *
 * Given an array of strings arr, and an integer k, return the k^th distinct
 * string present in arr. If there are fewer than k distinct strings, return an
 * empty string "".
 *
 * Note that the strings are considered in the order in which they appear in
 * the array.
 *
 *
 * Example 1:
 *
 *
 * Input: arr = ["d","b","c","b","c","a"], k = 2
 * Output: "a"
 * Explanation:
 * The only distinct strings in arr are "d" and "a".
 * "d" appears 1^st, so it is the 1^st distinct string.
 * "a" appears 2^nd, so it is the 2^nd distinct string.
 * Since k == 2, "a" is returned.
 *
 *
 * Example 2:
 *
 *
 * Input: arr = ["aaa","aa","a"], k = 1
 * Output: "aaa"
 * Explanation:
 * All strings in arr are distinct, so the 1^st string "aaa" is returned.
 *
 *
 * Example 3:
 *
 *
 * Input: arr = ["a","b","a"], k = 3
 * Output: ""
 * Explanation:
 * The only distinct string is "b". Since there are fewer than 3 distinct
 * strings, we return an empty string "".
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= arr.length <= 1000
 * 1 <= arr[i].length <= 5
 * arr[i] consists of lowercase English letters.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string kthDistinct(vector<string>& arr, int k)
    {
        unordered_map<string, int> um;
        for (auto& str : arr)
            um[str]++;
        string res = "";
        for (auto& str : arr)
        {
            if (um[str] == 1)
                k--;
            if (k == 0)
            {
                res = str;
                break;
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<string> arr_1 = { "d", "b", "c", "b", "c", "a" };
    int            k_1   = 2;
    string         res_1 = sol.kthDistinct(arr_1, k_1);
    cout << res_1 << endl;
    assert(res_1 == "a");

    // Test_2
    vector<string> arr_2 = { "aaa", "aa", "a" };
    int            k_2   = 1;
    string         res_2 = sol.kthDistinct(arr_2, k_2);
    cout << res_2 << endl;
    assert(res_2 == "aaa");

    // Test_3
    vector<string> arr_3 = { "a", "b", "a" };
    int            k_3   = 3;
    string         res_3 = sol.kthDistinct(arr_3, k_3);
    cout << res_3 << endl;
    assert(res_3 == "");

    return 0;
}
// Accepted
// 66/66 cases passed (11 ms)
// Your runtime beats 90.72 % of cpp submissions
// Your memory usage beats 31.7 % of cpp submissions (18.5 MB)