#include <iostream>
#include<vector>
using namespace std;
// count derrangments
int solve(int n) {

	//base case
	if(n == 1) {
		return 0;
	}
	if(n == 2) {
		return 1;
	}

	int ans = (n-1) * (solve(n-1) + solve(n-2));
	return ans;
}
//painting fence algo
int getPaintWays(int n, int k ) {
	//base case
	if(n == 1) {
		return k;
	}
	if(n == 2) {
		return k + k*(k-1);
	}

	int ans = (k-1) * (getPaintWays(n-1,k) + getPaintWays(n-2,k));
	return ans;
}

int main() {

	// int n = 4;
	// cout << solve(n) << endl;


	int n = 3;
	int k = 3;
	int ans = getPaintWays(n,k);
	cout << ans << endl;
	return 0;
}


//Maximal Square:

class Solution {
public: 
    int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int &maxi) {
        //base case
        if(i >= row || j>= col) {
            return 0;
        }

        //explore all 3 directions
        int right = solve(matrix, i, j+1, row, col, maxi);
        int diagnol = solve(matrix, i+1, j+1, row, col, maxi);
        int down = solve(matrix, i+1, j, row, col, maxi);

        //check can we build sqaure form current position
        if(matrix[i][j] == '1') {
            int ans = 1 + min(right, min(down, diagnol));
            //cout << "For i: " << i << "j: " << j << endl;
            //ye important hai 
            maxi = max(maxi, ans);
            return ans;

        }
        else {
            //agar 0 pr hi khade ho toh answer bhi zero hga
            return 0;
        }
     }
    int maximalSquare(vector<vector<char>>& matrix) {
        int i = 0; 
        int j = 0;
        int row = matrix.size();
        int col = matrix[0].size();
        int maxi = 0;
        int ans = solve(matrix, i, j, row, col, maxi) ;
        return maxi*maxi;
    }
};