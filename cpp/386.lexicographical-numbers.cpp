/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (64.56%)
 * Likes:    2097
 * Dislikes: 155
 * Total Accepted:    142.4K
 * Total Submissions: 215K
 * Testcase Example:  '13'
 *
 * Given an integer n, return all the numbers in the range [1, n] sorted in
 * lexicographical order.
 *
 * You must write an algorithm that runs in O(n) time and uses O(1) extra
 * space. 
 *
 *
 * Example 1:
 * Input: n = 13
 * Output: [1,10,11,12,13,2,3,4,5,6,7,8,9]
 * Example 2:
 * Input: n = 2
 * Output: [1,2]
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 5 * 10^4
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;
        if (n <= 0)
            return res;

        stack<int> st;
        for (int i = 9; i >= 1; i--)
            st.push(i);

        // DFS
        while (!st.empty())
        {
            int curr = st.top();
            st.pop();
            if (curr <= n)
                res.push_back(curr);

            curr *= 10;
            if (curr <= n)
            {
                // Add new children
                for (int i = 9; i >= 0; i--)
                    if ((curr + i) <= n)
                        st.push(curr + i);
            }
        }
        return res;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    int n_1 = 13;
    vector<int> res_1 = sol.lexicalOrder(n_1);
    for (auto it : res_1)
        cout << it << " ";
    cout << endl;
    assert((res_1 == vector<int>{1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9}));

    // Test_2
    int n_2 = 2;
    vector<int> res_2 = sol.lexicalOrder(n_2);
    for (auto it : res_2)
        cout << it << " ";
    cout << endl;
    assert((res_2 == vector<int>{1, 2}));

    // Test_3
    int n_3 = 100;
    vector<int> res_3 = sol.lexicalOrder(n_3);
    for (auto it : res_3)
        cout << it << " ";
    cout << endl;
    assert((res_3 == vector<int>{1, 10, 100, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 3, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 4, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 5, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 6, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 7, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 8, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 9, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99}));

    // Test_4
    int n_4 = 192;
    vector<int> res_4 = sol.lexicalOrder(n_4);
    for (auto it : res_4)
        cout << it << " ";
    cout << endl;
    assert((res_4 == vector<int>{1, 10, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 11, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 12, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 13, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 14, 140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 15, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 16, 160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 17, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 18, 180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 19, 190, 191, 192, 2, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 3, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 4, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 5, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 6, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 7, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 8, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 9, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99}));

    return 0;
}
