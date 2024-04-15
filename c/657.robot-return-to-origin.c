/*
 * @lc app=leetcode id=657 lang=c
 *
 * [657] Robot Return to Origin
 */

// @lc code=start

bool judgeCircle(char *moves)
{
	int updown = 0;
	int rightleft = 0;
	int l = strlen(moves);
	for (int i = 0; i < l; i++) {
		switch (moves[i]) {
		case 'U':
			updown++;
			break;
		case 'D':
			updown--;
			break;
		case 'R':
			rightleft++;
			break;
		case 'L':
			rightleft--;
			break;
		default:
			break;
		}
	}
	return (updown == 0 && rightleft == 0);
}

// @lc code=end

// Accepted
// 75/75 cases passed (5 ms)
// Your runtime beats 86.73 % of c submissions
// Your memory usage beats 48.98 % of c submissions (6.1 MB)
