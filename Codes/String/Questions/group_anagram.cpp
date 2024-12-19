#include <bits/stdc++.h>
using namespace std;
class Solution {
public:


    std::array<int,256>hash(string s){
        std::array<int,256>hash={0};
        for(int i = 0 ; i<s.size() ; i++){
            hash[s[i]]++;
        }
        return hash;
    }


    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<std::array<int,256>,vector<string>>mp;

        for(auto str:strs){
            mp[hash(str)].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto it = mp.begin(); it!=mp.end() ;it++){
            ans.push_back(it->second);
        }
        return ans;


        
    }
};

// Time Complexity:

// Hash Function: Calculating the hash for each string takes O(m), where m is the length of the string.
// Hash Map Insertion: Inserting into the map takes O(log n) time in the worst case, where n is the number of unique keys.
// Overall: The overall time complexity is O(n * m * log n), where n is the number of strings and m is the average length of the strings.
// Space Complexity:

// Hash Map: The space complexity for the hash map is O(n * m), where n is the number of strings and m is the average length of the strings.
// Auxiliary Space: Additional space is used for the hash arrays, which is O(n * 256).

// METHOD 2 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>>mp;

        for(auto str:strs){
            string s = str;
            sort(s.begin() ,s.end());
            mp[s].push_back(str);
        }

        vector<vector<string>>ans;
        for(auto it = mp.begin(); it!=mp.end() ;it++){
            ans.push_back(it->second);
        }
        return ans;


        
    }
};

// Time Complexity:

// Sorting: Sorting each string takes O(m log m), where m is the length of the string.
// Hash Map Insertion: Inserting into the unordered map takes O(1) on average.
// Overall: The overall time complexity is O(n * m log m), where n is the number of strings and m is the average length of the strings.
// Space Complexity:

// Hash Map: The space complexity for the hash map is O(n * m), where n is the number of strings and m is the average length of the strings.
// Auxiliary Space: Additional space is used for the sorted strings, which is O(n * m).
// Comparison and Optimization
// The second approach is generally better because it has a lower time complexity of O(n * m log m) compared to the first approach's O(n * m * log n). The second approach uses sorting, which is more efficient than the custom hash function and map insertion in the first approach.



class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (auto& str : strs) {
            vector<int> freq(26, 0);
            for (char c : str) {
                freq[c - 'a']++;
            }

            // Create a unique key from the frequency count
            string key = "";
            for (int count : freq) {
                key += '#' + to_string(count); // Use '#' to separate counts
            }

            mp[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto& it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};



// Time Complexity:
// freuency computation takes O(m) time, where m is the length of the string.
// iterating over all strings takes O(n.m) time, where n is the number of strings.
// Overall, the time complexity is O(n.m).

// and time complexity is O(n*m) and space complexity is O(n*m)