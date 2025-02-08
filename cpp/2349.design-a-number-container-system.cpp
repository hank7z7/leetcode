/*
 * @lc app=leetcode id=2349 lang=cpp
 *
 * [2349] Design a Number Container System
 *
 * https://leetcode.com/problems/design-a-number-container-system/description/
 *
 * algorithms
 * Medium (44.80%)
 * Likes:    863
 * Dislikes: 62
 * Total Accepted:    120.2K
 * Total Submissions: 207.2K
 * Testcase Example:  '["NumberContainers","find","change","change","change","change","find","change","find"]\n' +
  '[[],[10],[2,10],[1,10],[3,10],[5,10],[10],[1,20],[10]]'
 *
 * Design a number container system that can do the following:
 *
 *
 * Insert or Replace a number at the given index in the system.
 * Return the smallest index for the given number in the system.
 *
 *
 * Implement the NumberContainers class:
 *
 *
 * NumberContainers() Initializes the number container system.
 * void change(int index, int number) Fills the container at index with the
 * number. If there is already a number at that index, replace it.
 * int find(int number) Returns the smallest index for the given number, or -1
 * if there is no index that is filled by number in the system.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["NumberContainers", "find", "change", "change", "change", "change", "find",
 * "change", "find"]
 * [[], [10], [2, 10], [1, 10], [3, 10], [5, 10], [10], [1, 20], [10]]
 * Output
 * [null, -1, null, null, null, null, 1, null, 2]
 *
 * Explanation
 * NumberContainers nc = new NumberContainers();
 * nc.find(10); // There is no index that is filled with number 10. Therefore,
 * we return -1.
 * nc.change(2, 10); // Your container at index 2 will be filled with number
 * 10.
 * nc.change(1, 10); // Your container at index 1 will be filled with number
 * 10.
 * nc.change(3, 10); // Your container at index 3 will be filled with number
 * 10.
 * nc.change(5, 10); // Your container at index 5 will be filled with number
 * 10.
 * nc.find(10); // Number 10 is at the indices 1, 2, 3, and 5. Since the
 * smallest index that is filled with 10 is 1, we return 1.
 * nc.change(1, 20); // Your container at index 1 will be filled with number
 * 20. Note that index 1 was filled with 10 and then replaced with 20.
 * nc.find(10); // Number 10 is at the indices 2, 3, and 5. The smallest index
 * that is filled with 10 is 2. Therefore, we return 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= index, number <= 10^9
 * At most 10^5 calls will be made in total to change and find.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class NumberContainers
{
private:
    // index -> number
    unordered_map<int, int> um1;
    // number -> set of indexes
    unordered_map<int, set<int>> um2;

public:
    NumberContainers()
    {
        um1.clear();
        um2.clear();
    }

    void change(int index, int number)
    {
        int prev_num = -1;
        if (um1.find(index) != um1.end())
            prev_num = um1[index];
        um1[index] = number;

        if (prev_num != -1)
            um2[prev_num].erase(index);
        um2[number].insert(index);
    }

    int find(int number)
    {
        if (um2.find(number) != um2.end() && !um2[number].empty())
            return *um2[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// @lc code=end
int main()
{
    // Test_1
    NumberContainers *test_1 = new NumberContainers();
    cout << test_1->find(10) << endl;
    test_1->change(2, 10);
    cout << test_1->find(10) << endl;
    delete (test_1);

    // Test_2
    NumberContainers *test_2 = new NumberContainers();
    cout << test_2->find(10) << endl;
    test_2->change(2, 10);
    test_2->change(1, 10);
    test_2->change(3, 10);
    test_2->change(5, 10);
    cout << test_2->find(10) << endl;
    test_2->change(1, 20);
    cout << test_2->find(10) << endl;
    delete (test_2);

    // Test_3
    NumberContainers *test_3 = new NumberContainers();
    test_3->change(1, 10);
    cout << test_3->find(10) << endl;
    test_3->change(1, 20);
    cout << test_3->find(10) << endl;
    cout << test_3->find(20) << endl;
    cout << test_3->find(30) << endl;
    delete (test_3);

    return 0;
}
// Accepted
// 45/45 cases passed (128 ms)
// Your runtime beats 36.42 % of cpp submissions
// Your memory usage beats 45.07 % of cpp submissions (196 MB)