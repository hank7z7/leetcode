/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 *
 * https://leetcode.com/problems/product-of-the-last-k-numbers/description/
 *
 * algorithms
 * Medium (52.42%)
 * Likes:    2038
 * Dislikes: 100
 * Total Accepted:    227.5K
 * Total Submissions: 364.4K
 * Testcase Example:  '["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]\n' +
  '[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]'
 *
 * Design an algorithm that accepts a stream of integers and retrieves the
 * product of the last k integers of the stream.
 *
 * Implement the ProductOfNumbers class:
 *
 *
 * ProductOfNumbers() Initializes the test_1ect with an empty stream.
 * void add(int num) Appends the integer num to the stream.
 * int getProduct(int k) Returns the product of the last k numbers in the
 * current list. You can assume that always the current list has at least k
 * numbers.
 *
 *
 * The test cases are generated so that, at any time, the product of any
 * contiguous sequence of numbers will fit into a single 32-bit integer without
 * overflowing.
 *
 *
 * Example:
 *
 *
 * Input
 *
 * ["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
 * [[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
 *
 * Output
 * [null,null,null,null,null,null,20,40,0,null,32]
 *
 * Explanation
 * ProductOfNumbers productOfNumbers = new ProductOfNumbers();
 * productOfNumbers.add(3);        // [3]
 * productOfNumbers.add(0);        // [3,0]
 * productOfNumbers.add(2);        // [3,0,2]
 * productOfNumbers.add(5);        // [3,0,2,5]
 * productOfNumbers.add(4);        // [3,0,2,5,4]
 * productOfNumbers.getProduct(2); // return 20. The product of the last 2
 * numbers is 5 * 4 = 20
 * productOfNumbers.getProduct(3); // return 40. The product of the last 3
 * numbers is 2 * 5 * 4 = 40
 * productOfNumbers.getProduct(4); // return 0. The product of the last 4
 * numbers is 0 * 2 * 5 * 4 = 0
 * productOfNumbers.add(8);        // [3,0,2,5,4,8]
 * productOfNumbers.getProduct(2); // return 32. The product of the last 2
 * numbers is 4 * 8 = 32
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= num <= 100
 * 1 <= k <= 4 * 10^4
 * At most 4 * 10^4 calls will be made to add and getProduct.
 * The product of the stream at any point in time will fit in a 32-bit
 * integer.
 *
 *
 *
 * Follow-up: Can you implement both GetProduct and Add to work in O(1) time
 * complexity instead of O(k) time complexity?
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class ProductOfNumbers
{
private:
    vector<int> nums;
    // vector<int> prefix_product;

public:
    ProductOfNumbers()
    {
        nums = vector<int>{};
        // prefix_product = vector<int>{};
    }

    void add(int num)
    {
        nums.push_back(num);
        // if(prefix_product.size() == 0)
        //     prefix_product.push_back(num);
        // else
        //     prefix_product.push_back(prefix_product.back() * num);
        // cout << prefix_product.back() << endl;
    }

    int getProduct(int k)
    {
        const int n = (int)nums.size();
        int res = 1;
        for (int i = 0; i < k; i++)
            res *= nums[n - 1 - i];
        return res;
        // return prefix_product.back() / (prefix_product.back() - k);
    }
};

/**
 * Your ProductOfNumbers test_1ect will be instantiated and called as such:
 * ProductOfNumbers* test_1 = new ProductOfNumbers();
 * test_1->add(num);
 * int param_2 = test_1->getProduct(k);
 */
// @lc code=end
int main(int argc, char **argv)
{
    // Test_1
    ProductOfNumbers *test_1 = new ProductOfNumbers();
    test_1->add(3);                        // [3]
    test_1->add(0);                        // [3,0]
    test_1->add(2);                        // [3,0,2]
    test_1->add(5);                        // [3,0,2,5]
    test_1->add(4);                        // [3,0,2,5,4]
    cout << test_1->getProduct(2) << endl; // return 20. The product of the last 2 numbers is 5 * 4 = 20
    assert(test_1->getProduct(2) == 20);
    cout << test_1->getProduct(3) << endl; // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
    assert(test_1->getProduct(3) == 40);
    cout << test_1->getProduct(4) << endl; // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
    assert(test_1->getProduct(4) == 0);
    test_1->add(8);                        // [3,0,2,5,4,8]
    cout << test_1->getProduct(2) << endl; // return 32. The product of the last 2 numbers is 4 * 8 = 32
    assert(test_1->getProduct(2) == 32);
    delete (test_1);

    return 0;
}
