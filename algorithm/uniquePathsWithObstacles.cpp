/**********************
  LeetCode Unique Paths II 

  Follow up for "Unique Paths":

  Now consider if some obstacles are added to the grids. How many unique paths
  would there be?

  An obstacle and empty space is marked as 1 and 0 respectively in the grid.

  For example,
  There is one obstacle in the middle of a 3x3 grid as illustrated below.

  [
    [0,0,0],
    [0,1,0],
    [0,0,0]
  ]
  The total number of unique paths is 2.

  Note: m and n will be at most 100.

  Discussion:

  Dynamic Programming.
  need to pay attention to the first column. if there are obstacles in the 
  first column, the rest path will be 0.

  time complexity O(n^2), space complexity O(n)
*********************/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;     // if the start or end is obstacle
        
        vector<int> f(n, 0);
        
        f[0] = obstacleGrid[0][0] ? 0 : 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                f[j] = obstacleGrid[i][j] ? 0 : (f[j-1] + f[j]);
            }
        }
        return f[n-1];
    }
};
