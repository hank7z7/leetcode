/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution
{
public:
    void swap(char *x, char *y)
    {
        *y = *x ^ *y;
        *x = *x ^ *y;
        *y = *x ^ *y;
    }

    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }

    string reverseVowels(string s)
    {
        string out = s;
        for (int i = 0, j = out.size() - 1; i < j; i++, j--)
        {
            cout << "i = " << out[i] << ", j = " << out[j] << endl;
            while (!isVowel(out[i]))
            {
                i++;
                if (i >= j)
                    break;
            }
            while (!isVowel(out[j]))
            {
                j--;
                if (i >= j)
                    break;
            }
            if (i < j)
                swap(&out[i], &out[j]);
        }
        return out;
    }
};
// @lc code=end

// Accepted
// 480/480 cases passed (20 ms)
// Your runtime beats 11.29 % of cpp submissions
// Your memory usage beats 34.99 % of cpp submissions (7.9 MB)