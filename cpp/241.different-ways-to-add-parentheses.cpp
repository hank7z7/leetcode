/*
 * @lc app=leetcode id=241 lang=cpp
 *
 * [241] Different Ways to Add Parentheses
 *
 * https://leetcode.com/problems/different-ways-to-add-parentheses/description/
 *
 * algorithms
 * Medium (65.84%)
 * Likes:    5541
 * Dislikes: 298
 * Total Accepted:    243.7K
 * Total Submissions: 363.1K
 * Testcase Example:  '"2-1-1"'
 *
 * Given a string expression of numbers and operators, return all possible
 * results from computing all the different possible ways to group numbers and
 * operators. You may return the answer in any order.
 *
 * The test cases are generated such that the output values fit in a 32-bit
 * integer and the number of different results does not exceed 10^4.
 *
 *
 * Example 1:
 *
 *
 * Input: expression = "2-1-1"
 * Output: [0,2]
 * Explanation:
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 *
 *
 * Example 2:
 *
 *
 * Input: expression = "2*3-4*5"
 * Output: [-34,-14,-10,-10,10]
 * Explanation:
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= expression.length <= 20
 * expression consists of digits and the operator '+', '-', and '*'.
 * All the integer values in the input expression are in the range [0, 99].
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
private:
    int compute(int a, int b, char op)
    {
        if (op == '+')
            return a + b;
        else if (op == '-')
            return a - b;
        else if (op == '*')
            return a * b;
        // Prevent non-void function
        return -1;
    }

public:
    vector<int> diffWaysToCompute(string expression)
    {
        istringstream iss(expression);
        int num;
        char op;
        vector<int> num_arr;
        vector<char> op_arr;
        while (iss >> num)
        {
            num_arr.push_back(num);
            if (iss >> op)
                op_arr.push_back(op);
        }

        const int n = (int) num_arr.size();
        // dp[i][j] stores all results from num[i] to num[j]
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n));

        for (int i = 0; i < n; i++)
            dp[i][i].push_back(num_arr[i]);

        // Iterate possible length of left subarray
        for (int len = 0; len < n; len++)
        {
            // Iterate possible right bound of left subarray
            for (int l = 0; l < n - len; l++)
            {
                // Iterate possible right bound of left subarray
                for (int m = l; m < l + len; m++)
                {
                    // Possible solutions
                    for (int l_sol : dp[l][m])
                        for (int r_sol : dp[m + 1][l + len])
                            dp[l][l + len].push_back(
                                compute(l_sol, r_sol, op_arr[m]));
                }
            }
        }

        // Sort if needed
        sort(dp[0][n - 1].begin(), dp[0][n - 1].end());
        return dp[0][n - 1];
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string expression_1 = "2-1-1";
    vector<int> res_1 = sol.diffWaysToCompute(expression_1);
    for (auto elem : res_1)
        cout << elem << " ";
    cout << endl;
    assert((res_1 == vector<int>{ 0, 2 }));

    // Test_2
    string expression_2 = "2*3-4*5";
    vector<int> res_2 = sol.diffWaysToCompute(expression_2);
    for (auto elem : res_2)
        cout << elem << " ";
    cout << endl;
    assert((res_2 == vector<int>{ -34, -14, -10, -10, 10 }));
    return 0;
}
