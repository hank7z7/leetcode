/*
 * @lc app=leetcode id=14 lang=c
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (41.82%)
 * Likes:    16450
 * Dislikes: 4322
 * Total Accepted:    2.9M
 * Total Submissions: 6.9M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 *
 * If there is no common prefix, return an empty string "".
 *
 *
 * Example 1:
 *
 *
 * Input: strs = ["flower","flow","flight"]
 * Output: "fl"
 *
 *
 * Example 2:
 *
 *
 * Input: strs = ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= strs.length <= 200
 * 0 <= strs[i].length <= 200
 * strs[i] consists of only lowercase English letters.
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
char *
longestCommonPrefix (char **strs, int strsSize)
{
  if (strsSize == 0)
    return "\0";

  char *result = (char *)malloc (sizeof (char) * 201);
  memset (result, '\0', 201);
  int returnSize = 0;
  int strlength[200] = { 0 };
  for (int i = 0; i < strsSize; i++)
    strlength[i] = strlen (&strs[i][0]);
  for (returnSize = 0; strs[0][returnSize] != '\0'; returnSize++)
    {
      // printf("%d\n", returnSize);
      for (int j = 1; j < strsSize; j++)
        {
          // printf("%d\n", strlen(&(strs[j][0])));
          // printf("%c %c\n", strs[0][returnSize], strs[j][returnSize]);
          if (returnSize > strlength[j]
              || strs[0][returnSize] != strs[j][returnSize])
            return result;
        }
      result[returnSize] = strs[0][returnSize];
    }

  return result;
}
// @lc code=end

int
main (int argc, char **argv)
{
  int strsSize = 0;
  // test 1
  strsSize = 3;
  char *test1[3] = { "flower\0", "flow\0", "flight\0" };
  char *result1 = longestCommonPrefix (test1, strsSize);
  printf ("%s\n", result1);
  free (result1);

  // test 1
  strsSize = 3;
  char *test2[3] = { "dog\0", "racecar\0", "car\0" };
  char *result2 = longestCommonPrefix (test2, strsSize);
  printf ("%s\n", result2);
  free (result2);

  return 0;
}
// Accepted
// 124/124 cases passed (4 ms)
// Your runtime beats 47 % of c submissions
// Your memory usage beats 48.62 % of c submissions (6.7 MB)