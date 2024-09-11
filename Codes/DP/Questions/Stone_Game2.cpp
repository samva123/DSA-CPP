class Solution {
public:
    int solve(vector<int>&piles , int i , int m , int alice){
        if(i == piles.size()) return 0;

        int ans = alice ? INT_MIN : INT_MAX;
        int total = 0 ;

        for(int x=1 ; x<=2*m ; x++){
            if(i+x-1 >= piles.size()) break;
            total += piles[i+x-1];
            if(alice)
                ans = max(ans , total + solve(piles , i+x , max(x,m) , !alice));
            else
                ans = min(ans , solve(piles , i+x , max(x,m) , !alice));
        }
        return ans ;
    }
    int stoneGameII(vector<int>& piles) {
        return solve(piles ,0 ,1 , true);
        
    }
};



class Solution {
public:
    int solve(vector<int>&piles ){
        vector<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,0)));
        //if(i == piles.size()) return 0;

        for(int i = piles.size()-1 ; i>=0 ; --i){
            for(int M = piles.size() ; M>=1 ; --M){
                for(int alice = 0 ; alice<=1 ; ++alice){
                    int ans = alice ? INT_MIN : INT_MAX;
                    int total = 0 ;

                    for(int x=1 ; x<=2*M ; x++){
                        if(i+x-1 >= piles.size()) break;
                        total += piles[i+x-1];
                        if(alice)
                            ans = max(ans , total + dp[i+x][max(x,M)][!alice]);
                        else
                            ans = min(ans , dp[i+x][max(x,M)][!alice]);
                    }
                    dp[i][M][alice] = ans;
                }

            }
        }
        return dp[0][1][1];

       
    }
    int stoneGameII(vector<int>& piles) {
        //vect<vector<vector<int>>>dp(piles.size()+1,vector<vector<int>>(piles.size()+1,vector<int>(2,-1)));
        return solve(piles );
        
    }
};


