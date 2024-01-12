/*
 * @lc app=leetcode id=455 lang=c
 *
 * [455] Assign Cookies
 *
 * https://leetcode.com/problems/assign-cookies/description/
 *
 * algorithms
 * Easy (51.93%)
 * Likes:    3638
 * Dislikes: 340
 * Total Accepted:    401.1K
 * Total Submissions: 759.9K
 * Testcase Example:  '[1,2,3]\n[1,1]'
 *
 * Assume you are an awesome parent and want to give your children some
 * cookies. But, you should give each child at most one cookie.
 *
 * Each child i has a greed factor g[i], which is the minimum size of a cookie
 * that the child will be content with; and each cookie j has a size s[j]. If
 * s[j] >= g[i], we can assign the cookie j to the child i, and the child i
 * will be content. Your goal is to maximize the number of your content
 * children and output the maximum number.
 *
 *
 * Example 1:
 *
 *
 * Input: g = [1,2,3], s = [1,1]
 * Output: 1
 * Explanation: You have 3 children and 2 cookies. The greed factors of 3
 * children are 1, 2, 3.
 * And even though you have 2 cookies, since their size is both 1, you could
 * only make the child whose greed factor is 1 content.
 * You need to output 1.
 *
 *
 * Example 2:
 *
 *
 * Input: g = [1,2], s = [1,2,3]
 * Output: 2
 * Explanation: You have 2 children and 3 cookies. The greed factors of 2
 * children are 1, 2.
 * You have 3 cookies and their sizes are big enough to gratify all of the
 * children,
 * You need to output 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= g.length <= 3 * 10^4
 * 0 <= s.length <= 3 * 10^4
 * 1 <= g[i], s[j] <= 2^31 - 1
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE_G_1 3
#define SIZE_S_1 2
#define SIZE_G_2 2
#define SIZE_S_2 3
#define SIZE_S_3 0
// @lc code=start
int cmp(const void* a, const void* b) { return *(int*) a - *(int*) b; }

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
    qsort(g, gSize, sizeof(int), cmp);
    qsort(s, sSize, sizeof(int), cmp);
    int g_top    = 0;
    int s_top    = 0;
    int is_given = 0;
    while (g_top < gSize && s_top < sSize)
    {
        if (s[s_top] >= g[g_top])
        {
            g_top++;
            is_given++;
        }
        s_top++;
    }

    return is_given;
}
// @lc code=end

int main(int argc, char** argv)
{
    int g_size_1      = SIZE_G_1;
    int g_1[SIZE_G_1] = { 1, 2, 3 };
    int s_size_1      = SIZE_S_1;
    int s_1[SIZE_S_1] = { 1, 1 };
    printf("%d\n", findContentChildren(g_1, g_size_1, s_1, s_size_1));

    int g_size_2      = SIZE_G_2;
    int g_2[SIZE_G_2] = { 1, 2 };
    int s_size_2      = SIZE_S_2;
    int s_2[SIZE_S_2] = { 1, 2, 3 };
    printf("%d\n", findContentChildren(g_2, g_size_2, s_2, s_size_2));

    int g_size_3      = SIZE_G_1;
    int g_3[SIZE_G_1] = { 1, 2, 3 };
    int s_size_3      = SIZE_S_3;
    int s_3[SIZE_S_3] = {};
    printf("%d\n", findContentChildren(g_3, g_size_3, s_3, s_size_3));

    return 0;
}

// Accepted
// 21/21 cases passed (38 ms)
// Your runtime beats 85.19 % of c submissions
// Your memory usage beats 18.01 % of c submissions (8.3 MB)