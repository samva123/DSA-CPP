#include <bits/stdc++.h>
using namespace std;
















class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>s;
        generate(n,0,0,"",s);
        return s;
    }
    void generate(int n,int open,int close,string present,vector<string>&s) {
        if(open==n&&open==close){
            s.push_back(present);
            return;
        }
        if(open<n){
            generate(n,open+1,close,present + "(",s);
        }
        if(close<open){
            generate(n,open,close+1,present + ")",s);
        }
        
    }
};





















class Solution {
public:
    void generate_parenthesis(int opn, int cls, string &path, vector<string> &ans)
    {
        if(opn == 0 && cls == 0)
        {
            ans.push_back(path);
            return;
        }

        if(opn != 0)
        {
            path.push_back('(');
            generate_parenthesis(opn-1, cls, path, ans);
            path.pop_back();
        }

        if( cls - opn >= 1)
        {
            path.push_back(')');
            generate_parenthesis(opn, cls-1, path, ans);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string path;
        vector<string>ans;
        generate_parenthesis( n, n, path, ans);
        return ans;
    }
};