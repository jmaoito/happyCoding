/***********************
  LeetCode Unique Paths

  A robot is located at the top-left corner of a m x n grid (marked 'Start' 
  in the diagram below).

  The robot can only move either down or right at any point in time. The robot
  is trying to reach the bottom-right corner of the grid (marked 'Finish' in 
  the diagram below).

  How many possible unique paths are there?

  Note: m and n will be at most 100.

  Discussion:
  
  it can be resolved by Depth First Searching combined with a cache memo.

  time complexity O(n^2), space complexity O(n^2)
***********************/
class Solution {
public:
    int uniquePaths(int m, int n) {
        records = vector<vector<int>> (m+1, vector<int> (n+1, 0));
        return dfsPath(m, n);
    }
private:
    vector<vector<int>> records;
    int dfsPath(int x, int y) {
        if (x < 1 || y < 1) return 0;       // illegal data, return 0
        if (x == 1 && y == 1) return 1;     // converged, return 1
        
        return update(x-1, y) + update(x, y-1);
    }
    int update(int x, int y) {
        if (records[x][y] > 0) return records[x][y];
        return records[x][y] = dfsPath(x, y);
    }
};


/*****************
  Dynamic Programming method

  Assume f(i,j) representing number of paths from start (1, 1) to end (i, j).
  the state transition function is f(i,j) = f(i-1,j) + f(i,j-1).

  time complexity O(n^2), space complexity O(n)
*******************/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> f(n, 0);
        
        f[0] = 1;
        for (int i=0; i<m; ++i) {
            for (int j=1; j<n; ++j) {
                f[j] = f[j-1] + f[j];
                /* f[i][j] = f[i][j-1] + f[i-1][j] */
            }
        }
        return f[n-1];
    }
};
