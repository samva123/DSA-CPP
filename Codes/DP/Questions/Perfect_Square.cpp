class Solution {
public:

    int numsquarehelper(int n){
        if(n == 0) return 1 ;
        if(n < 0) return 0;

        int ans = INT_MAX;
        int i = 1 ;
        int end = sqrt(n);
        while(i <= end){
            int perfect = i*i;
            int number = 1+numsquarehelper(n-perfect);
            if(number < ans){
                ans = number;
            }
            ++i;
        }
        return ans;
    }
    int numSquares(int n) {
        return numsquarehelper(n)-1;
        
    }
};



/////////////////////////////////////////////////////////////

class Solution {
public:

    int numsquarehelper(int n ){
        vector<int>dp(n+1 , -1);
        
        dp[0] =1;

        for(int i = 1 ; i <=  n ; ++i){
        int ans = INT_MAX;
        int j = 1 ;
        int end = sqrt(i);
        while(j <= end){
            int perfect = j*j;
            int number = 1+numsquarehelper(i-perfect);
            if(number < ans){
                ans = number;
            }
            ++j;
        }
        dp[i] = ans;
        // return dp[n];
        }
        return dp[n]; 
    }
    int numSquares(int n) {
        
        return numsquarehelper(n )-1;
        
    }
};