// Find the length of the longest subsequence in an array whose bitwise AND is not zero
#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;


int lon(vector<int>& arr) {
    int ans = 0;
    for (int bit = 0; bit < 32; bit++) {
        int count = 0;
        for (int x : arr) {
            if (x & (1 << bit)) count++;
        }
        ans = max(ans, count);

        
    }
    return ans;
}

int longestSubarray(vector<int>& nums) {
    int ans = 0;

    for (int bit = 0; bit < 32; bit++) {
        int cnt = 0;

        for (int x : nums) {
            if (x & (1 << bit)) {
                cnt++;
                ans = max(ans, cnt);
            } else {
                cnt = 0;
            }
        }
    }

    return ans;
}
int main(){
    int n = 5;
    vector<int>arr = {7,3,5,8 ,2};
    int maxLen = 1;

    //solve(arr , n , maxLen , 0 , -1 , 0);

    cout<<maxLen << endl;
    cout << lon(arr);
}



































 
