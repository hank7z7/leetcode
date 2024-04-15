/*
 * @lc app=leetcode id=1337 lang=c
 *
 * [1337] The K Weakest Rows in a Matrix
 *
 * https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
 *
 * algorithms
 * Easy (73.40%)
 * Likes:    4100
 * Dislikes: 229
 * Total Accepted:    353.1K
 * Total Submissions: 481.1K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
 *
 * You are given an m x n binary matrix mat of 1's (representing soldiers) and
 * 0's (representing civilians). The soldiers are positioned in front of the
 * civilians. That is, all the 1's will appear to the left of all the 0's in
 * each row.
 *
 * A row i is weaker than a row j if one of the following is true:
 *
 *
 * The number of soldiers in row i is less than the number of soldiers in row
 * j.
 * Both rows have the same number of soldiers and i < j.
 *
 *
 * Return the indices of the k weakest rows in the matrix ordered from weakest
 * to strongest.
 *
 *
 * Example 1:
 *
 *
 * Input: mat =
 * [[1,1,0,0,0],
 * ⁠[1,1,1,1,0],
 * ⁠[1,0,0,0,0],
 * ⁠[1,1,0,0,0],
 * ⁠[1,1,1,1,1]],
 * k = 3
 * Output: [2,0,3]
 * Explanation:
 * The number of soldiers in each row is:
 * - Row 0: 2
 * - Row 1: 4
 * - Row 2: 1
 * - Row 3: 2
 * - Row 4: 5
 * The rows ordered from weakest to strongest are [2,0,3,1,4].
 *
 *
 * Example 2:
 *
 *
 * Input: mat =
 * [[1,0,0,0],
 * ⁠[1,1,1,1],
 * ⁠[1,0,0,0],
 * ⁠[1,0,0,0]],
 * k = 2
 * Output: [0,2]
 * Explanation:
 * The number of soldiers in each row is:
 * - Row 0: 1
 * - Row 1: 4
 * - Row 2: 1
 * - Row 3: 1
 * The rows ordered from weakest to strongest are [0,2,3,1].
 *
 *
 *
 * Constraints:
 *
 *
 * m == mat.length
 * n == mat[i].length
 * 2 <= n, m <= 100
 * 1 <= k <= m
 * matrix[i][j] is either 0 or 1.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
// @lc code=start
int cmp(const void** a, const void** b)
{
    if ((*(int**) a)[1] > (*(int**) b)[1])
        return 1;
    else if ((*(int**) a)[1] == (*(int**) b)[1])
    {
        return (*(int**) a)[0] > (*(int**) b)[0];
    }
    else
        return -1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize)
{
    int** idx_count = (int**) malloc(sizeof(int*) * matSize);
    for (int i = 0; i < matSize; i++)
    {
        idx_count[i]    = (int*) malloc(sizeof(int) * 2);
        idx_count[i][0] = i;
        idx_count[i][1] = 0;
        for (int j = 0; j < matColSize[i]; j++)
            if (mat[i][j] == 1)
                idx_count[i][1]++;
    }

    qsort(idx_count, matSize, sizeof(idx_count[0]), cmp);

    *returnSize = k;
    int* ret    = (int*) malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
        ret[i] = idx_count[i][0];
    for (int i = 0; i < matSize; i++)
        free(idx_count[i]);
    free(idx_count);

    return ret;
}
// @lc code=end
#define M_SIZE_1 5
#define N_SIZE_1 5
#define M_SIZE_2 4
#define N_SIZE_2 4
int main(int argc, char** argv)
{
    int k;
    int returnSize;
    // Test_1
    int  mat_1[M_SIZE_1][N_SIZE_1] = { { 1, 1, 0, 0, 0 },
                                       { 1, 1, 1, 1, 0 },
                                       { 1, 0, 0, 0, 0 },
                                       { 1, 1, 0, 0, 0 },
                                       { 1, 1, 1, 1, 1 } };
    int* mat_to_ptr_1[M_SIZE_1];
    for (int i = 0; i < M_SIZE_1; i++)
        mat_to_ptr_1[i] = mat_1[i];
    int** mat_to_ptr_of_ptr_1 = mat_to_ptr_1;
    int   matColSize_1[M_SIZE_1];
    for (int i = 0; i < M_SIZE_1; i++)
        matColSize_1[i] = N_SIZE_1;
    k = 3;

    int* ret_1 = kWeakestRows(mat_to_ptr_of_ptr_1, M_SIZE_1, matColSize_1, k, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d%c", ret_1[i], i == (returnSize - 1) ? '\n' : ' ');
    free(ret_1);

    // Test_2
    int mat_2[M_SIZE_2][N_SIZE_2]
        = { { 1, 0, 0, 0 }, { 1, 1, 1, 1 }, { 1, 0, 0, 0 }, { 1, 0, 0, 0 } };
    int* mat_to_ptr_2[M_SIZE_2];
    for (int i = 0; i < M_SIZE_2; i++)
        mat_to_ptr_2[i] = mat_2[i];
    int** mat_to_ptr_of_ptr_2 = mat_to_ptr_2;
    int   matColSize_2[M_SIZE_2];
    for (int i = 0; i < M_SIZE_2; i++)
        matColSize_2[i] = N_SIZE_2;
    k = 4;

    int* ret_2 = kWeakestRows(mat_to_ptr_of_ptr_2, M_SIZE_2, matColSize_2, k, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d%c", ret_2[i], i == (returnSize - 1) ? '\n' : ' ');
    free(ret_2);
    return 0;
}
// Accepted
// 52/52 cases passed (11 ms)
// Your runtime beats 71.05 % of c submissions
// Your memory usage beats 63.16 % of c submissions (6.8 MB)