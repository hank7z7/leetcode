/*
 * @lc app=leetcode id=2971 lang=cpp
 *
 * [2971] Find Polygon With the Largest Perimeter
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    static long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long prev = 0;
        long long curr;
        long long ret = -1;
        for(size_t i = 0; i < nums.size(); i++)
        {
            curr = (long long)nums[i];
            if(i >= 2 && prev > curr)
                ret = prev + curr;
            prev += curr;
        }
        return ret;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    // Test_1
    vector<int> nums_1 = { 5, 5, 5 };
    cout << Solution::largestPerimeter(nums_1) << endl;


    // Test_2
    vector<int> nums_2 = { 1, 12, 1, 2, 5, 50, 3 };
    cout << Solution::largestPerimeter(nums_2) << endl;


    // Test_3
    vector<int> nums_3 = { 5, 5, 50 };
    cout << Solution::largestPerimeter(nums_3) << endl;


    // Test_4
    vector<int> nums_4 = { 1, 1, 1, 10, 12, 21 };
    cout << Solution::largestPerimeter(nums_4) << endl;


    return 0;
}
// Accepted
// 980/980 cases passed (132 ms)
// Your runtime beats 91.9 % of cpp submissions
// Your memory usage beats 36.11 % of cpp submissions (83.3 MB)