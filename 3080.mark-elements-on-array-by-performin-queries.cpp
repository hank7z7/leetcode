#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        long long         sum = 0;
        vector<long long> ret;
        // Min heap with pair { value, index }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < (int) nums.size(); i++)
        {
            sum += nums[i];
            pq.push({ nums[i], i });
        }

        for (auto querie : queries)
        {
            int idx = querie[0];
            int ops = querie[1];

            // Mark the value to zero
            // Then next time find this element, the substraction won't go wrong
            // Mark thd idx
            sum -= nums[idx];
            nums[idx] = 0;

            while (ops > 0 && pq.size() > 0)
            {
                // Find the smallest element
                if (nums[pq.top().second] != 0)
                {
                    nums[pq.top().second] = 0;
                    sum -= pq.top().first;
                    ops--;
                }
                pq.pop();
            }
            ret.push_back(sum);
        }

        return ret;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int>         nums_1    = { 1, 2, 2, 1, 2, 3, 1 };
    vector<vector<int>> queries_1 = { { 1, 2 }, { 3, 3 }, { 4, 2 } };
    for (auto ll : sol.unmarkedSumArray(nums_1, queries_1))
        cout << ll << " ";
    cout << endl;

    // Test_2
    vector<int>         nums_2    = { 1, 4, 2, 3 };
    vector<vector<int>> queries_2 = { { 0, 1 } };
    for (auto ll : sol.unmarkedSumArray(nums_2, queries_2))
        cout << ll << " ";
    cout << endl;

    return 0;
}
// 659 / 659 test cases passed.
// Status: Accepted
// Runtime: 275 ms
// Memory Usage: 137.1 MB