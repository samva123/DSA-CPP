#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // Approach 1: Recursion + find
    bool isValidRecursive(string s) {
        if(s.size() == 0){
            return true;
        }

        int fnd = s.find("abc");
        if(fnd != string::npos){
            string tleft = s.substr(0, fnd);
            string tright = s.substr(fnd + 3, s.size());
            return isValidRecursive(tleft + tright);
        }

        return false;
    }


    // Approach 2: Stack
    bool isValidStack(string s) {

        if(s.size() == 0) return true;

        if(s[0] != 'a'){
            return false;
        }

        stack<char> st;

        for(char ch : s){
            if(ch == 'a'){
                st.push(ch);
            }
            else if(ch == 'b'){
                if(!st.empty() && st.top() == 'a'){
                    st.push('b');
                }
                else{
                    return false;
                }
            }
            else{
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();
    }


    // Approach 3: Vector as stack
    bool isValidVector(string s) {

        vector<char> st;

        for(char c : s){
            st.push_back(c);

            if(st.size() >= 3){
                int n = st.size();

                if(st[n-3]=='a' && st[n-2]=='b' && st[n-1]=='c'){
                    st.pop_back();
                    st.pop_back();
                    st.pop_back();
                }
            }
        }

        return st.empty();
    }
};