#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<string>& ans, string mapping[], string str, int index,string output) {
        //base case
        if(index >= str.length()) {
            
            if(output.length() > 0)
                ans.push_back(output);
            
            return;
        }
        string temp = mapping[str[index] - '0'];
        
        for(auto ch: temp) {
            output.push_back(ch);
            solve(ans,mapping,str,index+1,output);
            output.pop_back();


            // we can also write below line instead of above three lines 
            // solve(ans,mapping,str,index+1,output+ch);

        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string mapping[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index = 0;
        string output = "";
        solve(ans, mapping, digits,index,output);
        return ans;

        
    }
};




















#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> mapping = {
            
            "",    "",    "abc", "def", "ghi",
            "jkl", "mno", "pqrs","tuv","wxyz"
        };

        vector<string> ans = {""};  // start with an empty string

        for (char d : digits) {
            vector<string> temp;
            string letters = mapping[d - '0'];
            for (string s : ans) {
                for (char c : letters) {
                    temp.push_back(s + c);
                }
            }
            ans.swap(temp);  // update ans with new list
        }

        return ans;
    }
};

int main() {
    Solution obj;
    string digits = "23";
    vector<string> result = obj.letterCombinations(digits);

    for (auto &s : result) cout << s << " ";
    cout << endl;

    return 0;
}
