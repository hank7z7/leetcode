/*
 * @lc app=leetcode id=58 lang=c
 *
 * [58] Length of Last Word
 */

// @lc code=start

int lengthOfLastWord(char *s) {
    int length = strlen(s);
    int length_last_word = 0;
    bool isWord = false;
    for (int i = length - 1; i >= 0; i--) {
        if (isWord) {
            if (s[i] != ' ')
                length_last_word++;
            else
                break;
        } else {
            if (s[i] != ' ') {
                isWord = true;
                length_last_word++;
            }
        }
    }
    return length_last_word;
}
// @lc code=end

// Accepted
// 58/58 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 76.85 % of c submissions (5.7 MB)