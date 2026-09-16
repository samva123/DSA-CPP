#include <bits/stdc++.h>
using namespace std;
////////////////////TOP DOWN /////////////
class Solution {
public:
    bool check(vector<string>& wordDict , string&s){
        for(auto i:wordDict){
            if(s == i) return true;
        }
        return false;
    }
    bool solveTD(string&s , vector<string>& wordDict , int start , vector<int>&dp){
        if(start == s.size()) return true;

        if(dp[start] != -1) return dp[start];

        string word = "";
        bool flag = false;
        for(int i = start;i<s.size();++i){
            word += s[i];
            if(check(wordDict,word)){
                flag = flag || solveTD(s, wordDict , i+1 , dp);
            }
        }
        dp[start] =flag;
        return dp[start]; 
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int>dp(s.size(),-1);
        return solveTD(s, wordDict,0 , dp);
        
    }
};
// both has n^2.m time and n space
////////////////////////bottom up ////////////////////////////////
class Solution {
public:
    bool check(vector<string>& wordDict , string&s){
        for(auto i:wordDict){
            if(s == i) return true;
        }
        return false;
    }
    bool solveBU(string&s , vector<string>& wordDict , vector<int>&dp){
        for(int start = s.size() -1 ; start>=0 ; --start){
            string word = "";
            bool flag = false;
            for(int i = start;i<s.size();++i){
                word += s[i];
                if(check(wordDict,word)){
                    flag = flag || dp[i+1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }
    bool wordBreak(string s, vector<string>& wordDict) {

        vector<int>dp(s.size()+1 , true);
        return solveBU(s,wordDict,dp);
        
    }
};



class Solution {
public:
    bool solveBU(string&s , unordered_set<string>& wordDict , vector<int>&dp){
        for(int start = s.size() - 1; start >= 0; --start){
            string word = "";
            bool flag = false;
            for(int i = start; i < s.size(); ++i){
                word += s[i];
                if(wordDict.find(word) != wordDict.end()){
                    flag = flag || dp[i + 1];
                }
            }
            dp[start] = flag;
        }
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size() + 1, false);
        dp[s.size()] = true;  // base case: empty string can be segmented
        return solveBU(s, dict, dp);
    }
};


// Optimized Complexity (with unordered set):
// •	Time Complexity: O(n2)O(n^2)O(n2) — We no longer need to call check() and can perform lookups in constant time O(1)O(1)O(1).
// •	Space Complexity: O(n)O(n)O(n) — We still use a dp array of size nnn and the set to store dictionary words.
// Final Conclusion:
// •	Bottom-Up with set optimization is the best approach in terms of both time and space complexity.

