/*
 * @lc app=leetcode id=1074 lang=c
 *
 * [1074] Number of Submatrices That Sum to Target
 *
 * https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/description/
 *
 * algorithms
 * Hard (69.61%)
 * Likes:    3130
 * Dislikes: 67
 * Total Accepted:    96.9K
 * Total Submissions: 137.7K
 * Testcase Example:  '[[0,1,0],[1,1,1],[0,1,0]]\n0'
 *
 * Given a matrix and a target, return the number of non-empty submatrices that
 * sum to target.
 *
 * A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x
 * <= x2 and y1 <= y <= y2.
 *
 * Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if
 * they have some coordinate that is different: for example, if x1 != x1'.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
 * Output: 4
 * Explanation: The four 1x1 submatrices that only contain 0.
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [[1,-1],[-1,1]], target = 0
 * Output: 5
 * Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the
 * 2x2 submatrix.
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [[904]], target = 0
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= matrix.length <= 100
 * 1 <= matrix[0].length <= 100
 * -1000 <= matrix[i] <= 1000
 * -10^8 <= target <= 10^8
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
int numSubmatrixSumTarget(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    int result = 0;
    // Prefix Sum
    for (int i = 0; i < matrixSize; i++)
    {
        int sum = 0;
        for (int j = 0; j < matrixColSize[i]; j++)
        {
            sum += matrix[i][j];
            matrix[i][j] = sum;
        }
    }
    for (int j = 0; j < matrixColSize[0]; j++)
    {
        int sum = 0;
        for (int i = 0; i < matrixSize; i++)
        {
            sum += matrix[i][j];
            matrix[i][j] = sum;
        }
    }

    int x1, y1, x2, y2;
    for (x1 = 0; x1 < matrixSize; x1++)
    {
        for (y1 = 0; y1 < matrixColSize[0]; y1++)
        {
            for (x2 = x1; x2 < matrixSize; x2++)
            {
                for (y2 = y1; y2 < matrixColSize[0]; y2++)
                {
                    /*
                    D - B - C + A
                    ---------
                    | A | B |
                    ---------
                    | C | D |
                    ---------
                    */
                    int a_x    = x1 - 1;
                    int a_y    = y1 - 1;
                    int area_a = ((a_x < 0) || (a_y < 0)) ? 0 : matrix[a_x][a_y];
                    int b_x    = x1 - 1;
                    int b_y    = y2;
                    int area_b = ((b_x < 0) || (b_y < 0)) ? 0 : matrix[b_x][b_y];
                    int c_x    = x2;
                    int c_y    = y1 - 1;
                    int area_c = ((c_x < 0) || (c_y < 0)) ? 0 : matrix[c_x][c_y];
                    int area_d = matrix[x2][y2];

                    if (((area_d - area_b - area_c + area_a) == target))
                    {
                        result++;
                    }
                }
            }
        }
    }
    return result;
}
// @lc code=end
int main(int argc, char** argv)
{
    // Test 1
    int  matrixSize_1    = 3;
    int* matrixColSize_1 = malloc(sizeof(int) * matrixSize_1);
    matrixColSize_1[0]   = 3;
    matrixColSize_1[1]   = 3;
    matrixColSize_1[2]   = 3;
    int   target_1       = 0;
    int** matrix_1       = (int**) malloc(sizeof(int*) * matrixSize_1);
    for (int i = 0; i < matrixSize_1; i++)
    {
        matrix_1[i] = (int*) malloc(sizeof(int) * matrixColSize_1[i]);
        memset(matrix_1[i], 0, sizeof(int) * matrixColSize_1[i]);
    }
    matrix_1[0][1] = 1;
    matrix_1[1][0] = 1;
    matrix_1[1][1] = 1;
    matrix_1[1][2] = 1;
    matrix_1[2][1] = 1;

    printf("%d\n", numSubmatrixSumTarget(matrix_1, matrixSize_1, matrixColSize_1, target_1));

    for (int i = 0; i < matrixSize_1; i++)
        free(matrix_1[i]);
    free(matrix_1);
    free(matrixColSize_1);

    return 0;
}
// First try AC!
// Accepted
// 40/40 cases passed (717 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 100 % of c submissions (6.2 MB)
