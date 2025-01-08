#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool comp(vector<int>&a , vector<int>&b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int solve(vector<vector<int>>&arr){
        sort(arr.begin() , arr.end() , comp);


        if(arr.size() == 0)
            return 0;
        vector<int>ans;
        ans.push_back(arr[0][1]);

        for(int i  = 1 ; i<arr.size() ; i++){
            if(arr[i][1] > ans.back()){
                ans.push_back(arr[i][1]);
            }
            else{
                int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) - ans.begin();
                ans[index] = arr[i][1];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        return solve(envelopes);
        
    }
};



// Time Complexity
// Sorting: The sort function is used to sort the envelopes based on the custom comparator. The time complexity of sorting is O(n log n), where n is the number of envelopes.
// Dynamic Programming with Binary Search: The solve function uses a vector ans to store the heights of the envelopes in increasing order. For each envelope, it performs a binary search using lower_bound, which has a time complexity of O(log n). Since this operation is performed for each envelope, the overall time complexity for this part is O(n log n).
// Combining both parts, the overall time complexity is:

// Time Complexity: O(n log n) for sorting + O(n log n) for the dynamic programming with binary search = O(n log n).
// Space Complexity
// Sorting: The sorting operation does not require additional space beyond the input array.
// Dynamic Programming with Binary Search: The vector ans is used to store the heights of the envelopes, which can have at most n elements.
// Space Complexity: O(n) for the vector ans.