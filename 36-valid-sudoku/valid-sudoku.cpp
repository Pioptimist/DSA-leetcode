class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col) {
        char ch = board[row][col];

        // Check row
        for (int j = 0; j < 9; j++) {
            if (j != col && board[row][j] == ch) return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (i != row && board[i][col] == ch) return false;
        }

        // Check 3x3 subgrid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if ((i != row || j != col) && board[i][j] == ch) return false;
            }
        }

        return true; // If all checks pass
    }
    bool validate(vector<vector<char>>& board, int row, int col) {
        if (row == 9) return true; // Base case: If we finish all rows, board is valid
        if (col == 9) return validate(board, row + 1, 0); // Move to next row when column ends

        if (board[row][col] != '.') {
            if (!isValid(board, row, col)) return false; // If cell has a value, check validity
        }

        return validate(board, row, col + 1); // Move to next column
    }

    
    bool isValidSudoku(vector<vector<char>>& board) {
        return validate(board, 0, 0);
    }


   
};
