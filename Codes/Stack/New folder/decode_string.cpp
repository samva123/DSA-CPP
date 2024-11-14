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

                    // The line string temp(1, ch); creates a new string temp that contains a single character ch.

                    // Explanation
                    // string temp(1, ch); is a constructor call for the string class.
                    // The first argument 1 specifies the number of times the character ch should be repeated in the string.
                    // The second argument ch is the character to be repeated.
                    // In this case, it creates a string temp that consists of the character ch repeated once.

                    // Example
                    // If ch is 'a', then string temp(1, 'a'); will create a string temp with the value "a".
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













class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st;
        string currentString = "";
        int currentNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            } else if (ch == '[') {
                st.push({currentString, currentNum});
                currentString = "";
                currentNum = 0;
            } else if (ch == ']') {
                auto [prevString, repeatTimes] = st.top();
                st.pop();
                string temp = "";
                for (int i = 0; i < repeatTimes; ++i) {
                    temp += currentString;
                }
                currentString = prevString + temp;
            } else {
                currentString += ch;
            }
        }

        return currentString;
    }
};



// Explanation
// Use a stack to store pairs of the current string and the number of times it should be repeated.
// Traverse the input string s:
// If the current character is a digit, update currentNum.
// If the current character is '[', push the current string and number onto the stack, then reset them.
// If the current character is ']', pop from the stack and repeat the current string the specified number of times, then concatenate it with the previous string.
// If the current character is a letter, append it to the current string.
// After processing all characters, return the currentString.
// This approach maintains the time complexity of O(n * k) and space complexity of O(n), but it simplifies the code by using a single stack to store both characters and numbers.


