/*********************
  LeetCode Binary Tree Postorder Traversal

  Given a binary tree, return the postorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
  return [3,2,1].

  Note: Recursive solution is trivial, could you do it iteratively?

  discussion:

  use stack for depth-first traversal. the order for post-order traverse is
  right->left->root. the process is firstly push the left child all the way in
  to stack, then handle the right child. if the the right child has left child,
  then need to restart to handle the left subtree. until find the deepest leaf,
  go back to stack elements.

  time complexity O(n), space complexity O(n)
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode *current = root, *prev = nullptr;
        stack<const TreeNode *> s;
        
        do {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            prev = nullptr;
            while (!s.empty()) {
                current = s.top();
                s.pop();
                if (current->right == prev) { // the right child is either nullptr, or has been treated.
                    result.push_back(current->val);
                    prev = current;
                }
                else {  // still has untreated right child, push it back to stack.
                    s.push(current);
                    current = current->right;
                    break;
                }
            }
        } while (!s.empty());
        return result;
    }
};
