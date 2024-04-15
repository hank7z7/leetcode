/*
 * @lc app=leetcode id=219 lang=c
 *
 * [219] Contains Duplicate II
 *
 * https://leetcode.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (40.59%)
 * Likes:    2863
 * Dislikes: 2008
 * Total Accepted:    497.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * Given an integer array nums and an integer k, return true if there are two
 * distinct indices i and j in the array such that nums[i] == nums[j] and abs(i
 * - j) <= k.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,1], k = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,0,1,1], k = 1
 * Output: true
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,2,3,1,2,3], k = 2
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 * 
 * 
 */
// #include <bits/stdc++.h>
// @lc code=start

// Need to include "sthash.h", https://github.com/troydhanson/uthash
struct hash_struct {
	int id;
	int value;
	UT_hash_handle hh;
};

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
	struct hash_struct *map = NULL;
	for (int i = 0; i < numsSize; i++) {
		struct hash_struct *temp;
		HASH_FIND_INT(map, &nums[i], temp);
		if (temp == NULL) {
			temp = (struct hash_struct *)
			    malloc(sizeof(struct hash_struct));
			temp->id = nums[i];
			temp->value = i;
			HASH_ADD_INT(map, id, temp);
		} else {
			if ((i - temp->value) <= k) {
				return true;
			} else {
				temp->value = i;
			}
		}
	}
	return false;
}

// @lc code=end

// int main()
// {
//     int array[] = {1,2,3,1,2,3};
//     printf("%d\n", containsNearbyDuplicate(array, 6, 3));

//     return 0;
// }

// Accepted
// 51/51 cases passed (216 ms)
// Your runtime beats 55.33 % of c submissions
// Your memory usage beats 20 % of c submissions (43.3 MB)