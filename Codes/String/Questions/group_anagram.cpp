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


















// ⏱️ Time Complexity:

// For each string of length L:

// Counting frequency → O(L)

// Building key (26 chars) → O(26) ≈ O(1)

// For N strings → O(N * L) overall

// Inserting into unordered_map → O(1) average per insert

// ✅ Total: O(N * L)

// 💾 Space Complexity:

// Frequency array: O(26) per string (temporary) → O(1)

// Hashmap stores:

// Keys (26 * avg key length) → O(N)

// All original strings → O(N * L)

// ✅ Total: O(N * L)








// ⏱️ Time Complexity:

// Sorting each string of length L → O(L log L)

// For N strings → O(N * L log L)

// Inserting into unordered_map → O(1) average

// ✅ Total: O(N * L log L)

// 💾 Space Complexity:

// Copy of each string → O(L) temporary

// Hashmap stores:

// Sorted keys (length L each) → O(N * L)

// All original strings → O(N * L)

// ✅ Total: O(N * L)













// ⚖️ Comparison Table
// Approach	Map or Unordered_Map	Time Complexity	Space Complexity
// Frequency + unordered_map	Hash table	O(N × L)	O(N × L)
// Frequency + map	Balanced BST	O(N × (L + log N))	O(N × L)
// Sort + unordered_map	Hash table	O(N × L log L)	O(N × L)
// Sort + map	Balanced BST	O(N × (L log L + log N))	O(N × L)









