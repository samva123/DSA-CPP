#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool ismatchhelper(string&s , int si , string&p , int pi){
        if(si == s.size() && pi == p.size()){
            return true;
        }
        if (pi == p.size()) {
            return false;
        }
        if(si == s.size() && pi < p.size()){
            while(pi < p.size()){
                if(p[pi] != '*') return false;
                pi++;
            }
            return true;
        }

        if(s[si] == p[ pi] || '?' == p[pi]){
            return ismatchhelper(s , si+1 , p , pi+1);
        }

        if(p[pi] == '*'){
            bool caseA = ismatchhelper(s , si , p , pi+1);

            bool caseB = ismatchhelper(s , si+1 , p , pi);
            return caseA || caseB;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int si = 0 ;
        int pi  = 0 ;

        return ismatchhelper(s , si , p , pi);        
    }
};


class Solution {
public:
    bool ismatchhelper(string &s, int si, string &p, int pi, vector<vector<int>> &dp) {
        if (si == s.size() && pi == p.size()) return true;
        if (pi == p.size()) return false;
        if (si == s.size()) {
            while (pi < p.size()) {
                if (p[pi] != '*') return false;
                pi++;
            }
            return true;
        }

        if (dp[si][pi] != -1) return dp[si][pi];

        if (s[si] == p[pi] || p[pi] == '?') {
            return dp[si][pi] = ismatchhelper(s, si + 1, p, pi + 1, dp);
        }

        if (p[pi] == '*') {
            bool caseA = ismatchhelper(s, si + 1, p, pi + 1, dp); // Match '*' with current character
            bool caseB = ismatchhelper(s, si + 1, p, pi, dp);     // Match '*' with empty sequence
            bool caseC = ismatchhelper(s, si, p, pi + 1, dp);     // Skip '*' altogether
            return dp[si][pi] = caseA || caseB || caseC;
        }

        return dp[si][pi] = false;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size(), vector<int>(p.size(), -1));
        return ismatchhelper(s, 0, p, 0, dp);
    }
};















class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base cases
        dp[m][n] = true; // Empty string matches empty pattern

        // Fill for the case where s is empty and p has only '*'
        for (int pi = n - 1; pi >= 0; pi--) {
            if (p[pi] == '*') {
                dp[m][pi] = dp[m][pi + 1];
            } else {
                break;
            }
        }

        // Fill the DP table in reverse order
        for (int si = m - 1; si >= 0; si--) {
            for (int pi = n - 1; pi >= 0; pi--) {
                if (p[pi] == s[si] || p[pi] == '?') {
                    dp[si][pi] = dp[si + 1][pi + 1]; // Match current character
                } else if (p[pi] == '*') {
                    dp[si][pi] = dp[si + 1][pi] || dp[si][pi + 1]; // Match '*' with any sequence or skip '*'
                } else {
                    dp[si][pi] = false;
                }
            }
        }

        return dp[0][0]; // Result is whether the entire string matches the pattern
    }
    
};



