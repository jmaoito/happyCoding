/*************************
  LeetCode Binary Tree Inorder Traversal

  Given a binary tree, return the inorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
  return [1,3,2].

  Note: Recursive solution is trivial, could you do it iteratively?

  Discussion:
  use stack.

  time complexity O(n), space Complexity O(n)
********************/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode * current = root;
        stack<const TreeNode *> stk;
        
        while (!stk.empty() || current != nullptr) {
            if (current != nullptr) {
                stk.push(current);
                current = current->left;
            } 
            else {
                current = stk.top();
                stk.pop();
                result.push_back(current->val);
                current = current->right;
            }
        }
        return result;
    }
};
