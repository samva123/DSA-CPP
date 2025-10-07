#include <map>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<char>>& board, map<pair<int, int>, bool>& vis) {
        vis[{i, j}] = true;
        for (int d = 0; d < 4; d++) {
            int newX = i + dx[d];
            int newY = j + dy[d];
            if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() &&
                board[newX][newY] == 'O' && !vis[{newX, newY}]) {
                dfs(newX, newY, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        map<pair<int, int>, bool> vis;

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !vis[{i, 0}]) dfs(i, 0, board, vis);
            if (board[i][m - 1] == 'O' && !vis[{i, m - 1}]) dfs(i, m - 1, board, vis);
        }

        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[{0, j}]) dfs(0, j, board, vis);
            if (board[n - 1][j] == 'O' && !vis[{n - 1, j}]) dfs(n - 1, j, board, vis);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis.find({i, j}) == vis.end()) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};





















class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size(), n = board[0].size();
        queue<pair<int,int>> q;

        // Step 1: Add all boundary 'O's to queue
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') { q.push({i, 0}); board[i][0] = '#'; }
            if (board[i][n-1] == 'O') { q.push({i, n-1}); board[i][n-1] = '#'; }
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') { q.push({0, j}); board[0][j] = '#'; }
            if (board[m-1][j] == 'O') { q.push({m-1, j}); board[m-1][j] = '#'; }
        }

        // Directions for BFS
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // Step 2: BFS to mark safe 'O's
        while (!q.empty()) {
            //auto [x, y] = q.front(); q.pop();
            auto front = q.front();
            q.pop();
            auto x = front.first;
            auto y = front.second;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O') {
                    board[nx][ny] = '#';  // mark as safe
                    q.push({nx, ny});
                }
            }
        }

        // Step 3: Flip
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';   // surrounded
                else if (board[i][j] == '#') board[i][j] = 'O'; // safe
            }
        }
    }
};
