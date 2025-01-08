#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int solve(vector<int>& num , vector<int>&lis) {
        if(num.size() == 0){
            return 0;
        }
        vector<int> ans;
        lis.push_back(1);
        //initial state
        ans.push_back(num[0]);
        for(int i=1; i<num.size(); i++) {
            if(num[i] > ans.back()) {
                ans.push_back(num[i]);
                lis.push_back(ans.size());

            }
            else {
                //just bada number exist krta hai
                int index = lower_bound(ans.begin(), ans.end(), num[i]) - ans.begin();
                //replace 
                ans[index] = num[i];
                lis.push_back(index+1);
            }
        }
        return ans.size();
    }

    

    int minimumMountainRemovals(vector<int>& nums) {
        vector<int>lis;
        vector<int>lds;
        solve(nums , lis );
        reverse(nums.begin() , nums.end());
        solve(nums , lds);

        // for(auto v : lis){
        //     cout << v << " ";
        // }
        // cout << endl;

        // for(int i = 0 ; i < nums.size() ; ++i){
        //     cout << lds[nums.size()-i-1] << " ";
        // }
        // return -1;

        int name = INT_MIN;
        for(int i = 0 ; i<nums.size() ; ++i){
            if(lis[i] == 1|| lds[nums.size()-i-1] == 1) continue;
            name = max(name , lis[i]+lds[nums.size()-i-1] -1);

        }
        int minnumber = nums.size() - name;
        return minnumber;




        

        
    }
};



// Time Complexity
// First solve Call: The solve function is called twice, once for the original array and once for the reversed array.

// Sorting and Binary Search: The solve function uses a combination of sorting and binary search (lower_bound). For each element in the array, it performs a binary search, which has a time complexity of O(log n). Since this operation is performed for each element, the overall time complexity for this part is O(n log n).
// Overall Time Complexity for solve: O(n log n).
// Reversing the Array: Reversing the array has a time complexity of O(n).

// Combining Results: The final loop combines the results of the two solve calls. This loop runs in O(n) time.

// Combining all parts, the overall time complexity is:

// Time Complexity: O(n log n) for the first solve call + O(n) for reversing the array + O(n log n) for the second solve call + O(n) for combining results = O(n log n).
// Space Complexity
// Space for ans Vector: The ans vector in the solve function can have at most n elements.
// Space for lis and lds Vectors: The lis and lds vectors each have n elements.
// Space for Reversing the Array: Reversing the array does not require additional space beyond the input array.
// Space Complexity: O(n) for the ans vector + O(n) for the lis vector + O(n) for the lds vector = O(n).
