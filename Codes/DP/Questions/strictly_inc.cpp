class Solution {
public:
#define INF (1e9+1)
    int solve(vector<int>&arr1 , vector<int>&arr2 , int prev , int i ){
        if(i == arr1.size()) return 0;

        int op1 = INF;
        if(prev < arr1[i]){
            op1 = solve(arr1 , arr2 , arr1[i] , i+1);
        }
        int op2  = INF;
        auto it = upper_bound(arr2.begin() , arr2.end() , prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            // arr1[i] = arr2[index];
            op2 = 1+solve(arr1 , arr2 , arr2[index] , i+1);
        }
        return min(op1 , op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin() , arr2.end());

        int ans =  solve(arr1 , arr2 , -1 , 0);
        return ans == INF ? -1: ans;
        
    }
};









class Solution {
public:
#define INF (1e9+1)
    int solve(vector<int>&arr1 , vector<int>&arr2 , int prev , int i , map<pair<int , int>,int>&dp ){
        if(i == arr1.size()) return 0;

        if(dp.find({prev , i})!= dp.end()) return dp[{prev , i}];

        int op1 = INF;
        if(prev < arr1[i]){
            op1 = solve(arr1 , arr2 , arr1[i] , i+1,dp);
        }
        int op2  = INF;
        auto it = upper_bound(arr2.begin() , arr2.end() , prev);
        if(it != arr2.end()){
            int index = it - arr2.begin();
            // arr1[i] = arr2[index];
            op2 = 1+solve(arr1 , arr2 , arr2[index] , i+1,dp);
        }
        return dp[{prev , i }] = min(op1 , op2);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin() , arr2.end());

        map<pair<int , int>,int>dp;
        int ans =  solve(arr1 , arr2 , -1 , 0 ,dp);
        return ans == INF ? -1: ans;
        
    }
};



