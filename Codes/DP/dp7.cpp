// partition equal subset sum
#include <vector>

// class solution{
//     public :
        bool solveusingrecursion(vector<int>& arr, int index , int sum , int target){
            if(index >= arr.size()){
                return 0 ;
            }
            if(sum > target){
                return 0 ;
            }
            if(sum == target){
                return true;
            }
            //recursion
            bool include = solveusingrecursion(arr , index+1 , sum+arr[index] , target);
            bool exclude = solveusingrecursion(arr , index+1 , sum , target);
        }


// bool solveUsingMem(vector<int>& arr, int index, int sum, int target,
// vector<vector<int> >& dp) {
//         if(index >=arr.size()) {
//             return 0;
//         }

//         if(sum > target) {
//             return 0;
//         }

//         if(sum == target) {
//             return true;
//         }

// if(dp[index][sum] != -1) {
// return dp[index] [sum] ;
// }

// //recursion
// bool include = solveUsingMem(arr,index+1, sum+arr[index], target,dp);
// bool exclude = solveUsingMem(arr,index+1, sum, target,dp);

// return dp[index][sum] = (include || exclude);

// }


bool canpartition(vector<int>& nums){

    int index = 0;
    int totalsum = 0;
    for(int i =0 ; i < nums.size() ; i++){
        totalsum += nums[i];
    }
    if(totalsum&1){
        return false;
    }
    int target = totalsum/2;
    int currsum = 0; 
    //vector<vector<int> >dp(nums.size()+1 , vector<int>(target+1 ,-1))
    bool ans = solveusingrecursion(nums , index , currsum ,target); 
    }
//};

class Solution {
public:
    bool solve(vector<int>&arr , int target){
        int n = arr.size();
        vector<vector<int>> dp(n+2 , vector<int>(target+1 ,0));

        for(int row = 0 ; row<=n ; row++){
            dp[row][target] = 1;
        }

        for(int ind = n-1 ; ind >=0 ; ind--){
            for(int s = target-1 ; s>=0 ; s--){
                bool include = 0;
                if(s+arr[ind] <= target)
                    include = dp[ind+1][s+arr[ind]];
                
                bool exclude = dp[ind+1][s];
                dp[ind][s] = (include || exclude);
            }
        }
        return dp[0][0]; 
    }
    bool canPartition(vector<int>& nums) {
        int index = 0;
        int totalsum = 0;
        for(int i =0 ; i < nums.size() ; i++){
            totalsum += nums[i];
        }
        if(totalsum&1){
            return false;
        }
        int target = totalsum/2;
        int currsum = 0; 
        //vector<vector<int> >dp(nums.size()+1 , vector<int>(target+1 ,-1))
        bool ans = solve(nums ,target); 

        return ans ;
        
    }
};


// O(n*target) in old mathods
// O(targe) in space optimization

