/*
 * @lc app=leetcode id=1578 lang=c
 *
 * [1578] Minimum Time to Make Rope Colorful
 */
#include <bits/stdc++.h>
// @lc code=start

int minCost(char *colors, int *neededTime, int neededTimeSize)
{
	int l = neededTimeSize;
	if (l <= 1)
		return 0;
	int result = 0;
	int total = 0;
	int leave = 0;
	int max_curr = 0;
	char char_curr = '0';
	int i = 0;
	for (i = 0; i < l; i++) {
		total += neededTime[i];
		if (char_curr != colors[i]) {
			leave += max_curr;
			char_curr = colors[i];
			max_curr = neededTime[i];
		} else {
			if (neededTime[i] > max_curr)
				max_curr = neededTime[i];
		}
	}
	if (char_curr != colors[i]) {
		leave += max_curr;
		char_curr = colors[i];
		max_curr = neededTime[i];
	}
	return total - leave;
}

// @lc code=end

int main()
{
	int N = 5;
	char colors[N + 1] = "aabaa";
	int cost[N] = { 1, 2, 3, 4, 1 };
	int ans = minCost(colors, cost, N);
	printf("%d\n", ans);

	return 0;
}

// Accepted
// 113/113 cases passed (176 ms)
// Your runtime beats 83.02 % of c submissions
// Your memory usage beats 30.5 % of c submissions (14.8 MB)