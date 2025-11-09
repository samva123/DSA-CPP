#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int numsquarehelper(int n){
        if(n == 0) return 1 ;
        if(n < 0) return 0;

        int ans = INT_MAX;
        int i = 1 ;
        int end = sqrt(n);

        
        while(i <= end){
            int perfect = i*i;
            int number = 1+numsquarehelper(n-perfect);
            if(number < ans){
                ans = number;
            }
            ++i;
        }
        return ans;
    }
    int numSquares(int n) {
        return numsquarehelper(n)-1;
        
    }
};


/////////////////////////////////////////////

class Solution {
public:

    int numsquarehelper(int n ,vector<int>&dp){
        if(n == 0) return 1 ;
        if(n < 0) return 0;

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        int i = 1 ;
        int end = sqrt(n);
        while(i <= end){
            int perfect = i*i;
            int number = 1+numsquarehelper(n-perfect,dp);
            if(number < ans){
                ans = number;
            }
            ++i;
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int>dp(n+1 , -1);
        return numsquarehelper(n,dp)-1;
        
    }
};

/////////////////////////////////////////////////////////////

class Solution {
public:

    int numsquarehelper(int n ){
        vector<int>dp(n+1 , -1);
        
        dp[0] =1;

        for(int i = 1 ; i <=  n ; ++i){
        int ans = INT_MAX;
        int j = 1 ;
        int end = sqrt(i);
        while(j <= end){
            int perfect = j*j;
            int number = 1+dp[i-perfect];
            if(number < ans){
                ans = number;
            }
            ++j;
        }
        dp[i] = ans;
        // return dp[n];
        }
        return dp[n]; 
    }
    int numSquares(int n) {
        
        return numsquarehelper(n)-1;
        
    }
};


class Solution {
public:
    bool isPerfectSquare(int n) {
        int sq = sqrt(n);
        return sq * sq == n;
    }

    int numSquares(int n) {
        // Check if n is a perfect square
        if (isPerfectSquare(n)) return 1;

        // Check if n can be written as the sum of two perfect squares
        for (int i = 1; i * i <= n; ++i) {
            if (isPerfectSquare(n - i * i)) {
                return 2;
            }
        }

        // Check the 4-square condition
        while (n % 4 == 0) n /= 4;  // Remove factors of 4
        if (n % 8 == 7) return 4;

        // Otherwise, return 3
        return 3;
    }
};


// first has n^n time complexity and second has n time complexity.
// second has O(n.sqrt(n)) space complexity and first has O(n) space complexity.
// third has O(n.sqrt(n)) time complexity and O(n) space complexity.
// fourth has O(n.sqrt(n)) time complexity and O(1) space complexity.
