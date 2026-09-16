#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxlen = 1 , start = 0 ;
    bool solve(string&s , int i , int j){
        if(i>=j){
            return true;
        }
        bool flag = false;
        if(s[i] == s[j]){
            flag = solve(s, i+1 , j-1);
        }
        if(flag){
            int currlen = j-i+1;
            if(currlen > maxlen){
                maxlen = currlen;
                start = i;
            }
        }
        return flag;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = 0 ; i < n ; ++i){
            for(int j = i ; j < n ; ++j){
                bool t = solve(s,i,j);
            }
        }
        return s.substr(start,maxlen);

        
    }
};


// Time Complexity: O(n^3). The outer loops run in O(n^2) and the recursive function solve runs in O(n) for each pair (i, j).
// Space Complexity: O(n) due to the recursion stack.




class Solution {
public:
    int maxlen = 1 , start = 0 ;
    bool solve(string&s , int i , int j , vector<vector<int>>&dp){
        if(i>=j){
            return true;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool flag = false;
        if(s[i] == s[j]){
            flag = solve(s, i+1 , j-1,dp);
        }
        if(flag){
            int currlen = j-i+1;
            if(currlen > maxlen){
                maxlen = currlen;
                start = i;
            }
        }
        return dp[i][j] = flag;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));
        for(int i = 0 ; i < n ; ++i){
            for(int j = i ; j < n ; ++j){
                bool t = solve(s,i,j ,dp);
            }
        }
        return s.substr(start,maxlen);

        
    }
};

// Time Complexity: O(n^3). The outer loops run in O(n^2) and the recursive function solve runs in O(n) for each pair (i, j).
// Space Complexity: O(n^2) due to the memoization table.





///////ISME BOTTOM UP NAHI KARAYA////////////////////



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int start = 0, maxlen = 1;

        for (int i = 0; i < n; ++i) {
            // Odd length palindromes
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxlen) {
                    start = l;
                    maxlen = r - l + 1;
                }
                --l;
                ++r;
            }

            // Even length palindromes
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxlen) {
                    start = l;
                    maxlen = r - l + 1;
                }
                --l;
                ++r;
            }
        }

        return s.substr(start, maxlen);
    }
};


// Time Complexity: O(n^2), where n is the length of the string. This is because we are expanding around each center.
// Space Complexity: O(1). This approach only uses a few extra variables for tracking the start and length of the longest palindromic substring.




