class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto ch:s){
            if(!st.empty() && st.top() == ch){
                st.pop();
            }
            else{
                st.push(ch);
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

// time complexity is O(n) and space complexity is decreased to O(n) in worst case  from O(n) but it helps in removing overhead of stack
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (char ch : s) {
            if (!result.empty() && result.back() == ch) {
                result.pop_back();
            } else {
                result.push_back(ch);
            }
        }
        return result;
    }
};