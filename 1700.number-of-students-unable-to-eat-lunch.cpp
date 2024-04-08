/*
 * @lc app=leetcode id=1700 lang=cpp
 *
 * [1700] Number of Students Unable to Eat Lunch
 *
 * https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/
 *
 * algorithms
 * Easy (70.93%)
 * Likes:    1908
 * Dislikes: 165
 * Total Accepted:    137.8K
 * Total Submissions: 184.9K
 * Testcase Example:  '[1,1,0,0]\n[0,1,0,1]'
 *
 * The school cafeteria offers circular and square sandwiches at lunch break,
 * referred to by numbers 0 and 1 respectively. All students stand in a queue.
 * Each student either prefers square or circular sandwiches.
 *
 * The number of sandwiches in the cafeteria is equal to the number of
 * students. The sandwiches are placed in a stack. At each step:
 *
 *
 * If the student at the front of the queue prefers the sandwich on the top of
 * the stack, they will take it and leave the queue.
 * Otherwise, they will leave it and go to the queue's end.
 *
 *
 * This continues until none of the queue students want to take the top
 * sandwich and are thus unable to eat.
 *
 * You are given two integer arrays students and sandwiches where sandwiches[i]
 * is the type of the i^​​​​​​th sandwich in the stack (i = 0 is the top of the
 * stack) and students[j] is the preference of the j^​​​​​​th student in the
 * initial queue (j = 0 is the front of the queue). Return the number of
 * students that are unable to eat.
 *
 *
 * Example 1:
 *
 *
 * Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
 * Output: 0
 * Explanation:
 * - Front student leaves the top sandwich and returns to the end of the line
 * making students = [1,0,0,1].
 * - Front student leaves the top sandwich and returns to the end of the line
 * making students = [0,0,1,1].
 * - Front student takes the top sandwich and leaves the line making students =
 * [0,1,1] and sandwiches = [1,0,1].
 * - Front student leaves the top sandwich and returns to the end of the line
 * making students = [1,1,0].
 * - Front student takes the top sandwich and leaves the line making students =
 * [1,0] and sandwiches = [0,1].
 * - Front student leaves the top sandwich and returns to the end of the line
 * making students = [0,1].
 * - Front student takes the top sandwich and leaves the line making students =
 * [1] and sandwiches = [1].
 * - Front student takes the top sandwich and leaves the line making students =
 * [] and sandwiches = [].
 * Hence all students are able to eat.
 *
 *
 * Example 2:
 *
 *
 * Input: students = [1,1,1,0,0,1], sandwiches = [1,0,0,0,1,1]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= students.length, sandwiches.length <= 100
 * students.length == sandwiches.length
 * sandwiches[i] is 0 or 1.
 * students[i] is 0 or 1.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int countStudents(const vector<int>& students, const vector<int>& sandwiches)
    {
        queue<int> q;
        for (auto student : students)
            q.push(student);

        stack<int> st;
        for (auto it = sandwiches.rbegin(); it != sandwiches.rend(); it++)
            st.push(*it);

        int not_eat = 0;
        while (!q.empty())
        {
            int size = (int) q.size();
            if (q.front() == st.top())
            {
                st.pop();
                q.pop();
                not_eat = 0;
            }
            else
            {
                int to_end = q.front();
                q.pop();
                q.push(to_end);
                not_eat++;
            }
            if (not_eat == size)
                break;
        }
        return not_eat;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> students_1   = { 1, 1, 0, 0 };
    vector<int> sandwiches_1 = { 0, 1, 0, 1 };
    cout << sol.countStudents(students_1, sandwiches_1) << endl;

    // Test_2
    vector<int> students_2   = { 1, 1, 1, 0, 0, 1 };
    vector<int> sandwiches_2 = { 1, 0, 0, 0, 1, 1 };
    cout << sol.countStudents(students_2, sandwiches_2) << endl;

    return 0;
}
// Accepted
// 55/55 cases passed (5 ms)
// Your runtime beats 31.29 % of cpp submissions
// Your memory usage beats 50.25 % of cpp submissions (10.9 MB)