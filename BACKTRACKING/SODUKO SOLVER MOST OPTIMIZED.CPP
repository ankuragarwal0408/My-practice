class Solution {
    int row[9][10], col[9][10], cube[3][3][10];
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
        if (i == 9) return true;
        if (j == 9) return dfs(i + 1, 0, board);
        if (board[i][j] != '.') return dfs(i, j + 1, board);
        
        for (char c = '1'; c <= '9'; c++) {
            if (feasible(i, j, c)) {
                board[i][j] = c;
                row[i][c - '0'] = 1; col[j][c - '0'] = 1; cube[i/3][j/3][c - '0'] = 1;
                if (dfs(i, j + 1, board)) return true;
                row[i][c - '0'] = 0; col[j][c - '0'] = 0; cube[i/3][j/3][c - '0'] = 0;
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    bool feasible(int curRow, int curCol, char c) {
        if (row[curRow][c - '0'] == 1) return false;
        if (col[curCol][c - '0'] == 1) return false;
        if (cube[curRow/3][curCol/3][c - '0'] == 1) return false;
        return true;
    }
};
