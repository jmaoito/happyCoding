/**************
  leetCode Rotate Image

  You are given an n x n 2D matrix representing an image.

  Rotate the image by 90 degrees (clockwise).

  Follow up:
  Could you do this in-place?

  Discussion:
  1. swap along the horizontal middle line. or swap along the vise diagonal
  2. swap along the main diagonal. or swap along the middle line

  time complexity O(n^2), space comlexity O(1)
*******************/
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        const int n = matrix.size();
        //swap along the horizontal middle line
        for (int i=0; i<n/2; i++) {
            for (int j=0; j<n; j++)
                swap(matrix[i][j], matrix[n-1-i][j]);
        }
        // swap along the main diagonal 
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};
