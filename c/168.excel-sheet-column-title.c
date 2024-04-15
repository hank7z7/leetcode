/*
 * @lc app=leetcode id=168 lang=c
 *
 * [168] Excel Sheet Column Title
 *
 * https://leetcode.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (33.79%)
 * Likes:    3004
 * Dislikes: 442
 * Total Accepted:    328.7K
 * Total Submissions: 956.9K
 * Testcase Example:  '1'
 *
 * Given an integer columnNumber, return its corresponding column title as it
 * appears in an Excel sheet.
 * 
 * For example:
 * 
 * 
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 * ...
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: columnNumber = 1
 * Output: "A"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: columnNumber = 28
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: columnNumber = 701
 * Output: "ZY"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= columnNumber <= 2^31 - 1
 * 
 * 
 */

// @lc code=start


char * convertToTitle(int columnNumber){
    char * result = calloc(100, sizeof(char));
    int index = 0;
    while(columnNumber > 0)
    {
        result[index++] = columnNumber % 26 == 0 ? 'Z' : columnNumber % 26 + 'A' - 1;
        // Be careful if % 26 is zero
        columnNumber = columnNumber % 26 == 0 ? columnNumber / 26 - 1 : columnNumber / 26;
    }
    index--;

    // Reverse string
    int left = 0;
    while(index > left)
    {
        char tmp = result[index];
        result[index--] = result[left];
        result[left++] = tmp;
    }
    return result;
}
// @lc code=end

// Accepted
// 18/18 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 54.35 % of c submissions (5.6 MB)