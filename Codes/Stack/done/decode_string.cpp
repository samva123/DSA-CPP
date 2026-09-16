#include<bits/stdc++.h>
using namespace std;











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
                auto front = st.top();
                auto prevString  = front.first;
                auto repeatTimes = front.second;

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













#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, int>> st;
        string currentString = "";
        int currentNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                st.push({currentString.size(), currentNum});
                currentNum = 0;
            } 
            else if (ch == ']') {
                auto front = st.top();
                int prevSize = front.first;
                int repeatTimes = front.second;
                st.pop();
                
                string repeatedString = currentString.substr(prevSize);

                string temp = "";
                for (int i = 0; i < repeatTimes; i++) {
                    temp += repeatedString;
                }

                currentString = currentString.substr(0, prevSize) + temp;
            } 
            else {
                currentString += ch;
            }
        }

        return currentString;
    }
};