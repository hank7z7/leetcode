#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        long long x   = ((long long) n * (long long) n + (long long) n) / 2;
        long long ret = sqrt(x);
        if ((ret * ret) == x)
            return (int) ret;
        return -1;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    int      n;
    // Test_1
    n = 4;
    cout << sol.pivotInteger(n) << endl;

    // Test_1
    n = 1;
    cout << sol.pivotInteger(n) << endl;

    // Test_3
    n = 8;
    cout << sol.pivotInteger(n) << endl;

    // Test_4
    n = 1000;
    cout << sol.pivotInteger(n) << endl;

    // Test_5
    n = INT_MAX;
    cout << n << ": " << sol.pivotInteger(n) << endl;

    return 0;
}
// Success
// Details
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find the Pivot Integer.
// Memory Usage: 7.3 MB, less than 41.86% of C++ online submissions for Find the Pivot Integer.