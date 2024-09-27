/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 *
 * https://leetcode.com/problems/my-calendar-i/description/
 *
 * algorithms
 * Medium (56.59%)
 * Likes:    4450
 * Dislikes: 118
 * Total Accepted:    338.5K
 * Total Submissions: 590.5K
 * Testcase Example:  '["MyCalendar","book","book","book"]\n[[],[10,20],[15,25],[20,30]]'
 *
 * You are implementing a program to use as your calendar. We can add a new
 * event if adding the event will not cause a double booking.
 *
 * A double booking happens when two events have some non-empty intersection
 * (i.e., some moment is common to both events.).
 *
 * The event can be represented as a pair of integers start and end that
 * represents a booking on the half-open interval [start, end), the range of
 * real numbers x such that start <= x < end.
 *
 * Implement the MyCalendar class:
 *
 *
 * MyCalendar() Initializes the calendar object.
 * boolean book(int start, int end) Returns true if the event can be added to
 * the calendar successfully without causing a double booking. Otherwise,
 * return false and do not add the event to the calendar.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MyCalendar", "book", "book", "book"]
 * [[], [10, 20], [15, 25], [20, 30]]
 * Output
 * [null, true, false, true]
 *
 * Explanation
 * MyCalendar myCalendar = new MyCalendar();
 * myCalendar.book(10, 20); // return True
 * myCalendar.book(15, 25); // return False, It can not be booked because time
 * 15 is already booked by another event.
 * myCalendar.book(20, 30); // return True, The event can be booked, as the
 * first event takes every time less than 20, but not including 20.
 *
 *
 * Constraints:
 *
 *
 * 0 <= start < end <= 10^9
 * At most 1000 calls will be made to book.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyCalendar
{
private:
    // Start -> End
    map<int, int> mp;

public:
    MyCalendar()
    {
        mp = map<int, int>{};
    }

    bool book(int start, int end)
    {
        // Returns an iterator pointing to the first element
        // in the container whose key is not considered to go before k
        map<int, int>::iterator key_lower_it = mp.lower_bound(start);

        // Check overlap
        if (key_lower_it != mp.end() && key_lower_it->first < end)
            return false;
        if (key_lower_it != mp.begin() && prev(key_lower_it)->second > start)
            return false;

        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end
int main(int argc, char **argv)
{
    MyCalendar *sol_1 = new MyCalendar();
    // Test_1
    vector<bool> res_1;
    res_1.push_back(sol_1->book(10, 20));
    res_1.push_back(sol_1->book(15, 25));
    res_1.push_back(sol_1->book(20, 30));
    for (auto res : res_1)
        cout << res << " ";
    cout << endl;
    assert((res_1 == vector<bool>{true, false, true}));
    delete sol_1;

    return 0;
}
// Accepted
// 107/107 cases passed (68 ms)
// Your runtime beats 88.62 % of cpp submissions
// Your memory usage beats 59.1 % of cpp submissions (42.7 MB)