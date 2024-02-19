/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */
#include <bits/stdc++.h>

// @lc code=start
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
            return false;
        return (((n) & (n - 1)) == 0);
    }
};
int main(int argc, char** argv)
{
    int n;
    Solution obj;
    // Test_1
    n = 1;
    std::cout << obj.isPowerOfTwo(n) << std::endl;

    // Test_2
    n = 16;
    std::cout << obj.isPowerOfTwo(n) << std::endl;

    // Test_3
    n = 3;
    std::cout << obj.isPowerOfTwo(n) << std::endl;
    return 0;
}
// @lc code=end
// Accepted
// 1108/1108 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 88.2 % of cpp submissions (5.7 MB)