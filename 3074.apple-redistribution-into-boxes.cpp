#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        sort(capacity.begin(), capacity.end());
        int total = 0;
        for (auto it : apple)
            total += it;
        int ret = 0;
        // cout << total << endl;
        for (int i = (int) capacity.size() - 1; i >= 0; i--)
        {
            // cout << capacity[i] << " ";
            total -= capacity[i];
            ret++;
            if (total <= 0)
                break;
        }
        // cout << endl;
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> apple_1    = { 1, 3, 2 };
    vector<int> capacity_1 = { 4, 3, 1, 5, 2 };
    cout << sol.minimumBoxes(apple_1, capacity_1) << endl;

    // Test_2
    vector<int> apple_2    = { 5, 5, 5 };
    vector<int> capacity_2 = { 2, 4, 2, 7 };
    cout << sol.minimumBoxes(apple_2, capacity_2) << endl;
}
// 565 / 565 test cases passed.
// Status: Accepted
// Runtime: 3 ms
// Memory Usage: 32.1 MB