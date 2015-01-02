/****************
  LeetCode Valid Sudoku 

  Determine if a Sudoku is valid, according to:
  http://sudoku.com.au/TheRules.aspx

  The Sudoku board could be partially filled, where empty cells are 
  filled with the character '.'.

  Note:
  A valid Sudoku board (partially filled) is not necessarily solvable. 
  Only the filled cells need to be validated.

  Discussion:
  Use a bool array to record if the number 1 -- 9 has been used in a row,
  a column, and a 3*3 square.

  time complexity O(n^2), space complexity O(1)
*************/
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool record[9];
        
        for (int i=0; i<9; ++i) {
            fill(record, record+9, false);
            for (int j=0; j<9; ++j) // check row
                if (!check(board[i][j], record)) return false;
            
            fill(record, record+9, false);
            for (int j=0; j<9; ++j)  // check column
                if (!check(board[j][i], record)) return false;
        }
        
        for (int r=0; r<3; ++r) {
            for (int c=0; c<3; ++c) {
                fill(record, record+9, false);
                // check square
                for (int i=3*r; i<3*r+3; ++i) {
                    for (int j=3*c; j<3*c+3; ++j) {
                        if (!check(board[i][j], record)) return false;
                    }
                }
            }
        }
        return true;
    }
private:
    bool check(const char ch, bool * record) {
        if (ch == '.') return true;
        if (record[ch - '1']) return false;     // number ch has been used
        record[ch - '1'] = true;
        return true;
    }
};
