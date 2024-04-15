/*
 * @lc app=leetcode id=605 lang=c
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (33.05%)
 * Likes:    3114
 * Dislikes: 675
 * Total Accepted:    315.1K
 * Total Submissions: 952.9K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * You have a long flowerbed in which some of the plots are planted, and some
 * are not. However, flowers cannot be planted in adjacent plots.
 * 
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty
 * and 1 means not empty, and an integer n, return if n new flowers can be
 * planted in the flowerbed without violating the no-adjacent-flowers rule.
 * 
 * 
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= flowerbed.length <= 2 * 10^4
 * flowerbed[i] is 0 or 1.
 * There are no two adjacent flowers in flowerbed.
 * 0 <= n <= flowerbed.length
 * 
 * 
 */
#include <bits/stdc++.h>
// @lc code=start

bool canPlaceFlowers(int *flowerbed, int flowerbedSize, int n)
{
	// Starting from 1 for the head zero
	int continue_zero = 1;
	int flower = 0;
	for (int i = 0; i < flowerbedSize; i++) {
		if (flowerbed[i] == 0)
			continue_zero++;
		else {
			if (continue_zero > 0) {
				flower += (continue_zero - 1) / 2;
				continue_zero = 0;
			}
		}
		if (flower >= n)
			return true;
	}

	if (continue_zero > 0) {
		// Add one for tail zeros
		continue_zero++;
		flower += (continue_zero - 1) / 2;
	}
	if (flower >= n)
		return true;
	else
		return false;
}

// @lc code=end

int main()
{
	int flowerbedSize = 9;
	int flowerbed[flowerbedSize] = { 0, 0, 1, 0, 0, 0, 1, 0, 0 };
	int n = 3;
	int result = canPlaceFlowers(flowerbed, flowerbedSize, n);
	printf("%d\n", result);

	return 0;
}

// Accepted
// 124/124 cases passed (31 ms)
// Your runtime beats 40.38 % of c submissions
// Your memory usage beats 59.15 % of c submissions (7 MB)
