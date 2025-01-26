class Solution {
public:
    int mazeObstaclesUtil(int i, int j, vector<vector<int>> &maze, vector<vector<int>> &dp) {
        // Base cases
        if (i < 0 || j < 0) return 0; 
        if (maze[i][j] == 1) return 0; 
        if (i == 0 && j == 0) return 1; 

        if (dp[i][j] != -1) return dp[i][j]; 

        
        int up = mazeObstaclesUtil(i - 1, j, maze, dp);
        int left = mazeObstaclesUtil(i, j - 1, maze, dp);

        
        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1)); // DP table to memoize results
        return mazeObstaclesUtil(n - 1, m - 1, obstacleGrid, dp);
    }
};


















#include <bits/stdc++.h>
using namespace std;

// Helper function to count the number of paths from (0, 0) to (n-1, m-1) in the maze
int mazeObstaclesUtil(int n, int m, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Base case: if there's an obstacle at (i, j), no paths can pass through it
            if (maze[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            
            // Base case: starting point
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }

            int up = 0, left = 0;

            // Check if we can move up or left
            if (i > 0)
                up = dp[i - 1][j]; // Number of paths from above
            if (j > 0)
                left = dp[i][j - 1]; // Number of paths from the left

            // Total number of paths to reach (i, j)
            dp[i][j] = up + left;
        }
    }

    // Return the value at the bottom-right corner
    return dp[n - 1][m - 1];
}

// Main function to count paths with obstacles in a maze
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();

    // Edge case: if the start or end cell is blocked
    if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(m, 0)); // DP table to store results
    return mazeObstaclesUtil(n, m, obstacleGrid, dp);
}

int main() {
    vector<vector<int>> maze{
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Number of unique paths: " << uniquePathsWithObstacles(maze) << endl;
    return 0;
}























class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& maze) {
        int n = maze.size();
        int m = maze[0].size();
        vector<int> prev(m, 0); // Initialize a vector to store the previous row's path counts

    for (int i = 0; i < n; i++) {
        vector<int> temp(m, 0); // Initialize a temporary vector for the current row
        for (int j = 0; j < m; j++) {
            // If the cell is an obstacle, no paths can pass through it
            if (maze[i][j] == 1) {
                temp[j] = 0;
                continue;
            }

            // Base condition: starting point
            if (i == 0 && j == 0) {
                temp[j] = 1;
                continue;
            }

            int up = 0, left = 0;

            // Check if we can move up (not at the first row)
            if (i > 0)
                up = prev[j];

            // Check if we can move left (not at the first column)
            if (j > 0)
                left = temp[j - 1];

            // Total number of paths to reach (i, j)
            temp[j] = up + left;
        }
        prev = temp; // Update the previous row with the current row
    }

    // The final result is stored in prev[m-1], which represents the destination in the last row
    return prev[m - 1];
        
    }
};


