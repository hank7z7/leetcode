/*
 * @lc app=leetcode id=2264 lang=cpp
 *
 * [2264] Largest 3-Same-Digit Number in String
 *
 * https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/
 *
 * algorithms
 * Easy (69.04%)
 * Likes:    1300
 * Dislikes: 54
 * Total Accepted:    271.7K
 * Total Submissions: 375.9K
 * Testcase Example:  '"6777133339"'
 *
 * You are given a string num representing a large integer. An integer is good
 * if it meets the following conditions:
 * 
 * 
 * It is a substring of num with length 3.
 * It consists of only one unique digit.
 * 
 * 
 * Return the maximum good integer as a string or an empty string "" if no such
 * integer exists.
 * 
 * Note:
 * 
 * 
 * A substring is a contiguous sequence of characters within a string.
 * There may be leading zeroes in num or a good integer.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: num = "6777133339"
 * Output: "777"
 * Explanation: There are two distinct good integers: "777" and "333".
 * "777" is the largest, so we return "777".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: num = "2300019"
 * Output: "000"
 * Explanation: "000" is the only good integer.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: num = "42352338"
 * Output: ""
 * Explanation: No substring of length 3 consists of only one unique digit.
 * Therefore, there are no good integers.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= num.length <= 1000
 * num only consists of digits.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string largestGoodInteger(string num) {
        // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
        char maxDigit = '\0';

        // Iterate on characters of the num string.
        for (int index = 0; index <= num.size() - 3; ++index) {
            // If 3 consecutive characters are the same,
            // store the character in 'maxDigit' if bigger than what it already stores.
            if (num[index] == num[index + 1] && num[index] == num[index + 2]) {
                maxDigit = max(maxDigit, num[index]);
            }
        }

        // If 'maxDigit' is NUL return an empty string, otherwise string of size 3 with 'maxDigit' characters.
        return maxDigit == '\0' ? "" : string(3, maxDigit);
    }
};
// @lc code=end

