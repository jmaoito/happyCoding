/**************
  LeetCode Sudoku Solver 

  Write a program to solve a Sudoku puzzle by filling the empty cells.

  Empty cells are indicated by the character '.'.

  You may assume that there will be only one unique solution.

  Discussion:
  Use Depth First Search algorithm (DFS)

  time complexity O(9^4), space complexity O(1)
*****************/
class Solution {
public:
    bool solveSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (int k = 0; k < 9; ++k) {
                        board[i][j] = '1' + k;
                        if (isValid(board, i, j) && solveSudoku(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        return true;
    }
private:
    bool isValid(vector<vector<char> > &board, int x, int y) {
        for (int i=0; i<9; i++) {  // check y colume
            if (i != x && board[i][y] == board[x][y]) return false;
        }
        for (int j=0; j<9; j++) {  // check x row
            if (j != y && board[x][j] == board[x][y]) return false;
        }
        for (int i=3*(x/3); i<3*(x/3+1); i++) {  // check squar
            for (int j=3*(y/3); j<3*(y/3+1); j++) {
                if ((i!=x || j!=y) && board[i][j] == board[x][y]) return false;
            }
        }
        return true;
    }
};
