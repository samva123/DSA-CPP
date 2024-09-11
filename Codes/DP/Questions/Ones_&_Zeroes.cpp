class Solution {
public:
    void convert(vector<string>&strs, vector<pair<int , int>>&numstrs){
        for(auto  str:strs){
            int zeros = 0 , ones =0;
            for(auto ch : str){
                if(ch == '0') ++zeros;
                else ++ones;
            }
            numstrs.push_back({zeros,ones});
        }
    }

    int solve(vector<pair<int , int>>&numstrs , int i ,int m ,int n){
        if(i == numstrs.size()) return 0;

        int zeros = numstrs[i].first;
        int ones = numstrs[i].second;
        int include = 0 , exclude = 0;
        if( m -zeros >= 0 && n-ones >=0){
            include = 1+solve(numstrs , i+1,m-zeros,n-ones);}
            exclude = solve(numstrs , i+1 ,m ,n);
            return max(include,exclude);  

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int , int>>numstrs;//no. of zero and ones
        convert(strs,numstrs);
        return solve(numstrs ,0, m,n);
        
    }
};

class Solution {
public:
    void convert(vector<string>&strs, vector<pair<int , int>>&numstrs){
        for(auto  str:strs){
            int zeros = 0 , ones =0;
            for(auto ch : str){
                if(ch == '0') ++zeros;
                else ++ones;
            }
            numstrs.push_back({zeros,ones});
        }
    }

    int solve(vector<pair<int , int>>&numstrs ,int m ,int n){
        vector<vector<vector<int>>>dp(numstrs.size() +1, vector<vector<int>>(m+1 , vector<int>(n+1 ,0)));
        for(int i = numstrs.size()-1 ; i>=0 ; --i){
            for(int j = 0 ; j<=m ; ++j){
                for(int k = 0 ; k<=n ; k++){
                    
                    int zeros = numstrs[i].first;
                    int ones = numstrs[i].second;
                    int include = 0 , exclude = 0;
                    if( j -zeros >= 0 && k-ones >=0){
                        include = 1+dp[i+1][j-zeros][k-ones];}
                        exclude = dp[i+1][j][k];
                        dp[i][j][k] = max(include,exclude);  

    


                }
            }
        }
        return dp[0][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int , int>>numstrs;//no. of zero and ones
        convert(strs,numstrs);
        return solve(numstrs , m,n);
        
    }
};

// iska memo bhi dekhn hai
