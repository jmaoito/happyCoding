/************************
  LeetCode Unique Binary Search Trees

  Given n, how many structurally unique BST's (binary search trees) that store 
  values 1...n?

  For example,
  Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

  Discussion:
  Dynamic Programming f(i) = sum(f(k-1)*f(i-k))

  if pick k as the root, the left subtree is composed of [1,k-1], the right 
  subtree is composed of [k+1, n].

  assume f(i) is the number of unique BST, then
  if i=0, the tree will be empty f(0) = 1;
  if i=1, there is only one node f(1) = 1;
  if i=2, there are two possibilties f(2) = f(0) * f(1) + f(1) * f(0)
  if i=3, there are  five possibilities f(3) = f(0)*f(2) + f(1)*f(1) + f(2)*f(0)
  if i=n, f(n) = sum(f(k-1)*f(n-k)), k=1 to n

  time complexity O(n^2), space complexity O(n)
************************/
class Solution {
public:
    int numTrees(int n) {
        vector<int> f(n+1, 0);
        f[0] = 1;
        f[1] = 1;
        for (int i=2; i<=n; ++i) {
            for (int k=1; k<=n; ++k) {
                f[i] += f[k-1]*f[i-k];
            }
        }
        return f[n];
    }
};
