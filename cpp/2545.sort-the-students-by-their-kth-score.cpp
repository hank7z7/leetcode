#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k)
    {
        sort(score.begin(),
             score.end(),
             [&k](const vector<int>& a, const vector<int>& b) { return a[k] > b[k]; });

        return score;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    int      k;
    // Test_1
    k                           = 2;
    vector<vector<int>> score_1 = { { 10, 6, 9, 1 }, { 7, 5, 11, 2 }, { 4, 8, 3, 15 } };
    for (auto i : sol.sortTheStudents(score_1, k))
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }


    // Test_1
    k                           = 0;
    vector<vector<int>> score_2 = { { 3, 4 }, { 5, 6 } };
    for (auto i : sol.sortTheStudents(score_2, k))
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
// Success
// Details 
// Runtime: 57 ms, faster than 16.34% of C++ online submissions for Sort the Students by Their Kth Score.
// Memory Usage: 30.1 MB, less than 58.37% of C++ online submissions for Sort the Students by Their Kth Score.