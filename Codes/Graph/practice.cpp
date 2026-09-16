#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>arr , int n ){
    int ans  = 0 ;
    unordered_set<int>s(arr.begin(), arr.end());

    for(auto x : arr){
        if(!s.count(x-1)){
            int curr  = x ;
            int count  = 1;

            while(s.count(curr+1)){
                curr = curr+1;
                count++;
            }
            ans  = max(ans , count);
        }
    }
    return ans;
}

int main(){
    vector<int>arr  = {10,101,12,13,11,102,103,105,104,106};
    int n = 7;
    cout << solve(arr , n);
}