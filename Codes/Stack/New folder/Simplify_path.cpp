class Solution {
public:
    void buildans(stack<string>&s , string&ans){
        if(s.empty()){
            return;
        }
        string minPath = s.top(); s.pop();
        buildans(s,ans);
        ans += minPath;
    }
    string simplifyPath(string path) {
        stack<string>s;
        int i = 0;
        while(i < path.size()){
            int start = i;
            int end = i+1;
            while(end < path.size() && path[end] != '/'){
                ++end;
            }
            string minPath = path.substr(start , end-start);
            i = end;
            if(minPath == "/" || minPath == "/."){
                continue;
            }
            if(minPath != "/.."){
                s.push(minPath);
            }
            else if(!s.empty()){
                s.pop();
            }

        }
        string ans = s.empty() ? "/" : "";
        buildans(s,ans);
        return ans;
        
    }
};


// o(n) ans o(n)




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


