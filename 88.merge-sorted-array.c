/*
 * @lc app=leetcode id=88 lang=c
 *
 * [88] Merge Sorted Array
 */
// #include <bits/stdc++.h>
// @lc code=start

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    // Pick elements from tail of each nums
    for (int i = nums1Size - 1; i >= 0; i--) {
        // Early return
        if (n == 0)
            break;
        // Put larger one into nums1
        if (m > 0 && (nums1[m - 1] > nums2[n - 1])) {
            nums1[i] = nums1[m - 1];
            m--;
        } else {
            nums1[i] = nums2[n - 1];
            n--;
        }
    }
}
// @lc code=end

// int main()
// {
//     int nums1[6] = {4, 5, 6, 0, 0, 0};
//     int num1Size = 6;
//     int m = 3;
//     int nums2[3] = {1, 2, 3};
//     int num2Size = 3;
//     int n = 3;
//     merge(nums1, num1Size, m, nums2, num2Size, n);
//     for(int i = 0; i < num1Size; i++)
//         printf("%d ", nums1[i]);
//     return 0;
// }

// Accepted
// 59/59 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 9.46 % of c submissions (6.4 MB)