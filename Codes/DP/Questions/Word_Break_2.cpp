#include <bits/stdc++.h>
using namespace std;

///////////////SIMPLE////////////////////
class Solution {
public:
    vector<string>solve(string&s , unordered_map<string, bool>&dict , int i ){
        if(i == s.size()) {return {""};}
        vector<string>ans;
        string word;

        for(int j = i ; j <s.size();++j){

            
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) continue;

            //found
            auto right = solve(s ,dict , j+1);
            for(auto eachright:right){
                string endpart;
                if(eachright.size() > 0) endpart = " " + eachright;
                ans.push_back(word + endpart);
            }
        }
        return ans;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , bool>dict;
        for(auto word:wordDict) dict[word] = 1 ;

        return solve(s , dict ,0);
        
    }
};
//2^n time and n^2 space


//////////////////////////MEMO///////////////////////////
class Solution {
public:
    unordered_map<int , vector<string>>dp;
    vector<string>solveTD(string&s , unordered_map<string, bool>&dict , int i ){
        if(i == s.size()) {return {""};}
        vector<string>ans;
        string word;

        if(dp.find(i) != dp.end()) return dp[i];

        for(int j = i ; j <s.size();++j){
            word.push_back(s[j]);
            if(dict.find(word) == dict.end()) continue;

            //found
            auto right = solveTD(s ,dict , j+1);
            for(auto eachright:right){
                string endpart;
                if(eachright.size() > 0) endpart = " " + eachright;
                ans.push_back(word + endpart);

            }

            

        }
        return dp[i]=ans;

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string , bool>dict;
        for(auto word:wordDict) dict[word] = 1 ;

        //return solve(s , dict ,0);
        return solveTD(s ,dict,0);
    }
};


// this also has only changes for unoredered_set for the dict vector
// Time Complexity: (O(n^2 \cdot k))
// Each state (i) is computed at most once, and for each state, we explore all possible substrings. The time complexity is dominated by the number of substrings and the number of ways to concatenate them.
// (k) is the average number of words in the result.
// Space Complexity: (O(n^2 \cdot k))
// The memoization table dp stores results for each index, and each result can store up to (O(k)) strings.
// This approach is efficient and does not require further optimization. It achieves the best possible time complexity of (O(n^2 \cdot k)) and an optimized space complexity of (O(n^2 \cdot k)).