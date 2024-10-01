/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 *
 * https://leetcode.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (37.05%)
 * Likes:    2017
 * Dislikes: 196
 * Total Accepted:    155.7K
 * Total Submissions: 344.2K
 * Testcase Example:  '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n' +
  '[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * Design a data structure to store the strings' count with the ability to
 * return the strings with minimum and maximum counts.
 *
 * Implement the AllOne class:
 *
 *
 * AllOne() Initializes the object of the data structure.
 * inc(String key) Increments the count of the string key by 1. If key does not
 * exist in the data structure, insert it with count 1.
 * dec(String key) Decrements the count of the string key by 1. If the count of
 * key is 0 after the decrement, remove it from the data structure. It is
 * guaranteed that key exists in the data structure before the decrement.
 * getMaxKey() Returns one of the keys with the maximal count. If no element
 * exists, return an empty string "".
 * getMinKey() Returns one of the keys with the minimum count. If no element
 * exists, return an empty string "".
 *
 *
 * Note that each function must run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * Output
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 *
 * Explanation
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // return "hello"
 * allOne.getMinKey(); // return "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // return "hello"
 * allOne.getMinKey(); // return "leet"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= key.length <= 10
 * key consists of lowercase English letters.
 * It is guaranteed that for each call to dec, key is existing in the data
 * structure.
 * At most 5 * 10^4 calls will be made to inc, dec, getMaxKey, and getMinKey.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class AllOne
{
private:
    // String -> count
    unordered_map<string, int> um;
    // Count -> string
    map<int, unordered_set<string>> mp;

public:
    AllOne()
    {
        um = unordered_map<string, int>{};
        mp = map<int, unordered_set<string>>{};
    }

    void inc(string key)
    {
        int prev_count = um[key];
        um[key]++;
        if (prev_count > 0)
        {
            mp[prev_count].erase(key);
            if (mp[prev_count].empty())
                mp.erase(prev_count);
        }
        mp[um[key]].insert(key);
    }

    void dec(string key)
    {
        int prev_count = um[key];
        um[key]--;
        mp[prev_count].erase(key);
        if (mp[prev_count].empty())
            mp.erase(prev_count);
        if (um[key] == 0)
        {
            um.erase(key);
        }
        else
        {
            mp[um[key]].insert(key);
        }
    }

    string getMaxKey()
    {
        if (!mp.empty())
            return *(mp.rbegin()->second.begin());

        return "";
    }

    string getMinKey()
    {
        if (!mp.empty())
            return *(mp.begin()->second.begin());
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
int main(int argc, char **argv)
{
    AllOne *sol_1 = new AllOne();
    sol_1->inc("hello");
    sol_1->inc("hello");
    cout << sol_1->getMaxKey() << endl;
    cout << sol_1->getMinKey() << endl;
    sol_1->inc("leet");
    cout << sol_1->getMaxKey() << endl;
    cout << sol_1->getMinKey() << endl;
    delete (sol_1);

    return 0;
}
