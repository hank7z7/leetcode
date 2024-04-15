/*
 * @lc app=leetcode id=551 lang=c
 *
 * [551] Student Attendance Record I
 *
 * https://leetcode.com/problems/student-attendance-record-i/description/
 *
 * algorithms
 * Easy (47.50%)
 * Likes:    369
 * Dislikes: 22
 * Total Accepted:    155.2K
 * Total Submissions: 323.7K
 * Testcase Example:  '"PPALLP"'
 *
 * You are given a string s representing an attendance record for a student
 * where each character signifies whether the student was absent, late, or
 * present on that day. The record only contains the following three
 * characters:
 * 
 * 
 * 'A': Absent.
 * 'L': Late.
 * 'P': Present.
 * 
 * 
 * The student is eligible for an attendance award if they meet both of the
 * following criteria:
 * 
 * 
 * The student was absent ('A') for strictly fewer than 2 days total.
 * The student was never late ('L') for 3 or more consecutive days.
 * 
 * 
 * Return true if the student is eligible for an attendance award, or false
 * otherwise.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PPALLP"
 * Output: true
 * Explanation: The student has fewer than 2 absences and was never late 3 or
 * more consecutive days.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PPALLL"
 * Output: false
 * Explanation: The student was late 3 consecutive days in the last 3 days, so
 * is not eligible for the award.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 1000
 * s[i] is either 'A', 'L', or 'P'.
 * 
 * 
 */

// @lc code=start

bool checkRecord(char *s)
{
	int l = strlen(s);
	int late = 2;
	bool absent = false;
	for (int i = 0; i < l; i++) {
		switch (s[i]) {
		case 'A':
			if (absent)
				return false;
			else
				absent = true;
			late = 2;
			break;
		case 'L':
			if (late > 0)
				late--;
			else
				return false;
			break;
		case 'P':
			late = 2;
			break;
		default:
			break;
		}
	}

	return true;
}

// @lc code=end

// Accepted
// 113/113 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 33.33 % of c submissions (5.7 MB)