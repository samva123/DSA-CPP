class Solution {
public:
    int minAddToMakeValid(string s) {
        // int ans = 0;
        stack<int>st;
        for(auto ch:s){
            if(ch == '('){
                st.push(ch);}
            else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                    continue;
                }
                st.push(ch);
            }



        }
        return st.size();

        
        
        
    }
};