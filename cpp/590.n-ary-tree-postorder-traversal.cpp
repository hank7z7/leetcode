/*
 * @lc app=leetcode id=590 lang=cpp
 *
 * [590] N-ary Tree Postorder Traversal
 *
 * https://leetcode.com/problems/n-ary-tree-postorder-traversal/description/
 *
 * algorithms
 * Easy (78.07%)
 * Likes:    2395
 * Dislikes: 103
 * Total Accepted:    278.1K
 * Total Submissions: 354.4K
 * Testcase Example:  '[1,null,3,2,4,null,5,6]'
 *
 * Given the root of an n-ary tree, return the postorder traversal of its
 * nodes' values.
 * 
 * Nary-Tree input serialization is represented in their level order traversal.
 * Each group of children is separated by the null value (See examples)
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,3,2,4,null,5,6]
 * Output: [5,6,3,2,4,1]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root =
 * [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
 * Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 10^4].
 * 0 <= Node.val <= 10^4
 * The height of the n-ary tree is less than or equal to 1000.
 * 
 * 
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
 */
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void traverse(vector<int>& arr, Node* root)
    {
        if(root)
        {
            for(auto child : root->children)
                traverse(arr, child);
            arr.push_back(root->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        // Recursion
        // traverse(res, root);
        
        // Iterative
        stack<Node*> st;
        if(root)
            st.push(root);
        while(!st.empty())
        {
            Node* top_node = st.top();
            st.pop();
            for(auto child : top_node->children)
                st.push(child);
            res.push_back(top_node->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end
int main(int argc, char** argv)
{
    Solution sol;
    // Test_1
    Node test_1_node_5 = Node(6);
    Node test_1_node_4 = Node(5);
    Node test_1_node_3 = Node(4);
    Node test_1_node_2 = Node(2);
    Node test_1_node_1 = Node(3, vector<Node*>{&test_1_node_4, &test_1_node_5});
    Node test_1_node_0 = Node(1, vector<Node*>{&test_1_node_1, &test_1_node_2, &test_1_node_3});
    vector<int> res_1 = sol.postorder(&test_1_node_0);
    for(auto i : res_1)
        cout << i << " ";
    cout << endl;
    assert((res_1 == vector<int>{5, 6, 3, 2, 4, 1}));
    return 0;
}
// Accepted
// 38/38 cases passed (10 ms)
// Your runtime beats 84.88 % of cpp submissions
// Your memory usage beats 70.21 % of cpp submissions (15.2 MB)