/*
 * @lc app=leetcode id=2081 lang=cpp
 *
 * [2081] Sum of k-Mirror Numbers
 *
 * https://leetcode.com/problems/sum-of-k-mirror-numbers/description/
 *
 * algorithms
 * Hard (42.40%)
 * Likes:    263
 * Dislikes: 177
 * Total Accepted:    32.6K
 * Total Submissions: 56.3K
 * Testcase Example:  '2\n5'
 *
 * A k-mirror number is a positive integer without leading zeros that reads the
 * same both forward and backward in base-10 as well as in base-k.
 *
 *
 * For example, 9 is a 2-mirror number. The representation of 9 in base-10 and
 * base-2 are 9 and 1001 respectively, which read the same both forward and
 * backward.
 * On the contrary, 4 is not a 2-mirror number. The representation of 4 in
 * base-2 is 100, which does not read the same both forward and backward.
 *
 *
 * Given the base k and the number n, return the sum of the n smallest k-mirror
 * numbers.
 *
 *
 * Example 1:
 *
 *
 * Input: k = 2, n = 5
 * Output: 25
 * Explanation:
 * The 5 smallest 2-mirror numbers and their representations in base-2 are
 * listed as follows:
 * ⁠ base-10    base-2
 * ⁠   1          1
 * ⁠   3          11
 * ⁠   5          101
 * ⁠   7          111
 * ⁠   9          1001
 * Their sum = 1 + 3 + 5 + 7 + 9 = 25.
 *
 *
 * Example 2:
 *
 *
 * Input: k = 3, n = 7
 * Output: 499
 * Explanation:
 * The 7 smallest 3-mirror numbers are and their representations in base-3 are
 * listed as follows:
 * ⁠ base-10    base-3
 * ⁠   1          1
 * ⁠   2          2
 * ⁠   4          11
 * ⁠   8          22
 * ⁠   121        11111
 * ⁠   151        12121
 * ⁠   212        21212
 * Their sum = 1 + 2 + 4 + 8 + 121 + 151 + 212 = 499.
 *
 *
 * Example 3:
 *
 *
 * Input: k = 7, n = 17
 * Output: 20379000
 * Explanation: The 17 smallest 7-mirror numbers are:
 * 1, 2, 3, 4, 5, 6, 8, 121, 171, 242, 292, 16561, 65656, 2137312, 4602064,
 * 6597956, 6958596
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= k <= 9
 * 1 <= n <= 30
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    bool is_k_mirror(long long num, int k)
    {
        // Convert the number to base-k and check if it is a palindrome
        vector<int> digits;
        while (num > 0)
        {
            digits.push_back(num % k);
            num /= k;
        }
        int left = 0, right = (int) digits.size() - 1;
        while (left < right)
        {
            if (digits[left] != digits[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    long long kMirror(int k, int n)
    {
        long long sum = 0;  // result
        // start the left size with 1
        int left_len = 1;
        while (1)
        {
            // Generate palindromes of the current length
            int start = pow(10, left_len - 1);
            int end = pow(10, left_len) - 1;
            // Check if the generated palindromes are k-mirror numbers
            // Check odd-length first
            for (int i = start; i <= end; i++)
            {
                // cout << i << endl;
                string half = to_string(i);

                // Generate odd-length palindrome
                string odd_right = half;
                odd_right.pop_back();  // Remove last digit for odd length
                reverse(odd_right.begin(), odd_right.end());
                long long odd_num = stoll(half + odd_right);
                if (is_k_mirror(odd_num, k))
                {
                    sum += odd_num;
                    n--;
                    if (n == 0)
                        return sum;  // Return early if we found enough numbers
                }
            }
            // Then check even-length
            for (int i = start; i <= end; i++)
            {
                // cout << i << endl;
                string half = to_string(i);

                // Generate odd-length palindrome
                string even_right = half;
                reverse(even_right.begin(), even_right.end());
                long long even_num = stoll(half + even_right);
                if (is_k_mirror(even_num, k))
                {
                    sum += even_num;
                    n--;
                    if (n == 0)
                        return sum;  // Return early if we found enough numbers
                }
            }

            // Update left size
            left_len++;
        }

        // Should not reach here if n is valid
        return sum;
    }
};
// @lc code=end
int main()
{
    Solution sol;
    // Test_1
    int k = 2, n = 5;
    long long res = sol.kMirror(k, n);
    cout << res << endl;  // Expected output: 25
    assert(res == 25);

    // Test_2
    k = 3;
    n = 7;
    res = sol.kMirror(k, n);
    cout << res << endl;  // Expected output: 499
    assert(res == 499);

    // Test_3
    k = 7;
    n = 17;
    res = sol.kMirror(k, n);
    cout << res << endl;  // Expected output: 20379000
    assert(res == 20379000);

    // Test_4
    k = 5;
    n = 20;
    res = sol.kMirror(k, n);
    cout << res << endl;
    assert(res == 1000828708);

    // Test_5
    k = 9;
    n = 17;
    res = sol.kMirror(k, n);
    cout << res << endl;
    assert(res == 35841);

    return 0;
}
// Accepted
// 97/97 cases passed (2836 ms)
// Your runtime beats 6.14 % of cpp submissions
// Your memory usage beats 7.02 % of cpp submissions (556.2 MB)