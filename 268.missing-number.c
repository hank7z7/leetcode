/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (59.16%)
 * Likes:    6820
 * Dislikes: 2946
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array nums containing n distinct numbers in the range [0, n],
 * return the only number in the range that is missing from the array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3,0,1]
 * Output: 2
 * Explanation: n = 3 since there are 3 numbers, so all numbers are in the
 * range [0,3]. 2 is the missing number in the range since it does not appear
 * in nums.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: n = 2 since there are 2 numbers, so all numbers are in the
 * range [0,2]. 2 is the missing number in the range since it does not appear
 * in nums.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * Explanation: n = 9 since there are 9 numbers, so all numbers are in the
 * range [0,9]. 8 is the missing number in the range since it does not appear
 * in nums.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == nums.length
 * 1 <= n <= 10^4
 * 0 <= nums[i] <= n
 * All the numbers of nums are unique.
 * 
 * 
 * 
 * Follow up: Could you implement a solution using only O(1) extra space
 * complexity and O(n) runtime complexity?
 * 
 */
// #include <bits/stdc++.h>
// @lc code=start
// #define divide_5_mask 0x1f
// int missingNumber(int *nums, int numsSize)
// {
// 	int map_size = (numsSize >> 5) + 1;
// 	int bit_map[map_size];	// 313 integers = 10016, contain all possible n
// 	// Init all map
// 	memset(bit_map, 0, map_size * sizeof(int));
//     for (int i = numsSize & divide_5_mask; i < 32; i++)
// 		bit_map[map_size - 1] |= (UINT32_C(1) << i);

//     // Setting all map
// 	for (int i = 0; i < numsSize; i++) {
// 		bit_map[nums[i] >> 5] |= (UINT32_C(1) << (nums[i] & divide_5_mask));
// 	}

//     int result = 0;
//     int not_int_max;
// 	for (int not_int_max = 0; not_int_max < map_size; not_int_max++) {
// 		if ((unsigned int)bit_map[not_int_max] != 0xffffffff) {
// 			unsigned int bit = ~bit_map[not_int_max];
// 			result = not_int_max << 5;
// 			while (bit > 1) {
// 				result++;
// 				bit >>= 1;
// 			}
// 			return result;
// 		}
// 	}
// 	return numsSize;
// }
// Accepted
// 122/122 cases passed (27 ms)
// Your runtime beats 55.61 % of c submissions
// Your memory usage beats 29.44 % of c submissions (6.8 MB)
int missingNumber(int *nums, int numsSize)
{
	// Amazing!
    int actual_sum = 0, expected_sum = 0;
    for(int i = 0; i < numsSize; i++)
    {
        expected_sum += i;
        actual_sum += nums[i];
    }
    expected_sum += numsSize;
    return expected_sum - actual_sum;
}
// Accepted
// 122/122 cases passed (17 ms)
// Your runtime beats 95.53 % of c submissions
// Your memory usage beats 29.44 % of c submissions (6.8 MB)
// @lc code=end

// int main()
// {
// 	int array[] = {37,21,24,4,35,14,41,36,45,27,2,39,6,8,48,33,0,32,43,40,10,34,23,11,17,16,47,29,15,28,13,5,49,38,9,22,19,1,42,30,3,26,46,44,7,12,25,18,20};
// 	printf("%d\n", missingNumber(array, sizeof(array)/sizeof(int)));
// 	return 0;
// }
