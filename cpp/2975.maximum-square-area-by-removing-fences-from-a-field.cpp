/*
 * @lc app=leetcode id=2975 lang=cpp
 *
 * [2975] Maximum Square Area by Removing Fences From a Field
 *
 * https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/
 *
 * algorithms
 * Medium (24.35%)
 * Likes:    240
 * Dislikes: 134
 * Total Accepted:    37K
 * Total Submissions: 102.2K
 * Testcase Example:  '4\n3\n[2,3]\n[2]'
 *
 * There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1)
 * and (m, n) containing some horizontal and vertical fences given in arrays
 * hFences and vFences respectively.
 * 
 * Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i],
 * n) and vertical fences are from the coordinates (1, vFences[i]) to (m,
 * vFences[i]).
 * 
 * Return the maximum area of a square field that can be formed by removing
 * some fences (possibly none) or -1 if it is impossible to make a square
 * field.
 * 
 * Since the answer may be large, return it modulo 10^9 + 7.
 * 
 * Note: The field is surrounded by two horizontal fences from the coordinates
 * (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the
 * coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be
 * removed.
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
 * Output: 4
 * Explanation: Removing the horizontal fence at 2 and the vertical fence at 2
 * will give a square field of area 4.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: m = 6, n = 7, hFences = [2], vFences = [4]
 * Output: -1
 * Explanation: It can be proved that there is no way to create a square field
 * by removing fences.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 3 <= m, n <= 10^9
 * 1 <= hFences.length, vFences.length <= 600
 * 1 < hFences[i] < m
 * 1 < vFences[i] < n
 * hFences and vFences are unique.
 * 
 * 
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int h_size = (int)hFences.size();
        const int v_size = (int)vFences.size();
        int max_width = -1;
        // Add the boundary fences
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        // Calculate all possible horizontal distances
        unordered_set<int> h_distances;
        for(int i = 0; i < h_size + 2; i++) {
            for(int j = i + 1; j < h_size + 2; j++) {
                h_distances.insert(abs(hFences[i] - hFences[j]));
            }
        }

        // Calculate all possible vertical distances
        unordered_set<int> v_distances;
        for(int i = 0; i < v_size + 2; i++) {
            for(int j = i + 1; j < v_size + 2; j++) {
                int v_width = abs(vFences[i] - vFences[j]);
                // Check if it exist in h_distances
                if(h_distances.count(v_width)) {
                    max_width = max(max_width, v_width);
                }
            }
        }

        return max_width == -1 ? -1 : (int)((long long)max_width * max_width % (1000000007));
    }
};
// @lc code=end
int main(int argc, char const **argv) {
    Solution sol;
    // Test_1
    int m = 4, n = 3;
    vector<int> hFences = {2,3}, vFences = {2};
    int res = sol.maximizeSquareArea(m, n, hFences, vFences);
    cout << res << endl;
    assert(res == 4);

    // Test_2
    m = 6; n = 7;
    hFences = {2}; vFences = {4};
    res = sol.maximizeSquareArea(m, n, hFences, vFences);
    cout << res << endl;
    assert(res == -1);

    return 0;
}
// Accepted
// 648/648 cases passed (1063 ms)
// Your runtime beats 60.19 % of cpp submissions
// Your memory usage beats 49.51 % of cpp submissions (267.4 MB)