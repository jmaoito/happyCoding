/**********************
  LeetCode  Set Matrix Zeroes

  Given a m x n matrix, if an element is 0, 
  set its entire row and column to 0. Do it in place.

  Time complexcity O(m*n), Space Complexity O(m+n)

  Follow up:
  Did you use extra space?
  A straight forward solution using O(mn) space is probably a bad idea.
  A simple improvement uses O(m + n) space, but still not the best solution.
  Could you devise a constant space solution? 
  ** use matrix[0][j] and matrix[i][0] as the flag row and colume.

***********************/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool> row(m, false);   // flag of row
        vector<bool> col(n, false);   // flag of col
        
        for (int i=0; i<m; ++i){
            for(int j=0; j<n; ++j) {
                if (matrix[i][j] == 0)
                    row[i] = col[j] = true;
            }
        }
        
        for (int i=0; i<m; ++i) {
            if(row[i])
	      fill(&matrix[i][0], &matrix[i][0]+n, 0);  // assign the entire row to be zero
        }
        
        for (int j=0; j<n; ++j) {
            if(col[j]) {
                for (int i=0; i<m; ++i)
                    matrix[i][j] = 0;
            }
        }
    }
};
