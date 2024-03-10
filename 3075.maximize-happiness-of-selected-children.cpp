#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        sort(happiness.begin(), happiness.end());
        long long ret         = 0;
        int       select_time = 0;
        for (int i = (int) happiness.size() - 1; i >= 0; i--)
        {
            ret += (long long) ((happiness[i] - select_time) < 0 ? 0
                                                                 : (happiness[i] - select_time));
            select_time++;
            k--;
            if (k == 0)
                break;
        }
        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    int      k;
    // Test_1
    vector<int> happiness_1 = { 1, 2, 3 };
    k                       = 2;
    cout << sol.maximumHappinessSum(happiness_1, k) << endl;

    // Test_2
    vector<int> happiness_2 = { 1, 1, 1, 1 };
    k                       = 2;
    cout << sol.maximumHappinessSum(happiness_2, k) << endl;

    // Test_3
    vector<int> happiness_3 = { 2, 3, 4, 5 };
    k                       = 1;
    cout << sol.maximumHappinessSum(happiness_3, k) << endl;
    return 0;
}
// 674 / 674 test cases passed.
// Status: Accepted
// Runtime: 153 ms
// Memory Usage: 107.1 MB