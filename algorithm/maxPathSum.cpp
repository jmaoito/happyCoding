/******************
  LeetCode Binary Tree Maximum Path Sum
  
  Given a binary tree, find the maximum path sum.

  The path may start and end at any node in the tree.

  For example:
  Given the below binary tree,

       1
      / \
     2   3
  Return 6.

  Discussion:

  The idea is based on the solution of max sum of a sequence array. 
  Here is the explaination of the code:

  Have a DFS recursive method which traverse the binary tree, it also return 
  the max possible sum of left branch and right branch saperately. for 
  example, For node A, when it's left and right node recusive call returned, 
  we will know the max possible sum of left branch, right branch.

  Compare the sequence sum and record the max history. For node A, check 
  whether left branch + this node + right branch is the maximum, check whether 
  left branch + this node is max， check whether right branch + this node 
  is max.

  When recursive method return, we should only return the max sum of one 
  path - either the left branch + this node, or the right branch + this node. 
  So that this is still a single path and can be used to link by node A's 
  parent node.

  time complexity O(n), space complexity O(logn)
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
    int maxPathSum(TreeNode *root) {
        if (root == NULL) return 0;
        maxsum = INT_MIN;
        dfsGetSum(root);
        return maxsum;
    }
private:
    int maxsum;
    int dfsGetSum(const TreeNode *root) {
        if (root == NULL) return 0;
        
        int leftsum = dfsGetSum(root->left);
        int rightsum =dfsGetSum(root->right);
        
        int sum = root->val;
        if (leftsum > 0) sum += leftsum;
        if (rightsum > 0) sum += rightsum;
        
        maxsum = max(maxsum, sum);
        
        return max(leftsum, rightsum) > 0 ? max(leftsum, rightsum) + root->val : root->val;
    }
};
