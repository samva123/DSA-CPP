#include<bits/stdc++.h>
using namespace std;

//METHOD 1 

class Solution {
public:
    bool isAnagram(string s, string t) {

        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

        if(s != t){
            return false;
        }
        return true;
        
    }
};


// METHOD 2 

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> count;
        
        // Count the frequency of characters in string s
        for (auto x : s) {
            count[x]++;
        }
        
        // Decrement the frequency of characters in string t
        for (auto x : t) {
            count[x]--;
        }
        
        // Check if any character has non-zero frequency
        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};


// METHOD 3 

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        
        // Count the frequency of characters in string s
        for (char x : s) {
            count[x - 'a']++;
        }
        
        // Decrement the frequency of characters in string t
        for (char x : t) {
            count[x - 'a']--;
        }
        
        // Check if any character has non-zero frequency
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        
        return true;
    }
};


//METHOD 4 
class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqtable[256] = {0};
        for(int i = 0 ; i<s.size() ; i++){
            freqtable[s[i]]++;
        }

        for(int i = 0 ; i<t.size() ; i++){
            freqtable[t[i]]--;

        }


        for(int i = 0 ; i<256 ;i++){
            if(freqtable[i] != 0){
                return false;
            }
        }
        return true;
        
    }
};