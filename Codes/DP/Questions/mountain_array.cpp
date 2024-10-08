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