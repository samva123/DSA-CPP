#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(string& s, int index, int left, int right, int bal, string &output, unordered_set<string>& ans ) {
        //base case
        if(index >= s.length()) {
            //valid ans
            if(left ==0 && right ==0 && bal == 0 ) {
                ans.insert(output);
            } 
            return;
        }

        //main logic -> incl/excl
        if(s[index] !='(' && s[index] != ')') {
            //include
            output.push_back(s[index]);
            solve(s,index+1, left, right, bal, output, ans);
            output.pop_back();
        }
        else {
            //bracket wala case
            if(s[index] =='(') {
                //removal - include(remove karu)
                if(left > 0) {
                    solve(s, index + 1, left-1, right, bal, output, ans);
                }
                //removal - exclude(remove na karu)
                output.push_back(s[index]);
                solve(s, index+1, left, right, bal+1,output, ans );
                output.pop_back();
            }
            else if(s[index] == ')') {
                //removal - include
                if(right > 0 ) {
                    solve(s, index+1, left, right-1, bal, output, ans);
                }
                //removal - exclude
                //removal nahi karna , sirf usi case jab corresponding opening bracket available hai 
                if(bal > 0 ) {
                    output.push_back(s[index]);
                    solve(s, index + 1, left, right, bal-1, output, ans);
                    output.pop_back();
                }
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans;
        int invalidLeft = 0;
        int invalidRight = 0;

        for(auto ch: s ){
            if(ch == '(') 
                invalidLeft++;
            if(ch == ')') {
                if(invalidLeft != 0) {
                    --invalidLeft;
                }
                else {
                    invalidRight++;
                }
            }
        }
        int index = 0;
        int balance = 0;
        string output = "";
        solve(s,index,invalidLeft,invalidRight,balance,output,ans);
        return vector<string>(ans.begin(), ans.end());
    }
};



class Solution {
public:
    vector<string> ans;

    void remove(string s, int last_i, int last_j, char open, char close) {
        int balance = 0;

        for (int i = last_i; i < s.size(); i++) {
            if (s[i] == open)
                balance++;
            else if (s[i] == close)
                balance--;

            if (balance >= 0)
                continue;

            // Too many closing parentheses.
            for (int j = last_j; j <= i; j++) {
                // Remove only the first closing parenthesis in a sequence.
                if (s[j] == close && (j == last_j || s[j - 1] != close)) {
                    remove(s.substr(0, j) + s.substr(j + 1),
                           i,
                           j,
                           open,
                           close);
                }
            }
            return;
        }

        // No extra closing parentheses.
        reverse(s.begin(), s.end());

        if (open == '(') {
            // Now remove extra opening parentheses.
            remove(s, 0, 0, ')', '(');
        } else {
            // Both passes finished.
            ans.push_back(s);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        remove(s, 0, 0, '(', ')');
        return ans;
    }
};