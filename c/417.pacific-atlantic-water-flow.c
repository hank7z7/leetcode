/*
 * @lc app=leetcode id=417 lang=c
 *
 * [417] Pacific Atlantic Water Flow
 *
 * https://leetcode.com/problems/pacific-atlantic-water-flow/description/
 *
 * algorithms
 * Medium (54.70%)
 * Likes:    7007
 * Dislikes: 1367
 * Total Accepted:    415.1K
 * Total Submissions: 756.3K
 * Testcase Example:  '[[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]'
 *
 * There is an m x n rectangular island that borders both the Pacific Ocean and
 * Atlantic Ocean. The Pacific Ocean touches the island's left and top edges,
 * and the Atlantic Ocean touches the island's right and bottom edges.
 * 
 * The island is partitioned into a grid of square cells. You are given an m x
 * n integer matrix heights where heights[r][c] represents the height above sea
 * level of the cell at coordinate (r, c).
 * 
 * The island receives a lot of rain, and the rain water can flow to
 * neighboring cells directly north, south, east, and west if the neighboring
 * cell's height is less than or equal to the current cell's height. Water can
 * flow from any cell adjacent to an ocean into the ocean.
 * 
 * Return a 2D list of grid coordinates result where result[i] = [ri, ci]
 * denotes that rain water can flow from cell (ri, ci) to both the Pacific and
 * Atlantic oceans.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: heights =
 * [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 * Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 * Explanation: The following cells can flow to the Pacific and Atlantic
 * oceans, as shown below:
 * [0,4]: [0,4] -> Pacific Ocean 
 * [0,4] -> Atlantic Ocean
 * [1,3]: [1,3] -> [0,3] -> Pacific Ocean 
 * [1,3] -> [1,4] -> Atlantic Ocean
 * [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
 * [1,4] -> Atlantic Ocean
 * [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
 * [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
 * [3,0]: [3,0] -> Pacific Ocean 
 * [3,0] -> [4,0] -> Atlantic Ocean
 * [3,1]: [3,1] -> [3,0] -> Pacific Ocean 
 * [3,1] -> [4,1] -> Atlantic Ocean
 * [4,0]: [4,0] -> Pacific Ocean 
 * ⁠      [4,0] -> Atlantic Ocean
 * Note that there are other possible paths for these cells to flow to the
 * Pacific and Atlantic oceans.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: heights = [[1]]
 * Output: [[0,0]]
 * Explanation: The water can flow from the only cell to the Pacific and
 * Atlantic oceans.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == heights.length
 * n == heights[r].length
 * 1 <= m, n <= 200
 * 0 <= heights[r][c] <= 10^5
 * 
 * 
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes) {
    
}
// @lc code=end

