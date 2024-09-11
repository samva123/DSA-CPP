class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        for(auto ch:s){
            if(ch == ']'){
                string stringtorepeat = "";
                while(!st.empty() && !isdigit(st.top()[0])){
                    string top = st.top();
                    stringtorepeat += top == "[" ? "" : top;
                    st.pop();
                }

                string numericTimes = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes += st.top();
                    st.pop(); 
                }
                reverse(numericTimes.begin() , numericTimes.end());
                int n = stoi(numericTimes);

                string current = "";
                while(n--){
                    current += stringtorepeat;
                }
                st.push(current);

            }
            else{
                string temp(1,ch);
                st.push(temp);

            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;

        
    }
};