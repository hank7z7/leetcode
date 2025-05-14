/*
 * @lc app=leetcode id=3337 lang=cpp
 *
 * [3337] Total Characters in String After Transformations II
 *
 * https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/description/
 *
 * algorithms
 * Hard (32.76%)
 * Likes:    154
 * Dislikes: 23
 * Total Accepted:    16.5K
 * Total Submissions: 33.2K
 * Testcase Example:  '"abcyy"\n2\n[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]'
 *
 * You are given a string s consisting of lowercase English letters, an integer
 * t representing the number of transformations to perform, and an array nums
 * of size 26. In one transformation, every character in s is replaced
 * according to the following rules:
 *
 *
 * Replace s[i] with the next nums[s[i] - 'a'] consecutive characters in the
 * alphabet. For example, if s[i] = 'a' and nums[0] = 3, the character 'a'
 * transforms into the next 3 consecutive characters ahead of it, which results
 * in "bcd".
 * The transformation wraps around the alphabet if it exceeds 'z'. For example,
 * if s[i] = 'y' and nums[24] = 3, the character 'y' transforms into the next 3
 * consecutive characters ahead of it, which results in "zab".
 *
 *
 * Return the length of the resulting string after exactly t transformations.
 *
 * Since the answer may be very large, return it modulo 10^9 + 7.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "abcyy", t = 2, nums =
 * [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2]
 *
 * Output: 7
 *
 * Explanation:
 *
 *
 *
 * First Transformation (t = 1):
 *
 *
 * 'a' becomes 'b' as nums[0] == 1
 * 'b' becomes 'c' as nums[1] == 1
 * 'c' becomes 'd' as nums[2] == 1
 * 'y' becomes 'z' as nums[24] == 1
 * 'y' becomes 'z' as nums[24] == 1
 * String after the first transformation: "bcdzz"
 *
 *
 *
 * Second Transformation (t = 2):
 *
 *
 * 'b' becomes 'c' as nums[1] == 1
 * 'c' becomes 'd' as nums[2] == 1
 * 'd' becomes 'e' as nums[3] == 1
 * 'z' becomes 'ab' as nums[25] == 2
 * 'z' becomes 'ab' as nums[25] == 2
 * String after the second transformation: "cdeabab"
 *
 *
 *
 * Final Length of the string: The string is "cdeabab", which has 7
 * characters.
 *
 *
 *
 *
 * Example 2:
 *
 *
 * Input: s = "azbk", t = 1, nums =
 * [2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2]
 *
 * Output: 8
 *
 * Explanation:
 *
 *
 *
 * First Transformation (t = 1):
 *
 *
 * 'a' becomes 'bc' as nums[0] == 2
 * 'z' becomes 'ab' as nums[25] == 2
 * 'b' becomes 'cd' as nums[1] == 2
 * 'k' becomes 'lm' as nums[10] == 2
 * String after the first transformation: "bcabcdlm"
 *
 *
 *
 * Final Length of the string: The string is "bcabcdlm", which has 8
 * characters.
 *
 *
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists only of lowercase English letters.
 * 1 <= t <= 10^9
 * nums.length == 26
 * 1 <= nums[i] <= 25
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums)
    {
        vector<long long> cnt(26, 0);  // current count of each character
        for (auto c : s)
            cnt[c - 'a']++;
        vector<long long> next(26, 0);
        for (int i = 0; i < t; i++)
        {
            // Reset next count
            fill(next.begin(), next.end(), 0);
            for (int j = 0; j < 26; j++)
            {
                for (int k = 1; k <= nums[j]; k++)
                {
                    // Calculate the next character index
                    int nextIndex = (j + k) % 26;
                    // Update the next count for the character
                    next[nextIndex] = (next[nextIndex] + cnt[j]) % 1000000007;
                }
            }
            // Update current count with the next count
            cnt = next;
        }
        long long res = accumulate(cnt.begin(), cnt.end(), 0LL) % 1000000007;
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string s = "abcyy";
    int t = 2;
    vector<int> nums
        = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 };
    int res = sol.lengthAfterTransformations(s, t, nums);
    cout << "Test_1: " << res << endl;  // Expected output: 7
    assert(res == 7);

    // Test_2
    s = "azbk";
    t = 1;
    nums = { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 };
    res = sol.lengthAfterTransformations(s, t, nums);
    cout << "Test_2: " << res << endl;  // Expected output: 8
    assert(res == 8);

    return 0;
}
