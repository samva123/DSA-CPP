#include <bits/stdc++.h>
using namespace std;

void solve(string s , int index , string&temp){
    if(index ==  s.size()){
        cout << temp << endl;
        return;
    }
    temp += s[index];
    solve(s , index+1 , temp);
    temp.pop_back();
    solve(s , index+1 , temp);

}


int main(){
    string s  = "abc";
    string temp = "";
    solve(s , 0 ,temp);
}