#include <bits/stdc++.h>
using namespace std;


void subs(vector<int>arr , vector<int>&ans , vector<vector<int>>&result, int i){
    if(i == arr.size() ){
        result.push_back(ans);
        return;
    }
    ans.push_back(arr[i]);
    subs(arr , ans , result , i+1);
    ans.pop_back();
    subs(arr , ans , result , i+1);

}
int main(){
    vector<int>arr={1,2,3};
    vector<int>ans;
    vector<vector<int>>result;
    subs(arr,ans ,result , 0);
    cout << result.size();
}