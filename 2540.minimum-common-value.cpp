#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        int top_1 = 0;
        int top_2 = 0;
        while (top_1 < (int)nums1.size() && top_2 < (int)nums2.size())
        {
            if (nums1[top_1] == nums2[top_2])
                return nums1[top_1];
            else if (nums1[top_1] < nums2[top_2])
                top_1++;
            else
                top_2++;
        }
        return -1;
    }
};

int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    vector<int> test_1_nums1 = { 1, 2, 3 };
    vector<int> test_1_nums2 = { 2, 4 };
    cout << sol.getCommon(test_1_nums1, test_1_nums2) << endl;

    // Test_1
    vector<int> test_2_nums1 = { 1, 2, 3, 6 };
    vector<int> test_2_nums2 = { 2, 3, 4, 5 };
    cout << sol.getCommon(test_2_nums1, test_2_nums2) << endl;

    return 0;
}