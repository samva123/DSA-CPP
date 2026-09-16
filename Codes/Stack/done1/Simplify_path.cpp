#include <bits/stdc++.h>
using namespace std;





class Solution {
public:
    string simplifyPath(string path) {
        vector<string> components;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                continue;
            } else if (token == "..") {
                if (!components.empty()) {
                    components.pop_back();
                }
            } else {
                components.push_back(token);
            }
        }

        string result = "/";
        for (int i = 0; i < components.size(); ++i) {
            result += components[i];
            if (i != components.size() - 1) {
                result += "/";
            }
        }

        return result;
    }
};



// Explanation
// Use a stringstream to split the input path by '/'.
// Use a vector components to store the valid path components.
// Traverse the split tokens:
// Ignore empty tokens and ".".
// If the token is "..", pop the last component from the vector if it's not empty.
// Otherwise, push the token onto the vector.
// Construct the result string by joining the components with '/'.
// Return the result string.
// This approach maintains the time complexity of O(n) and space complexity of O(n), but it simplifies the code by using a vector and directly constructing the result string.











#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string curr = "";

        for (int i = 0; i <= path.size(); i++) {
            if (i == path.size() || path[i] == '/') {
                if (curr == "" || curr == ".") {
                    
                }
                else if (curr == "..") {
                    if (!st.empty()) st.pop_back();
                }
                else {
                    st.push_back(curr);
                }
                curr = "";
            } 
            else {
                curr += path[i];
            }
        }

        if (st.empty()) return "/";

        string ans = "";
        for (string &dir : st) {
            ans += "/" + dir;
        }

        return ans;
    }
};