#include<bits/stdc++.h>
using namespace std;
///////////////////TOP DOWN ///////////////////////////////
class Solution
{
public:
    int solveTD(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
    {
        int cost = 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == s1.size() || j == s2.size())
        {
            // return the sum of
            for (int x = i; x < s1.size(); ++x)
                cost += s1[x];
            for (int x = j; x < s2.size(); ++x)
                cost += s2[x];
        }

        else if (s1[i] == s2[j])
        {
            cost = solveTD(s1, s2, i + 1, j + 1, dp);
        }
        else
        {
            int cost1 = s1[i] + solveTD(s1, s2, i + 1, j, dp);
            int cost2 = s2[j] + solveTD(s1, s2, i, j + 1, dp);
            cost = min(cost1, cost2);
        }

        return dp[i][j] = cost;
    }
    int minimumDeleteSum(string s1, string s2)
    {
        // return solve(s1 , s2 ,0 , 0);

        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solveTD(s1, s2, 0, 0, dp);

        // return solveBU(s1, s2);
    }
};                
                 


// --------------BOTTOM UP-------------------
class Solution {
public:

    int solveBU(string&s1 ,string&s2){
        vector<vector<int>>dp(s1.size()+10, vector<int>(s2.size()+10 , 0));

        for(int i = s1.size(); i>=0 ; --i){
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
        }
        for(int i = s2.size(); i>=0 ; --i){
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i+1];
        }

        for(int i = s1.size()-1; i >= 0 ; --i){
            for(int j = s2.size()-1 ; j>=0 ; --j){
                int cost = 0;
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1];}
                else{
                    int cost1 = s1[i] + dp[i+1][j];
                    int cost2 = s2[j] + dp[i][j+1];
                    cost = min(cost1 , cost2);
                }
                dp[i][j] = cost;

            }
        }
        return dp[0][0];
    }


    int minimumDeleteSum(string s1, string s2) {

        return solveBU(s1,s2);
        
    }
}; 

class Solution {
public:

    int solveBU(string&s1 ,string&s2){
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1 , 0));

        for(int i = s1.size()-1; i>=0 ; --i){
            dp[i][s2.size()] = s1[i] + dp[i+1][s2.size()];
        }
        for(int i = s2.size()-1; i>=0 ; --i){
            dp[s1.size()][i] = s2[i] + dp[s1.size()][i+1];
        }

        for(int i = s1.size()-1; i >= 0 ; --i){
            for(int j = s2.size()-1 ; j>=0 ; --j){
                int cost = 0;
                if(s1[i] == s2[j]){
                    cost = dp[i+1][j+1];}
                else{
                    int cost1 = s1[i] + dp[i+1][j];
                    int cost2 = s2[j] + dp[i][j+1];
                    cost = min(cost1 , cost2);
                }
                dp[i][j] = cost;

            }
        }
        return dp[0][0];
    }


    int minimumDeleteSum(string s1, string s2) {

        return solveBU(s1,s2);
        
    }
};



#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        // Initialize the last row
        for (int j = n - 1; j >= 0; --j) {
            prev[j] = s2[j] + prev[j + 1];
        }

        for (int i = m - 1; i >= 0; --i) {
            curr[n] = s1[i] + prev[n]; // Initialize the last column
            for (int j = n - 1; j >= 0; --j) {
                if (s1[i] == s2[j]) {
                    curr[j] = prev[j + 1];
                } else {
                    curr[j] = min(s1[i] + prev[j], s2[j] + curr[j + 1]);
                }
            }
            swap(prev, curr); // Move current row to previous row
        }

        return prev[0];
    }
};




class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        vector<int> dp(n + 1, 0);

        for (int j = n - 1; j >= 0; --j) {
            dp[j] = s2[j] + dp[j + 1];
        }

        for (int i = m - 1; i >= 0; --i) {
            int prev = dp[n];
            dp[n] = s1[i] + dp[n];
            for (int j = n - 1; j >= 0; --j) {
                int temp = dp[j];
                if (s1[i] == s2[j]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(s1[i] + dp[j], s2[j] + dp[j + 1]);
                }
                prev = temp;
            }
        }

        return dp[0];
    }
};


// each has time complexity O(m*n) and
// space complexity O(n) where m and n are the lengths of s1 and s2, respectively in third and fourth approach



