/*
 * @lc app=leetcode id=150 lang=c
 *
 * [150] Evaluate Reverse Polish Notation
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// @lc code=start
#define STACK_SIZE 10000
bool is_operator(char c) { return (c == '+') || (c == '-') || (c == '*') || (c == '/'); }

int evalRPN(char** tokens, int tokensSize)
{
    int result     = 0;
    int stack_idx  = 0;
    int stack_size = STACK_SIZE;
    int stack[STACK_SIZE];

    for (int i = 0; i < tokensSize; i++)
    {
        int value = 0;
        value     = atoi(tokens[i]);

        if (strlen(tokens[i]) == 1 && is_operator(tokens[i][0]))
        {
            stack_idx--;
            int op2 = stack[stack_idx];
            stack_idx--;
            int op1 = stack[stack_idx];

            switch (tokens[i][0])
            {
                case '+':
                    stack[stack_idx] = op1 + op2;
                    break;
                case '-':
                    stack[stack_idx] = op1 - op2;
                    break;
                case '*':
                    stack[stack_idx] = op1 * op2;
                    break;
                case '/':
                    stack[stack_idx] = op1 / op2;
                    break;
            }
            stack_idx++;
        }
        else
        {
            stack[stack_idx] = value;
            stack_idx++;
        }
    }
    result = (int) stack[0];
    return result;
}
// @lc code=end
#define SIZE_1 5
#define SIZE_2 5
#define SIZE_3 13
#define INPUT_SIZE 10000
#define MAX_ASCII_INT 12
int main(int argc, char** argv)
{
    char** input = (char**) malloc(sizeof(char*) * INPUT_SIZE);
    for (int i = 0; i < INPUT_SIZE; i++)
    {
        input[i] = (char*) malloc(sizeof(char) * MAX_ASCII_INT);
        // memset(input[i], '\0', sizeof(char) * MAX_ASCII_INT);
    }
    // Test 1
    int  size_1      = SIZE_1;
    char input_1_0[] = "2";
    strcpy(input[0], input_1_0);
    char input_1_1[] = "1";
    strcpy(input[1], input_1_1);
    char input_1_2[] = "+";
    strcpy(input[2], input_1_2);
    char input_1_3[] = "-13";
    strcpy(input[3], input_1_3);
    char input_1_4[] = "*";
    strcpy(input[4], input_1_4);
    printf("%d\n", evalRPN((char**) input, size_1));

    for (int i = 0; i < INPUT_SIZE; i++)
    {
        free(input[i]);
    }
    free(input);
    return 0;
}

// Accepted
// 21/21 cases passed (8 ms)
// Your runtime beats 53.96 % of c submissions
// Your memory usage beats 95.73 % of c submissions (7.3 MB)