#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs.back();

        int i = 0;
        while(i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
    }
};






#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]) {
                j++;
            }
            prefix = prefix.substr(0, j);  // shorten prefix

            if (prefix == "") break;  // no need to continue
        }

        return prefix;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs[0].size();

        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < len && j < strs[i].size() && strs[0][j] == strs[i][j]) {
                j++;
            }
            len = j;
        }

        return strs[0].substr(0, len); // only one substring created at the end
    }
};