class Solution {
    int row[9][10], col[9][10], cube[3][3][10];
    // row array is of size 9*10 because there are in total of 9 rows and for each row position there are 10 possible numbers 
    // similarly for col there are 9 columns and for each there are 10 possiblilities 
    //  now there are 9 block in total and in each block has 10 positions so 
    // above method is used for contant time checking when checking in terms of safety 
    
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(cube, 0, sizeof(cube));
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') {
                    row[r][board[r][c] - '0'] = 1;
                    col[c][board[r][c] - '0'] = 1;
                    cube[r/3][c/3][board[r][c] - '0'] = 1;
                } 
            }
        }
        dfs(0, 0, board);
    }
    
    bool dfs(int i, int j, vector<vector<char>>& board) {
        if (i == 9) return true;// means all rows have been assigned 
        if (j == 9) return dfs(i + 1, 0, board);// means this row has been assigned now time to change the row 
        if (board[i][j] != '.') return dfs(i, j + 1, board);// for unassigned pos only we are concerned 
        
        for (char c = '1'; c <= '9'; c++) {
            if (feasible(i, j, c)) {// checking safety
                board[i][j] = c;
                row[i][c - '0'] = 1; col[j][c - '0'] = 1; cube[i/3][j/3][c - '0'] = 1;// assigned
                if (dfs(i, j + 1, board)) return true;// if solved return from here
                row[i][c - '0'] = 0; col[j][c - '0'] = 0; cube[i/3][j/3][c - '0'] = 0;// backtracking 
                board[i][j] = '.';// backtracking
            }
        }
        return false;
    }
    
    bool feasible(int curRow, int curCol, char c) {
        // below we are doing constant time to check that current position is safe or not 
        // very good approach
        if (row[curRow][c - '0'] == 1) return false;
        if (col[curCol][c - '0'] == 1) return false;
        if (cube[curRow/3][curCol/3][c - '0'] == 1) return false;
        return true;
    }
};
