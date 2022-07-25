/*
 * @lc app=leetcode id=28 lang=c
 *
 * [28] Implement strStr()
 */

// @lc code=start

int strStr(char *haystack, char *needle) {
    int haystack_length = strlen(haystack);
    int needle_length = strlen(needle);
    if (needle_length == 0)
        return 0;

    int result = -1;
    if (haystack_length < needle_length)
        return result;

    for (int i = 0; i < haystack_length - needle_length + 1; i++) {
        if (haystack[i] == needle[0]) {
            bool one_part = true;
            for (int j = 0; j < needle_length; j++) {
                if (haystack[i + j] != needle[j]) {
                    one_part = false;
                    break;
                }
            }
            if (one_part == true) {
                result = i;
                return result; // Early return result for beat 100%
                break;         // Doesn't need actually
            }
        }
    }
    return result;
}
// @lc code=end

// Accepted
// 75/75 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 93.91 % of c submissions (5.6 MB)