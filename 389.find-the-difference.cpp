/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */
#include <bits/stdc++.h>
// @lc code=start
#define LOWERCASE_SIZE (26)
class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        std::vector<int> count(LOWERCASE_SIZE, 0);
        for(size_t i = 0; i < s.size(); i++)
            count[s[i] - 'a']++;
        char ret;
        for(size_t i = 0; i < t.size(); i++)
        {
            if(count[t[i] - 'a'] == 0)
            {
                ret = t[i];
                break;
            }
            count[t[i] - 'a']--;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution obj;
    // Test_1
    std::string s_1 = "abcd";
    std::string t_1 = "abcde";
    std::cout << obj.findTheDifference(s_1, t_1) << std::endl;

    // Test_2
    std::string s_2 = "";
    std::string t_2 = "y";
    std::cout << obj.findTheDifference(s_2, t_2) << std::endl;

    // Test_3
    std::string s_3 = "abcd";
    std::string t_3 = "abcde";
    std::cout << obj.findTheDifference(s_3, t_3) << std::endl;

    return 0;
}
// Accepted
// 54/54 cases passed (0 ms)
// Your runtime beats 100 % of cpp submissions
// Your memory usage beats 29.96 % of cpp submissions (7.9 MB)