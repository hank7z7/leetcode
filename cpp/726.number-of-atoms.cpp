/*
 * @lc app=leetcode id=726 lang=cpp
 *
 * [726] Number of Atoms
 *
 * https://leetcode.com/problems/number-of-atoms/description/
 *
 * algorithms
 * Hard (53.07%)
 * Likes:    1449
 * Dislikes: 312
 * Total Accepted:    78.8K
 * Total Submissions: 137.4K
 * Testcase Example:  '"H2O"'
 *
 * Given a string formula representing a chemical formula, return the count of
 * each atom.
 *
 * The atomic element always starts with an uppercase character, then zero or
 * more lowercase letters, representing the name.
 *
 * One or more digits representing that element's count may follow if the count
 * is greater than 1. If the count is 1, no digits will follow.
 *
 *
 * For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
 *
 *
 * Two formulas are concatenated together to produce another formula.
 *
 *
 * For example, "H2O2He3Mg4" is also a formula.
 *
 *
 * A formula placed in parentheses, and a count (optionally added) is also a
 * formula.
 *
 *
 * For example, "(H2O2)" and "(H2O2)3" are formulas.
 *
 *
 * Return the count of all elements as a string in the following form: the
 * first name (in sorted order), followed by its count (if that count is more
 * than 1), followed by the second name (in sorted order), followed by its
 * count (if that count is more than 1), and so on.
 *
 * The test cases are generated so that all the values in the output fit in a
 * 32-bit integer.
 *
 *
 * Example 1:
 *
 *
 * Input: formula = "H2O"
 * Output: "H2O"
 * Explanation: The count of elements are {'H': 2, 'O': 1}.
 *
 *
 * Example 2:
 *
 *
 * Input: formula = "Mg(OH)2"
 * Output: "H2MgO2"
 * Explanation: The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
 *
 *
 * Example 3:
 *
 *
 * Input: formula = "K4(ON(SO3)2)2"
 * Output: "K4N2O14S4"
 * Explanation: The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S':
 * 4}.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= formula.length <= 1000
 * formula consists of English letters, digits, '(', and ')'.
 * formula is always valid.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    string countOfAtoms(string formula)
    {
        int n = formula.length();
        unordered_map<string, int> result_counter;
        stack<unordered_map<string, int>> parenthesis_stack;
        int cur_ind = 0;

        while (cur_ind < n)
        {
            char cur_char = formula[cur_ind];

            if (cur_char == '(')
            {
                cur_ind++;
                parenthesis_stack.push(unordered_map<string, int>());
                continue;
            }

            if (cur_char == ')')
            {
                string mult_str = "";
                cur_ind++;

                while (cur_ind < n && isdigit(formula[cur_ind]))
                {
                    mult_str += formula[cur_ind];
                    cur_ind++;
                }

                int mult = mult_str.empty() ? 1 : stoi(mult_str);
                unordered_map<string, int> last_counter = parenthesis_stack.top();
                parenthesis_stack.pop();
                unordered_map<string, int> &target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();

                for (const auto &[elem, counter] : last_counter)
                {
                    target[elem] += counter * mult;
                }
                continue;
            }

            string cur_elem = "";
            string cur_counter_str = "";
            unordered_map<string, int> &target = parenthesis_stack.empty() ? result_counter : parenthesis_stack.top();

            while (cur_ind < n && formula[cur_ind] != '(' && formula[cur_ind] != ')')
            {
                if (isalpha(formula[cur_ind]))
                {
                    if (isupper(formula[cur_ind]) && !cur_elem.empty())
                    {
                        target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
                        cur_elem = "";
                        cur_counter_str = "";
                    }
                    cur_elem += formula[cur_ind];
                }
                else
                {
                    cur_counter_str += formula[cur_ind];
                }
                cur_ind++;
            }

            target[cur_elem] += cur_counter_str.empty() ? 1 : stoi(cur_counter_str);
        }

        vector<string> parts;
        for (const auto &[elem, counter] : result_counter)
        {
            parts.push_back(elem + (counter == 1 ? "" : to_string(counter)));
        }
        sort(parts.begin(), parts.end());

        string result;
        for (const auto &part : parts)
        {
            result += part;
        }

        return result;
    }
};
// @lc code=end
int main(int argc, char **argv)
{
    Solution sol;
    // Test_1
    string formula_1 = "H2O";
    string res_1 = sol.countOfAtoms(formula_1);
    cout << res_1 << endl;
    assert(res_1 == "H2O");

    // Test_2
    string formula_2 = "Mg(OH)2";
    string res_2 = sol.countOfAtoms(formula_2);
    cout << res_2 << endl;
    assert(res_2 == "H2MgO2");

    // Test_3
    string formula_3 = "K4(ON(SO3)2)2";
    string res_3 = sol.countOfAtoms(formula_3);
    cout << res_3 << endl;
    assert(res_3 == "K4N2O14S4");
}
