/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// #include <bits/stdc++.h>

// @lc code=start

char *addBinary(char *a, char *b) {
    // Result length should be max(a_char, b_char) or max(a_char, b_char) + 1
    int a_length = strlen(a);
    int b_length = strlen(b);
    int result_length = a_length > b_length ? a_length : b_length;
    char *result = (char *)malloc(sizeof(char) * (result_length + 2));
    result[result_length + 1] = '\0';

    // Add from tail of each string
    int carry = 0;
    for (int i = 0; i <= result_length; i++) {
        char a_char = a_length - 1 - i >= 0 ? a[a_length - 1 - i] : '0';
        char b_char = b_length - 1 - i >= 0 ? b[b_length - 1 - i] : '0';
        if (a_char == b_char) {
            if (carry)
                result[result_length - i] = '1';
            else
                result[result_length - i] = '0';
            if (a_char == '1')
                carry = 1;
            else
                carry = 0;
        } else if (carry == 0) {
            result[result_length - i] = '1';
            carry = 0;
        } else {
            result[result_length - i] = '0';
            carry = 1;
        }
    }

    if (result[0] == '1')
        return result;
    else
        return result + 1;
}
// @lc code=end

// int main()
// {
//     char a[3] = "11";
//     char b[2] = "1";
//     printf("%s\n", addBinary((a, b)));

//     return 0;
// }

// Accepted
// 294/294 cases passed (0 ms)
// Your runtime beats 100 % of c submissions
// Your memory usage beats 52.72 % of c submissions (5.8 MB)