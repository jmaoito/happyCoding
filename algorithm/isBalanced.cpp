/****************
  LeetCode Balanced Binary Tree

  Given a binary tree, determine if it is height-balanced.

  For this problem, a height-balanced binary tree is defined as a binary
  tree in which the depth of the two subtrees of every node never differ 
  by more than 1.

  Discussion:
  recursively find the height of the two substrees of every node.

  time complexity O(n), space complexify O(logn)
*********************/
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
    bool isBalanced(TreeNode *root) {
        return balancedHeight(root)>=0;
        
    }
private:
    int balancedHeight(TreeNode *root) {
        if (root == NULL) return 0;  // terminate condition
        
        int leftHeight = balancedHeight(root->left);
        int rightHeight = balancedHeight(root->right);
        
        if (leftHeight < 0 || rightHeight < 0 || abs(leftHeight - rightHeight) > 1)
            return -1;
            
        return max(leftHeight, rightHeight) + 1;
    }
};
