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