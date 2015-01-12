/*************************
  LeetCode Unique Binary Search Trees II 

  Given n, generate all structurally unique BST's (binary search trees) that 
  store values 1...n.

  For example,
  Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

  Discussion:
  Dynamic Programming f(i) = sum(f(k-1)*f(i-k))

  1..n is the in-order traversal for any BST with nodes 1 to n. 
  So if I pick i-th node as my root, the left subtree will contain elements 
  1 to (i-1), and the right subtree will contain elements (i+1) to n. use 
  recursive calls to get back all possible trees for left and right subtrees 
  and combine them in all possible ways with the root.

****************************/
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
    vector<TreeNode *> generateTrees(int n) {
        return generateTree(1, n);
    }
private:
    vector<TreeNode *> generateTree(int start, int end) {
        vector<TreeNode *> result;
        if (start > end) {
            result.push_back(nullptr);
            return result;
        }
        
        for (int k=start; k<=end; ++k) {
            vector<TreeNode *> left = generateTree(start, k-1);
            vector<TreeNode *> right = generateTree(k+1, end);
            
            for (int i=0; i<left.size(); ++i) {
                for (int j=0; j<right.size(); ++j) {
                    TreeNode * node = new TreeNode(k);
                    node->left = left[i];
                    node->right = right[j];
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};
