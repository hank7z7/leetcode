/*
 * @lc app=leetcode id=74 lang=c
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (43.95%)
 * Likes:    8885
 * Dislikes: 293
 * Total Accepted:    911.1K
 * Total Submissions: 2M
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,60]]\n3'
 *
 * Write an efficient algorithm that searches for a value target in an m x n
 * integer matrix matrix. This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 100
 * -10^4 <= matrix[i][j], target <= 10^4
 * 
 * 
 */

// @lc code=start

bool searchMatrix(int **matrix, int matrixSize, int *matrixColSize, int target)
{
    for(int i = 0; i < matrixSize; i++)
    {
        if(target >= matrix[i][0])
            for(int j = 0; j < matrixColSize[i]; j++)
                if(target == matrix[i][j])
                    return true;
                else if(target < matrix[i][j])
                    return false;
    }

    return false;
}

// @lc code=end

// Accepted
// 133/133 cases passed (8 ms)
// Your runtime beats 43.2 % of c submissions
// Your memory usage beats 19.13 % of c submissions (6.5 MB)