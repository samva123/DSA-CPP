class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int maxlen = 0;

        for(int i =0 ; i<s.length() ; i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len = i - st.top();
                    maxlen = max(len,maxlen);
                }
            }
        }
        return maxlen;
        
    }
};





class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxlen = 0;

        // Left to right scan
        for (char ch : s) {
            if (ch == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlen = max(maxlen, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;

        // Right to left scan
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlen = max(maxlen, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return maxlen;
    }
};




// Explanation
// Use two counters left and right to keep track of the number of '(' and ')' characters.
// Perform a left-to-right scan:
// Increment left for each '(' and right for each ')'.
// If left equals right, update maxlen with the length of the valid substring.
// If right exceeds left, reset both counters.
// Perform a right-to-left scan:
// Increment left for each '(' and right for each ')'.
// If left equals right, update maxlen with the length of the valid substring.
// If left exceeds right, reset both counters.
// Return maxlen.
// This approach maintains the time complexity of O(n) but reduces the space complexity to O(1), making it more space-efficient.