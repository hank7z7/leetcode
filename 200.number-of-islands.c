/*
 * @lc app=leetcode id=200 lang=c
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (57.65%)
 * Likes:    21580
 * Dislikes: 471
 * Total Accepted:    2.4M
 * Total Submissions: 4.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 * 
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 * 
 * 
 */
#include <bits/stdc++.h>

// @lc code=start
#define DIMANTION (2)
#define DIR (4)
const int four_direction[DIR][DIMANTION] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void BFS(char **grid, int i_index, int j_index, int gridSize, int colSize)
{
	grid[i_index][j_index] = '0';
	int new_i = 0;
	int new_j = 0;
	for (int i = 0; i < DIR; i++) {
		new_i = i_index + four_direction[i][0];
		new_j = j_index + four_direction[i][1];
		if (new_i >= 0 && new_i < gridSize
		    && new_j >= 0 && new_j < colSize) {
			if (grid[new_i][new_j] == '1')
				BFS(grid, new_i, new_j, gridSize, colSize);
		}
	}
}

int numIslands(char **grid, int gridSize, int *gridColSize)
{
	int result = 0;
	int colSize = gridColSize[0];
	for (int i = 0; i < gridSize; i++) {
		for (int j = 0; j < colSize; j++) {
			if (grid[i][j] == '1') {
				result++;
				BFS(grid, i, j, gridSize, gridColSize[0]);
			}
		}
	}

	return result;
}

// @lc code=end

int main(int argc, char **argv)
{
	int gridSize = 4, colSize = 5;
	int gridColSize[gridSize] = { 0 };

	char input_1[gridSize][colSize] = { {'1', '1', '1', '1', '0'},
	{'1', '1', '0', '1', '0'},
	{'1', '1', '0', '0', '0'},
	{'0', '0', '0', '0', '0'}
	};

	char input_2[gridSize][colSize] = { {'1', '1', '0', '0', '0'},
	{'1', '1', '0', '0', '0'},
	{'0', '0', '1', '0', '0'},
	{'0', '0', '0', '1', '1'}
	};

	char *cast_input_1[] =
	    { input_1[0], input_1[1], input_1[2], input_1[3] };
	char *cast_input_2[] =
	    { input_2[0], input_2[1], input_2[2], input_2[3] };

	int result = numIslands(cast_input_1, gridSize, gridColSize);
	printf("%d\n", result);

	result = numIslands(cast_input_2, gridSize, gridColSize);
	printf("%d\n", result);

	return 0;
}
