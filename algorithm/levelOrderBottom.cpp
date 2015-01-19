/**************************
  LeetCode Binary Tree Level Order Traversal II

  Given a binary tree, return the bottom-up level order traversal of its 
  nodes' values. (ie, from left to right, level by level from leaf to root).

  For example:
  Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
  return its bottom-up level order traversal as:
  [
    [15,7],
    [9,20],
    [3]
  ]

  Tags: Tree, Breadth-first Search

  Discussion:

  Uses two queues to do breadth first travesal. one is for current level, the other is for reocrding of the next level. the final result needs to be reversed.

  time complexity O(n), space complexity O(1)
*************************/
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> result;
        if(root == nullptr) return result;
        
        vector<int> level;
        TreeNode *current = root;
        queue<TreeNode *> currentLevel, nextLevel;
        
        currentLevel.push(current);
        while (!currentLevel.empty()) {
            while (!currentLevel.empty()) {
                current = currentLevel.front();
                currentLevel.pop();
                level.push_back(current->val);
                if (current->left != nullptr) nextLevel.push(current->left);
                if (current->right != nullptr) nextLevel.push(current->right);
            }
            result.push_back(level);
            level.clear();
            swap(currentLevel, nextLevel);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
