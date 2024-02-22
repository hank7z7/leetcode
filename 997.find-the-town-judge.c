/*
 * @lc app=leetcode id=997 lang=c
 *
 * [997] Find the Town Judge
 *
 * https://leetcode.com/problems/find-the-town-judge/description/
 *
 * algorithms
 * Easy (49.07%)
 * Likes:    6162
 * Dislikes: 518
 * Total Accepted:    483.9K
 * Total Submissions: 981.6K
 * Testcase Example:  '2\n[[1,2]]'
 *
 * In a town, there are n people labeled from 1 to n. There is a rumor that one
 * of these people is secretly the town judge.
 *
 * If the town judge exists, then:
 *
 *
 * The town judge trusts nobody.
 * Everybody (except for the town judge) trusts the town judge.
 * There is exactly one person that satisfies properties 1 and 2.
 *
 *
 * You are given an array trust where trust[i] = [ai, bi] representing that the
 * person labeled ai trusts the person labeled bi. If a trust relationship does
 * not exist in trust array, then such a trust relationship does not exist.
 *
 * Return the label of the town judge if the town judge exists and can be
 * identified, or return -1 otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2, trust = [[1,2]]
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: n = 3, trust = [[1,3],[2,3]]
 * Output: 3
 *
 *
 * Example 3:
 *
 *
 * Input: n = 3, trust = [[1,3],[2,3],[3,1]]
 * Output: -1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1000
 * 0 <= trust.length <= 10^4
 * trust[i].length == 2
 * All the pairs of trust are unique.
 * ai != bi
 * 1 <= ai, bi <= n
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// @lc code=start
// C bitset
#define BITMASK(b) (1 << ((b) & (CHAR_BIT - 1)))
#define BITSLOT(b) ((b) / CHAR_BIT)
#define BITSET(a, b) ((a)[BITSLOT(b)] |= BITMASK(b))
#define BITCLEAR(a, b) ((a)[BITSLOT(b)] &= ~BITMASK(b))
#define BITTEST(a, b) ((a)[BITSLOT(b)] & BITMASK(b))
#define BITNSLOTS(nb) ((nb + CHAR_BIT - 1) / CHAR_BIT)

int findJudge(int n, int** trust, int trustSize, int* trustColSize)
{
    char bitarray[BITNSLOTS(n + 1)];
    memset(bitarray, 0, sizeof(bitarray));
    int* count = (int*) malloc(sizeof(int) * (n + 1));
    memset(count, 0, sizeof(int) * (n + 1));
    for (int i = 0; i < trustSize; i++)
    {
        BITSET(bitarray, trust[i][0]);
        count[trust[i][1]]++;
    }
    int judge       = 0;
    int trust_count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!BITTEST(bitarray, i))
        {
            judge = i;
            trust_count++;
        }
    }
    if (!(trust_count == 1 && count[judge] == (n - 1)))
        judge = -1;
    free(count);
    return judge;
}
// @lc code=end
#define SIZE_1 (1)
#define SIZE_2 (2)
#define SIZE_3 (3)
#define SIZE_4 (2)
#define COL_SIZE (2)
int main(int argc, char** argv)
{
    printf("%d\n", CHAR_BIT);
    int n;
    int size;
    // Test_1
    n                              = 2;
    size                           = SIZE_1;
    int  trust_1[SIZE_1][COL_SIZE] = { { 1, 2 } };
    int* trust_1_ptr[SIZE_1];
    for (int i = 0; i < size; i++)
        trust_1_ptr[i] = trust_1[i];
    int** trust_1_ptr_ptr   = trust_1_ptr;
    int   colsize_1[SIZE_1] = { 2 };
    printf("%d\n", findJudge(n, trust_1_ptr_ptr, size, colsize_1));

    // Test_2
    n                              = 3;
    size                           = SIZE_2;
    int  trust_2[SIZE_2][COL_SIZE] = { { 1, 3 }, { 2, 3 } };
    int* trust_2_ptr[SIZE_2];
    for (int i = 0; i < size; i++)
        trust_2_ptr[i] = trust_2[i];
    int** trust_2_ptr_ptr   = trust_2_ptr;
    int   colsize_2[SIZE_2] = { 2, 2 };
    printf("%d\n", findJudge(n, trust_2_ptr_ptr, size, colsize_2));

    // Test_3
    n                              = 3;
    size                           = SIZE_3;
    int  trust_3[SIZE_3][COL_SIZE] = { { 1, 3 }, { 2, 3 }, { 3, 1 } };
    int* trust_3_ptr[SIZE_3];
    for (int i = 0; i < size; i++)
        trust_3_ptr[i] = trust_3[i];
    int** trust_3_ptr_ptr   = trust_3_ptr;
    int   colsize_3[SIZE_3] = { 2, 2, 2 };
    printf("%d\n", findJudge(n, trust_3_ptr_ptr, size, colsize_3));

    // Test_4
    n                              = 3;
    size                           = SIZE_4;
    int  trust_4[SIZE_4][COL_SIZE] = { { 1, 2 }, { 2, 3 } };
    int* trust_4_ptr[SIZE_4];
    for (int i = 0; i < size; i++)
        trust_4_ptr[i] = trust_4[i];
    int** trust_4_ptr_ptr   = trust_4_ptr;
    int   colsize_4[SIZE_4] = { 2, 2 };
    printf("%d\n", findJudge(n, trust_4_ptr_ptr, size, colsize_4));

    return 0;
}
// Accepted
// 92/92 cases passed (130 ms)
// Your runtime beats 62.26 % of c submissions
// Your memory usage beats 75.47 % of c submissions (16 MB)