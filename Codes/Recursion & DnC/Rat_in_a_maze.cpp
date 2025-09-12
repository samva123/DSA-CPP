class Solution {
    bool isSafe(int newx, int newy, vector<vector<int>> &maze, int row, int col, vector<vector<bool>> &visited) {
      return (newx >= 0 && newx < row) &&
             (newy >= 0 && newy < col) &&
             (maze[newx][newy] == 1) &&
             (visited[newx][newy] == false);
    }
  
    void solve(int srcx, int srcy, vector<vector<int>> &maze, int row, int col, string &output,
               vector<vector<bool>> &visited, vector<string> &ans) {
      if (srcx == row - 1 && srcy == col - 1) {
        ans.push_back(output);
        return;
      }
  
      // Mark current cell as visited
      visited[srcx][srcy] = true;
  
      // Up
      int newx = srcx - 1, newy = srcy;
      if (isSafe(newx, newy, maze, row, col, visited)) {
        output.push_back('U');
        solve(newx, newy, maze, row, col, output, visited, ans);
        output.pop_back();
      }
  
      // Right
      newx = srcx, newy = srcy + 1;
      if (isSafe(newx, newy, maze, row, col, visited)) {
        output.push_back('R');
        solve(newx, newy, maze, row, col, output, visited, ans);
        output.pop_back();
      }
  
      // Down
      newx = srcx + 1, newy = srcy;
      if (isSafe(newx, newy, maze, row, col, visited)) {
        output.push_back('D');
        solve(newx, newy, maze, row, col, output, visited, ans);
        output.pop_back();
      }
  
      // Left
      newx = srcx, newy = srcy - 1;
      if (isSafe(newx, newy, maze, row, col, visited)) {
        output.push_back('L');
        solve(newx, newy, maze, row, col, output, visited, ans);
        output.pop_back();
      }
  
      // Unmark current cell (Backtrack)
      visited[srcx][srcy] = false;
    }
  
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
      int n = mat.size();
      vector<string> ans;
      if (mat[0][0] == 0) return ans;
  
      vector<vector<bool>> visited(n, vector<bool>(n, false));
      string output = "";
  
      visited[0][0] = true;
      solve(0, 0, mat, n, n, output, visited, ans);
  
      return ans;
    }
  };







































  class Solution {
    void findPathHelper(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
                        vector<vector<int>> &vis) {
      if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
      }
  
      // Down
      if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
        vis[i][j] = 1;
        findPathHelper(i + 1, j, a, n, ans, move + 'D', vis);
        vis[i][j] = 0;
      }
  
      // Left
      if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
        vis[i][j] = 1;
        findPathHelper(i, j - 1, a, n, ans, move + 'L', vis);
        vis[i][j] = 0;
      }
  
      // Right
      if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
        vis[i][j] = 1;
        findPathHelper(i, j + 1, a, n, ans, move + 'R', vis);
        vis[i][j] = 0;
      }
  
      // Up
      if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
        vis[i][j] = 1;
        findPathHelper(i - 1, j, a, n, ans, move + 'U', vis);
        vis[i][j] = 0;
      }
    }
  
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
      int n = mat.size();
      vector<string> ans;
      vector<vector<int>> vis(n, vector<int>(n, 0));
  
      if (mat[0][0] == 1) findPathHelper(0, 0, mat, n, ans, "", vis);
      return ans;
    }
  };
  
  






































  
  class Solution {
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string &move,
               vector<vector<int>> &vis, const int (&di)[4], const int (&dj)[4]) {
      if (i == n - 1 && j == n - 1) {
        ans.push_back(move);
        return;
      }
  
      string dir = "DLRU";
  
      // Mark current cell as visited
      vis[i][j] = 1;
  
      for (int ind = 0; ind < 4; ind++) {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
          move.push_back(dir[ind]);  // Append character
          solve(nexti, nextj, a, n, ans, move, vis, di, dj);
          move.pop_back();           // Backtrack the character
        }
      }
  
      // Unmark current cell (Backtracking)
      vis[i][j] = 0;
    }
  
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
      int n = mat.size();
      vector<string> ans;
      vector<vector<int>> vis(n, vector<int>(n, 0));
      
      // Direction vectors for Down, Left, Right, Up
      const int di[4] = {+1, 0, 0, -1};
      const int dj[4] = {0, -1, 1, 0};
  
      if (mat[0][0] == 1) {
        string move = "";
        solve(0, 0, mat, n, ans, move, vis, di, dj);
      }
  
      return ans;
    }
  };
  




















































#include <bits/stdc++.h>

using namespace std;

class Solution {
  void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string &move,
             vector<vector<int>> &vis, const int (&di)[4], const int (&dj)[4]) {
    if (i == n - 1 && j == n - 1) {
      ans.push_back(move);
      return;
    }

    string dir = "DLRU";

    // Mark as visited
    vis[i][j] = 1;

    for (int ind = 0; ind < 4; ind++) {
      int nexti = i + di[ind];
      int nextj = j + dj[ind];
      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1) {
        move.push_back(dir[ind]);  // Append character
        solve(nexti, nextj, a, n, ans, move, vis, di, dj);
        move.pop_back();           // Backtrack the character
      }
    }

    // Unmark as visited (Backtracking)
    vis[i][j] = 0;
  }

public:
  vector<string> findPath(vector<vector<int>> &m, int n) {
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    
    // Direction vectors for Down, Left, Right, Up
    const int di[4] = {+1, 0, 0, -1};
    const int dj[4] = {0, -1, 1, 0};

    if (m[0][0] == 1) {
      string move = "";
      solve(0, 0, m, n, ans, move, vis, di, dj);
    }

    return ans;
  }
};

int main() {
  int n = 4;
  vector<vector<int>> m = {
      {1, 0, 0, 0},
      {1, 1, 0, 1},
      {1, 1, 0, 0},
      {0, 1, 1, 1}};
  
  Solution obj;
  vector<string> result = obj.findPath(m, n);

  if (result.empty())
    cout << -1;
  else
    for (const string &s : result) cout << s << " ";
  cout << endl;

  return 0;
}
