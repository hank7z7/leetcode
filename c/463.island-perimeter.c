/*
 * @lc app=leetcode id=463 lang=c
 *
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (68.84%)
 * Likes:    4766
 * Dislikes: 254
 * Total Accepted:    384.9K
 * Total Submissions: 555.9K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given row x col grid representing a map where grid[i][j] = 1
 * represents land and grid[i][j] = 0 represents water.
 * 
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e.,
 * one or more connected land cells).
 * 
 * The island doesn't have "lakes", meaning the water inside isn't connected to
 * the water around the island. One cell is a square with side length 1. The
 * grid is rectangular, width and height don't exceed 100. Determine the
 * perimeter of the island.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
 * Output: 16
 * Explanation: The perimeter is the 16 yellow stripes in the image above.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1]]
 * Output: 4
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,0]]
 * Output: 4
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * row == grid.length
 * col == grid[i].length
 * 1 <= row, col <= 100
 * grid[i][j] is 0 or 1.
 * There is exactly one island in grid.
 * 
 * 
 */

// @lc code=start

int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
	// int result = 0;
	// for(int i = 0; i < gridSize; i++)
	// {
	//     int col_size = gridColSize[i];
	//     for(int j = 0; j < col_size; j++)
	//     {
	//         if(grid[i][j] == 1){
	//             int check_grid = 0;
	//             // Up
	//             check_grid = (i == 0) ? 0 : grid[i-1][j];
	//             if(check_grid == 0)
	//                 result++;
	//             // Down
	//             check_grid = (i == (gridSize - 1)) ? 0 : grid[i + 1][j];
	//             if (check_grid == 0)
	//               result++;
	//             // Left
	//             check_grid = (j == 0) ? 0 : grid[i][j - 1];
	//             if (check_grid == 0)
	//               result++;
	//             // Right
	//             check_grid = (j == (col_size - 1)) ? 0 : grid[i][j + 1];
	//             if (check_grid == 0)
	//               result++;
	//         }
	//     }
	// }
	// return result;

	// Accepted
	// 5833/5833 cases passed (133 ms)
	// Your runtime beats 46.62 % of c submissions
	// Your memory usage beats 16.54 % of c submissions (9.1 MB)

	// Amazing Solution
	int count = 0, repeat = 0;
	for (int i = 0; i < gridSize; i++) {
		int colSize = gridColSize[i];
		for (int j = 0; j < colSize; j++) {
			if (grid[i][j] == 1) {
				count++;
				if (i != 0 && grid[i - 1][j] == 1)
					repeat++;
				if (j != 0 && grid[i][j - 1] == 1)
					repeat++;
			}
		}
	}
	return 4 * count - repeat * 2;
}

// @lc code=end

// Accepted
// 5833/5833 cases passed (105 ms)
// Your runtime beats 70.68 % of c submissions
// Your memory usage beats 61.65 % of c submissions (8.8 MB)
