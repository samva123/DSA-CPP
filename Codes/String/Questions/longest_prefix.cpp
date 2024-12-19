#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs){
        sort(strs.begin(),strs.end());
        int m=strs[0].size();
        string ans="";
        for(int i=0; i<m; i++){
            if(strs[0][i]==strs.back()[i])
            ans.push_back(strs[0][i]);
            else
            break;
        }
        return ans;
    }
};


//METHOD 2

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = strs[0];
        for (string s : strs)
            while (s.find(prefix) != 0)
                prefix = prefix.substr(0, prefix.length() - 1);
        return prefix;
    }
};








class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != c)
                    return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};




// ```

// ---

// ### **Complexity of Vertical Scanning**

// 1. **Time Complexity**:
//    - In the worst case, every character of every string is compared.
//    - \(O(n \cdot k)\), where \(n\) is the number of strings and \(k\) is the length of the shortest string.

// 2. **Space Complexity**:
//    - Only a few variables and the result string are used.
//    - **Space Complexity**: \(O(1)\).

// ---

// ### **Comparison**

// | **Method**              | **Time Complexity**   | **Space Complexity** | **Notes**                                       |
// |--------------------------|-----------------------|-----------------------|------------------------------------------------|
// | Sorting (Method 1)       | \(O(nlog n + k)\)   | \(O(1)\)              | Includes sorting overhead but is simple.      |
// | Iterative Prefix (Method 2) | \(O(n.k)\)      | \(O(k)\)              | No sorting but modifies prefix iteratively.   |
// | Vertical Scanning        | \(O(n.k)\)      | \(O(1)\)              | Most efficient and avoids unnecessary sorting.|

// ---

// ### **Conclusion**

// The **Vertical Scanning** approach is the most optimized in terms of both time and space complexity. It eliminates the overhead of sorting (Method 1) and avoids unnecessary prefix modifications (Method 2).