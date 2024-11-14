class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<char>st;
        for(auto digit : num){
            if(k>0){
                while(!st.empty() && st.top() > digit){
                    st.pop();
                    k--;
                    if(k==0)
                        break;
                }
            }
            st.push(digit);
        }
        if(k>0){
            while(!st.empty() && k){
                st.pop();
                k--;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        while(ans.size()>0 && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin() , ans.end());
        return ans == "" ? "0" : ans;


        
    }
};




class Solution {
public:
    string removeKdigits(string num, int k) {
        string result;
        for (char digit : num) {
            while (!result.empty() && k > 0 && result.back() > digit) {
                result.pop_back();
                k--;
            }
            if (!result.empty() || digit != '0') { // Avoid leading zeros
                result.push_back(digit);
            }
        }
        // If there are still characters to remove
        while (k > 0 && !result.empty()) {
            result.pop_back();
            k--;
        }
        return result.empty() ? "0" : result;
    }
};



// Explanation
// Use a string result to simulate the stack.
// Traverse the input string num:
// While the result is not empty, k is greater than 0, and the last character in result is greater than the current digit, pop the last character from result and decrement k.
// If the result is not empty or the current digit is not '0' (to avoid leading zeros), push the current digit onto result.
// If there are still characters to remove (k > 0), pop characters from the end of result.
// If result is empty, return "0". Otherwise, return result.
// This approach maintains the time complexity of O(n) and space complexity of O(n), but it simplifies the code by using a string instead of a stack and handling leading zeros more efficiently.