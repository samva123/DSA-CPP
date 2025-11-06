#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int solve(vector<int>& sat, int i, int time) {
        if (i == sat.size()) return 0;

        int includeLikeTimeCoeff = time * sat[i] + solve(sat, i + 1, time + 1);
        int excludeLikeTimeCoeff = solve(sat, i + 1, time);

        return max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
    }

    int solveTD(vector<int>& sat, int i, int time, vector<vector<int>>& dp) {
        if (i == sat.size()) return 0;

        if (dp[i][time] != -1) return dp[i][time];

        int includeLikeTimeCoeff = time * sat[i] + solveTD(sat, i + 1, time + 1, dp);
        int excludeLikeTimeCoeff = solveTD(sat, i + 1, time, dp);

        return dp[i][time] = max(includeLikeTimeCoeff, excludeLikeTimeCoeff);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(satisfaction.size() + 1, vector<int>(satisfaction.size() + 1, -1));
        return solveTD(satisfaction, 0, 1, dp);
    }
};





class Solution {
public:
    int solve(vector<int>& sat) {

        vector<vector<int>> dp(sat.size()+1, vector<int>(sat.size() + 2, 0));
        for(int i = sat.size()-1 ; i >=0 ; --i){
            for(int j = sat.size() ; j >= 1 ; --j){
                int include  = j * sat[i] + dp[i+1][j+1];
                int exclude  = dp[i+1][j]; 
                dp[i][j] = max(include , exclude);
            }
        }
        return dp[0][1];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());

        // DP table dimensions corrected
        
        return solve(satisfaction);
    }
};




/////no dp solution 

class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        int prefix = 0, res = 0;

        
        for (int i = n - 1; i >= 0; i--) {
            prefix += satisfaction[i];
            if (prefix < 0) break; 
            res += prefix;
        }

        return res;
    }
};