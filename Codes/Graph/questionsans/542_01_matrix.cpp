// #include <vector>
// #include <queue>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

// class Solution {
// public:
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int m = mat.size(), n = mat[0].size();
//         queue<pair<int, int>> q;

//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (mat[i][j] == 0) {
//                     q.push({i, j});
//                 } else {
//                     mat[i][j] = INT_MAX;
//                 }
//             }
//         }

//         vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();

//             for (auto [dx, dy] : directions) {
//                 int newX = x + dx;
//                 int newY = y + dy;

//                 if (newX >= 0 && newX < m && newY >= 0 && newY < n &&
//                     mat[newX][newY] > mat[x][y] + 1) {
                    
//                     mat[newX][newY] = mat[x][y] + 1;
//                     q.push({newX, newY});
//                 }
//             }
//         }

//         return mat;
//     }
// };










