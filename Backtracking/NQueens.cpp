// Backtracking: N-Queens Problem
#include <vector>
using namespace std;

bool isSafe(int row, int col, vector<string>& board, int n) {
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') return false;
    }
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') return false;
    }
    for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') return false;
    }
    return true;
}

void solveNQueens(int row, int n, vector<string>& board, vector<vector<string>>& res) {
    if (row == n) {
        res.push_back(board);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, board, n)) {
            board[row][col] = 'Q';
            solveNQueens(row + 1, n, board, res);
            board[row][col] = '.';
        }
    }
}
