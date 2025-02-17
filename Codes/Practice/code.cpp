#include<iostream>
using namespace std;

int solve(int first , int second){
    int ans  = second - first;
    return ans;
}

int main(){
    int T;
    cin >> T;
    
    while(T--){
        int first ;
        int second;
        
        cin >> first >> second;
        
        cout << solve(first , second) << endl;
    }
}