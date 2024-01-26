/*
 * @lc app=leetcode id=576 lang=c
 *
 * [576] Out of Boundary Paths
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// @lc code=start
#define MOD 1000000007
int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
{
	int result = 0;
	// DP for the sum of paths "k steps from (i, j) to boundary"
	// DP[k][m][n]
	int ***dp = (int ***)malloc(sizeof(int **) * (maxMove + 1));
	for (int i = 0; i <= maxMove; i++) {
		dp[i] = (int **)malloc(sizeof(int *) * m);
		for (int j = 0; j < m; j++) {
			dp[i][j] = (int *)malloc(sizeof(int) * n);
			memset(dp[i][j], 0, sizeof(int) * n);
		}
	}

	long long up, left, right, down;
	// the sum of DP[row - 1, column, n - 1]
	//          + DP[row + 1, column, n - 1]
	//          + DP[row, column - 1, n - 1]
	//          + DP[row, column + 1, n - 1]
	for (int k = 1; k <= maxMove; k++) {
		for (int x = 0; x < m; x++) {
			for (int y = 0; y < n; y++) {
				up = (x == 0) ? 1 : dp[k - 1][x - 1][y];
				left = (y == 0) ? 1 : dp[k - 1][x][y - 1];
				right =
				    (y == (n - 1)) ? 1 : dp[k - 1][x][y + 1];
				down = (x == (m - 1)) ? 1 : dp[k - 1][x + 1][y];
				dp[k][x][y] =
				    (int)((up + left + right + down) % MOD);
			}
		}
	}
	result = dp[maxMove][startRow][startColumn];

	for (int i = 0; i < (maxMove + 1); i++) {
		for (int j = 0; j < m; j++) {
			free(dp[i][j]);
		}
		free(dp[i]);
	}
	free(dp);
	return result;
}

// @lc code=end

int main(int argc, char **argv)
{
	int m, n, maxMove, startRow, startColumn;
	// Test 1
	m = 2;
	n = 2;
	maxMove = 2;
	startRow = 0;
	startColumn = 0;
	printf("%d\n", findPaths(m, n, maxMove, startRow, startColumn));

	// Test 2
	m = 1;
	n = 3;
	maxMove = 3;
	startRow = 0;
	startColumn = 1;
	printf("%d\n", findPaths(m, n, maxMove, startRow, startColumn));

	return 0;
}

// Accepted
// 94/94 cases passed (10 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 100 % of c submissions (8.3 MB)
