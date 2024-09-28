/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 *
 * https://leetcode.com/problems/design-circular-deque/description/
 *
 * algorithms
 * Medium (57.23%)
 * Likes:    1345
 * Dislikes: 89
 * Total Accepted:    103K
 * Total Submissions: 170.2K
 * Testcase Example:  '["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]\n' +
  '[[3],[1],[2],[3],[4],[],[],[],[4],[]]'
 *
 * Design your implementation of the circular double-ended queue (deque).
 *
 * Implement the MyCircularDeque class:
 *
 *
 * MyCircularDeque(int k) Initializes the deque with a maximum size of k.
 * boolean insertFront() Adds an item at the front of Deque. Returns true if
 * the operation is successful, or false otherwise.
 * boolean insertLast() Adds an item at the rear of Deque. Returns true if the
 * operation is successful, or false otherwise.
 * boolean deleteFront() Deletes an item from the front of Deque. Returns true
 * if the operation is successful, or false otherwise.
 * boolean deleteLast() Deletes an item from the rear of Deque. Returns true if
 * the operation is successful, or false otherwise.
 * int getFront() Returns the front item from the Deque. Returns -1 if the
 * deque is empty.
 * int getRear() Returns the last item from Deque. Returns -1 if the deque is
 * empty.
 * boolean isEmpty() Returns true if the deque is empty, or false
 * otherwise.
 * boolean isFull() Returns true if the deque is full, or false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MyCircularDeque", "insertLast", "insertLast", "insertFront",
 * "insertFront", "getRear", "isFull", "deleteLast", "insertFront", "getFront"]
 * [[3], [1], [2], [3], [4], [], [], [], [4], []]
 * Output
 * [null, true, true, true, false, 2, true, true, true, 4]
 *
 * Explanation
 * MyCircularDeque myCircularDeque = new MyCircularDeque(3);
 * myCircularDeque.insertLast(1);  // return True
 * myCircularDeque.insertLast(2);  // return True
 * myCircularDeque.insertFront(3); // return True
 * myCircularDeque.insertFront(4); // return False, the queue is full.
 * myCircularDeque.getRear();      // return 2
 * myCircularDeque.isFull();       // return True
 * myCircularDeque.deleteLast();   // return True
 * myCircularDeque.insertFront(4); // return True
 * myCircularDeque.getFront();     // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= k <= 1000
 * 0 <= value <= 1000
 * At most 2000 calls will be made to insertFront, insertLast, deleteFront,
 * deleteLast, getFront, getRear, isEmpty, isFull.
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class MyCircularDeque
{
private:
    size_t capacity;
    size_t size;
    size_t head, tail;
    vector<int> dq;

public:
    MyCircularDeque(int k)
    {
        this->capacity = (size_t)k;
        this->dq = vector<int>(this->capacity);
        this->size = 0;
        this->head = this->capacity - 1;
        this->tail = 0;
    }

    bool insertFront(int value)
    {
        if (this->isFull())
            return false;
        else
        {
            this->dq[this->head] = value;
            this->head = (this->head + this->capacity - 1) % capacity;
            this->size++;
        }
        return true;
    }

    bool insertLast(int value)
    {
        if (this->isFull())
            return false;
        else
        {
            this->dq[this->tail] = value;
            this->tail = (this->tail + 1) % capacity;
            this->size++;
        }
        return true;
    }

    bool deleteFront()
    {
        if (this->isEmpty())
            return false;
        else
        {
            this->head = (this->head + 1) % capacity;
            this->size--;
        }
        return true;
    }

    bool deleteLast()
    {
        if (this->isEmpty())
            return false;
        else
        {
            this->tail = (this->tail + capacity - 1) % capacity;
            this->size--;
        }
        return true;
    }

    int getFront()
    {
        if (this->isEmpty())
            return -1;
        return this->dq[(this->head + 1) % capacity];
    }

    int getRear()
    {
        if (this->isEmpty())
            return -1;
        return this->dq[(this->tail + capacity - 1) % capacity];
    }

    bool isEmpty()
    {
        return this->size == 0;
    }

    bool isFull()
    {
        return this->size == this->capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end
int main(int argc, char **argv)
{
    MyCircularDeque *sol_1 = new MyCircularDeque(3);
    bool param_1 = sol_1->insertLast(1);
    bool param_2 = sol_1->insertLast(2);
    bool param_3 = sol_1->insertFront(3);
    bool param_4 = sol_1->insertFront(4);
    int param_5 = sol_1->getRear();
    bool param_6 = sol_1->deleteLast();
    bool param_7 = sol_1->insertFront(4);
    bool param_8 = sol_1->getFront();
    delete (sol_1);

    return 0;
}
// Accepted
// 51/51 cases passed (20 ms)
// Your runtime beats 64.1 % of cpp submissions
// Your memory usage beats 48.19 % of cpp submissions (22.7 MB)