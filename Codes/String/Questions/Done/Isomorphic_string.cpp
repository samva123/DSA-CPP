#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
     
    void createUpdateMapping(string& str) {
        //find mappping
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: str) {
            if(mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        //update the string
        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }
    bool isIsomorphic(string s, string t) {
       createUpdateMapping(s);
        createUpdateMapping(t);

        if(s == t){
            return true;
        }
        return false;
        
    }
};




















//courtesty of chatgpt
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        vector<int> mapST(256, -1), mapTS(256, -1); // Fixed size for ASCII

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            if (mapST[c1] == -1 && mapTS[c2] == -1) {
                mapST[c1] = c2;
                mapTS[c2] = c1;
            } else if (mapST[c1] != c2 || mapTS[c2] != c1) {
                return false;
            }
        }

        return true;
    }
};
// Time complexity is O(n) and space complexity is O(1) for both the solutions.





// Which is Better?
// Your Approach:

// Advantage: Simpler conceptually for understanding, as it reduces the problem to string equality.
// Drawback: Requires modifying the strings and uses extra space for normalization.
// My Optimized Approach:

// Advantage: No string modification and less overhead. Direct mapping validation is faster and more efficient in real-world scenarios.
// Drawback: Slightly more complex to understand due to dual mappings.
