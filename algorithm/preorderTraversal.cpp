/************
  LeetCode Binary Tree Preorder Traversal

  Given a binary tree, return the preorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
  return [1,2,3].

  Note: Recursive solution is trivial, could you do it iteratively?

  Discussion:
  Binary tree depth-first traversal uses stack to store the intermidiate nodes.
  preorder traverse is in the order of root->left->right;
  in the stack, the order is root->right->left.

  time complexity O(n), space complexity O(n)
**************/
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        const TreeNode *current = root;
        stack<const TreeNode *> s;
        if (current != nullptr) s.push(current);
        while (!s.empty()) {
            current = s.top();
            s.pop();
            result.push_back(current->val);
            if (current->right)
                s.push(current->right);
            if (current->left != nullptr)
                s.push(current->left);
        }
        return result;
    }
};
