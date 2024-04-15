/*
 * @lc app=leetcode id=155 lang=c
 *
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (49.88%)
 * Likes:    7642
 * Dislikes: 602
 * Total Accepted:    938.5K
 * Total Submissions: 1.9M
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 *
 * Implement the MinStack class:
 *
 *
 * MinStack() initializes the stack object.
 * void push(int val) pushes the element val onto the stack.
 * void pop() removes the element on the top of the stack.
 * int top() gets the top element of the stack.
 * int getMin() retrieves the minimum element in the stack.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *
 * Output
 * [null,null,null,null,-3,null,0,-2]
 *
 * Explanation
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin(); // return -3
 * minStack.pop();
 * minStack.top();    // return 0
 * minStack.getMin(); // return -2
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * Methods pop, top and getMin operations will always be called on non-empty
 * stacks.
 * At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
 *
 *
 */

// @lc code=start
#define SIZE __INT16_MAX__

typedef struct
{
    int *array;
    int index;
} MinStack;

MinStack *minStackCreate()
{
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->array = (int *)malloc(sizeof(int) * SIZE);
    obj->index = -1;

    return obj;
}

void minStackPush(MinStack *obj, int val)
{
    obj->index++;
    obj->array[obj->index] = val;
}

void minStackPop(MinStack *obj)
{
    if (obj->index > -1)
        obj->index--;
}

int minStackTop(MinStack *obj)
{
    return obj->array[obj->index];
}

int minStackGetMin(MinStack *obj)
{
    int i;
    int min = __INT32_MAX__;
    for (i = 0; i <= obj->index; i++)
    {
        if (obj->array[i] < min)
            min = obj->array[i];
    }
    return min;
}

void minStackFree(MinStack *obj)
{
    free(obj->array);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
// @lc code=end

// Accepted
// 31/31 cases passed (128 ms)
// Your runtime beats 31.95 % of c submissions
// Your memory usage beats 49.88 % of c submissions (13.5 MB)