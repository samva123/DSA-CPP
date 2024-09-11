// ////////////////////TOP DOWN /////////////
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