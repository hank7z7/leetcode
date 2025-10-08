/*
 * @lc app=leetcode id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 *
 * https://leetcode.com/problems/successful-pairs-of-spells-and-potions/description/
 *
 * algorithms
 * Medium (45.90%)
 * Likes:    2897
 * Dislikes: 93
 * Total Accepted:    277.8K
 * Total Submissions: 589.3K
 * Testcase Example:  '[5,1,3]\n[1,2,3,4,5]\n7'
 *
 * You are given two positive integer arrays spells and potions, of length n
 * and m respectively, where spells[i] represents the strength of the i^th
 * spell and potions[j] represents the strength of the j^th potion.
 * 
 * You are also given an integer success. A spell and potion pair is considered
 * successful if the product of their strengths is at least success.
 * 
 * Return an integer array pairs of length n where pairs[i] is the number of
 * potions that will form a successful pair with the i^th spell.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: spells = [5,1,3], potions = [1,2,3,4,5], success = 7
 * Output: [4,0,3]
 * Explanation:
 * - 0^th spell: 5 * [1,2,3,4,5] = [5,10,15,20,25]. 4 pairs are successful.
 * - 1^st spell: 1 * [1,2,3,4,5] = [1,2,3,4,5]. 0 pairs are successful.
 * - 2^nd spell: 3 * [1,2,3,4,5] = [3,6,9,12,15]. 3 pairs are successful.
 * Thus, [4,0,3] is returned.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: spells = [3,1,2], potions = [8,5,8], success = 16
 * Output: [2,0,2]
 * Explanation:
 * - 0^th spell: 3 * [8,5,8] = [24,15,24]. 2 pairs are successful.
 * - 1^st spell: 1 * [8,5,8] = [8,5,8]. 0 pairs are successful. 
 * - 2^nd spell: 2 * [8,5,8] = [16,10,16]. 2 pairs are successful. 
 * Thus, [2,0,2] is returned.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == spells.length
 * m == potions.length
 * 1 <= n, m <= 10^5
 * 1 <= spells[i], potions[i] <= 10^5
 * 1 <= success <= 10^10
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        const int n_spells = (int)spells.size();
        const int n_potions = (int)potions.size();
        sort(potions.begin(), potions.end());
        vector<int> res(n_spells, 0);
        for(auto &spell : spells) {
            long long target = (success + spell - 1) / spell; // ceil(success / spell)
            // Binary search for the first potion >= target
            auto it = lower_bound(potions.begin(), potions.end(), target);
            if(it != potions.end()) {
                res[&spell - &spells[0]] = (int)(n_potions - (it - potions.begin()));
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
    vector<int> spells_1 = {5, 1, 3};
    vector<int> potions_1 = {1, 2, 3, 4, 5};
    long long success_1 = 7;
    vector<int> res_1 = sol.successfulPairs(spells_1, potions_1, success_1);
    cout << "Test_1: ";
    for (auto num : res_1)
        cout << num << " ";
    cout << endl;
    assert((res_1 == vector<int>{4, 0, 3}));

    // Test_2
    vector<int> spells_2 = {3, 1, 2};
    vector<int> potions_2 = {8, 5, 8};
    long long success_2 = 16;
    vector<int> res_2 = sol.successfulPairs(spells_2, potions_2, success_2);
    cout << "Test_2: ";
    for (auto num : res_2)
        cout << num << " ";
    cout << endl;
    assert((res_2 == vector<int>{2, 0, 2}));

    return 0;
}
// Accepted
// 57/57 cases passed (42 ms)
// Your runtime beats 67.49 % of cpp submissions
// Your memory usage beats 81.16 % of cpp submissions (125 MB)