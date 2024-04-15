#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        queue<int> radiant;
        queue<int> dire;
        for (size_t i = 0; i < senate.size(); i++)
        {
            if (senate[i] == 'R')
            {
                radiant.push(i);
            }
            else if (senate[i] == 'D')
            {
                dire.push(i);
            }
        }

        int top = (int) senate.size();
        while (!radiant.empty() && !dire.empty())
        {
            if (radiant.front() < dire.front())
            {
                radiant.push(top++);
            }
            else
            {
                dire.push(top++);
            }
            radiant.pop();
            dire.pop();
        }
        if (!radiant.empty())
            return "Radiant";
        else
            return "Dire";
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    string senate_1 = "RD";
    cout << sol.predictPartyVictory(senate_1) << endl;

    // Test_2
    string senate_2 = "RDD";
    cout << sol.predictPartyVictory(senate_2) << endl;

    return 0;
}
// Success
// Details
// Runtime: 5 ms, faster than 62.24% of C++ online submissions for Dota2 Senate.
// Memory Usage: 10.4 MB, less than 40.41% of C++ online submissions for Dota2 Senate.