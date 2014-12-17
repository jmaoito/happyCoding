/***************
  minimumTotal(vector<vector<int>> &triangle)

  Given a triangle, find the minimum path sum from top to bottom. 
  Each step you may move to adjacent numbers on the row below.

  For example, given the following triangle
  [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
  ]
  The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

  Note:
  Bonus point if you are able to do this using only O(n) extra space, 
  where n is the total number of rows in the triangle.

  Discussion:
  Use Dynamic Programming (DP) method, the functional equation (Bellman equ.)
  F(i,j) = min{f(i,j+1),f(i+1,j+1)} + f(i,j)

  time complexity O(n^2), space complexity O(1)
****************/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        size_t n = triangle.size();
        for (int i=n-2; i>=0; --i) {
            for (int j=0; j<i+1; ++j) {
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};
