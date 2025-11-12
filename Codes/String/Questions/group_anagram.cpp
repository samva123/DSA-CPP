#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mpp;

        for (auto& str : strs) {
            vector<int> freq(26, 0);
            for (char c : str)
                freq[c - 'a']++;

            // Convert freq array to a key string (e.g. "#1#0#0#2#0...")
            string key;
            for (int f : freq) {
                key += "#" + to_string(f);
            }

            mpp[key].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& it : mpp)
            result.push_back(it.second);

        return result;
    }
};

///below is my solution 
//use chatgpt for both answers time and space if forgot 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mpp;
        for(auto str : strs){
            string temp  = str;
            sort(temp.begin() , temp.end());
            if(mpp.count(temp)){
                mpp[temp].push_back(str);
            }else{
                mpp[temp].push_back(str);
            }
        }

        vector<vector<string>>result;
        for(auto it : mpp){
            result.push_back(it.second);
        }
        return result;
        
    }
};



































































































