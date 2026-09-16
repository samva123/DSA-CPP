#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string rle(string s){
        stringstream ss;

        char prev = s[0];
        int count = 0 ;

        for(int i = 0 ; i < s.size() ; i++){
            if(prev == s[i]){
                count++;
            }else{
                ss << count << prev;
                count = 1;
                prev = s[i];
            }

            
        }
        ss << count << prev;
        return ss.str();
    }
    string countAndSay(int n) {
        string ans = "1";
        for(int i = 1 ; i < n ; i++){
            ans = rle(ans);
        }
        return ans;
        
    }
};


class Solution {
public:
    string say(string s) {
        string res;

        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find end of current group
            while (j < s.size() && s[j] == s[i]) {
                j++;
            }

            int count = j - i;

            res += to_string(count);
            res += s[i];

            i = j;
        }

        return res;
    }

    string countAndSay(int n) {
        string ans = "1";

        for (int i = 1; i < n; i++) {
            ans = say(ans);
        }

        return ans;
    }
};

// L grows approximately as 1.3036^n,
// so the complexity can also be expressed as O(1.3036^n).