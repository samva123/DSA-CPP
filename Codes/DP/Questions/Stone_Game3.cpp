class Solution {
public:
    int solve(vector<int>&sv , int i){
        if(i == sv.size()) return 0;

        int ans = INT_MIN;
        int total = 0;
        for(int x = 1 ; x<=3 ; ++x){
            if(i+x-1 >= sv.size()) break ;
            total += sv[i+x-1];
            ans = max(ans , total - solve(sv , i+x));

        }
        return ans ;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int ans = solve(stoneValue,0);

        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
        
    }
};



class Solution {
public:
    int solve(vector<int>&sv){
        vector<int>dp(sv.size()+1 ,0);
        for(int i = sv.size()-1 ; i>=0 ; i--){
            int ans = INT_MIN;
            int total = 0;
            for(int x = 1 ; x<=3 ; ++x){
                if(i+x-1 >= sv.size()) break ;
                total += sv[i+x-1];
                ans = max(ans , total - dp[i+x]);

            }
            dp[i] =ans;

        }
        return dp[0];

        
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int ans = solve(stoneValue);

        if(ans>0) return "Alice";
        if(ans<0) return "Bob";
        return "Tie";
        
    }
};