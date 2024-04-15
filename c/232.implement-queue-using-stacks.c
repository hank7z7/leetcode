/*
 * @lc app=leetcode id=232 lang=c
 *
 * [232] Implement Queue using Stacks
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
// @lc code=start
#define ARR_SIZE 100
typedef struct
{
    int* arr;
    int  front;
    int  end;
    int  count;
} MyQueue;


MyQueue* myQueueCreate()
{
    MyQueue* obj = (MyQueue*) malloc(sizeof(MyQueue));
    obj->arr     = (int*) malloc(sizeof(int) * ARR_SIZE);
    memset(obj->arr, 0, sizeof(int) * ARR_SIZE);
    obj->front = 0;
    obj->end   = 0;
    obj->count = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x)
{
    obj->arr[obj->end] = x;
    obj->count++;
    obj->end = (obj->end + 1) % ARR_SIZE;
}

bool myQueueEmpty(MyQueue* obj) { return (obj->count == 0); }

int myQueuePop(MyQueue* obj)
{
    if (!(obj->count == 0))
    {
        int result = obj->arr[obj->front];
        obj->count--;
        obj->front = (obj->front + 1) % ARR_SIZE;
        return result;
    }
    else
    {
        return 0;
    }
}

int myQueuePeek(MyQueue* obj)
{
    if (!(obj->count == 0))
        return obj->arr[obj->front];
    else
        return 0;
}

void myQueueFree(MyQueue* obj)
{
    free(obj->arr);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/
// @lc code=end
int main(int argc, char** argv)
{
    MyQueue* obj = myQueueCreate();
    int      x   = 1;
    myQueuePush(obj, x);

    int param_2 = myQueuePop(obj);
    printf("param_2: %d\n", param_2);
    int param_3 = myQueuePeek(obj);
    printf("param_3: %d\n", param_3);
    bool param_4 = myQueueEmpty(obj);
    printf("param_4: %d\n", param_4);

    myQueueFree(obj);

    return 0;
}
// Accepted
// 22/22 cases passed (3 ms)
// Your runtime beats 40.26 % of c submissions
// Your memory usage beats 97.66 % of c submissions (5.6 MB)