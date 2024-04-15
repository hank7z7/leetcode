/*
 * @lc app=leetcode id=506 lang=c
 *
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (56.37%)
 * Likes:    634
 * Dislikes: 37
 * Total Accepted:    99.6K
 * Total Submissions: 171.4K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * You are given an integer array score of size n, where score[i] is the score
 * of the i^th athlete in a competition. All the scores are guaranteed to be
 * unique.
 * 
 * The athletes are placed based on their scores, where the 1^st place athlete
 * has the highest score, the 2^nd place athlete has the 2^nd highest score,
 * and so on. The placement of each athlete determines their rank:
 * 
 * 
 * The 1^st place athlete's rank is "Gold Medal".
 * The 2^nd place athlete's rank is "Silver Medal".
 * The 3^rd place athlete's rank is "Bronze Medal".
 * For the 4^th place to the n^th place athlete, their rank is their placement
 * number (i.e., the x^th place athlete's rank is "x").
 * 
 * 
 * Return an array answer of size n where answer[i] is the rank of the i^th
 * athlete.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: score = [5,4,3,2,1]
 * Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
 * Explanation: The placements are [1^st, 2^nd, 3^rd, 4^th, 5^th].
 * 
 * Example 2:
 * 
 * 
 * Input: score = [10,3,8,9,4]
 * Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
 * Explanation: The placements are [1^st, 5^th, 3^rd, 2^nd, 4^th].
 * 
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == score.length
 * 1 <= n <= 10^4
 * 0 <= score[i] <= 10^6
 * All the values in score are unique.
 * 
 * 
 */
#include <bits/stdc++.h>
// @lc code=start
struct Scores
{
  int score_val;
  int index;
};

int
compare (const void *a, const void *b)
{
  // Be careful the address casting!
  return (*(struct Scores *) a).score_val < (*(struct Scores *) b).score_val;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **
findRelativeRanks (int *score, int scoreSize, int *returnSize)
{
  char **result = (char **) malloc (sizeof (char *) * scoreSize);
  struct Scores arr[scoreSize];
  for (int i = 0; i < scoreSize; i++)
    {
      arr[i].score_val = score[i];
      arr[i].index = i;
    }

  qsort (arr, scoreSize, sizeof (struct Scores), compare);

  (*returnSize) = scoreSize;
  for (int i = 0; i < scoreSize; i++)
    {
      printf ("%d ", arr[i].score_val);
      if (i == 0)
	{
	  result[arr[i].index] = (char *) malloc (sizeof (char) * 11);
	  sprintf (result[arr[i].index], "Gold Medal\0");
	}
      else if (i == 1)
	{
	  result[arr[i].index] = (char *) malloc (sizeof (char) * 13);
	  sprintf (result[arr[i].index], "Silver Medal\0");
	}
      else if (i == 2)
	{
	  result[arr[i].index] = (char *) malloc (sizeof (char) * 13);
	  sprintf (result[arr[i].index], "Bronze Medal\0");
	}
      else
	{
	  result[arr[i].index] = (char *) malloc (sizeof (char) * 10);
	  sprintf (result[arr[i].index], "%d\0", i + 1);
	}
    }
  return result;
}

// @lc code=end
int
main ()
{
  int arr[5] = { 5, 4, 3, 2, 1 };
  int size = 0;
  char **result = findRelativeRanks (arr, 5, &size);
  for (int i = 0; i < size; i++)
    printf ("%s\n", result[i]);
  return 0;
}
