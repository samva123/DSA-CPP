#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> upperLeftDiagnolCheck;
    unordered_map<int,bool> bottomLeftDiagnolCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string output = "";
            for (int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, vector<vector<char>> &board, int n) {
        if (rowCheck[row]) return false;
        if (upperLeftDiagnolCheck[n - 1 + col - row]) return false;
        if (bottomLeftDiagnolCheck[row + col]) return false;
        return true;
    }

    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans) {
        if (col >= n) {
            storeSolution(board, n, ans);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagnolCheck[n - 1 + col - row] = true;
                bottomLeftDiagnolCheck[row + col] = true;

                solve(board, col + 1, n, ans);

                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagnolCheck[n - 1 + col - row] = false;
                bottomLeftDiagnolCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(board, 0, n, ans);
        return ans;
    }
};

















#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> rowCheck;
    vector<bool> upperLeftDiagnolCheck;
    vector<bool> bottomLeftDiagnolCheck;

    void storeSolution(vector<vector<char>> &board, int n, vector<vector<string>> &ans) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string output = "";
            for (int j = 0; j < n; j++) {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }

    bool isSafe(int row, int col, int n) {
        if (rowCheck[row]) return false;
        if (upperLeftDiagnolCheck[n - 1 + col - row]) return false;
        if (bottomLeftDiagnolCheck[row + col]) return false;
        return true;
    }

    void solve(vector<vector<char>> &board, int col, int n, vector<vector<string>> &ans) {
        if (col >= n) {
            storeSolution(board, n, ans);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, n)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                upperLeftDiagnolCheck[n - 1 + col - row] = true;
                bottomLeftDiagnolCheck[row + col] = true;

                solve(board, col + 1, n, ans);

                board[row][col] = '.';
                rowCheck[row] = false;
                upperLeftDiagnolCheck[n - 1 + col - row] = false;
                bottomLeftDiagnolCheck[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        
        rowCheck.assign(n, false);
        upperLeftDiagnolCheck.assign(2 * n - 1, false);
        bottomLeftDiagnolCheck.assign(2 * n - 1, false);

        solve(board, 0, n, ans);
        return ans;
    }
};
