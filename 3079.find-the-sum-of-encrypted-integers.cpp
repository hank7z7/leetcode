// 3079. Find the Sum of Encrypted Integers
// User Accepted:20776
// User Tried:21759
// Total Accepted:22076
// Total Submissions:31758
// Difficulty:Easy
// You are given an integer array nums containing positive integers. We define a function encrypt
// such that encrypt(x) replaces every digit in x with the largest digit in x. For example,
// encrypt(523) = 555 and encrypt(213) = 333.

// Return the sum of encrypted elements.


// Example 1:

// Input: nums = [1,2,3]

// Output: 6

// Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.

// Example 2:

// Input: nums = [10,21,31]

// Output: 66

// Explanation: The encrypted elements are [11,22,33]. The sum of encrypted elements is 11 + 22 + 33
// == 66.


// Constraints:

// 1 <= nums.length <= 50
// 1 <= nums[i] <= 1000
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int sumOfEncryptedInt(vector<int>& nums)
    {
        int ret = 0;
        for (auto num : nums)
        {
            int max_digit   = 0;
            int digit_count = 0;
            while (num > 0)
            {
                int digit = num % 10;
                max_digit = max(max_digit, digit);
                num       = num / 10;
                digit_count++;
            }

            int to_add = 0;
            while (digit_count > 0)
            {
                to_add *= 10;
                to_add += max_digit;
                digit_count--;
            }

            ret += to_add;
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> nums_1 = { 1, 2, 3 };
    cout << sol.sumOfEncryptedInt(nums_1) << endl;

    // Test_2
    vector<int> nums_2 = { 10, 21, 31 };
    cout << sol.sumOfEncryptedInt(nums_2) << endl;

    return 0;
}
// 865 / 865 test cases passed.
// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 26.6 MB