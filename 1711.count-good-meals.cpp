#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int>& deliciousness)
    {
        unordered_map<int, int> um;
        vector<int>             pow_2s;
        for (long long pow_2 = 1; pow_2 < INT_MAX; pow_2 <<= 1)
            pow_2s.push_back((int) pow_2);
        long long count = 0;
        for (auto it : deliciousness)
        {
            for (auto pow_2 : pow_2s)
            {
                if ((int) pow_2 >= it && um.find(pow_2 - it) != um.end())
                {
                    // cout << it << ", " << pow_2 - it;
                    // cout << " Add " << um[pow_2 - it] << endl;
                    count += um[pow_2 - it];
                    count = count % 1000000007;
                }
            }
            um[it]++;
        }
        return (int) count;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> deliciousness_1 = { 1, 3, 5, 7, 9 };
    cout << sol.countPairs(deliciousness_1) << endl;

    // Test_2
    vector<int> deliciousness_2 = { 1, 1, 1, 3, 3, 3, 7 };
    cout << sol.countPairs(deliciousness_2) << endl;

    // Test_3
    vector<int> deliciousness_3
        = { 149, 107, 1, 63, 0, 1, 6867, 1325, 5611, 2581, 39, 89, 46, 18, 12, 20, 22, 234 };
    cout << sol.countPairs(deliciousness_3) << endl;

    return 0;
}
// Success
// Runtime: 322 ms, faster than 50.91% of C++ online submissions for Count Good Meals.
// Memory Usage: 75.9 MB, less than 70.00% of C++ online submissions for Count Good Meals.