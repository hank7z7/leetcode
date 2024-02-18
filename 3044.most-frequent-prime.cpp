/*
 * @lc app=leetcode id=3044 lang=cpp
 *
 * [3044] Most Frequent Prime
 *
 * https://leetcode.com/problems/most-frequent-prime/description/
 *
 * algorithms
 * Medium (46.45%)
 * Likes:    23
 * Dislikes: 28
 * Total Accepted:    8K
 * Total Submissions: 17.2K
 * Testcase Example:  '[[1,1],[9,9],[1,1]]'
 *
 * You are given a m x n 0-indexed 2D matrix mat. From every cell, you can
 * create numbers in the following way:
 *
 *
 * There could be at most 8 paths from the cells namely: east, south-east,
 * south, south-west, west, north-west, north, and north-east.
 * Select a path from them and append digits in this path to the number being
 * formed by traveling in this direction.
 * Note that numbers are generated at every step, for example, if the digits
 * along the path are 1, 9, 1, then there will be three numbers generated along
 * the way: 1, 19, 191.
 *
 *
 * Return the most frequent prime number greater than 10 out of all the numbers
 * created by traversing the matrix or -1 if no such prime number exists. If
 * there are multiple prime numbers with the highest frequency, then return the
 * largest among them.
 *
 * Note: It is invalid to change the direction during the move.
 *
 *
 * Example 1:
 * ⁠
 *
 *
 *
 * Input: mat = [[1,1],[9,9],[1,1]]
 * Output: 19
 * Explanation:
 * From cell (0,0) there are 3 possible directions and the numbers greater than
 * 10 which can be created in those directions are:
 * East: [11], South-East: [19], South: [19,191].
 * Numbers greater than 10 created from the cell (0,1) in all possible
 * directions are: [19,191,19,11].
 * Numbers greater than 10 created from the cell (1,0) in all possible
 * directions are: [99,91,91,91,91].
 * Numbers greater than 10 created from the cell (1,1) in all possible
 * directions are: [91,91,99,91,91].
 * Numbers greater than 10 created from the cell (2,0) in all possible
 * directions are: [11,19,191,19].
 * Numbers greater than 10 created from the cell (2,1) in all possible
 * directions are: [11,19,19,191].
 * The most frequent prime number among all the created numbers is 19.
 *
 * Example 2:
 *
 *
 * Input: mat = [[7]]
 * Output: -1
 * Explanation: The only number which can be formed is 7. It is a prime number
 * however it is not greater than 10, so return -1.
 *
 * Example 3:
 *
 *
 * Input: mat = [[9,7,8],[4,6,5],[2,8,6]]
 * Output: 97
 * Explanation:
 * Numbers greater than 10 created from the cell (0,0) in all possible
 * directions are: [97,978,96,966,94,942].
 * Numbers greater than 10 created from the cell (0,1) in all possible
 * directions are: [78,75,76,768,74,79].
 * Numbers greater than 10 created from the cell (0,2) in all possible
 * directions are: [85,856,86,862,87,879].
 * Numbers greater than 10 created from the cell (1,0) in all possible
 * directions are: [46,465,48,42,49,47].
 * Numbers greater than 10 created from the cell (1,1) in all possible
 * directions are: [65,66,68,62,64,69,67,68].
 * Numbers greater than 10 created from the cell (1,2) in all possible
 * directions are: [56,58,56,564,57,58].
 * Numbers greater than 10 created from the cell (2,0) in all possible
 * directions are: [28,286,24,249,26,268].
 * Numbers greater than 10 created from the cell (2,1) in all possible
 * directions are: [86,82,84,86,867,85].
 * Numbers greater than 10 created from the cell (2,2) in all possible
 * directions are: [68,682,66,669,65,658].
 * The most frequent prime number among all the created numbers is 97.
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 6
 * 1 <= mat[i][j] <= 9
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    static bool isPrime(int n)
    {
        // Corner case
        if (n <= 1)
            return false;

        // Check from 2 to n-1
        for (int i = 2; i <= n / 2; i++)
            if (n % i == 0)
                return false;

        return true;
    }
    static int mostFrequentPrime(vector<vector<int>>& mat)
    {
        int                     i, j;
        int                     ret = 0;
        unordered_map<int, int> prime_table;
        vector<int>             prime;
        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++)
            {
                int idx_i, idx_j;
                int curr;
                // North
                idx_i = i;
                idx_j = j;
                curr  = 0;
                while (idx_i >= 0 && idx_i < mat.size() && idx_j >= 0 && idx_j < mat[i].size())
                {
                    curr = curr * 10;
                    curr += mat[idx_i][idx_j];
                    idx_i--;
                    if (curr > 10 && isPrime(curr))
                    {
                        // cout << curr << endl;
                        if (prime_table.find(curr) == prime_table.end())
                        {
                            prime.push_back(curr);
                            prime_table[curr] = 1;
                        }
                        else
                        {
                            prime_table[curr]++;
                        }
                    }
                }

                // East
                idx_i = i;
                idx_j = j;
                curr  = 0;
                while (idx_i >= 0 && idx_i < mat.size() && idx_j >= 0 && idx_j < mat[i].size())
                {
                    curr = curr * 10;
                    curr += mat[idx_i][idx_j];
                    idx_j++;
                    if (curr > 10 && isPrime(curr))
                    {
                        // cout << curr << endl;
                        if (prime_table.find(curr) == prime_table.end())
                        {
                            prime.push_back(curr);
                            prime_table[curr] = 1;
                        }
                        else
                        {
                            prime_table[curr]++;
                        }
                    }
                }

                // South
                idx_i = i;
                idx_j = j;
                curr  = 0;
                while (idx_i >= 0 && idx_i < mat.size() && idx_j >= 0 && idx_j < mat[i].size())
                {
                    curr = curr * 10;
                    curr += mat[idx_i][idx_j];
                    idx_i++;
                    if (curr > 10 && isPrime(curr))
                    {
                        // cout << curr << endl;
                        if (prime_table.find(curr) == prime_table.end())
                        {
                            prime.push_back(curr);
                            prime_table[curr] = 1;
                        }
                        else
                        {
                            prime_table[curr]++;
                        }
                    }
                }

                // West
                idx_i = i;
                idx_j = j;
                curr  = 0;
                while (idx_i >= 0 && idx_i < mat.size() && idx_j >= 0 && idx_j < mat[i].size())
                {
                    curr = curr * 10;
                    curr += mat[idx_i][idx_j];
                    idx_j--;
                    if (curr > 10 && isPrime(curr))
                    {
                        // cout << curr << endl;
                        if (prime_table.find(curr) == prime_table.end())
                        {
                            prime.push_back(curr);
                            prime_table[curr] = 1;
                        }
                        else
                        {
                            prime_table[curr]++;
                        }
                    }
                }


                // North-East
                idx_i = i;
                idx_j = j;
                curr  = 0;
                while (idx_i >= 0 && idx_i < mat.size() && idx_j >= 0 && idx_j < mat[i].size())
                {
                    curr = curr * 10;
                    curr += mat[idx_i][idx_j];
                    idx_i--;
                    idx_j++;
                    if (curr > 10 && isPrime(curr))
                    {
                        // cout << curr << endl;
                        if (prime_table.find(curr) == prime_table.end())
                        {
                            prime.push_back(curr);
                            prime_table[curr] = 1;
                        }
                        else
                        {
                            prime_table[curr]++;
                        }
                    }
                }

                // South-East
                idx_i = i;
                idx_j = j;
                curr  = 0;
                while (idx_i >= 0 && idx_i < mat.size() && idx_j >= 0 && idx_j < mat[i].size())
                {
                    curr = curr * 10;
                    curr += mat[idx_i][idx_j];
                    idx_i++;
                    idx_j++;
                    if (curr > 10 && isPrime(curr))
                    {
                        // cout << curr << endl;
                        if (prime_table.find(curr) == prime_table.end())
                        {
                            prime.push_back(curr);
                            prime_table[curr] = 1;
                        }
                        else
                        {
                            prime_table[curr]++;
                        }
                    }
                }

                // South-West
                idx_i = i;
                idx_j = j;
                curr  = 0;
                while (idx_i >= 0 && idx_i < mat.size() && idx_j >= 0 && idx_j < mat[i].size())
                {
                    curr = curr * 10;
                    curr += mat[idx_i][idx_j];
                    idx_i++;
                    idx_j--;
                    if (curr > 10 && isPrime(curr))
                    {
                        // cout << curr << endl;
                        if (prime_table.find(curr) == prime_table.end())
                        {
                            prime.push_back(curr);
                            prime_table[curr] = 1;
                        }
                        else
                        {
                            prime_table[curr]++;
                        }
                    }
                }

                // North-West
                idx_i = i;
                idx_j = j;
                curr  = 0;
                while (idx_i >= 0 && idx_i < mat.size() && idx_j >= 0 && idx_j < mat[i].size())
                {
                    curr = curr * 10;
                    curr += mat[idx_i][idx_j];
                    idx_i--;
                    idx_j--;
                    if (curr > 10 && isPrime(curr))
                    {
                        // cout << curr << endl;
                        if (prime_table.find(curr) == prime_table.end())
                        {
                            prime.push_back(curr);
                            prime_table[curr] = 1;
                        }
                        else
                        {
                            prime_table[curr]++;
                        }
                    }
                }
            }
        int occur_time = 0;

        for (auto it : prime)
        {
            if (prime_table[it] > occur_time)
            {
                ret        = it;
                occur_time = prime_table[it];
            }
            else if (prime_table[it] == occur_time)
            {
                if (it > ret)
                    ret = it;
            }
        }
        if (ret == 0)
            return -1;
        return ret;
    }
};
// @lc code=end

int main(int argc, char** argv)
{
    // Test_1
    vector<vector<int>> mat_1 = { { 1, 1 }, { 9, 9 }, { 1, 1 } };
    cout << Solution::mostFrequentPrime(mat_1) << endl;

    // Test_2
    vector<vector<int>> mat_2 = { { 7 } };
    cout << Solution::mostFrequentPrime(mat_2) << endl;

    // Test_3
    vector<vector<int>> mat_3 = { { 9, 7, 8 }, { 4, 6, 5 }, { 2, 8, 6 } };
    cout << Solution::mostFrequentPrime(mat_3) << endl;

    return 0;
}
// Accepted
// 974/974 cases passed (329 ms)
// Your runtime beats 25 % of cpp submissions
// Your memory usage beats 75 % of cpp submissions (31.7 MB)